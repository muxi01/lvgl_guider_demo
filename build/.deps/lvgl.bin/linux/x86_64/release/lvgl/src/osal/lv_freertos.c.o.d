{
    files = {
        "lvgl/src/osal/lv_freertos.c"
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
    depfiles = "lv_freertos.o: lvgl/src/osal/lv_freertos.c lvgl/src/osal/lv_os.h  lvgl/src/osal/../lv_conf_internal.h lvgl/src/osal/../lv_conf_kconfig.h  ports/linux/lv_conf.h custom/lv_conf_ext.h  lvgl/src/osal/../misc/lv_types.h  lvgl/src/osal/../misc/../lv_conf_internal.h lvgl/src/osal/lv_os_none.h\
",
    depfiles_format = "gcc"
}