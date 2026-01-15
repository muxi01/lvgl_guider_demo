{
    files = {
        "lvgl/src/drivers/libinput/lv_xkb.c"
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
    depfiles = "lv_xkb.o: lvgl/src/drivers/libinput/lv_xkb.c  lvgl/src/drivers/libinput/lv_xkb_private.h  lvgl/src/drivers/libinput/lv_xkb.h  lvgl/src/drivers/libinput/../../lv_conf_internal.h  lvgl/src/drivers/libinput/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
"
}