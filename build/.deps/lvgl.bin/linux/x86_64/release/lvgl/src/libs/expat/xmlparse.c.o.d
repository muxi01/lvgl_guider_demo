{
    files = {
        "lvgl/src/libs/expat/xmlparse.c"
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
    depfiles = "xmlparse.o: lvgl/src/libs/expat/xmlparse.c  lvgl/src/libs/expat/../../lv_conf_internal.h  lvgl/src/libs/expat/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
",
    depfiles_format = "gcc"
}