{
    files = {
        "lvgl/src/drivers/wayland/lv_wl_seat.c"
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
    depfiles = "lv_wl_seat.o: lvgl/src/drivers/wayland/lv_wl_seat.c  lvgl/src/drivers/wayland/lv_wayland.h  lvgl/src/drivers/wayland/../../lv_conf_internal.h  lvgl/src/drivers/wayland/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
",
    depfiles_format = "gcc"
}