{
    files = {
        "lvgl/src/stdlib/builtin/lv_sprintf_builtin.c"
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
    depfiles = "lv_sprintf_builtin.o: lvgl/src/stdlib/builtin/lv_sprintf_builtin.c  lvgl/src/stdlib/builtin/../../lv_conf_internal.h  lvgl/src/stdlib/builtin/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
",
    depfiles_format = "gcc"
}