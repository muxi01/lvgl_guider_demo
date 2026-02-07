#ifndef __DECODE_H__
#define __DECODE_H__


#ifdef __cplusplus
extern "C" {
#endif

int decode_init(void);
void decode_uninit(void);
int decode_jpeg_decompress(char *jpg_buff, int jpg_size,char *rgb_buff,int rgb_size,int *w,int *h);


#ifdef __cplusplus
}
#endif


#endif 
