{
    files = {
        "lvgl/src/libs/lz4/lz4.c"
    },
    depfiles_format = "gcc",
    depfiles = "lz4.o: lvgl/src/libs/lz4/lz4.c lvgl/src/libs/lz4/../../lv_conf_internal.h  lvgl/src/libs/lz4/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
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