{
    files = {
        "lvgl/src/libs/gif/gifdec.c"
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
    depfiles = "gifdec.o: lvgl/src/libs/gif/gifdec.c lvgl/src/libs/gif/gifdec.h  lvgl/src/libs/gif/../../misc/lv_fs.h  lvgl/src/libs/gif/../../misc/../lv_conf_internal.h  lvgl/src/libs/gif/../../misc/../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h lvgl/src/libs/gif/../../misc/lv_types.h  lvgl/src/libs/gif/../../misc/lv_log.h  lvgl/src/libs/gif/../../stdlib/lv_mem.h  lvgl/src/libs/gif/../../stdlib/../lv_conf_internal.h  lvgl/src/libs/gif/../../stdlib/lv_string.h  lvgl/src/libs/gif/../../stdlib/../misc/lv_types.h  lvgl/src/libs/gif/../../misc/lv_color.h  lvgl/src/libs/gif/../../misc/lv_assert.h  lvgl/src/libs/gif/../../misc/lv_log.h  lvgl/src/libs/gif/../../misc/../stdlib/lv_mem.h  lvgl/src/libs/gif/../../misc/lv_math.h  lvgl/src/libs/gif/../../misc/lv_palette.h  lvgl/src/libs/gif/../../misc/lv_color.h  lvgl/src/libs/gif/../../misc/lv_color_op.h\
",
    depfiles_format = "gcc"
}