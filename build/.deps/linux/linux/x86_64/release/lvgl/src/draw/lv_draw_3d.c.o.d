{
    files = {
        "lvgl/src/draw/lv_draw_3d.c"
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
    depfiles = "lv_draw_3d.o: lvgl/src/draw/lv_draw_3d.c lvgl/src/draw/lv_draw_3d.h  lvgl/src/draw/../lv_conf_internal.h lvgl/src/draw/../lv_conf_kconfig.h  ports/linux/lv_conf.h custom/lv_conf_ext.h\
"
}