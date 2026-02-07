#ifndef SIMPLE_FIFO_H
#define SIMPLE_FIFO_H

#include <stdint.h>
#include <string.h>
#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif
// -------------------------- 配置区 --------------------------
#define FIFO_BUF_COUNT    5   // FIFO中Buffer的总数量
// -----------------------------------------------------------

/**
 * @brief FIFO操作句柄
 * @note 从FIFO获取Buffer后，通过此结构体描述Buffer的所有信息
 */
typedef struct {
    int         buf_id;    // Buffer在数组中的ID（内部索引）
    uint8_t*    data;      // 指向Buffer数据区的指针（核心）
    int         w,h;
    size_t      data_len;  // Buffer中有效数据的长度
    size_t      buf_size;  // Buffer的总容量（最大可写入大小）
} FIFOHandle;

typedef FIFOHandle* FIFOHandle_p;

/**
 * @brief 静态FIFO核心结构体（全局实例）
 */
typedef struct {
    FIFOHandle  pool[FIFO_BUF_COUNT];
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
int fifo_init(int w, int h);

/**
 * @brief 生产者获取一个空的Buffer
 * @return FIFOHandle 包含buf_id和data指针的句柄，获取失败时data为NULL
 */
FIFOHandle_p fifo_acquire(void);

/**
 * @brief 生产者将填充好数据的Buffer放入FIFO
 * @param handle 已填充数据的句柄（必须已调用fifo_acquire）
 */
void fifo_push(FIFOHandle_p handle);

/**
 * @brief 消费者从FIFO取出一个Buffer
 * @return FIFOHandle 包含数据的句柄，队列为空时会阻塞
 */
FIFOHandle_p fifo_pop(void);

/**
 * @brief 消费者释放Buffer（归还到池）
 * @param handle 要释放的句柄
 */
void fifo_release(FIFOHandle_p handle);


#ifdef __cplusplus
}
#endif



#endif // SIMPLE_FIFO_H