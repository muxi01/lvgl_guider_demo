#ifndef SIMPLE_FIFO_H
#define SIMPLE_FIFO_H

#include <stdint.h>
#include <string.h>
#include <pthread.h>

#define IMAGE_TYPE_RGB565  (('R' << 24) | ('G' << 16) | ('B' << 8) | (16 << 0))
#define IMAGE_TYPE_RGB888  (('R' << 24) | ('G' << 16) | ('B' << 8) | (24 << 0))
#define IMAGE_TYPE_YUV420  (('Y' << 24) | ('4' << 16) | ('2' << 8) | ('0' << 0))
#define IMAGE_TYPE_JPG     (('J' << 24) | ('P' << 16) | ('E' << 8) | ('G' << 0))
#define IMAGE_TYPE_NULL    (('N' << 24) | ('U' << 16) | ('L' << 8) | ('L' << 0))
#define FRAME_MAGIC_ID     (('l' << 24) | ('v' << 16) | ('s' << 8) | ('n' << 0))


typedef struct _image_info {
    uint32_t img_len;
    uint32_t img_cnt;
}image_frame_info;
// -------------------------- 配置区 --------------------------
#define FIFO_BUF_COUNT    8   // FIFO中Buffer的总数量
#define FIFO_BUF_SIZE   1024  // 单个Buffer的字节大小
// -----------------------------------------------------------

/**
 * @brief FIFO操作句柄
 * @note 从FIFO获取Buffer后，通过此结构体描述Buffer的所有信息
 */
typedef struct {
    int         buf_id;    // Buffer在数组中的ID（内部索引）
    uint8_t*    data;      // 指向Buffer数据区的指针（核心）
    size_t      data_len;  // Buffer中有效数据的长度
    size_t      buf_size;  // Buffer的总容量（最大可写入大小）
} FIFOHandle;

/**
 * @brief 静态FIFO核心结构体（全局实例）
 */
typedef struct {
    uint8_t     pool[FIFO_BUF_COUNT][FIFO_BUF_SIZE]; // 静态Buffer池
    int         head;                                // 消费者索引
    int         tail;                                // 生产者索引
    int         count;                               // 当前有效Buffer数

    // 同步原语
    pthread_mutex_t mutex;
    pthread_cond_t  cond;
} StaticFIFO;


/**
 * @brief 初始化全局FIFO
 */
void fifo_init(void);

/**
 * @brief 生产者获取一个空的Buffer
 * @return FIFOHandle 包含buf_id和data指针的句柄，获取失败时data为NULL
 */
FIFOHandle fifo_acquire(void);

/**
 * @brief 生产者将填充好数据的Buffer放入FIFO
 * @param handle 已填充数据的句柄（必须已调用fifo_acquire）
 */
void fifo_push(FIFOHandle handle);

/**
 * @brief 消费者从FIFO取出一个Buffer
 * @return FIFOHandle 包含数据的句柄，队列为空时会阻塞
 */
FIFOHandle fifo_pop(void);

/**
 * @brief 消费者释放Buffer（归还到池）
 * @param handle 要释放的句柄
 */
void fifo_release(FIFOHandle handle);



void *usb_fetch_thread(void *args);
#endif // SIMPLE_FIFO_H