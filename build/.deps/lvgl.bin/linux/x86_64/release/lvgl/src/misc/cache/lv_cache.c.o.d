{
    files = {
        "lvgl/src/misc/cache/lv_cache.c"
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
    depfiles = "lv_cache.o: lvgl/src/misc/cache/lv_cache.c lvgl/src/misc/cache/lv_cache.h  lvgl/src/misc/cache/../lv_types.h  lvgl/src/misc/cache/../../lv_conf_internal.h  lvgl/src/misc/cache/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h lvgl/src/misc/cache/lv_cache_entry.h  lvgl/src/misc/cache/class/lv_cache_class.h  lvgl/src/misc/cache/class/lv_cache_lru_rb.h  lvgl/src/misc/cache/class/../lv_cache_private.h  lvgl/src/misc/cache/class/../../lv_types.h  lvgl/src/misc/cache/class/../../../osal/lv_os.h  lvgl/src/misc/cache/class/../../../osal/../lv_conf_internal.h  lvgl/src/misc/cache/class/../../../osal/../misc/lv_types.h  lvgl/src/misc/cache/class/../../../osal/lv_os_none.h  lvgl/src/misc/cache/class/lv_cache_lru_ll.h  lvgl/src/misc/cache/instance/lv_cache_instance.h  lvgl/src/misc/cache/instance/lv_image_header_cache.h  lvgl/src/misc/cache/instance/../../lv_types.h  lvgl/src/misc/cache/instance/lv_image_cache.h  lvgl/src/misc/cache/../../stdlib/lv_sprintf.h  lvgl/src/misc/cache/../../stdlib/../misc/lv_types.h  lvgl/src/misc/cache/../lv_assert.h lvgl/src/misc/cache/../lv_log.h  lvgl/src/misc/cache/../lv_types.h  lvgl/src/misc/cache/../../stdlib/lv_mem.h  lvgl/src/misc/cache/../../stdlib/../lv_conf_internal.h  lvgl/src/misc/cache/../../stdlib/lv_string.h  lvgl/src/misc/cache/lv_cache_entry_private.h  lvgl/src/misc/cache/../../osal/lv_os.h  lvgl/src/misc/cache/../lv_profiler.h  lvgl/src/misc/cache/lv_cache_private.h\
",
    depfiles_format = "gcc"
}