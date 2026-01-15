{
    files = {
        "lvgl/src/others/font_manager/lv_font_manager_recycle.c"
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
    depfiles = "lv_font_manager_recycle.o:  lvgl/src/others/font_manager/lv_font_manager_recycle.c  lvgl/src/others/font_manager/lv_font_manager_recycle.h  lvgl/src/others/font_manager/../../misc/lv_types.h  lvgl/src/others/font_manager/../../misc/../lv_conf_internal.h  lvgl/src/others/font_manager/../../misc/../lv_conf_kconfig.h  ports/linux/lv_conf.h custom/lv_conf_ext.h\
",
    depfiles_format = "gcc"
}