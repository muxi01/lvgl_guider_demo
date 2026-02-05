/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdbool.h>
#include <stdio.h>
#include "core/lv_obj_pos.h"
#include "display/lv_display.h"
#include "lvgl.h"
#include "custom.h"
#include "misc/lv_event.h"
#include "misc/lv_types.h"
#include <pthread.h>
#include "images.h"
#include <string.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>


#define IMAGE_TYPE_RGB565  (('R' << 24) | ('G' << 16) | ('B' << 8) | (16 << 0))
#define IMAGE_TYPE_RGB888  (('R' << 24) | ('G' << 16) | ('B' << 8) | (24 << 0))
#define IMAGE_TYPE_YUV420  (('Y' << 24) | ('4' << 16) | ('2' << 8) | ('0' << 0))
#define IMAGE_TYPE_JPG     (('J' << 24) | ('P' << 16) | ('E' << 8) | ('G' << 0))
#define IMAGE_TYPE_NULL    (('N' << 24) | ('U' << 16) | ('L' << 8) | ('L' << 0))
#define FRAME_MAGIC_ID     (('l' << 24) | ('v' << 16) | ('s' << 8) | ('n' << 0))
#define BUFFER_POOL_SIZE   8
#define BUFFER_SIZE        (1024 * 1024)

#define BUFFER_STATE_EMPTY 0
#define BUFFER_STATE_FULL  1

typedef struct _buffer_node {
    unsigned char *data;
    size_t size;
    size_t capacity;
    int state;
} buffer_node_t;

typedef struct _buffer_pool {
    buffer_node_t buffers[BUFFER_POOL_SIZE];
    int empty_count;
    int full_count;
    pthread_mutex_t mutex;
    pthread_cond_t empty_cond;
    pthread_cond_t full_cond;
} buffer_pool_t;

static buffer_pool_t g_buffer_pool;

typedef struct _Image {
    unsigned char *buff;
    unsigned int buff_size;
    unsigned int img_size;
    unsigned int img_cnt;
    unsigned int w,h;
}image_body_buff;


typedef union _image_select {
    uint64_t image_select;
    struct  {
        uint32_t id;
        uint32_t type;
    }magic;
}image_frame_select;

typedef struct _image_info {
    uint32_t img_len;
    uint32_t img_cnt;
}image_frame_info;

typedef struct _image_frame_header_t {
    image_frame_select select;
    image_frame_info  info;
} image_frame_header_t;


uint64_t transfer_get_image_header(void)
{
    uint64_t select=FRAME_MAGIC_ID;
    select=(select << 32) | IMAGE_TYPE_JPG;
    return select;
}

int transfer_buffer_pool_init(void)
{
    int i;

    memset(&g_buffer_pool, 0, sizeof(buffer_pool_t));

    pthread_mutex_init(&g_buffer_pool.mutex, NULL);
    pthread_cond_init(&g_buffer_pool.empty_cond, NULL);
    pthread_cond_init(&g_buffer_pool.full_cond, NULL);

    for (i = 0; i < BUFFER_POOL_SIZE; i++) {
        g_buffer_pool.buffers[i].data = malloc(BUFFER_SIZE);
        if (!g_buffer_pool.buffers[i].data) {
            return -1;
        }
        g_buffer_pool.buffers[i].capacity = BUFFER_SIZE;
        g_buffer_pool.buffers[i].size = 0;
        g_buffer_pool.buffers[i].state = BUFFER_STATE_EMPTY;
    }
    g_buffer_pool.empty_count = BUFFER_POOL_SIZE;
    g_buffer_pool.full_count = 0;

    return 0;
}

buffer_node_t *transfer_buffer_pool_alloc(void)
{
    int i;
    buffer_node_t *node = NULL;
    pthread_mutex_lock(&g_buffer_pool.mutex);
    while (g_buffer_pool.empty_count == 0) {
        pthread_cond_wait(&g_buffer_pool.empty_cond, &g_buffer_pool.mutex);
    }

    for (i = 0; i < BUFFER_POOL_SIZE; i++) {
        if (g_buffer_pool.buffers[i].state == BUFFER_STATE_EMPTY) {
            node = &g_buffer_pool.buffers[i];
            node->state = BUFFER_STATE_FULL;
            node->size = 0;
            g_buffer_pool.empty_count--;
            break;
        }
    }
    pthread_mutex_unlock(&g_buffer_pool.mutex);

    return node;
}

void transfer_buffer_pool_commit(buffer_node_t *node)
{
    pthread_mutex_lock(&g_buffer_pool.mutex);

    node->state = BUFFER_STATE_FULL;
    g_buffer_pool.full_count++;

    pthread_cond_signal(&g_buffer_pool.full_cond);
    pthread_mutex_unlock(&g_buffer_pool.mutex);
}

buffer_node_t *transfer_buffer_pool_acquire(void)
{
    int i;
    buffer_node_t *node = NULL;

    pthread_mutex_lock(&g_buffer_pool.mutex);

    while (g_buffer_pool.full_count == 0) {
        pthread_cond_wait(&g_buffer_pool.full_cond, &g_buffer_pool.mutex);
    }

    for (i = 0; i < BUFFER_POOL_SIZE; i++) {
        if (g_buffer_pool.buffers[i].state == BUFFER_STATE_FULL) {
            node = &g_buffer_pool.buffers[i];
            break;
        }
    }

    pthread_mutex_unlock(&g_buffer_pool.mutex);

    return node;
}

void transfer_buffer_pool_release(buffer_node_t *node)
{
    pthread_mutex_lock(&g_buffer_pool.mutex);

    node->state = BUFFER_STATE_EMPTY;
    g_buffer_pool.empty_count++;
    g_buffer_pool.full_count--;

    pthread_cond_signal(&g_buffer_pool.empty_cond);
    pthread_mutex_unlock(&g_buffer_pool.mutex);
}



void *transfer_thread(void *args) {

    const char *path="/dev/ttyGS0";

    uint32_t nbytes,wants,readed;
    uint64_t header;
    uint64_t select;
    image_frame_info  info;
    buffer_node_t *buffer =NULL;

    transfer_buffer_pool_init();
    select = transfer_get_image_header();
    int fd=open(path,O_RDONLY);
    if(fd > 0) {
        for(;;) {
            while(buffer == NULL) {
                buffer = transfer_buffer_pool_alloc();
            }
            nbytes = read(fd, &header, sizeof(uint64_t));  
            if((nbytes == sizeof(uint64_t)) && (header == select)) {
                nbytes =read(fd, &info, sizeof(image_frame_info));
                if(nbytes == sizeof(image_frame_info)) {
                    if(buffer->capacity >= info.img_len) {
                        readed =0;
                        nbytes =0;
                        wants =info.img_len;
                        do {
                            nbytes =read(fd, buffer->data + readed, wants);
                            readed +=nbytes;
                            wants -=nbytes;
                        }while(readed < info.img_len);
                        buffer->size = readed;
                        transfer_buffer_pool_commit(buffer);
                        buffer=NULL;
                    }
                }
            }
        }
        close(fd);
    }
}

void *consumer_thread(void *args)
{
    buffer_node_t *buffer;

    for (;;) {
        buffer = transfer_buffer_pool_acquire();
        if (buffer) {
            printf("Consumer: received %zu bytes\n", buffer->size);
            transfer_buffer_pool_release(buffer);
        }
    }
    return NULL;
}