{
    files = {
        "lvgl/src/draw/nxp/g2d/lv_g2d_buf_map.c"
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
    depfiles = "lv_g2d_buf_map.o: lvgl/src/draw/nxp/g2d/lv_g2d_buf_map.c  lvgl/src/draw/nxp/g2d/lv_g2d_buf_map.h  lvgl/src/draw/nxp/g2d/../../../lv_conf_internal.h  lvgl/src/draw/nxp/g2d/../../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
"
}