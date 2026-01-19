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
 void keyboard_input_cb(lv_event_t * e)
 {

 }


 void keyboard_init(lv_ui *ui)
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


 void keyboard_show(lv_event_t * e)
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


void set_connected_state(lv_ui *ui, bool state)
{
    lv_obj_set_flag(ui->scr0_btn_enable_key,LV_OBJ_FLAG_HIDDEN,true);
    lv_obj_set_flag(ui->scr0_img_display,LV_OBJ_FLAG_HIDDEN,false);
    lv_obj_set_flag(ui->scr0_cvs_displayer,LV_OBJ_FLAG_HIDDEN,true);
    lv_obj_set_flag(ui->scr0_lb_status0,LV_OBJ_FLAG_HIDDEN,true);
    lv_obj_set_flag(ui->scr0_lb_connecting,LV_OBJ_FLAG_HIDDEN,true);
}


void custom_image_show(lv_obj_t * obj,const unsigned char *data,long size,int w,int h)
{
    lv_image_dsc_t img;

    img.header.magic =LV_IMAGE_HEADER_MAGIC;
    img.header.cf   =LV_COLOR_FORMAT_RGB888;
    img.header.flags =LV_IMAGE_FLAGS_CUSTOM_DRAW;

    img.header.w =w;
    img.header.h =h;
    img.header.stride = w * 3;

    img.data =data;
    img.data_size =size;
    lv_image_set_src(obj, &img);
}

void *custom_thread(void *args)
{
    lv_ui *ui =(lv_ui *)args;
    
    int w,h;
    long length;
    unsigned char *buff;
    int path_len =strlen(setting.image);
    image_init();
    for (;;) {
        if(path_len > 3) {
            if(image_decode(setting.image,&buff,&length,&w,&h) >=0){
                usleep(1000 * 1000);
                custom_image_show(ui->scr0_img_display,buff,length,w,h);
            }
        }
        usleep(1000);
    }
    image_deinit();
}


void custom_init(lv_ui *ui)
{
    /* Add your codes here */
    lv_obj_add_event_cb(ui->scr0_btn_enable_key, keyboard_show, LV_EVENT_CLICKED,ui); 
    set_connected_state(ui,true);
}



