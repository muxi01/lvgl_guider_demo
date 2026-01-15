{
    files = {
        "lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.c"
    },
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
    },
    depfiles = "lv_draw_vg_lite_layer.o: lvgl/src/draw/vg_lite/lv_draw_vg_lite_layer.c  lvgl/src/draw/vg_lite/lv_draw_vg_lite.h  lvgl/src/draw/vg_lite/../../lv_conf_internal.h  lvgl/src/draw/vg_lite/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
",
    depfiles_format = "gcc"
}