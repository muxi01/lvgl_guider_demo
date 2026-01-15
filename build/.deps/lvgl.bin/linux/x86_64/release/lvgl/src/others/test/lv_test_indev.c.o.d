{
    files = {
        "lvgl/src/others/test/lv_test_indev.c"
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
    depfiles = "lv_test_indev.o: lvgl/src/others/test/lv_test_indev.c  lvgl/src/others/test/lv_test.h  lvgl/src/others/test/../../lv_conf_internal.h  lvgl/src/others/test/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
",
    depfiles_format = "gcc"
}