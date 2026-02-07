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
        printf("[FIFO] 警告: FIFO已初始化，跳过重复初始化.\n");
        return 0;
    }

    g_fifo.head = 0;
    g_fifo.tail = 0;
    g_fifo.count = 0;

    int ret = pthread_mutex_init(&g_fifo.mutex, NULL);
    if (ret != 0) {
        fprintf(stderr, "[FIFO] 错误: mutex初始化失败 (errno=%d)\n", ret);
        return -1;
    }

    ret = pthread_cond_init(&g_fifo.cond, NULL);
    if (ret != 0) {
        fprintf(stderr, "[FIFO] 错误: cond初始化失败 (errno=%d)\n", ret);
        pthread_mutex_destroy(&g_fifo.mutex);
        return -2;
    }

    g_fifo.buf_size = w * h * 4;
    for (int i = 0; i < FIFO_BUF_COUNT; i++) {
        g_fifo.pool[i] = malloc(g_fifo.buf_size);
        if (g_fifo.pool[i] == NULL) {
            fprintf(stderr, "[FIFO] 错误: 内存分配失败 (errno=%d)\n", errno);
            for (int j = 0; j < i; j++) {
                free(g_fifo.pool[j]);
            }
            pthread_cond_destroy(&g_fifo.cond);
            pthread_mutex_destroy(&g_fifo.mutex);
            return -3;
        }
    }

    initialized = 1;
    printf("[FIFO] 初始化完成. 容量: %d, 单Buffer大小: %d bytes.\n", FIFO_BUF_COUNT, g_fifo.buf_size);
}

FIFOHandle fifo_acquire(void) {
    FIFOHandle handle = {0};
    handle.data = NULL;

    pthread_mutex_lock(&g_fifo.mutex);

    if (g_fifo.count >= FIFO_BUF_COUNT) {
        pthread_mutex_unlock(&g_fifo.mutex);
        printf("[FIFO] buffer full.\n");
        return handle;
    }

    handle.buf_id   = g_fifo.tail;
    handle.data     = g_fifo.pool[g_fifo.tail];
    handle.buf_size = g_fifo.buf_size;
    handle.data_len = 0; 

    pthread_mutex_unlock(&g_fifo.mutex);
    return handle;
}

void fifo_push(FIFOHandle handle) {

    if (handle.data == NULL || handle.buf_id < 0 || handle.buf_id >= FIFO_BUF_COUNT) {
        printf("[FIFO] failed to push id%d.\n",handle.buf_id);
        return;
    }

    pthread_mutex_lock(&g_fifo.mutex);
    g_fifo.tail = (g_fifo.tail + 1) % FIFO_BUF_COUNT;
    g_fifo.count++;

    printf("[FIFO] Push ID: %d, Len: %d bytes. sum: %d\n",handle.buf_id, handle.data_len, g_fifo.count);

    pthread_cond_signal(&g_fifo.cond);
    pthread_mutex_unlock(&g_fifo.mutex);
}

FIFOHandle fifo_pop(void) {
    FIFOHandle handle = {0};
    handle.data = NULL;

    pthread_mutex_lock(&g_fifo.mutex);
    if(g_fifo.count > 0) {
        // pthread_cond_wait(&g_fifo.cond, &g_fifo.mutex);
        handle.buf_id   = g_fifo.head;
        handle.data     = g_fifo.pool[g_fifo.head];
        handle.buf_size = g_fifo.buf_size;
        pthread_mutex_unlock(&g_fifo.mutex);
    }
    return handle;
}

void fifo_release(FIFOHandle handle) {
    if (handle.data == NULL || handle.buf_id < 0 || handle.buf_id >= FIFO_BUF_COUNT) {
        printf("[FIFO] failed to release id=%d\n",handle.buf_id);
        return;
    }

    pthread_mutex_lock(&g_fifo.mutex);
    g_fifo.head = (g_fifo.head + 1) % FIFO_BUF_COUNT;
    g_fifo.count--;

    printf("[FIFO] Release ID: %d. sum: %d\n", handle.buf_id, g_fifo.count);
    pthread_cond_signal(&g_fifo.cond);
    pthread_mutex_unlock(&g_fifo.mutex);
}
