#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include "core/lv_obj_pos.h"
#include "display/lv_display.h"
#include "lvgl.h"
#include "custom.h"
#include "misc/lv_event.h"
#include "misc/lv_types.h"
#include <pthread.h>

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> 
#include <jpeglib.h>
#include <jerror.h>
#include <setjmp.h>


const char *images_get_next(const char *jpg,int *pic_size)
{
    static int conter=0;
    static char path[128];
    struct stat fstat;

    sprintf(path,"%s.%d",jpg,conter);
    if(stat(path,&fstat) == 0) {
        conter++;
        *pic_size =fstat.st_size;
        return (const char *)path;
    }
    else if(stat(path,&fstat) == 0)  {
        strcpy(path,jpg);
        *pic_size =fstat.st_size;
        return (const char *)path;
    }
    return NULL;
}

int images_loading(const char *jpg,char *raw_buff,int size)
{
    int fd;
    int len=0;
    if(jpg != NULL) {
        fd=open(jpg,O_RDONLY);
        if(fd > 0) {
            if(lseek(fd,0,SEEK_SET) < 0) {
                close(fd);
                return -1;
            }
        
            len =read(fd,raw_buff,size);
            close(fd);
            return len;
        }
    }
    return -1;
}


int image_decode(const char *path,char *buff,int buff_size)
{
    const char *pic_path;
    static int  raw_size=0;
    static char *raw_buff=NULL;

    int  pic_size=0;
    pic_path =images_get_next(path, &pic_size);
    if(pic_path !=NULL) {

        if(pic_size > raw_size) {
            if(raw_buff == NULL) {
                raw_buff =malloc(pic_size);
                raw_size =pic_size;
            }
            else {
                free(raw_buff);
                raw_buff =malloc(pic_size);
                raw_size =pic_size;
            }
        }

        if(images_loading(pic_path,raw_buff,pic_size) > 0) {
            int width,height,channels;
            
        }
    }
    return 0;
}
