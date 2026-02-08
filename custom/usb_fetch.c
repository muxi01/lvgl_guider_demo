#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>
#include <sys/time.h>
#include <stdint.h>
#include <fcntl.h>
#include "usb_fetch.h"
#include "loopbuffer.h"
#include "main.h"
#include "decode.h"


extern st_parmaters setting;


static void usb_fetch_limited(long fps){
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

static int usb_fetch_frame(int fd,char *pbuff,int size) {
    uint64_t header;
    uint8_t discard[64];
    image_frame_info info;
    uint64_t select=get_image_header();

    int nbytes = read(fd, &header, sizeof(uint64_t));
    if((nbytes == sizeof(uint64_t)) && (header == select)) {
        nbytes =read(fd, &info, sizeof(image_frame_info));
        if(nbytes == sizeof(image_frame_info)) {
            int readn=0;
            int wanas =info.img_len;
            int total =info.img_len;
            if((pbuff != NULL) && (size >= info.img_len) && (info.img_len !=0)) {
                nbytes =0;
                do {
                    nbytes =read(fd, pbuff + readn, wanas);
                    readn +=nbytes;
                    wanas -=nbytes;
                }while(readn < info.img_len);
                return info.img_len;
            }
            else if(info.img_len > 0){
                do {
                    if(total > sizeof(discard)) {
                        wanas =sizeof(discard);
                    } else {
                        wanas =total;
                    }
                    nbytes =read(fd, &discard, wanas);
                    total -=nbytes;
                }while(total);
            }
        }
    }
    return -1;
}


void usb_fetch_thread(char *buff,int size) {

    int fd;
    int frame_size;
    const int fps=60;
    FIFOHandle_p fifo;
    fd=open(setting.image,O_RDONLY);
    if(fd <=0 ){
        printf("failed to open %s.%d\n",setting.image,fd);
        return ;
    }
    for(;;) {
        fifo =fifo_acquire();
        frame_size =usb_fetch_frame(fd,buff,size);
        if(frame_size > 0){
            fifo->data_len =decode_jpeg_decompress(buff,frame_size,fifo->data,fifo->buf_size,&fifo->w,&fifo->h);
            if(fifo->data_len > 0) {
                fifo_push(fifo);
            }
        }
        usb_fetch_limited(fps);
    }
    close(fd);
}
