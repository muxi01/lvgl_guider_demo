{
    files = {
        "lvgl/src/draw/nxp/g2d/lv_draw_buf_g2d.c"
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
    depfiles = "lv_draw_buf_g2d.o: lvgl/src/draw/nxp/g2d/lv_draw_buf_g2d.c  lvgl/src/draw/nxp/g2d/lv_draw_g2d.h  lvgl/src/draw/nxp/g2d/../../../lv_conf_internal.h  lvgl/src/draw/nxp/g2d/../../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
",
    depfiles_format = "gcc"
}