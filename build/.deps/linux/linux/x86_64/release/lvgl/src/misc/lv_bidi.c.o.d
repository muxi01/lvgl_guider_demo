{
    files = {
        "lvgl/src/misc/lv_bidi.c"
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
    depfiles = "lv_bidi.o: lvgl/src/misc/lv_bidi.c lvgl/src/misc/lv_bidi_private.h  lvgl/src/misc/lv_bidi.h lvgl/src/misc/../lv_conf_internal.h  lvgl/src/misc/../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h lvgl/src/misc/lv_types.h lvgl/src/misc/lv_text.h  lvgl/src/misc/lv_area.h lvgl/src/misc/lv_math.h  lvgl/src/misc/../font/lv_font.h  lvgl/src/misc/../font/../lv_conf_internal.h  lvgl/src/misc/../font/../misc/lv_types.h  lvgl/src/misc/../font/lv_symbol_def.h  lvgl/src/misc/../font/../draw/lv_draw_buf.h  lvgl/src/misc/../font/../draw/../misc/lv_types.h  lvgl/src/misc/../font/../draw/../misc/lv_area.h  lvgl/src/misc/../font/../draw/../misc/lv_color.h  lvgl/src/misc/../font/../draw/../misc/../lv_conf_internal.h  lvgl/src/misc/../font/../draw/../misc/lv_assert.h  lvgl/src/misc/../font/../draw/../misc/lv_log.h  lvgl/src/misc/../font/../draw/../misc/lv_types.h  lvgl/src/misc/../font/../draw/../misc/../stdlib/lv_mem.h  lvgl/src/misc/../font/../draw/../misc/../stdlib/../lv_conf_internal.h  lvgl/src/misc/../font/../draw/../misc/../stdlib/lv_string.h  lvgl/src/misc/../font/../draw/../misc/../stdlib/../misc/lv_types.h  lvgl/src/misc/../font/../draw/../misc/lv_math.h  lvgl/src/misc/../font/../draw/../misc/lv_palette.h  lvgl/src/misc/../font/../draw/../misc/lv_color.h  lvgl/src/misc/../font/../draw/../misc/lv_color_op.h  lvgl/src/misc/../font/../draw/../stdlib/lv_string.h  lvgl/src/misc/../font/../draw/lv_image_dsc.h  lvgl/src/misc/../font/../draw/../lv_conf_internal.h  lvgl/src/misc/../font/../misc/lv_area.h  lvgl/src/misc/../stdlib/lv_sprintf.h  lvgl/src/misc/../stdlib/../misc/lv_types.h  lvgl/src/misc/lv_text_private.h lvgl/src/misc/../stdlib/lv_mem.h  lvgl/src/misc/../stdlib/lv_string.h\
"
}