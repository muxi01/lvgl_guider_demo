#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> 
#include <string.h>
#include "loopbuffer.h"
#include "main.h" 
#include "decode.h"


extern st_parmaters setting;

static void read_jpeg_limited(long fps){
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

const char *jpeg_get_next(const char *jpg)
{
    static int conter=0;
    static char path[128];
    struct stat fstat;

    sprintf(path,"%s%d",jpg,conter);
    if(stat(path,&fstat) == 0) {
        conter++;
        return (const char *)path;
    }
    else if(conter > 0) {
        conter=0;
        sprintf(path,"%s%d",jpg,conter);
        if(stat(path,&fstat) == 0) {
            conter++;
            return (const char *)path;
        }
    }
    else if(stat(jpg,&fstat) == 0)  {
        strcpy(path,jpg);
        return (const char *)path;
    }
    return NULL;
}

int jpeg_loading(const char *path,char *pbuff,int size)
{
    int fd;
    int fsize=0,len=0;
    if((path != NULL) && (pbuff !=NULL)) {
        fd=open(path,O_RDONLY);
        if(fd > 0) {
            fsize =lseek(fd,0,SEEK_END);
            if(fsize < 0) {
                close(fd);
                return -1;
            }

            if(fsize > size) {
                close(fd);
                return -2;
            }

            if(lseek(fd,0,SEEK_SET) < 0){
                close(fd);
                return -3;
            }
            len =read(fd,pbuff,fsize);
            close(fd);
            return len;
        }
    }
    return -4;
}

void read_jpeg_thread(char *buff,int size)
{
    int frame_size;
    FIFOHandle fifo;
    const char *path;
     for(;;) {
        fifo=fifo_acquire();
        if(fifo.data != NULL) {
            path =jpeg_get_next(setting.image);
            frame_size =jpeg_loading(path,buff,size);
            if(frame_size > 0) {
                fifo.data_len =decode_jpeg_decompress(buff,frame_size,fifo.data,fifo.buf_size,&fifo.w,&fifo.h);
                printf("image path: %s size:%d w:%d h:%d\n", path,fifo.data_len,fifo.w,fifo.h);
#if 1
                for(int x=0;x<fifo.h;x++) {
                    for(int y=0;y<fifo.w;y++) {
                        int off =x * fifo.w * 4;
                        fifo.data[off + 0] = 0xaa;
                        fifo.data[off + 1] = 0xaa;
                        fifo.data[off + 2] = 0xaa;
                        fifo.data[off + 3] = 0xaa;
                    }
                }
#endif
                if(fifo.data_len > 0) {
                    fifo_push(fifo);
                }
                else {
                    fifo_release(fifo);
                }
            }
        }
        read_jpeg_limited(60);
    }
}

