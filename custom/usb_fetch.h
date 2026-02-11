#ifndef USB_FETCH_H
#define USB_FETCH_H
#ifdef __cplusplus
extern "C" {
#endif

// Default encoder type
#define IMAGE_TYPE_RGB565  (('R' << 0) | ('G' << 8) | ('B' << 16) | ('6' << 24))
#define IMAGE_TYPE_RGB888  (('R' << 0) | ('G' << 8) | ('B' << 16) | ('8' << 24))
#define IMAGE_TYPE_YUV420  (('Y' << 0) | ('4' << 8) | ('2' << 16) | ('0' << 24))
#define IMAGE_TYPE_JPG     (('J' << 0) | ('P' << 8) | ('E' << 16) | ('G' << 24))
#define IMAGE_TYPE_NULL    (('N' << 0) | ('U' << 8) | ('L' << 16) | ('L' << 24))
#define FRAME_MAGIC_ID     (('l' << 0) | ('v' << 8) | ('s' << 16) | ('n' << 24))


typedef struct _image_frame_header_t {
    uint32_t magic_id;
    uint32_t img_type;
    uint32_t img_len;
    uint32_t img_cnt;
    uint16_t img_x,img_y;
    uint16_t img_w,img_h;
    uint32_t reserved[2];
} image_frame_header_t;


void usb_fetch_thread(char *buff,int size);
#ifdef __cplusplus
}
#endif

#endif 
