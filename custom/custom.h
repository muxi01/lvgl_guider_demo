/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"
#include "main.h"


typedef struct update_info {
    lv_image_dsc_t  *img_dsc;
    lv_obj_t *img_obj;
}st_update_info;


void custom_init(lv_ui *ui);
void *custom_thread(void *args);


#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
