{
    files = {
        "lvgl/src/others/vg_lite_tvg/vg_lite_matrix.c"
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
    depfiles = "vg_lite_matrix.o: lvgl/src/others/vg_lite_tvg/vg_lite_matrix.c  lvgl/src/others/vg_lite_tvg/../../lv_conf_internal.h  lvgl/src/others/vg_lite_tvg/../../lv_conf_kconfig.h  ports/linux/lv_conf.h custom/lv_conf_ext.h\
"
}