{
    files = {
        "lvgl/src/drivers/wayland/lv_wl_window_decorations.c"
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
    depfiles = "lv_wl_window_decorations.o:  lvgl/src/drivers/wayland/lv_wl_window_decorations.c  lvgl/src/drivers/wayland/lv_wayland.h  lvgl/src/drivers/wayland/../../lv_conf_internal.h  lvgl/src/drivers/wayland/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
"
}