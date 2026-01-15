{
    files = {
        "lvgl/src/libs/tjpgd/tjpgd.c"
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
    depfiles = "tjpgd.o: lvgl/src/libs/tjpgd/tjpgd.c lvgl/src/libs/tjpgd/tjpgd.h  lvgl/src/libs/tjpgd/../../lv_conf_internal.h  lvgl/src/libs/tjpgd/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h lvgl/src/libs/tjpgd/tjpgdcnf.h\
",
    depfiles_format = "gcc"
}