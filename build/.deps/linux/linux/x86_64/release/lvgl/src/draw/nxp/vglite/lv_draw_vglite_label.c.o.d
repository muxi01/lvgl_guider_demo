{
    files = {
        "lvgl/src/draw/nxp/vglite/lv_draw_vglite_label.c"
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
    depfiles = "lv_draw_vglite_label.o: lvgl/src/draw/nxp/vglite/lv_draw_vglite_label.c  lvgl/src/draw/nxp/vglite/lv_draw_vglite.h  lvgl/src/draw/nxp/vglite/../../../lv_conf_internal.h  lvgl/src/draw/nxp/vglite/../../../lv_conf_kconfig.h  ports/linux/lv_conf.h custom/lv_conf_ext.h\
"
}