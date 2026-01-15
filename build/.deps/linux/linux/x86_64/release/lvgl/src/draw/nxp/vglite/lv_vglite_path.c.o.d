{
    files = {
        "lvgl/src/draw/nxp/vglite/lv_vglite_path.c"
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
    depfiles = "lv_vglite_path.o: lvgl/src/draw/nxp/vglite/lv_vglite_path.c  lvgl/src/draw/nxp/vglite/lv_vglite_path.h  lvgl/src/draw/nxp/vglite/../../../lv_conf_internal.h  lvgl/src/draw/nxp/vglite/../../../lv_conf_kconfig.h  ports/linux/lv_conf.h custom/lv_conf_ext.h\
"
}