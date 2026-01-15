{
    files = {
        "lvgl/src/drivers/display/st_ltdc/lv_st_ltdc.c"
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
    depfiles = "lv_st_ltdc.o: lvgl/src/drivers/display/st_ltdc/lv_st_ltdc.c  lvgl/src/drivers/display/st_ltdc/../../../lv_conf_internal.h  lvgl/src/drivers/display/st_ltdc/../../../lv_conf_kconfig.h  ports/linux/lv_conf.h custom/lv_conf_ext.h\
",
    depfiles_format = "gcc"
}