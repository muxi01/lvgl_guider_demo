{
    files = {
        "lvgl/src/misc/cache/class/lv_cache_lru_rb.c"
    },
    depfiles_format = "gcc",
    depfiles = "lv_cache_lru_rb.o: lvgl/src/misc/cache/class/lv_cache_lru_rb.c  lvgl/src/misc/cache/class/lv_cache_lru_rb.h  lvgl/src/misc/cache/class/../lv_cache_private.h  lvgl/src/misc/cache/class/../../lv_types.h  lvgl/src/misc/cache/class/../../../lv_conf_internal.h  lvgl/src/misc/cache/class/../../../lv_conf_kconfig.h  ports/linux/lv_conf.h custom/lv_conf_ext.h  lvgl/src/misc/cache/class/../../../osal/lv_os.h  lvgl/src/misc/cache/class/../../../osal/../lv_conf_internal.h  lvgl/src/misc/cache/class/../../../osal/../misc/lv_types.h  lvgl/src/misc/cache/class/../../../osal/lv_os_none.h  lvgl/src/misc/cache/class/../lv_cache_entry.h  lvgl/src/misc/cache/class/../../../stdlib/lv_sprintf.h  lvgl/src/misc/cache/class/../../../stdlib/../misc/lv_types.h  lvgl/src/misc/cache/class/../../../stdlib/lv_string.h  lvgl/src/misc/cache/class/../../../stdlib/../lv_conf_internal.h  lvgl/src/misc/cache/class/../../lv_ll.h  lvgl/src/misc/cache/class/../../lv_types.h  lvgl/src/misc/cache/class/../../lv_rb_private.h  lvgl/src/misc/cache/class/../../lv_rb.h  lvgl/src/misc/cache/class/../../lv_assert.h  lvgl/src/misc/cache/class/../../lv_log.h  lvgl/src/misc/cache/class/../../../stdlib/lv_mem.h  lvgl/src/misc/cache/class/../../../stdlib/lv_string.h  lvgl/src/misc/cache/class/../../lv_rb.h  lvgl/src/misc/cache/class/../../lv_iter.h\
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