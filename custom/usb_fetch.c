#include "usb_fetch.h"
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#include <pthread.h>
#include "images.h"
#include <string.h>
#include <semaphore.h>
#include <sys/time.h>
#include <stdint.h>
#include "main.h"

extern st_parmaters setting;
// 定义全局FIFO实例
static StaticFIFO g_fifo;

void fifo_init(void) {
    static bool initialized = false;

    // 防止重复初始化
    if (initialized) {
        printf("[FIFO] 警告: FIFO已初始化，跳过重复初始化.\n");
        return;
    }

    // 初始化索引
    g_fifo.head = 0;
    g_fifo.tail = 0;
    g_fifo.count = 0;

    // 初始化同步机制（带错误检查）
    int ret = pthread_mutex_init(&g_fifo.mutex, NULL);
    if (ret != 0) {
        fprintf(stderr, "[FIFO] 错误: mutex初始化失败 (errno=%d)\n", ret);
        return;
    }

    ret = pthread_cond_init(&g_fifo.cond, NULL);
    if (ret != 0) {
        fprintf(stderr, "[FIFO] 错误: cond初始化失败 (errno=%d)\n", ret);
        pthread_mutex_destroy(&g_fifo.mutex); // 清理已初始化的mutex
        return;
    }

    initialized = true;
    printf("[FIFO] 初始化完成. 容量: %d, 单Buffer大小: %d bytes.\n", FIFO_BUF_COUNT, FIFO_BUF_SIZE);
}

FIFOHandle fifo_acquire(void) {
    FIFOHandle handle = {0};
    handle.data = NULL; // 默认置空，表示无效

    pthread_mutex_lock(&g_fifo.mutex);

    // 检查FIFO是否已满
    if (g_fifo.count >= FIFO_BUF_COUNT) {
        pthread_mutex_unlock(&g_fifo.mutex);
        printf("[FIFO] 警告: FIFO已满，无法获取空Buffer.\n");
        return handle;
    }

    // 填充句柄信息
    handle.buf_id   = g_fifo.tail;
    handle.data     = g_fifo.pool[g_fifo.tail]; // 直接指向静态数组
    handle.buf_size = FIFO_BUF_SIZE;
    handle.data_len = 0; // 初始有效长度为0，由用户填充

    pthread_mutex_unlock(&g_fifo.mutex);
    return handle;
}

void fifo_push(FIFOHandle handle) {
    // 合法性检查
    if (handle.data == NULL || handle.buf_id < 0 || handle.buf_id >= FIFO_BUF_COUNT) {
        printf("[FIFO] 错误: Push了无效的Handle.\n");
        return;
    }

    pthread_mutex_lock(&g_fifo.mutex);

    // 移动tail指针（生产）
    g_fifo.tail = (g_fifo.tail + 1) % FIFO_BUF_COUNT;
    g_fifo.count++;

    printf("[FIFO] Push ID: %d, 数据长度: %zu bytes. 当前队列数: %d\n",
           handle.buf_id, handle.data_len, g_fifo.count);

    // 通知消费者有数据了
    pthread_cond_signal(&g_fifo.cond);

    pthread_mutex_unlock(&g_fifo.mutex);
}

FIFOHandle fifo_pop(void) {
    FIFOHandle handle = {0};
    handle.data = NULL;

    pthread_mutex_lock(&g_fifo.mutex);

    // 阻塞等待数据
    while (g_fifo.count == 0) {
        pthread_cond_wait(&g_fifo.cond, &g_fifo.mutex);
    }

    // 填充句柄信息
    handle.buf_id   = g_fifo.head;
    handle.data     = g_fifo.pool[g_fifo.head];
    handle.buf_size = FIFO_BUF_SIZE;
    // 注意：data_len 应该是生产者在push前设置好的，这里直接使用内存中的值

    pthread_mutex_unlock(&g_fifo.mutex);
    return handle;
}

void fifo_release(FIFOHandle handle) {
    // 合法性检查
    if (handle.data == NULL || handle.buf_id < 0 || handle.buf_id >= FIFO_BUF_COUNT) {
        printf("[FIFO] 错误: Release了无效的Handle.\n");
        return;
    }

    pthread_mutex_lock(&g_fifo.mutex);

    // 移动head指针（消费完成）
    g_fifo.head = (g_fifo.head + 1) % FIFO_BUF_COUNT;
    g_fifo.count--;

    printf("[FIFO] Release ID: %d. 当前队列数: %d\n", handle.buf_id, g_fifo.count);

    // 通知可能阻塞的生产者（如果有）
    pthread_cond_signal(&g_fifo.cond);
    pthread_mutex_unlock(&g_fifo.mutex);
}


