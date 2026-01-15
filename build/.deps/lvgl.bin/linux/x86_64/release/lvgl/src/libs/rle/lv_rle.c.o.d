{
    files = {
        "lvgl/src/libs/rle/lv_rle.c"
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
    depfiles = "lv_rle.o: lvgl/src/libs/rle/lv_rle.c  lvgl/src/libs/rle/../../stdlib/lv_string.h  lvgl/src/libs/rle/../../stdlib/../lv_conf_internal.h  lvgl/src/libs/rle/../../stdlib/../lv_conf_kconfig.h  ports/linux/lv_conf.h custom/lv_conf_ext.h  lvgl/src/libs/rle/../../stdlib/../misc/lv_types.h  lvgl/src/libs/rle/../../stdlib/../misc/../lv_conf_internal.h  lvgl/src/libs/rle/lv_rle.h lvgl/src/libs/rle/../../lv_conf_internal.h\
",
    depfiles_format = "gcc"
}