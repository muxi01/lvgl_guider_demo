/*
 * SPDX-License-Identifier: MIT
 * Copyright 2024 NXP
 */

/*********************
 *      INCLUDES
 *********************/
#define _DEFAULT_SOURCE /* needed for usleep() */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lvgl.h"
#include "lv_conf.h"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"
#include "main.h"
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdint.h>
#include <string.h>


lv_ui guider_ui;
pthread_t video_thread;
st_parmaters setting;


static void hal_init(void)
{
#if LV_USE_LINUX_FBDEV  && LV_USE_EVDEV
    lv_display_t * disp;
    lv_indev_t * touch;
    lv_indev_t * keyboard;
    disp = lv_linux_fbdev_create(setting.width,setting.height,setting.rotation);

    if((setting.mouse_dev != NULL) && (strlen(setting.mouse_dev) > 4)) {
        touch = lv_evdev_create(LV_INDEV_TYPE_POINTER, setting.mouse_dev);
        if(touch != NULL) {
            lv_indev_set_display(touch, disp);

            /* Set the cursor icon */
            LV_IMAGE_DECLARE(mouse_cursor_icon);
            lv_obj_t * cursor_obj = lv_image_create(lv_screen_active());
            lv_image_set_src(cursor_obj, &mouse_cursor_icon);
            lv_indev_set_cursor(touch, cursor_obj);
        } else {
            printf("Warnning: Can't open %s device, please run 'evtest' to check.\n", setting.mouse_dev);
        }
    }

    if((setting.key_dev != NULL) && (strlen(setting.key_dev) > 4)) {
        keyboard = lv_evdev_create(LV_INDEV_TYPE_KEYPAD, setting.key_dev);
        if(keyboard != NULL) {
            lv_indev_set_display(keyboard, disp);
        }
    }

    lv_linux_fbdev_set_file(disp, setting.fb_dev);
#else 
#error Unsupported Backend
#endif
}

static void help_info(const char *name)
{
    printf("%s [-v ] [-f fb] [-m mouse] [-k key] [-W width] [-H height] [ -R rotation ] [-i image] [ -a audio]\n\n",name);
    printf(" -v : version\n");
    printf(" -m : input event of mouse\n");
    printf(" -k : input event of keyboard\n");
    printf(" -W : set the width of screen \n");
    printf(" -H : set the height of screen \n");
    printf(" -R : adjust the screen rotation angle [0 90 180 270] \n");
    printf(" -i : image source path \n");
    printf(" -a : sound card path \n");
}


static int parse_args(int argc,char **argv)
{


#if 0
    static const char *fb= "/dev/fb0";
    static const char *mouse= "/dev/input/event2";
    static const char *keyboard= "/dev/input/event3";
    static const char *image= "/dev/ffs";
    static const char *audio= "/dev/snd/card0";
#else 
    static const char *fb= "/dev/fb0";
    static const char *mouse= "";
    static const char *keyboard= "";
    static const char *audio= "";
    static const char *image= "";
#endif 

    setting.fb_dev=fb;
    setting.mouse_dev=mouse;
    setting.key_dev=keyboard;
    setting.image=image;
    setting.audio=audio;
    setting.rotation =0;
    setting.width=800;
    setting.height=480;

    int opt;
    while((opt = getopt(argc, argv, "hvW:H:R:m:k:i:a:")) != -1) {
        switch(opt) {
            case 'h':
                help_info(argv[0]);
                exit(0);
            break;

            case 'v':
                printf("version : 1.0.0\n");
                exit(0);
            break;

            case 'W':
                setting.width =atoi(optarg);
            break;
            case 'H':
                setting.height =atoi(optarg);
            break;
            case 'R':
                setting.rotation =atoi(optarg);
            break;

            case 'm':
                setting.mouse_dev =optarg;
            break;
            case 'k':
                setting.key_dev =optarg;
            break;
            case 'i':
                setting.image =optarg;
            break;
            case 'a':
                setting.audio =optarg;
            break;
            default:
            break;
        }
    }

    printf("fb      :%s\n",setting.fb_dev);
    printf("mouse   : %s\n",setting.mouse_dev);
    printf("keyboard: %s\n",setting.key_dev);
    printf("image   : %s\n",setting.image);
    printf("audio   : %s\n",setting.audio);
    printf("screen info: %dx%d:R%d\n",setting.width,setting.height,setting.rotation);
    return 0;
}



static void limited(long fps){
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


int main(int argc,char **argv)
{
    parse_args(argc,argv);

    lv_init();
    hal_init();

    /* Create a GUI-Guider app */
    setup_ui(&guider_ui);
    events_init(&guider_ui);
    custom_init(&guider_ui);
    pthread_create(&video_thread, NULL, custom_thread, &guider_ui);

    usleep(1000*100);
    /* Handle LVGL tasks */
    while(1) {
        /* Return the time to the next timer execution */
        lv_timer_handler();
	    limited(60);
    }
    return 0;
}
