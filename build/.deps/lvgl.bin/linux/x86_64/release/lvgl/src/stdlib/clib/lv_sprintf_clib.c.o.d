{
    files = {
        "lvgl/src/stdlib/clib/lv_sprintf_clib.c"
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
    depfiles = "lv_sprintf_clib.o: lvgl/src/stdlib/clib/lv_sprintf_clib.c  lvgl/src/stdlib/clib/../../lv_conf_internal.h  lvgl/src/stdlib/clib/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h lvgl/src/stdlib/clib/../lv_sprintf.h  lvgl/src/stdlib/clib/../../misc/lv_types.h  lvgl/src/stdlib/clib/../../misc/../lv_conf_internal.h\
",
    depfiles_format = "gcc"
}