static void fetch_limited(long fps){
    struct timeval tv;
    static long long last=0,current=0;
    long long interval =1000000LL / fps;
    long long error,delay;

    gettimeofday(&tv, NULL);
    current =tv.tv_sec * 1000000LL + tv.tv_usec;

    if(last !=0) {
        error =current - last;
        delay =interval - error;
        if(delay > 0) {
            usleep(delay);
            gettimeofday(&tv, NULL);
            last =tv.tv_sec * 1000000LL + tv.tv_usec;
        } else {
            last = current;
        }
    }
    else {
        last = current;
    }
}


static uint64_t get_image_header(void)
{
    uint64_t select=FRAME_MAGIC_ID;
    select=(select << 32) | IMAGE_TYPE_JPG;
    return select;
}

int usb_fetch_frame(const char *path,FIFOHandle *pbuff) {
    uint64_t header;
    uint64_t select=get_image_header();
    image_frame_info info;
    static uint8_t discard[64];
    int fd=open(path,O_RDONLY);
    if(fd > 0) {
        return -1;
    }
    int nbytes = read(fd, &header, sizeof(uint64_t));
    if((nbytes == sizeof(uint64_t)) && (header == select)) {
        nbytes =read(fd, &info, sizeof(image_frame_info));
        if(nbytes == sizeof(image_frame_info)) {
            int readed =0;
            int total =info.img_len;
            int wants =info.img_len;
            if((pbuff->data != NULL) && (pbuff->buf_size >= info.img_len) && (info.img_len !=0)) {
                nbytes =0;
                do {
                    nbytes =read(fd, &(pbuff->data[readed]), wants);
                    readed +=nbytes;
                    wants -=nbytes;
                }while(readed < info.img_len);
                pbuff->data_len =info.img_len;
                close(fd);
                return 0;
            }
            else if(info.img_len > 0){
                do {
                    if(total > sizeof(discard)) {
                        wants =sizeof(discard);
                    } else {
                        wants =total;
                    }
                    nbytes =read(fd, &discard, wants);
                    total -=nbytes;
                }while(total);
            }
        }
    }
    close(fd);
    return -1;
}




int usb_fetch_one_frame(FIFOHandle *pbuff,int fd) {
    uint64_t header;
    image_frame_info info;
    uint8_t discard[64];
    uint64_t select=get_image_header();
    int nbytes = read(fd, &header, sizeof(uint64_t));
    if((nbytes == sizeof(uint64_t)) && (header == select)) {
        nbytes =read(fd, &info, sizeof(image_frame_info));
        if(nbytes == sizeof(image_frame_info)) {
            int readed =0;
            int wants =info.img_len;
            if((pbuff !=NULL) && (pbuff->data != NULL) && (pbuff->buf_size >= info.img_len) && (info.img_len !=0)) {
                nbytes =0;
                do {
                    nbytes =read(fd, &(pbuff->data[readed]), wants);
                    readed +=nbytes;
                    wants -=nbytes;
                }while(readed < info.img_len);
                pbuff->data_len =info.img_len;
                return 0;
            }
            else if(info.img_len > 0){
                do {
                    if(info.img_len > sizeof(discard)) {
                        wants =sizeof(discard);
                    } else {
                        wants =info.img_len;
                    }
                    nbytes =read(fd, &discard, wants);
                    info.img_len -=nbytes;
                }while(info.img_len);
            }
        }
    }
    return -1;
}


int usb_acquire_buff(FIFOHandle *pbuff,int fps)
{
    for(int i=0;i<3;i++){
        *pbuff =fifo_acquire();
        if(*pbuff->data == NULL) {
            fetch_limited(fps);
        } else {
            return 0;
        }
    }
    return -1;
}


void *usb_fetch_thread(void *args) {
    FIFOHandle buff;
    int fd=open(setting.image,O_RDONLY);
    if(fd > 0) {
        printf("failed to open file %s %d",setting.image,fd);
        return NULL;
    }
    fifo_init();
    for(;;) {
        usb_acquire_buff(&buff,60);
        if(usb_fetch_one_frame(&buff,fd) < 0) {
            continue;
        } else {
            fifo_push(buff);
        }
    }
    close(fd);
}
