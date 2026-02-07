#ifndef USB_FETCH_H
#define USB_FETCH_H
#ifdef __cplusplus
extern "C" {
#endif

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

void usb_fetch_thread(char *buff,int size);
#ifdef __cplusplus
}
#endif

#endif 
