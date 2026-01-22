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

#include "images.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> 
#include <string.h>

#include <jpeglib.h>
#include <jerror.h>
#include <jmorecfg.h>
#include <setjmp.h>

#define uint64 unsigned long long
#define BMP_SUM     3
#define BMP_DOT_SIZE 3

struct  {
    struct {
        unsigned char *mem;
        unsigned char *buff;
        long size;
    }file;

    struct {
        int index;
        struct jpeg_decompress_struct object;
        st_bit_map bitMap[BMP_SUM];
    }decoder;
}mng;


void *image_aline8(void *mem)
{
    uint64 addr=(uint64)mem;
    return (void *)(addr & 0xfffffffffffffff7 + 8);
}

void image_buff_remalloc(int resize)
{
    if(resize > mng.file.size) {
        if((mng.file.buff != NULL) && (mng.file.mem !=NULL)){
            free(mng.file.mem);
        }
        mng.file.mem =malloc(resize + 16);
        mng.file.buff =image_aline8(mng.file.mem);
        mng.file.size =resize;
    }
}


const char *images_get_next(const char *jpg)
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

int images_loading(const char *jpg)
{
    int fd;
    int fsize=0,len=0;
    if(jpg != NULL) {
        fd=open(jpg,O_RDONLY);
        if(fd > 0) {
            fsize =lseek(fd,0,SEEK_END);
            if(fsize < 0) {
                close(fd);
                return -1;
            }

            if(lseek(fd,0,SEEK_SET) < 0){
                close(fd);
                return -1;
            }

            image_buff_remalloc(fsize);
            len =read(fd,mng.file.buff,fsize);
            close(fd);
            return len;
        }
    }
    return -1;
}



struct my_error_mgr {
  struct jpeg_error_mgr pub;
  jmp_buf setjmp_buffer; 
};

typedef struct my_error_mgr *my_error_ptr;

void image_copy(void *des,const void *src, long size,long des_size,long *off)
{
    if(des_size < (off + size)) {
        memcpy(&des[*off],src,size);
        *off +=size;
    }
}

void my_error_exit(j_common_ptr cinfo)
{
    my_error_ptr myerr = (my_error_ptr)cinfo->err;
    (*cinfo->err->output_message) (cinfo);
    longjmp(myerr->setjmp_buffer, 1);
}

int image_jpeg_decompress(void)
{
/* Step 1: allocate and initialize JPEG decompression object */
    struct jpeg_decompress_struct *cinfo;

    cinfo =&(mng.decoder.object);

    jpeg_abort_decompress(cinfo);
    // jpeg_create_decompress(cinfo);

/* Step 2: specify data source (eg, a file) */
    jpeg_mem_src(cinfo,mng.file.buff,mng.file.size);

/* Step 3: read file parameters with jpeg_read_header() */
    jpeg_read_header(cinfo, TRUE);
    
    int index=mng.decoder.index % BMP_SUM;
    long buff_size =mng.decoder.bitMap[index].size;
    unsigned char *out_buff=mng.decoder.bitMap[index].buff;
    long out_off =0;

/* Step 4: set parameters for decompression */
    cinfo->out_color_space = JCS_RGB;
    cinfo->dct_method = JDCT_FASTEST;
    
/* Step 5: Start decompressor */
    jpeg_start_decompress(cinfo);


    JSAMPARRAY buffer = NULL;
    J12SAMPARRAY buffer12 = NULL;
    int col;
    int row_stride; 
    int little_endian = 1;

/* Samples per row in output buffer */
    row_stride = cinfo->output_width * cinfo->output_components;

    /* Make a one-row-high sample array that will go away when done with image */
    if (cinfo->data_precision == 12) {
        buffer12 = (J12SAMPARRAY)(*cinfo->mem->alloc_sarray)((j_common_ptr)cinfo, JPOOL_IMAGE, row_stride, 1);
    }
    else {
        buffer = (*cinfo->mem->alloc_sarray)((j_common_ptr)cinfo, JPOOL_IMAGE, row_stride, 1);
    }
        

  /* Step 6: while (scan lines remain to be read) */

  /* Here we use the library's state variable cinfo->output_scanline as the
   * loop counter, so that we don't have to keep track ourselves.
   */
    if (cinfo->data_precision == 12) {
        while (cinfo->output_scanline < cinfo->output_height) {
            (void)jpeg12_read_scanlines(cinfo, buffer12, 1);
            if (*(char *)&little_endian == 1) {
                for (col = 0; col < row_stride; col++) {
                    buffer12[0][col] = ((buffer12[0][col] & 0xFF) << 8) | ((buffer12[0][col] >> 8) & 0xFF);
                }
            }
            image_copy(out_buff,buffer12[0],row_stride * sizeof(J12SAMPLE),buff_size,&out_off);
        }
    } 
    else {
        while (cinfo->output_scanline < cinfo->output_height) {
            jpeg_read_scanlines(cinfo, buffer, 1);
            image_copy(out_buff,buffer[0],row_stride,buff_size,&out_off);
        }
  }

/* Step 7: Finish decompression */
    jpeg_finish_decompress(cinfo);

/* Step 8: Release JPEG decompression object */
    // jpeg_destroy_decompress(cinfo);

    return out_off;
}


