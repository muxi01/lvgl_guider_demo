{
    files = {
        "lvgl/src/stdlib/clib/lv_string_clib.c"
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
    depfiles = "lv_string_clib.o: lvgl/src/stdlib/clib/lv_string_clib.c  lvgl/src/stdlib/clib/../../lv_conf_internal.h  lvgl/src/stdlib/clib/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
"
}