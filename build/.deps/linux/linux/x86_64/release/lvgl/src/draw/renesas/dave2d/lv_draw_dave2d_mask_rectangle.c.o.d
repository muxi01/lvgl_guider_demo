{
    files = {
        "lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.c"
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
    depfiles = "lv_draw_dave2d_mask_rectangle.o:  lvgl/src/draw/renesas/dave2d/lv_draw_dave2d_mask_rectangle.c  lvgl/src/draw/renesas/dave2d/lv_draw_dave2d.h  lvgl/src/draw/renesas/dave2d/../../../lv_conf_internal.h  lvgl/src/draw/renesas/dave2d/../../../lv_conf_kconfig.h  ports/linux/lv_conf.h custom/lv_conf_ext.h\
"
}