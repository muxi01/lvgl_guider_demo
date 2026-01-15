{
    files = {
        "lvgl/src/draw/vg_lite/lv_vg_lite_math.c"
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
    depfiles = "lv_vg_lite_math.o: lvgl/src/draw/vg_lite/lv_vg_lite_math.c  lvgl/src/draw/vg_lite/lv_vg_lite_math.h  lvgl/src/draw/vg_lite/../../lv_conf_internal.h  lvgl/src/draw/vg_lite/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
"
}