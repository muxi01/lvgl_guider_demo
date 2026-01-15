{
    files = {
        "lvgl/src/drivers/nuttx/lv_nuttx_touchscreen.c"
    },
    depfiles_format = "gcc",
    depfiles = "lv_nuttx_touchscreen.o: lvgl/src/drivers/nuttx/lv_nuttx_touchscreen.c  lvgl/src/drivers/nuttx/lv_nuttx_touchscreen.h  lvgl/src/drivers/nuttx/../../indev/lv_indev.h  lvgl/src/drivers/nuttx/../../indev/../core/lv_group.h  lvgl/src/drivers/nuttx/../../indev/../core/../lv_conf_internal.h  lvgl/src/drivers/nuttx/../../indev/../core/../lv_conf_kconfig.h  ports/linux/lv_conf.h custom/lv_conf_ext.h  lvgl/src/drivers/nuttx/../../indev/../core/../misc/lv_types.h  lvgl/src/drivers/nuttx/../../indev/../core/../misc/../lv_conf_internal.h  lvgl/src/drivers/nuttx/../../indev/../core/../misc/lv_ll.h  lvgl/src/drivers/nuttx/../../indev/../core/../misc/lv_types.h  lvgl/src/drivers/nuttx/../../indev/../misc/lv_area.h  lvgl/src/drivers/nuttx/../../indev/../misc/../lv_conf_internal.h  lvgl/src/drivers/nuttx/../../indev/../misc/lv_types.h  lvgl/src/drivers/nuttx/../../indev/../misc/lv_math.h  lvgl/src/drivers/nuttx/../../indev/../misc/lv_timer.h  lvgl/src/drivers/nuttx/../../indev/../misc/../tick/lv_tick.h  lvgl/src/drivers/nuttx/../../indev/../misc/../tick/../lv_conf_internal.h  lvgl/src/drivers/nuttx/../../indev/../misc/../tick/../misc/lv_types.h  lvgl/src/drivers/nuttx/../../indev/../misc/lv_ll.h  lvgl/src/drivers/nuttx/../../indev/../misc/lv_event.h  lvgl/src/drivers/nuttx/../../indev/../misc/lv_array.h\
",
    values = {
        "/usr/bin/gcc",
        {
            "-m64",
            "-O0",
            "-Ilvgl",
            "-Ilvgl/src",
            "-Icustom",
            "-Igenerated",
            "-Iports/linux",
            "-I/usr/include/drm",
            "-DLV_CONF_INCLUDE_SIMPLE=1"
        }
    }
}