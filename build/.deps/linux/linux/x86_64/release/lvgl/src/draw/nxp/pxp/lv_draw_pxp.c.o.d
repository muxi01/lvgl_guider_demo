{
    files = {
        "lvgl/src/draw/nxp/pxp/lv_draw_pxp.c"
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
    depfiles = "lv_draw_pxp.o: lvgl/src/draw/nxp/pxp/lv_draw_pxp.c  lvgl/src/draw/nxp/pxp/lv_draw_pxp.h  lvgl/src/draw/nxp/pxp/../../../lv_conf_internal.h  lvgl/src/draw/nxp/pxp/../../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
"
}