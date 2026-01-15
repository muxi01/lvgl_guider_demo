{
    files = {
        "lvgl/src/osal/lv_pthread.c"
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
    depfiles = "lv_pthread.o: lvgl/src/osal/lv_pthread.c lvgl/src/osal/lv_os.h  lvgl/src/osal/../lv_conf_internal.h lvgl/src/osal/../lv_conf_kconfig.h  ports/linux/lv_conf.h custom/lv_conf_ext.h  lvgl/src/osal/../misc/lv_types.h  lvgl/src/osal/../misc/../lv_conf_internal.h lvgl/src/osal/lv_os_none.h\
"
}