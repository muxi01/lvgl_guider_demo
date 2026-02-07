/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
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
#include <string.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdint.h>

#include "decode.h"
#include "read_jpegs.h"
#include "usb_fetch.h"
#include "loopbuffer.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static lv_obj_t *keyboard_ui=NULL;
static lv_obj_t *keyboard_layer=NULL;
static lv_timer_t *display_timer = NULL;
extern st_parmaters setting;
/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */
 static void keyboard_input_cb(lv_event_t * e)
 {

 }


static void keyboard_init(lv_ui *ui)
{
    int32_t x,y,w,h;
    if((keyboard_layer == NULL) && (keyboard_ui == NULL)) {
        lv_obj_t * parent = lv_layer_top();
        keyboard_layer = lv_obj_create(parent);

        x =lv_obj_get_x(ui->screen_ctn_key_dummy);
        y =lv_obj_get_y(ui->screen_ctn_key_dummy);
        w =lv_obj_get_width(ui->screen_ctn_key_dummy);
        h =lv_obj_get_height(ui->screen_ctn_key_dummy);


        lv_obj_set_size(keyboard_layer,w,h);
        lv_obj_set_pos(keyboard_layer,x,y);

        lv_obj_set_style_bg_opa(keyboard_layer, LV_OPA_TRANSP, 0);
        lv_obj_clear_flag(keyboard_layer, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_add_flag(keyboard_layer, LV_OBJ_FLAG_HIDDEN);


        keyboard_ui =lv_keyboard_create(keyboard_layer);
        lv_obj_set_size(keyboard_ui, w, h);
        
        lv_obj_align(keyboard_ui, LV_ALIGN_CENTER, 0,0);
        lv_obj_add_event_cb(keyboard_ui, keyboard_input_cb, LV_EVENT_ALL, ui);
    }
}


static void keyboard_show(lv_event_t * e)
 {
    static bool is_enable=false;
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED) {
        is_enable =!is_enable;
        lv_obj_set_flag(keyboard_layer,LV_OBJ_FLAG_HIDDEN,!is_enable);
    }
 }



static void custom_level_ui(lv_ui *ui, ui_level_type level)
{
    lv_obj_set_flag(ui->screen_ctn_key_dummy,LV_OBJ_FLAG_HIDDEN,true);
    switch(level) {
        case UI_LEVEL_OFFLINE: {
            lv_obj_set_flag(ui->screen_lbr_waiting,LV_OBJ_FLAG_HIDDEN,false);
            lv_obj_set_flag(ui->screen_img_default,LV_OBJ_FLAG_HIDDEN,false);

            lv_obj_set_flag(ui->screen_win_details,LV_OBJ_FLAG_HIDDEN,true);
            lv_obj_set_flag(ui->screen_ctn_authority,LV_OBJ_FLAG_HIDDEN,true);
            lv_obj_set_flag(ui->screen_btn_keyboard,LV_OBJ_FLAG_HIDDEN,true);
            lv_obj_set_flag(ui->screen_cvs_display,LV_OBJ_FLAG_HIDDEN,true);

            
        }
        break;

        case UI_LEVEL_UNREGISTER:{  
            lv_obj_set_flag(ui->screen_ctn_authority,LV_OBJ_FLAG_HIDDEN,false);
            lv_obj_set_flag(ui->screen_btn_keyboard,LV_OBJ_FLAG_HIDDEN,false);
            lv_obj_set_flag(ui->screen_cvs_display,LV_OBJ_FLAG_HIDDEN,false);

            
            lv_obj_set_flag(ui->screen_win_details,LV_OBJ_FLAG_HIDDEN,true);
            lv_obj_set_flag(ui->screen_lbr_waiting,LV_OBJ_FLAG_HIDDEN,true);
            lv_obj_set_flag(ui->screen_img_default,LV_OBJ_FLAG_HIDDEN,true);
        }
        break;

        default:{
            lv_obj_set_flag(ui->screen_btn_keyboard,LV_OBJ_FLAG_HIDDEN,false);
            lv_obj_set_flag(ui->screen_cvs_display,LV_OBJ_FLAG_HIDDEN,false);

            lv_obj_set_flag(ui->screen_ctn_authority,LV_OBJ_FLAG_HIDDEN,true);
            lv_obj_set_flag(ui->screen_win_details,LV_OBJ_FLAG_HIDDEN,true);
            lv_obj_set_flag(ui->screen_lbr_waiting,LV_OBJ_FLAG_HIDDEN,true);
            lv_obj_set_flag(ui->screen_img_default,LV_OBJ_FLAG_HIDDEN,true);
        }
        break;
    }
}




