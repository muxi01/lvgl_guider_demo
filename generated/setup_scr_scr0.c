/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_scr0(lv_ui *ui)
{
    //Write codes scr0
    ui->scr0 = lv_obj_create(NULL);
    lv_obj_set_size(ui->scr0, 800, 480);
    lv_obj_set_scrollbar_mode(ui->scr0, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr0_img_display
    ui->scr0_img_display = lv_image_create(ui->scr0);
    lv_obj_set_pos(ui->scr0_img_display, 0, 0);
    lv_obj_set_size(ui->scr0_img_display, 800, 480);
    lv_obj_add_flag(ui->scr0_img_display, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->scr0_img_display, &_horse_RGB565A8_800x480);
    lv_image_set_pivot(ui->scr0_img_display, 50,50);
    lv_image_set_rotation(ui->scr0_img_display, 0);

    //Write style for scr0_img_display, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->scr0_img_display, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->scr0_img_display, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr0_lb_connecting
    ui->scr0_lb_connecting = lv_label_create(ui->scr0);
    lv_obj_set_pos(ui->scr0_lb_connecting, 534, 395);
    lv_obj_set_size(ui->scr0_lb_connecting, 63, 32);
    lv_label_set_text(ui->scr0_lb_connecting, ". . . . . . ");
    lv_label_set_long_mode(ui->scr0_lb_connecting, LV_LABEL_LONG_WRAP);

    //Write style for scr0_lb_connecting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr0_lb_connecting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr0_lb_connecting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr0_lb_connecting, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr0_lb_connecting, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr0_lb_connecting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr0_lb_connecting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr0_lb_connecting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr0_lb_connecting, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr0_lb_connecting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr0_lb_connecting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr0_lb_connecting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr0_lb_connecting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr0_lb_connecting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr0_lb_connecting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr0_lb_status0
    ui->scr0_lb_status0 = lv_label_create(ui->scr0);
    lv_obj_set_pos(ui->scr0_lb_status0, 192, 390);
    lv_obj_set_size(ui->scr0_lb_status0, 329, 40);
    lv_label_set_text(ui->scr0_lb_status0, "waiting for connecting");
    lv_label_set_long_mode(ui->scr0_lb_status0, LV_LABEL_LONG_WRAP);

    //Write style for scr0_lb_status0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr0_lb_status0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr0_lb_status0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr0_lb_status0, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr0_lb_status0, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr0_lb_status0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr0_lb_status0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr0_lb_status0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr0_lb_status0, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr0_lb_status0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr0_lb_status0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr0_lb_status0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr0_lb_status0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr0_lb_status0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr0_lb_status0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr0_cvs_displayer
    LV_DRAW_BUF_DEFINE_STATIC(scr0_cvs_displayer_draw_buf, 800, 480, LV_COLOR_FORMAT_ARGB8888);
    LV_DRAW_BUF_INIT_STATIC(scr0_cvs_displayer_draw_buf);
    ui->scr0_cvs_displayer = lv_canvas_create(ui->scr0);
    lv_obj_set_pos(ui->scr0_cvs_displayer, 0, 0);
    lv_obj_set_size(ui->scr0_cvs_displayer, 800, 480);
    lv_obj_set_scrollbar_mode(ui->scr0_cvs_displayer, LV_SCROLLBAR_MODE_OFF);
    lv_canvas_set_draw_buf(ui->scr0_cvs_displayer, &scr0_cvs_displayer_draw_buf);
    lv_canvas_fill_bg(ui->scr0_cvs_displayer, lv_color_hex(0xffffff), 255);

    lv_layer_t layer_scr0_cvs_displayer;
    lv_canvas_init_layer(ui->scr0_cvs_displayer, &layer_scr0_cvs_displayer);
    //Canvas draw rectangle
    lv_draw_rect_dsc_t scr0_cvs_displayer_rect_dsc_0;
    lv_draw_rect_dsc_init(&scr0_cvs_displayer_rect_dsc_0);
    scr0_cvs_displayer_rect_dsc_0.radius = 0;
    scr0_cvs_displayer_rect_dsc_0.bg_opa = 255;
    scr0_cvs_displayer_rect_dsc_0.bg_color = lv_color_hex(0x667f8d);
    scr0_cvs_displayer_rect_dsc_0.bg_grad.dir = LV_GRAD_DIR_NONE;
    scr0_cvs_displayer_rect_dsc_0.border_width = 0;
    scr0_cvs_displayer_rect_dsc_0.border_opa = 255;
    scr0_cvs_displayer_rect_dsc_0.border_color = lv_color_hex(0x000000);
    lv_area_t scr0_cvs_displayer_coords_rect_0 = {0, 0, 800, 480};
    lv_draw_rect(&layer_scr0_cvs_displayer, &scr0_cvs_displayer_rect_dsc_0, &scr0_cvs_displayer_coords_rect_0);

    lv_canvas_finish_layer(ui->scr0_cvs_displayer, &layer_scr0_cvs_displayer);

    //Write codes scr0_btn_enable_key
    ui->scr0_btn_enable_key = lv_button_create(ui->scr0);
    lv_obj_set_pos(ui->scr0_btn_enable_key, 62, 41);
    lv_obj_set_size(ui->scr0_btn_enable_key, 45, 45);
    ui->scr0_btn_enable_key_label = lv_label_create(ui->scr0_btn_enable_key);
    lv_label_set_text(ui->scr0_btn_enable_key_label, "key");
    lv_label_set_long_mode(ui->scr0_btn_enable_key_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr0_btn_enable_key_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr0_btn_enable_key, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr0_btn_enable_key_label, LV_PCT(100));

    //Write style for scr0_btn_enable_key, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr0_btn_enable_key, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr0_btn_enable_key, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr0_btn_enable_key, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr0_btn_enable_key, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr0_btn_enable_key, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr0_btn_enable_key, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->scr0_btn_enable_key, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->scr0_btn_enable_key, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->scr0_btn_enable_key, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->scr0_btn_enable_key, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->scr0_btn_enable_key, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr0_btn_enable_key, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr0_btn_enable_key, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr0_btn_enable_key, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr0_btn_enable_key, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr0_contaier_auth
    ui->scr0_contaier_auth = lv_obj_create(ui->scr0);
    lv_obj_set_pos(ui->scr0_contaier_auth, 199, 115);
    lv_obj_set_size(ui->scr0_contaier_auth, 394, 233);
    lv_obj_set_scrollbar_mode(ui->scr0_contaier_auth, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->scr0_contaier_auth, LV_OBJ_FLAG_HIDDEN);

    //Write style for scr0_contaier_auth, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr0_contaier_auth, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr0_contaier_auth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr0_contaier_auth, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr0_contaier_auth, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr0_contaier_auth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr0_contaier_auth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr0_contaier_auth, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr0_contaier_auth, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr0_contaier_auth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr0_contaier_auth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr0_contaier_auth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr0_contaier_auth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr0_contaier_auth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr0_auth_lb_device_id
    ui->scr0_auth_lb_device_id = lv_label_create(ui->scr0_contaier_auth);
    lv_obj_set_pos(ui->scr0_auth_lb_device_id, 79, 64);
    lv_obj_set_size(ui->scr0_auth_lb_device_id, 190, 17);
    lv_label_set_text(ui->scr0_auth_lb_device_id, "device  id : 123456789");
    lv_label_set_long_mode(ui->scr0_auth_lb_device_id, LV_LABEL_LONG_WRAP);

    //Write style for scr0_auth_lb_device_id, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr0_auth_lb_device_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr0_auth_lb_device_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr0_auth_lb_device_id, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr0_auth_lb_device_id, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr0_auth_lb_device_id, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr0_auth_lb_device_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr0_auth_lb_device_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr0_auth_lb_device_id, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr0_auth_lb_device_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr0_auth_lb_device_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr0_auth_lb_device_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr0_auth_lb_device_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr0_auth_lb_device_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr0_auth_lb_device_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr0_auth_txt_code
    ui->scr0_auth_txt_code = lv_textarea_create(ui->scr0_contaier_auth);
    lv_obj_set_pos(ui->scr0_auth_txt_code, 179, 90);
    lv_obj_set_size(ui->scr0_auth_txt_code, 120, 24);
    lv_textarea_set_text(ui->scr0_auth_txt_code, "Hello World");
    lv_textarea_set_placeholder_text(ui->scr0_auth_txt_code, "");
    lv_textarea_set_password_bullet(ui->scr0_auth_txt_code, "*");
    lv_textarea_set_password_mode(ui->scr0_auth_txt_code, false);
    lv_textarea_set_one_line(ui->scr0_auth_txt_code, false);
    lv_textarea_set_accepted_chars(ui->scr0_auth_txt_code, "");
    lv_textarea_set_max_length(ui->scr0_auth_txt_code, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->scr0_auth_txt_code, ta_event_cb, LV_EVENT_ALL, ui->scr0_g_kb_top_layer);
#endif

    //Write style for scr0_auth_txt_code, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->scr0_auth_txt_code, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr0_auth_txt_code, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr0_auth_txt_code, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr0_auth_txt_code, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr0_auth_txt_code, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr0_auth_txt_code, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr0_auth_txt_code, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr0_auth_txt_code, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr0_auth_txt_code, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr0_auth_txt_code, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr0_auth_txt_code, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr0_auth_txt_code, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr0_auth_txt_code, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr0_auth_txt_code, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr0_auth_txt_code, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr0_auth_txt_code, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr0_auth_txt_code, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scr0_auth_txt_code, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr0_auth_txt_code, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr0_auth_txt_code, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr0_auth_txt_code, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr0_auth_txt_code, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes scr0_auth_btn_done
    ui->scr0_auth_btn_done = lv_button_create(ui->scr0_contaier_auth);
    lv_obj_set_pos(ui->scr0_auth_btn_done, 131, 144);
    lv_obj_set_size(ui->scr0_auth_btn_done, 133, 31);
    ui->scr0_auth_btn_done_label = lv_label_create(ui->scr0_auth_btn_done);
    lv_label_set_text(ui->scr0_auth_btn_done_label, "done");
    lv_label_set_long_mode(ui->scr0_auth_btn_done_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scr0_auth_btn_done_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scr0_auth_btn_done, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scr0_auth_btn_done_label, LV_PCT(100));

    //Write style for scr0_auth_btn_done, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scr0_auth_btn_done, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scr0_auth_btn_done, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scr0_auth_btn_done, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scr0_auth_btn_done, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr0_auth_btn_done, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr0_auth_btn_done, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr0_auth_btn_done, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr0_auth_btn_done, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr0_auth_btn_done, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr0_auth_btn_done, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr0_auth_lb_name
    ui->scr0_auth_lb_name = lv_label_create(ui->scr0_contaier_auth);
    lv_obj_set_pos(ui->scr0_auth_lb_name, 79, 96);
    lv_obj_set_size(ui->scr0_auth_lb_name, 95, 19);
    lv_label_set_text(ui->scr0_auth_lb_name, "auth code :");
    lv_label_set_long_mode(ui->scr0_auth_lb_name, LV_LABEL_LONG_WRAP);

    //Write style for scr0_auth_lb_name, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr0_auth_lb_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr0_auth_lb_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scr0_auth_lb_name, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scr0_auth_lb_name, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scr0_auth_lb_name, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scr0_auth_lb_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scr0_auth_lb_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scr0_auth_lb_name, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr0_auth_lb_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr0_auth_lb_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr0_auth_lb_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr0_auth_lb_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr0_auth_lb_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr0_auth_lb_name, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scr0_g_kb_top_layer
    ui->scr0_g_kb_top_layer = lv_obj_create(ui->scr0);
    lv_obj_set_pos(ui->scr0_g_kb_top_layer, 0, 0);
    lv_obj_set_size(ui->scr0_g_kb_top_layer, 800, 480);
    lv_obj_set_scrollbar_mode(ui->scr0_g_kb_top_layer, LV_SCROLLBAR_MODE_OFF);

    //Write style for scr0_g_kb_top_layer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scr0_g_kb_top_layer, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scr0_g_kb_top_layer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scr0_g_kb_top_layer, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scr0_g_kb_top_layer, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scr0_g_kb_top_layer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scr0_g_kb_top_layer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scr0_g_kb_top_layer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scr0_g_kb_top_layer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scr0_g_kb_top_layer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scr0_g_kb_top_layer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scr0_g_kb_top_layer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of scr0.


    //Update current screen layout.
    lv_obj_update_layout(ui->scr0);

}
