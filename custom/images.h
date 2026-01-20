/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef __IMAGES_DEC_H_
#define __IMAGES_DEC_H_
#ifdef __cplusplus
extern "C" {
#endif

extern void image_init(void);
extern void image_deinit(void);
extern lv_image_dsc_t  *image_decode(const char *jpg_path);

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
