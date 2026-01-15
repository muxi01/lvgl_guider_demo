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



void setup_scr_screen(lv_ui *ui)
{
    //Write codes screen
    ui->screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen, 800, 480);
    lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_canvas_screen
    LV_DRAW_BUF_DEFINE_STATIC(screen_canvas_screen_draw_buf, 800, 480, LV_COLOR_FORMAT_ARGB8888);
    LV_DRAW_BUF_INIT_STATIC(screen_canvas_screen_draw_buf);
    ui->screen_canvas_screen = lv_canvas_create(ui->screen);
    lv_obj_set_pos(ui->screen_canvas_screen, 0, 0);
    lv_obj_set_size(ui->screen_canvas_screen, 800, 480);
    lv_obj_set_scrollbar_mode(ui->screen_canvas_screen, LV_SCROLLBAR_MODE_OFF);
    lv_canvas_set_draw_buf(ui->screen_canvas_screen, &screen_canvas_screen_draw_buf);
    lv_canvas_fill_bg(ui->screen_canvas_screen, lv_color_hex(0xffffff), 255);

    lv_layer_t layer_screen_canvas_screen;
    lv_canvas_init_layer(ui->screen_canvas_screen, &layer_screen_canvas_screen);
    //Canvas draw rectangle
    lv_draw_rect_dsc_t screen_canvas_screen_rect_dsc_0;
    lv_draw_rect_dsc_init(&screen_canvas_screen_rect_dsc_0);
    screen_canvas_screen_rect_dsc_0.radius = 0;
    screen_canvas_screen_rect_dsc_0.bg_opa = 255;
    screen_canvas_screen_rect_dsc_0.bg_color = lv_color_hex(0x0775B7);
    screen_canvas_screen_rect_dsc_0.bg_grad.dir = LV_GRAD_DIR_NONE;
    screen_canvas_screen_rect_dsc_0.border_width = 0;
    screen_canvas_screen_rect_dsc_0.border_opa = 255;
    screen_canvas_screen_rect_dsc_0.border_color = lv_color_hex(0x000000);
    lv_area_t screen_canvas_screen_coords_rect_0 = {100, 80, 200, 130};
    lv_draw_rect(&layer_screen_canvas_screen, &screen_canvas_screen_rect_dsc_0, &screen_canvas_screen_coords_rect_0);

    lv_canvas_finish_layer(ui->screen_canvas_screen, &layer_screen_canvas_screen);

    //Write codes screen_img_display
    ui->screen_img_display = lv_image_create(ui->screen);
    lv_obj_set_pos(ui->screen_img_display, 0, 0);
    lv_obj_set_size(ui->screen_img_display, 800, 480);
    lv_obj_add_flag(ui->screen_img_display, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_img_display, &_horse_RGB565A8_800x480);
    lv_image_set_pivot(ui->screen_img_display, 50,50);
    lv_image_set_rotation(ui->screen_img_display, 0);

    //Write style for screen_img_display, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_img_display, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_img_display, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_btn_key_on
    ui->screen_btn_key_on = lv_button_create(ui->screen);
    lv_obj_set_pos(ui->screen_btn_key_on, 62, 41);
    lv_obj_set_size(ui->screen_btn_key_on, 45, 45);
    ui->screen_btn_key_on_label = lv_label_create(ui->screen_btn_key_on);
    lv_label_set_text(ui->screen_btn_key_on_label, "key");
    lv_label_set_long_mode(ui->screen_btn_key_on_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_key_on_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_key_on, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_key_on_label, LV_PCT(100));

    //Write style for screen_btn_key_on, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_key_on, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_key_on, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_key_on, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_key_on, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_key_on, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_key_on, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_btn_key_on, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_btn_key_on, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_btn_key_on, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_btn_key_on, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_btn_key_on, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_key_on, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_key_on, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_key_on, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_key_on, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_waiting
    ui->screen_label_waiting = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_label_waiting, 534, 395);
    lv_obj_set_size(ui->screen_label_waiting, 63, 32);
    lv_label_set_text(ui->screen_label_waiting, ". . . . . . ");
    lv_label_set_long_mode(ui->screen_label_waiting, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_waiting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_waiting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_waiting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_waiting, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_waiting, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_waiting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_waiting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_waiting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_waiting, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_waiting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_waiting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_waiting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_waiting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_waiting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_waiting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_1
    ui->screen_label_1 = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_label_1, 192, 390);
    lv_obj_set_size(ui->screen_label_1, 329, 40);
    lv_label_set_text(ui->screen_label_1, "waiting for connecting");
    lv_label_set_long_mode(ui->screen_label_1, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_1, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_1, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cont_auth
    ui->screen_cont_auth = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_cont_auth, 199, 115);
    lv_obj_set_size(ui->screen_cont_auth, 394, 233);
    lv_obj_set_scrollbar_mode(ui->screen_cont_auth, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->screen_cont_auth, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_cont_auth, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_auth, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_cont_auth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_cont_auth, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_cont_auth, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_auth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_auth, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_cont_auth, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_cont_auth, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_auth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_auth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_auth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_auth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_auth, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_device_id
    ui->screen_label_device_id = lv_label_create(ui->screen_cont_auth);
    lv_obj_set_pos(ui->screen_label_device_id, 79, 64);
    lv_obj_set_size(ui->screen_label_device_id, 190, 17);
    lv_label_set_text(ui->screen_label_device_id, "device  id : 123456789");
    lv_label_set_long_mode(ui->screen_label_device_id, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_device_id, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_device_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_device_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_device_id, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_device_id, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_device_id, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_device_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_device_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_device_id, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_device_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_device_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_device_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_device_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_device_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_device_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_txt_code
    ui->screen_txt_code = lv_textarea_create(ui->screen_cont_auth);
    lv_obj_set_pos(ui->screen_txt_code, 179, 90);
    lv_obj_set_size(ui->screen_txt_code, 120, 24);
    lv_textarea_set_text(ui->screen_txt_code, "Hello World");
    lv_textarea_set_placeholder_text(ui->screen_txt_code, "");
    lv_textarea_set_password_bullet(ui->screen_txt_code, "*");
    lv_textarea_set_password_mode(ui->screen_txt_code, false);
    lv_textarea_set_one_line(ui->screen_txt_code, false);
    lv_textarea_set_accepted_chars(ui->screen_txt_code, "");
    lv_textarea_set_max_length(ui->screen_txt_code, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->screen_txt_code, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for screen_txt_code, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_txt_code, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_txt_code, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_txt_code, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_txt_code, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_txt_code, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_txt_code, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_txt_code, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_txt_code, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_txt_code, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_txt_code, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_txt_code, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_txt_code, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_txt_code, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_txt_code, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_txt_code, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_txt_code, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_txt_code, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_txt_code, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_txt_code, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_txt_code, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_txt_code, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_txt_code, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_btn_done
    ui->screen_btn_done = lv_button_create(ui->screen_cont_auth);
    lv_obj_set_pos(ui->screen_btn_done, 131, 144);
    lv_obj_set_size(ui->screen_btn_done, 133, 31);
    ui->screen_btn_done_label = lv_label_create(ui->screen_btn_done);
    lv_label_set_text(ui->screen_btn_done_label, "done");
    lv_label_set_long_mode(ui->screen_btn_done_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_done_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_done, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_done_label, LV_PCT(100));

    //Write style for screen_btn_done, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_done, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_done, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_done, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_done, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_done, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_done, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_done, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_done, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_done, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_done, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_info
    ui->screen_label_info = lv_label_create(ui->screen_cont_auth);
    lv_obj_set_pos(ui->screen_label_info, 79, 96);
    lv_obj_set_size(ui->screen_label_info, 95, 19);
    lv_label_set_text(ui->screen_label_info, "auth code :");
    lv_label_set_long_mode(ui->screen_label_info, LV_LABEL_LONG_WRAP);

    //Write style for screen_label_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_info, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_info, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_info, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen);

}
