{
    files = {
        "lvgl/src/libs/freetype/lv_freetype.c"
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
    depfiles = "lv_freetype.o: lvgl/src/libs/freetype/lv_freetype.c  lvgl/src/libs/freetype/lv_freetype_private.h  lvgl/src/libs/freetype/lv_freetype.h  lvgl/src/libs/freetype/../../lv_conf_internal.h  lvgl/src/libs/freetype/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
",
    depfiles_format = "gcc"
}