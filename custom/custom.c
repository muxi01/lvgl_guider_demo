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
#include "images.h"
#include <string.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdint.h>
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
    lv_obj_t *scr;
    if(keyboard_ui == NULL) {
        scr =lv_scr_act();
        int32_t w =lv_obj_get_width(scr) * 8 / 10;
        int32_t h =lv_obj_get_height(scr) * 6 / 10;

        keyboard_ui = lv_keyboard_create(ui->scr0_g_kb_top_layer);
        lv_obj_set_size(keyboard_ui, w, h);
        lv_obj_align(keyboard_ui, LV_ALIGN_CENTER, 0, h * 3 / 10);
        lv_obj_add_event_cb(keyboard_ui, keyboard_input_cb, LV_EVENT_KEY, NULL);
    }
}


static void keyboard_show(lv_event_t * e)
 {
    lv_ui *ui =lv_event_get_param(e);
    static bool is_enable=true;
    if(1) {

        is_enable =!is_enable;
        keyboard_init(ui);
        lv_obj_set_flag(keyboard_ui,LV_OBJ_FLAG_HIDDEN,is_enable);
        lv_obj_set_flag(ui->scr0_g_kb_top_layer, LV_OBJ_FLAG_HIDDEN,is_enable);
        printf("%s %d",__FUNCTION__,__LINE__);
    }
 }


static void set_connected_state(lv_ui *ui, bool state)
{
    lv_obj_set_flag(ui->scr0_btn_enable_key,LV_OBJ_FLAG_HIDDEN,true);
    lv_obj_set_flag(ui->scr0_img_display,LV_OBJ_FLAG_HIDDEN,true);
    lv_obj_set_flag(ui->scr0_cvs_displayer,LV_OBJ_FLAG_HIDDEN,false);
    lv_obj_set_flag(ui->scr0_lb_status0,LV_OBJ_FLAG_HIDDEN,true);
    lv_obj_set_flag(ui->scr0_lb_connecting,LV_OBJ_FLAG_HIDDEN,true);
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

    for (;;) {
        if(path_len > 3) {
            update.bit_map =image_decode(setting.image);
            if(update.bit_map != NULL){
                update.cvs_obj =ui->scr0_cvs_displayer;
                update.sem =&sem;
                sem_wait(&sem);
                if(LV_RESULT_OK != lv_async_call(custom_display, &update)){
                    printf("fialed to call lv_async_call\n");
                    sem_post(update.sem);
                    usleep(1000*1000);
                }
            }
            custom_limited(10);
        }
        else {
            usleep(1000*1000);
        }
    }
    image_deinit();
}


void custom_init(lv_ui *ui)
{
    /* Add your codes here */
    lv_obj_add_event_cb(ui->scr0_btn_enable_key, keyboard_show, LV_EVENT_CLICKED,ui); 
    set_connected_state(ui,true);
}



