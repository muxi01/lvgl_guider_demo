{
    files = {
        "lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.c"
    },
    depfiles_format = "gcc",
    values = {
        "/usr/bin/gcc",
        {
            "-m64",
            "-fvisibility=hidden",
            "-O3",
            "-Ilvgl",
            "-Ilvgl/src",
            "-Icustom",
            "-Igenerated",
            "-Iports/linux",
            "-I/usr/include/drm",
            "-DLV_CONF_INCLUDE_SIMPLE=1",
            "-DNDEBUG"
        }
    },
    depfiles = "lv_draw_vg_lite_box_shadow.o:  lvgl/src/draw/vg_lite/lv_draw_vg_lite_box_shadow.c  lvgl/src/draw/vg_lite/../../misc/lv_area_private.h  lvgl/src/draw/vg_lite/../../misc/lv_area.h  lvgl/src/draw/vg_lite/../../misc/../lv_conf_internal.h  lvgl/src/draw/vg_lite/../../misc/../lv_conf_kconfig.h  ports/linux/lv_conf.h custom/lv_conf_ext.h  lvgl/src/draw/vg_lite/../../misc/lv_types.h  lvgl/src/draw/vg_lite/../../misc/lv_math.h  lvgl/src/draw/vg_lite/lv_draw_vg_lite.h  lvgl/src/draw/vg_lite/../../lv_conf_internal.h\
"
}