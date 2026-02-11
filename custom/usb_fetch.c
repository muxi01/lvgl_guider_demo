#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>
#include <sys/time.h>
#include <stdint.h>
#include <fcntl.h>
#include <termios.h>
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


static int usb_search_header(int fd,int maxlen)
{
    static const magic_id =FRAME_MAGIC_ID;
    static const type_jpeg =IMAGE_TYPE_JPG;
    image_frame_header_t header;
    for(int len=0;len<maxlen;len+=sizeof(image_frame_header_t)) {
        int nbytes = read(fd, &header, sizeof(image_frame_header_t));
        if((nbytes == sizeof(image_frame_header_t)) && 
            (header.img_len > 0) && 
            (header.img_len <=maxlen) &&
            (header.magic_id == magic_id)  && 
            (header.img_type ==type_jpeg)) {
            return header.img_len;
        }
    }
    return 0;
}

static int usb_tty_bulk_mode(int fd)
{
    struct termios tty;
    tcgetattr(fd,&tty);
    cfmakeraw(&tty);
    tty.c_cflag &=~CSTOPB;
    tty.c_cflag &=~CRTSCTS;
    tty.c_cflag &=~ECHO;
    tcsetattr(fd,TCSANOW,&tty);
    return 0;
}

static int usb_fetch_frame(char *pbuff,int size) {
    uint8_t discard[64];
    int fd=open(setting.image,O_RDONLY);
    if(fd <=0 ){
        printf("failed to open %s.%d\n",setting.image,fd);
        return -1;
    }
    usb_tty_bulk_mode(fd);
    int img_len =usb_search_header(fd,size);
    if(img_len > 0) {
        int readn=0;
        int nbytes=0;
        int wanas =img_len;
        int total =img_len;
        if(pbuff != NULL) {
            do {
                nbytes =read(fd, pbuff + readn, wanas);
                readn +=nbytes;
                wanas -=nbytes;
            }while(readn < img_len);
        }
        else {
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
    close(fd);
    return img_len;
}


void usb_fetch_thread(char *buff,int size) {

    int fd;
    int frame_size;
    FIFOHandle_p fifo;
    for(;;) {
        fifo =fifo_acquire();
        frame_size =usb_fetch_frame(buff,size);
        if(frame_size > 0){
            printf("usb_fetch_frame size:%d\n",frame_size);
            fifo->data_len =decode_jpeg_decompress(buff,frame_size,fifo->data,fifo->buf_size,&fifo->w,&fifo->h);
            if(fifo->data_len > 0) {
                fifo_push(fifo);
            }
        }
        usb_fetch_limited(setting.fps);
    }
}
