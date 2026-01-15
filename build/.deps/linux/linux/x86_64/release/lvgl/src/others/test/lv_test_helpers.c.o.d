{
    files = {
        "lvgl/src/others/test/lv_test_helpers.c"
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
    depfiles = "lv_test_helpers.o: lvgl/src/others/test/lv_test_helpers.c  lvgl/src/others/test/lv_test_helpers.h  lvgl/src/others/test/../../lv_conf_internal.h  lvgl/src/others/test/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
"
}