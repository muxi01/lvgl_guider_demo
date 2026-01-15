{
    files = {
        "lvgl/src/misc/lv_utils.c"
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
    depfiles = "lv_utils.o: lvgl/src/misc/lv_utils.c lvgl/src/misc/lv_utils.h  lvgl/src/misc/lv_types.h lvgl/src/misc/../lv_conf_internal.h  lvgl/src/misc/../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h lvgl/src/misc/../draw/lv_draw_buf.h  lvgl/src/misc/../draw/../misc/lv_types.h  lvgl/src/misc/../draw/../misc/lv_area.h  lvgl/src/misc/../draw/../misc/../lv_conf_internal.h  lvgl/src/misc/../draw/../misc/lv_types.h  lvgl/src/misc/../draw/../misc/lv_math.h  lvgl/src/misc/../draw/../misc/lv_color.h  lvgl/src/misc/../draw/../misc/lv_assert.h  lvgl/src/misc/../draw/../misc/lv_log.h  lvgl/src/misc/../draw/../misc/../stdlib/lv_mem.h  lvgl/src/misc/../draw/../misc/../stdlib/../lv_conf_internal.h  lvgl/src/misc/../draw/../misc/../stdlib/lv_string.h  lvgl/src/misc/../draw/../misc/../stdlib/../misc/lv_types.h  lvgl/src/misc/../draw/../misc/lv_palette.h  lvgl/src/misc/../draw/../misc/lv_color.h  lvgl/src/misc/../draw/../misc/lv_color_op.h  lvgl/src/misc/../draw/../stdlib/lv_string.h  lvgl/src/misc/../draw/lv_image_dsc.h  lvgl/src/misc/../draw/../lv_conf_internal.h lvgl/src/misc/lv_fs.h  lvgl/src/misc/cache/lv_cache.h lvgl/src/misc/cache/../lv_types.h  lvgl/src/misc/cache/lv_cache_entry.h  lvgl/src/misc/cache/class/lv_cache_class.h  lvgl/src/misc/cache/class/lv_cache_lru_rb.h  lvgl/src/misc/cache/class/../lv_cache_private.h  lvgl/src/misc/cache/class/../../lv_types.h  lvgl/src/misc/cache/class/../../../osal/lv_os.h  lvgl/src/misc/cache/class/../../../osal/../lv_conf_internal.h  lvgl/src/misc/cache/class/../../../osal/../misc/lv_types.h  lvgl/src/misc/cache/class/../../../osal/lv_os_none.h  lvgl/src/misc/cache/class/lv_cache_lru_ll.h  lvgl/src/misc/cache/instance/lv_cache_instance.h  lvgl/src/misc/cache/instance/lv_image_header_cache.h  lvgl/src/misc/cache/instance/../../lv_types.h  lvgl/src/misc/cache/instance/lv_image_cache.h\
",
    depfiles_format = "gcc"
}