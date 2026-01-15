{
    files = {
        "lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.c"
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
    depfiles = "lv_draw_buf_pxp.o: lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.c  lvgl/src/draw/nxp/pxp/lv_draw_pxp.h  lvgl/src/draw/nxp/pxp/../../../lv_conf_internal.h  lvgl/src/draw/nxp/pxp/../../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
",
    depfiles_format = "gcc"
}