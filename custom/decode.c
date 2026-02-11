#include <dirent.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> 
#include <string.h>

#include <jpeglib.h>
#include <jerror.h>
#include <jmorecfg.h>
#include <setjmp.h>

struct my_error_mgr {
  struct jpeg_error_mgr pub;
  jmp_buf setjmp_buffer;
};

typedef struct my_error_mgr *my_error_ptr;

static struct jpeg_decompress_struct object;
static struct my_error_mgr jerr;

void my_error_exit(j_common_ptr cinfo)
{
    my_error_ptr myerr = (my_error_ptr)cinfo->err;
    (*cinfo->err->output_message) (cinfo);
    longjmp(myerr->setjmp_buffer, 1);
    printf("JPEG failed\n");
}

int decode_init(void)
{
    object.err = jpeg_std_error(&jerr.pub);
    jerr.pub.error_exit = my_error_exit;
    if (setjmp(jerr.setjmp_buffer)) {
        jpeg_destroy_decompress(&object);
        return -1;
    }
    jpeg_create_decompress(&object);
    return 0;
}


void decode_uninit(void)
{
    jpeg_destroy_decompress(&object);
}

void decode_copy(void *des,const void *src, long size,long des_size,long *off)
{
    if(des_size < (off + size)) {
        memcpy(&des[*off],src,size);
        *off +=size;
    }
}


int decode_jpeg_decompress(char *jpg_buff, int jpg_size,char *rgb_buff,int rgb_size,int *w,int *h)
{
/* Step 1: allocate and initialize JPEG decompression object */
    struct jpeg_decompress_struct *cinfo;

    cinfo =&object;

    jpeg_abort_decompress(cinfo);
    // jpeg_create_decompress(cinfo);

/* Step 2: specify data source (eg, a file) */
    jpeg_mem_src(cinfo,jpg_buff,jpg_size);

/* Step 3: read file parameters with jpeg_read_header() */
    jpeg_read_header(cinfo, TRUE);
    char *out_buff =rgb_buff;
    long buff_size =rgb_size;
    long out_off=0;

/* Step 4: set parameters for decompression */
    cinfo->out_color_space = JCS_EXT_BGRX;
    cinfo->dct_method = JDCT_FASTEST;
    
/* Step 5: Start decompressor */
    jpeg_start_decompress(cinfo);


    JSAMPARRAY buffer = NULL;
    J12SAMPARRAY buffer12 = NULL;
    int col;
    int row_stride; 
    int little_endian = 1;

    *w =cinfo->output_width;
    *h =cinfo->output_height;

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
            decode_copy(out_buff,buffer12[0],row_stride * sizeof(J12SAMPLE),buff_size,&out_off);
        }
    } 
    else {
        while (cinfo->output_scanline < cinfo->output_height) {
            jpeg_read_scanlines(cinfo, buffer, 1);
            decode_copy(out_buff,buffer[0],row_stride,buff_size,&out_off);
        }
  }

/* Step 7: Finish decompression */
    jpeg_finish_decompress(cinfo);

/* Step 8: Release JPEG decompression object */
    // jpeg_destroy_decompress(cinfo);

    return out_off;
}

