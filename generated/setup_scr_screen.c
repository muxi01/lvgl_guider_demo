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

    //Write codes screen_img_default
    ui->screen_img_default = lv_image_create(ui->screen);
    lv_obj_set_pos(ui->screen_img_default, 0, 0);
    lv_obj_set_size(ui->screen_img_default, 800, 480);
    lv_obj_add_flag(ui->screen_img_default, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_img_default, &_horse_RGB888_800x480);
    lv_image_set_pivot(ui->screen_img_default, 50,50);
    lv_image_set_rotation(ui->screen_img_default, 0);

    //Write style for screen_img_default, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_img_default, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_img_default, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_lbr_waiting
    ui->screen_lbr_waiting = lv_label_create(ui->screen);
    lv_obj_set_pos(ui->screen_lbr_waiting, 173, 373);
    lv_obj_set_size(ui->screen_lbr_waiting, 450, 40);
    lv_label_set_text(ui->screen_lbr_waiting, "waiting for connecting ....");
    lv_label_set_long_mode(ui->screen_lbr_waiting, LV_LABEL_LONG_WRAP);

    //Write style for screen_lbr_waiting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_lbr_waiting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_lbr_waiting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_lbr_waiting, lv_color_hex(0xff71ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_lbr_waiting, &lv_font_montserratMedium_32, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_lbr_waiting, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_lbr_waiting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_lbr_waiting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_lbr_waiting, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_lbr_waiting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_lbr_waiting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_lbr_waiting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_lbr_waiting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_lbr_waiting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_lbr_waiting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cvs_display
    LV_DRAW_BUF_DEFINE_STATIC(screen_cvs_display_draw_buf, 800, 480, LV_COLOR_FORMAT_ARGB8888);
    LV_DRAW_BUF_INIT_STATIC(screen_cvs_display_draw_buf);
    ui->screen_cvs_display = lv_canvas_create(ui->screen);
    lv_obj_set_pos(ui->screen_cvs_display, 0, 0);
    lv_obj_set_size(ui->screen_cvs_display, 800, 480);
    lv_obj_set_scrollbar_mode(ui->screen_cvs_display, LV_SCROLLBAR_MODE_OFF);
    lv_canvas_set_draw_buf(ui->screen_cvs_display, &screen_cvs_display_draw_buf);
    lv_canvas_fill_bg(ui->screen_cvs_display, lv_color_hex(0xffffff), 255);

    lv_layer_t layer_screen_cvs_display;
    lv_canvas_init_layer(ui->screen_cvs_display, &layer_screen_cvs_display);
    //Canvas draw rectangle
    lv_draw_rect_dsc_t screen_cvs_display_rect_dsc_0;
    lv_draw_rect_dsc_init(&screen_cvs_display_rect_dsc_0);
    screen_cvs_display_rect_dsc_0.radius = 0;
    screen_cvs_display_rect_dsc_0.bg_opa = 255;
    screen_cvs_display_rect_dsc_0.bg_color = lv_color_hex(0x667f8d);
    screen_cvs_display_rect_dsc_0.bg_grad.dir = LV_GRAD_DIR_NONE;
    screen_cvs_display_rect_dsc_0.border_width = 0;
    screen_cvs_display_rect_dsc_0.border_opa = 255;
    screen_cvs_display_rect_dsc_0.border_color = lv_color_hex(0x000000);
    lv_area_t screen_cvs_display_coords_rect_0 = {0, 0, 800, 480};
    lv_draw_rect(&layer_screen_cvs_display, &screen_cvs_display_rect_dsc_0, &screen_cvs_display_coords_rect_0);

    lv_canvas_finish_layer(ui->screen_cvs_display, &layer_screen_cvs_display);

    //Write codes screen_btn_keyboard
    ui->screen_btn_keyboard = lv_button_create(ui->screen);
    lv_obj_set_pos(ui->screen_btn_keyboard, 62, 41);
    lv_obj_set_size(ui->screen_btn_keyboard, 45, 45);
    lv_obj_add_flag(ui->screen_btn_keyboard, LV_OBJ_FLAG_HIDDEN);
    ui->screen_btn_keyboard_label = lv_label_create(ui->screen_btn_keyboard);
    lv_label_set_text(ui->screen_btn_keyboard_label, "key");
    lv_label_set_long_mode(ui->screen_btn_keyboard_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_keyboard_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_keyboard, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_keyboard_label, LV_PCT(100));

    //Write style for screen_btn_keyboard, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_keyboard, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_keyboard, lv_color_hex(0xf871ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_keyboard, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_keyboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_keyboard, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_keyboard, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->screen_btn_keyboard, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->screen_btn_keyboard, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->screen_btn_keyboard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_x(ui->screen_btn_keyboard, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_offset_y(ui->screen_btn_keyboard, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_keyboard, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_keyboard, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_keyboard, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_keyboard, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_ctn_authority
    ui->screen_ctn_authority = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_ctn_authority, 99, 104);
    lv_obj_set_size(ui->screen_ctn_authority, 616, 269);
    lv_obj_set_scrollbar_mode(ui->screen_ctn_authority, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->screen_ctn_authority, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->screen_ctn_authority, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_ctn_authority, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_ctn_authority, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_ctn_authority, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_ctn_authority, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_ctn_authority, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_ctn_authority, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_ctn_authority, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_ctn_authority, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_ctn_authority, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_ctn_authority, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_ctn_authority, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_ctn_authority, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_ctn_authority, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_ctn_authority, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_txt_input
    ui->screen_txt_input = lv_textarea_create(ui->screen_ctn_authority);
    lv_obj_set_pos(ui->screen_txt_input, 280, 104);
    lv_obj_set_size(ui->screen_txt_input, 234, 39);
    lv_textarea_set_text(ui->screen_txt_input, "Hello World");
    lv_textarea_set_placeholder_text(ui->screen_txt_input, "");
    lv_textarea_set_password_bullet(ui->screen_txt_input, "*");
    lv_textarea_set_password_mode(ui->screen_txt_input, false);
    lv_textarea_set_one_line(ui->screen_txt_input, false);
    lv_textarea_set_accepted_chars(ui->screen_txt_input, "");
    lv_textarea_set_max_length(ui->screen_txt_input, 32);
#if LV_USE_KEYBOARD
    // lv_obj_add_event_cb(ui->screen_txt_input, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for screen_txt_input, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_txt_input, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_txt_input, &lv_font_montserratMedium_30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_txt_input, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_txt_input, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_txt_input, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_txt_input, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_txt_input, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_txt_input, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_txt_input, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_txt_input, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_txt_input, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_txt_input, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_txt_input, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_txt_input, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_txt_input, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_txt_input, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_txt_input, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_txt_input, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_txt_input, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_txt_input, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_txt_input, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_txt_input, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes screen_auth_btn_done
    ui->screen_auth_btn_done = lv_button_create(ui->screen_ctn_authority);
    lv_obj_set_pos(ui->screen_auth_btn_done, 92, 177);
    lv_obj_set_size(ui->screen_auth_btn_done, 290, 45);
    ui->screen_auth_btn_done_label = lv_label_create(ui->screen_auth_btn_done);
    lv_label_set_text(ui->screen_auth_btn_done_label, "Empower");
    lv_label_set_long_mode(ui->screen_auth_btn_done_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_auth_btn_done_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_auth_btn_done, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_auth_btn_done_label, LV_PCT(100));

    //Write style for screen_auth_btn_done, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_auth_btn_done, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_auth_btn_done, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_auth_btn_done, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_auth_btn_done, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_auth_btn_done, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_auth_btn_done, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_auth_btn_done, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_auth_btn_done, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_auth_btn_done, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_auth_btn_done, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_lbr_order_id
    ui->screen_lbr_order_id = lv_label_create(ui->screen_ctn_authority);
    lv_obj_set_pos(ui->screen_lbr_order_id, 84, 106);
    lv_obj_set_size(ui->screen_lbr_order_id, 189, 35);
    lv_label_set_text(ui->screen_lbr_order_id, "Order   ID  :");
    lv_label_set_long_mode(ui->screen_lbr_order_id, LV_LABEL_LONG_WRAP);

    //Write style for screen_lbr_order_id, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_lbr_order_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_lbr_order_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_lbr_order_id, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_lbr_order_id, &lv_font_montserratMedium_32, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_lbr_order_id, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_lbr_order_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_lbr_order_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_lbr_order_id, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_lbr_order_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_lbr_order_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_lbr_order_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_lbr_order_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_lbr_order_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_lbr_order_id, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_lbr_serial_no
    ui->screen_lbr_serial_no = lv_label_create(ui->screen_ctn_authority);
    lv_obj_set_pos(ui->screen_lbr_serial_no, 280, 52);
    lv_obj_set_size(ui->screen_lbr_serial_no, 239, 35);
    lv_label_set_text(ui->screen_lbr_serial_no, "1234567890ab");
    lv_label_set_long_mode(ui->screen_lbr_serial_no, LV_LABEL_LONG_WRAP);

    //Write style for screen_lbr_serial_no, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_lbr_serial_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_lbr_serial_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_lbr_serial_no, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_lbr_serial_no, &lv_font_montserratMedium_32, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_lbr_serial_no, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_lbr_serial_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_lbr_serial_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_lbr_serial_no, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_lbr_serial_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_lbr_serial_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_lbr_serial_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_lbr_serial_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_lbr_serial_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_lbr_serial_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_btn_details
    ui->screen_btn_details = lv_button_create(ui->screen_ctn_authority);
    lv_obj_set_pos(ui->screen_btn_details, 420, 177);
    lv_obj_set_size(ui->screen_btn_details, 100, 45);
    ui->screen_btn_details_label = lv_label_create(ui->screen_btn_details);
    lv_label_set_text(ui->screen_btn_details_label, "details");
    lv_label_set_long_mode(ui->screen_btn_details_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_btn_details_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_btn_details, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_btn_details_label, LV_PCT(100));

    //Write style for screen_btn_details, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_btn_details, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_btn_details, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_btn_details, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_btn_details, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_btn_details, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_btn_details, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_btn_details, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_btn_details, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_btn_details, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_btn_details, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_lbr_device_no
    ui->screen_lbr_device_no = lv_label_create(ui->screen_ctn_authority);
    lv_obj_set_pos(ui->screen_lbr_device_no, 80, 50);
    lv_obj_set_size(ui->screen_lbr_device_no, 188, 35);
    lv_label_set_text(ui->screen_lbr_device_no, "Device No :");
    lv_label_set_long_mode(ui->screen_lbr_device_no, LV_LABEL_LONG_WRAP);

    //Write style for screen_lbr_device_no, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_lbr_device_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_lbr_device_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_lbr_device_no, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_lbr_device_no, &lv_font_montserratMedium_32, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_lbr_device_no, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_lbr_device_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_lbr_device_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_lbr_device_no, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_lbr_device_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_lbr_device_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_lbr_device_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_lbr_device_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_lbr_device_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_lbr_device_no, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_win_details
    ui->screen_win_details = lv_win_create(ui->screen);
    lv_obj_set_pos(ui->screen_win_details, 56, 55);
    lv_obj_set_size(ui->screen_win_details, 685, 367);
    lv_obj_set_scrollbar_mode(ui->screen_win_details, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->screen_win_details, LV_OBJ_FLAG_HIDDEN);
    lv_obj_t * screen_win_details_title = lv_win_add_title(ui->screen_win_details, "details");
    lv_obj_t * screen_win_details_header = lv_win_get_header(ui->screen_win_details);
    lv_obj_set_height(screen_win_details_header, 40);
    ui->screen_win_details_item0 = lv_win_add_button(ui->screen_win_details, LV_SYMBOL_CLOSE, 40);
    lv_obj_t *screen_win_details_label = lv_label_create(lv_win_get_content(ui->screen_win_details));
    lv_obj_set_scrollbar_mode(lv_win_get_content(ui->screen_win_details), LV_SCROLLBAR_MODE_OFF);
    lv_label_set_text(screen_win_details_label, "this is a long text to show scrollbar. if \nit \nis not \nlong enough, \nadd more content");

    //Write style for screen_win_details, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_win_details, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_win_details, lv_color_hex(0xeeeef6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_win_details, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->screen_win_details, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_win_details, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_win_details_extra_content_main_default
    static lv_style_t style_screen_win_details_extra_content_main_default;
    ui_init_style(&style_screen_win_details_extra_content_main_default);

    lv_style_set_bg_opa(&style_screen_win_details_extra_content_main_default, 255);
    lv_style_set_bg_color(&style_screen_win_details_extra_content_main_default, lv_color_hex(0xeeeef6));
    lv_style_set_bg_grad_dir(&style_screen_win_details_extra_content_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_text_color(&style_screen_win_details_extra_content_main_default, lv_color_hex(0x393c41));
    lv_style_set_text_font(&style_screen_win_details_extra_content_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_win_details_extra_content_main_default, 255);
    lv_style_set_text_letter_space(&style_screen_win_details_extra_content_main_default, 0);
    lv_style_set_text_line_space(&style_screen_win_details_extra_content_main_default, 2);
    lv_obj_add_style(lv_win_get_content(ui->screen_win_details), &style_screen_win_details_extra_content_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_win_details_extra_header_main_default
    static lv_style_t style_screen_win_details_extra_header_main_default;
    ui_init_style(&style_screen_win_details_extra_header_main_default);

    lv_style_set_bg_opa(&style_screen_win_details_extra_header_main_default, 255);
    lv_style_set_bg_color(&style_screen_win_details_extra_header_main_default, lv_color_hex(0xe6e6e6));
    lv_style_set_bg_grad_dir(&style_screen_win_details_extra_header_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_text_color(&style_screen_win_details_extra_header_main_default, lv_color_hex(0x393c41));
    lv_style_set_text_font(&style_screen_win_details_extra_header_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_screen_win_details_extra_header_main_default, 255);
    lv_style_set_text_letter_space(&style_screen_win_details_extra_header_main_default, 0);
    lv_style_set_text_line_space(&style_screen_win_details_extra_header_main_default, 2);
    lv_style_set_pad_top(&style_screen_win_details_extra_header_main_default, 5);
    lv_style_set_pad_right(&style_screen_win_details_extra_header_main_default, 5);
    lv_style_set_pad_bottom(&style_screen_win_details_extra_header_main_default, 5);
    lv_style_set_pad_left(&style_screen_win_details_extra_header_main_default, 5);
    lv_style_set_pad_column(&style_screen_win_details_extra_header_main_default, 5);
    lv_obj_add_style(lv_win_get_header(ui->screen_win_details), &style_screen_win_details_extra_header_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_screen_win_details_extra_btns_main_default
    static lv_style_t style_screen_win_details_extra_btns_main_default;
    ui_init_style(&style_screen_win_details_extra_btns_main_default);

    lv_style_set_radius(&style_screen_win_details_extra_btns_main_default, 8);
    lv_style_set_border_width(&style_screen_win_details_extra_btns_main_default, 0);
    lv_style_set_bg_opa(&style_screen_win_details_extra_btns_main_default, 255);
    lv_style_set_bg_color(&style_screen_win_details_extra_btns_main_default, lv_color_hex(0x2195f6));
    lv_style_set_bg_grad_dir(&style_screen_win_details_extra_btns_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_shadow_width(&style_screen_win_details_extra_btns_main_default, 0);
    lv_obj_add_style(ui->screen_win_details_item0, &style_screen_win_details_extra_btns_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_ctn_key_dummy
    ui->screen_ctn_key_dummy = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_ctn_key_dummy, 0, 180);
    lv_obj_set_size(ui->screen_ctn_key_dummy, 800, 300);
    lv_obj_set_scrollbar_mode(ui->screen_ctn_key_dummy, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_ctn_key_dummy, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_ctn_key_dummy, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_ctn_key_dummy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_ctn_key_dummy, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_ctn_key_dummy, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_ctn_key_dummy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_ctn_key_dummy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_ctn_key_dummy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_ctn_key_dummy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_ctn_key_dummy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_ctn_key_dummy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_ctn_key_dummy, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen);

}
