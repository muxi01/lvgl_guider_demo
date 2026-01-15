{
    files = {
        "lvgl/src/stdlib/rtthread/lv_mem_core_rtthread.c"
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
    depfiles = "lv_mem_core_rtthread.o: lvgl/src/stdlib/rtthread/lv_mem_core_rtthread.c  lvgl/src/stdlib/rtthread/../lv_mem.h  lvgl/src/stdlib/rtthread/../../lv_conf_internal.h  lvgl/src/stdlib/rtthread/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h lvgl/src/stdlib/rtthread/../lv_string.h  lvgl/src/stdlib/rtthread/../../misc/lv_types.h  lvgl/src/stdlib/rtthread/../../misc/../lv_conf_internal.h\
",
    depfiles_format = "gcc"
}