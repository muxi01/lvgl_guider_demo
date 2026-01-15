{
    files = {
        "lvgl/src/misc/lv_log.c"
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
    depfiles = "lv_log.o: lvgl/src/misc/lv_log.c lvgl/src/misc/lv_log.h  lvgl/src/misc/../lv_conf_internal.h lvgl/src/misc/../lv_conf_kconfig.h  ports/linux/lv_conf.h custom/lv_conf_ext.h lvgl/src/misc/lv_types.h\
",
    depfiles_format = "gcc"
}