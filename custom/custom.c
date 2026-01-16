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
#include "misc/lv_types.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */
 void keyboard_show(lv_event_t * e)
 {
    // lv_ui *ui;
    // static bool is_enable=false;
    // is_enable =!is_enable;
    // ui =lv_event_get_param(e);
    // if(is_enable) {
    //     lv_obj_clear_flag(ui->g_kb_top_layer, LV_OBJ_FLAG_HIDDEN);
    //     lv_obj_move_foreground(ui->g_kb_top_layer);
    // }else {
    //     lv_obj_add_flag(ui->g_kb_top_layer, LV_OBJ_FLAG_HIDDEN);
    // }
 }

 void keyboard_event_cb(lv_event_t * e)
 {

 }


void keyboard_init(lv_ui *ui)
{
    lv_obj_t *kb;
    lv_obj_t *scr;

    scr =lv_scr_act();
    kb = lv_keyboard_create(scr);
    lv_obj_add_event_cb(kb, keyboard_event_cb, LV_EVENT_ALL, NULL);

    int32_t w =lv_obj_get_width(scr) * 8 / 10;
    int32_t h =lv_obj_get_height(scr) * 6 / 10;
    lv_obj_set_size(kb, w, h);

    lv_obj_align(kb, LV_ALIGN_CENTER, 0, h * 3 / 10);

    lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
    lv_obj_move_foreground(kb);

    ui->g_kb_top_layer =kb;
}


void set_connected_state(lv_ui *ui, bool state)
{
    lv_obj_set_flag(ui->screen_canvas_screen,LV_OBJ_FLAG_HIDDEN,state == true);
    lv_obj_set_flag(ui->screen_img_display,LV_OBJ_FLAG_HIDDEN,state == false);
    lv_obj_set_flag(ui->screen_label_1,LV_OBJ_FLAG_HIDDEN,state == false);
    lv_obj_set_flag(ui->screen_label_waiting,LV_OBJ_FLAG_HIDDEN,state == false);
}

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
    lv_obj_add_event_cb(ui->screen_btn_key_on, keyboard_show, LV_EVENT_CLICKED,ui); 

    
    set_connected_state(ui,true);
}

