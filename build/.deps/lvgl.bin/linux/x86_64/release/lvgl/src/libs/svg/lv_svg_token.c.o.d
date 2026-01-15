{
    files = {
        "lvgl/src/libs/svg/lv_svg_token.c"
    },
    depfiles_format = "gcc",
    depfiles = "lv_svg_token.o: lvgl/src/libs/svg/lv_svg_token.c  lvgl/src/libs/svg/lv_svg_token.h  lvgl/src/libs/svg/../../lv_conf_internal.h  lvgl/src/libs/svg/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
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