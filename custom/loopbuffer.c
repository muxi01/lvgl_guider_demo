#include "loopbuffer.h"
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>
#include <sys/time.h>
#include <stdint.h>
#include <stdlib.h>
#include "main.h"


static StaticFIFO g_fifo;

int fifo_init(int w, int h) {
    static int initialized = 0;

    if (initialized) {
        printf("[FIFO] failed to init agian\n");
        return 0;
    }

    g_fifo.head = 0;
    g_fifo.tail = 0;
    g_fifo.count = 0;

    int ret = pthread_mutex_init(&g_fifo.mutex, NULL);
    if (ret != 0) {
        fprintf(stderr, "[FIFO] failed to init mutex(errno=%d)\n", ret);
        return -1;
    }

    ret = pthread_cond_init(&g_fifo.cond, NULL);
    if (ret != 0) {
        fprintf(stderr, "[FIFO] failed to init cond (errno=%d)\n", ret);
        pthread_mutex_destroy(&g_fifo.mutex);
        return -2;
    }

    int buf_size = w * h * 4;
    for (int i = 0; i < FIFO_BUF_COUNT; i++) {
        memset(&(g_fifo.pool[i]), 0, sizeof(FIFOHandle));
        g_fifo.pool[i].buf_size = buf_size;
        g_fifo.pool[i].data = malloc(buf_size);
        if (g_fifo.pool[i].data == NULL) {
            fprintf(stderr, "failed to malloc buffer (errno=%d)\n", errno);
            for (int j = 0; j < i; j++) {
                free(g_fifo.pool[j].data);
            }
            pthread_cond_destroy(&g_fifo.cond);
            pthread_mutex_destroy(&g_fifo.mutex);
            return -3;
        }
    }
    initialized = 1;
    printf("[FIFO] init done capacity: %d, buffer size: %d bytes.\n", FIFO_BUF_COUNT,buf_size);
}
FIFOHandle_p fifo_acquire(void) {
    FIFOHandle_p handle;
    pthread_mutex_lock(&g_fifo.mutex);
    if (g_fifo.count >= FIFO_BUF_COUNT) {
        pthread_mutex_unlock(&g_fifo.mutex);
        printf("[FIFO] buffer full.\n");
        return NULL;
    }
    handle = &(g_fifo.pool[g_fifo.tail]);
    handle->buf_id =g_fifo.tail;
    pthread_mutex_unlock(&g_fifo.mutex);
    return handle;
}

void fifo_push(FIFOHandle_p handle) {

    if(handle == NULL || handle->data == NULL || handle->buf_id < 0 || handle->buf_id >= FIFO_BUF_COUNT) {
        printf("[FIFO] failed to push id%d.\n",handle->buf_id);
        return;
    }

    pthread_mutex_lock(&g_fifo.mutex);
    g_fifo.tail = (g_fifo.tail + 1) % FIFO_BUF_COUNT;
    g_fifo.count++;

    printf("[FIFO] Push ID: %d, Len: %ld bytes. sum: %d\n",handle->buf_id, handle->data_len, g_fifo.count);

    pthread_cond_signal(&g_fifo.cond);
    pthread_mutex_unlock(&g_fifo.mutex);
}

FIFOHandle_p fifo_pop(void) {
    FIFOHandle_p handle=NULL;

    pthread_mutex_lock(&g_fifo.mutex);
    if(g_fifo.count > 0) {
        // pthread_cond_wait(&g_fifo.cond, &g_fifo.mutex);
        handle =&(g_fifo.pool[g_fifo.head]);
        handle->buf_id =g_fifo.head;
    }
    pthread_mutex_unlock(&g_fifo.mutex);
    return handle;
}

void fifo_release(FIFOHandle_p handle) {
    if( handle == NULL || handle->data == NULL || handle->buf_id < 0 || handle->buf_id >= FIFO_BUF_COUNT) {
        printf("[FIFO] failed to release id=%d\n",handle->buf_id);
        return;
    }

    pthread_mutex_lock(&g_fifo.mutex);
    g_fifo.head = (g_fifo.head + 1) % FIFO_BUF_COUNT;
    g_fifo.count--;

    printf("[FIFO] Release ID: %d. sum: %d\n", handle->buf_id, g_fifo.count);
    pthread_cond_signal(&g_fifo.cond);
    pthread_mutex_unlock(&g_fifo.mutex);
}
