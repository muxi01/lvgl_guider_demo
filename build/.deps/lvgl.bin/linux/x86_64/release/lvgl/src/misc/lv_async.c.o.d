{
    files = {
        "lvgl/src/misc/lv_async.c"
    },
    depfiles_format = "gcc",
    depfiles = "lv_async.o: lvgl/src/misc/lv_async.c lvgl/src/misc/lv_async.h  lvgl/src/misc/lv_types.h lvgl/src/misc/../lv_conf_internal.h  lvgl/src/misc/../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h lvgl/src/misc/lv_timer_private.h  lvgl/src/misc/lv_timer.h lvgl/src/misc/../tick/lv_tick.h  lvgl/src/misc/../tick/../lv_conf_internal.h  lvgl/src/misc/../tick/../misc/lv_types.h lvgl/src/misc/lv_ll.h  lvgl/src/misc/../stdlib/lv_mem.h  lvgl/src/misc/../stdlib/../lv_conf_internal.h  lvgl/src/misc/../stdlib/lv_string.h  lvgl/src/misc/../stdlib/../misc/lv_types.h\
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