static void custom_limited(long fps){
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

#if 0

typedef struct update_info {
    st_bit_map  *bit_map;
    lv_obj_t *cvs_obj;
    sem_t *sem;
}st_update_info;


static void custom_display(void *args)
{
    st_update_info update;
    st_bit_map  *bmap;

    update =*(st_update_info *)args;
    bmap =update.bit_map;

    lv_canvas_set_buffer(update.cvs_obj,bmap->buff,bmap->width,bmap->height,LV_COLOR_FORMAT_RGB888);
    lv_obj_invalidate(update.cvs_obj);
    sem_post(update.sem);
}

void *custom_thread(void *args)
{
    lv_ui *ui =(lv_ui *)args;
    st_update_info  update;
    sem_t sem;
    int path_len =strlen(setting.image);
    sem_init(&sem,0,1);
    image_init(setting.width,setting.height);

    // path_len=0;
    for (;;) {
        if(path_len > 3) {
            update.bit_map =image_decode(setting.image);
            if(update.bit_map != NULL){
                update.cvs_obj =ui->screen_cvs_display;
                update.sem =&sem;
                sem_wait(&sem);
                if(LV_RESULT_OK != lv_async_call(custom_display, &update)){
                    printf("fialed to call lv_async_call\n");
                    sem_post(update.sem);
                    usleep(1000*1000);
                }
            }
            custom_limited(60);
        }
        else {
            usleep(1000*1000);
        }
    }
    image_deinit();
}

#else 

void *custom_thread(void *args)
{
    int path_len =strlen(setting.image);
    if(path_len > 3) {
        int  jpeg_size =setting.width*setting.height*4;
        char *jpeg_buff =malloc(jpeg_size);
        decode_init();

        fifo_init(setting.width,setting.height);
        if(strstr(setting.image,"/dev/tty") == NULL) {
            read_jpeg_thread(jpeg_buff, jpeg_size);
        } else {
            usb_fetch_thread(jpeg_buff,jpeg_size);
        }
        free(jpeg_buff);
        decode_uninit();  
    }
}

static void custom_draw_post_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    void *user_data = lv_event_get_user_data(e);
    if(code == LV_EVENT_DRAW_POST) {
        FIFOHandle *fifo =(FIFOHandle *)user_data;
        fifo_release(*fifo);
        lv_obj_remove_event(obj,LV_EVENT_DRAW_POST);
        fifo->data =NULL;
        fifo->buf_id =-1;
    }
}

static void custom_display(lv_timer_t *ptimer)
{
    static FIFOHandle fifo={0};
    fifo =fifo_pop();
    if(fifo.data != NULL) {
        printf("fifo info: id:%d len:%ld w:%d h:%d\n",fifo.buf_id,fifo.data_len,fifo.w,fifo.h);
        lv_obj_t *cvs_obj =(lv_obj_t *)lv_timer_get_user_data(ptimer);
        // lv_obj_add_event_cb(cvs_obj, custom_draw_post_cb, LV_EVENT_DRAW_POST, &fifo);
        lv_canvas_set_buffer(cvs_obj,fifo.data,fifo.w,fifo.h,LV_COLOR_FORMAT_RGB888);
        lv_obj_invalidate(cvs_obj); 
        // fifo_release(fifo);
    }
}

void custom_freash_timer(lv_obj_t *display_ui,int fps){
    if(display_timer == NULL){
        display_timer = lv_timer_create(custom_display, 1000/fps, display_ui);
        lv_timer_set_repeat_count(display_timer, -1);
    }
}
#endif 

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
    keyboard_init(ui);
    custom_level_ui(ui,UI_LEVEL_NORMAL);
    custom_freash_timer(ui->screen_cvs_display,60);
    lv_obj_add_event_cb(ui->screen_btn_keyboard, keyboard_show, LV_EVENT_CLICKED,ui); 
}


