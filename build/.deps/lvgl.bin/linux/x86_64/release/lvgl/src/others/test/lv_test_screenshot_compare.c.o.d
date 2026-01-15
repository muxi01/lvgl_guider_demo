{
    files = {
        "lvgl/src/others/test/lv_test_screenshot_compare.c"
    },
    depfiles_format = "gcc",
    depfiles = "lv_test_screenshot_compare.o:  lvgl/src/others/test/lv_test_screenshot_compare.c  lvgl/src/others/test/../../lv_conf_internal.h  lvgl/src/others/test/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
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