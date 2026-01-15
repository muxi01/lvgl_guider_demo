{
    files = {
        "lvgl/src/misc/lv_iter.c"
    },
    depfiles_format = "gcc",
    depfiles = "lv_iter.o: lvgl/src/misc/lv_iter.c lvgl/src/misc/lv_assert.h  lvgl/src/misc/../lv_conf_internal.h lvgl/src/misc/../lv_conf_kconfig.h  ports/linux/lv_conf.h custom/lv_conf_ext.h lvgl/src/misc/lv_log.h  lvgl/src/misc/lv_types.h lvgl/src/misc/../stdlib/lv_mem.h  lvgl/src/misc/../stdlib/../lv_conf_internal.h  lvgl/src/misc/../stdlib/lv_string.h  lvgl/src/misc/../stdlib/../misc/lv_types.h lvgl/src/misc/lv_iter.h  lvgl/src/misc/lv_circle_buf.h\
",
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
    }
}