void image_init(int w,int h)
{
    static struct my_error_mgr jerr;
    struct jpeg_decompress_struct *cinfo;

    cinfo =&(mng.decoder.object);
    memset(&mng,0,sizeof(mng));

    cinfo->err = jpeg_std_error(&jerr.pub);
    jerr.pub.error_exit = my_error_exit;
    if (setjmp(jerr.setjmp_buffer)) {
        ;
    }
    jpeg_create_decompress(&(mng.decoder.object));

    int i;
    int size =w * h * BMP_DOT_SIZE;
    for(i=0;i<BMP_SUM;i++) {
        mng.decoder.bitMap[i].height =h;
        mng.decoder.bitMap[i].width =w;
        mng.decoder.bitMap[i].mem  =malloc(size + 16);
        mng.decoder.bitMap[i].size =size;
        mng.decoder.bitMap[i].buff =image_aline8(mng.decoder.bitMap[i].mem); 
    }
}


void image_deinit(void)
{
    int i;
    for(i=0;i<BMP_SUM;i++) {
        if((mng.decoder.bitMap[i].size > 0) && (mng.decoder.bitMap[i].mem !=NULL)){
            free(mng.decoder.bitMap[i].mem);
            mng.decoder.bitMap[i].mem=NULL;
            mng.decoder.bitMap[i].buff=NULL;
            mng.decoder.bitMap[i].size=0;
        }
    }
    if((mng.file.size > 0) && (mng.file.mem !=NULL)){
        free(mng.file.mem);
    }
    jpeg_destroy_decompress(&mng.decoder.object);
    memset(&mng,0,sizeof(mng));
}

#if 0
lv_image_dsc_t  *image_describe(void)
{
    lv_image_dsc_t  *img;
    int index =mng.decoder.index % BMP_SUM;
    img = &(mng.decoder.bitMap[index].dsc);

    img->header.magic =LV_IMAGE_HEADER_MAGIC;
    img->header.cf   =LV_COLOR_FORMAT_RGB888;
    img->header.flags =0;
    img->header.w =mng.decoder.bitMap[index].width;
    img->header.h =mng.decoder.bitMap[index].height;
    img->header.stride = mng.decoder.bitMap[index].width * 3;

    img->data =mng.decoder.bitMap[index].buff;
    img->data_size =mng.decoder.bitMap[index].off;
    printf("image info:idx[%d] %dx%d.%d\n",index,img->header.w,img->header.h,img->data_size);

#if 1
    static int pingpong=0;
    pingpong=!pingpong;
    long long i,k;
    for(i=0;i< 480 * 800 * 3;i+=3){
        if(pingpong) {
            mng.decoder.bitMap[index].buff[i + 0] =0xa0;
            mng.decoder.bitMap[index].buff[i + 1] =0x00;
            mng.decoder.bitMap[index].buff[i + 2] =0x00;
        }
        else {
            mng.decoder.bitMap[index].buff[i + 0] =0x00;
            mng.decoder.bitMap[index].buff[i + 1] =0xa0;
            mng.decoder.bitMap[index].buff[i + 2] =0x00;
        }
    }
#endif 
    mng.decoder.index++;
    return img;
}
#else
st_bit_map  *get_bit_map(void)
{
    st_bit_map  *bmap;
    int index =mng.decoder.index % BMP_SUM;
    bmap = &(mng.decoder.bitMap[index]);
    mng.decoder.index++;

#if 0
    static int pingpong=0;
    pingpong=!pingpong;
    long long i,k;
    for(i=0;i< 480 * 800 * BMP_DOT_SIZE;i+=BMP_DOT_SIZE){
        if(pingpong) {
            mng.decoder.bitMap[index].buff[i + 0] =0xff;
            mng.decoder.bitMap[index].buff[i + 1] =0xff;
            mng.decoder.bitMap[index].buff[i + 2] =0;
            mng.decoder.bitMap[index].buff[i + 3] =0xff;
        }
        else {
            mng.decoder.bitMap[index].buff[i + 0] =0;
            mng.decoder.bitMap[index].buff[i + 1] =0xff;
            mng.decoder.bitMap[index].buff[i + 2] =0xff;
            mng.decoder.bitMap[index].buff[i + 3] =0xff;
        }
    }
#endif 
    return bmap;
}
#endif 

st_bit_map  *image_decode(const char *jpg_path)
{
    const char *img_path;
    static long  count=0;
    img_path =images_get_next(jpg_path);
    if(img_path !=NULL) {
        if(images_loading(img_path) > 0) {
            printf("loading image %s .%ld\n",img_path,count++);
            if(image_jpeg_decompress() >= 0) {
                return get_bit_map();
            }
        }
    }
    return NULL;
}
