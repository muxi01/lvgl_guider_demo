{
    files = {
        "lvgl/src/font/lv_font.c"
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
    depfiles = "lv_font.o: lvgl/src/font/lv_font.c lvgl/src/font/lv_font.h  lvgl/src/font/../lv_conf_internal.h lvgl/src/font/../lv_conf_kconfig.h  ports/linux/lv_conf.h custom/lv_conf_ext.h  lvgl/src/font/../misc/lv_types.h  lvgl/src/font/../misc/../lv_conf_internal.h  lvgl/src/font/lv_symbol_def.h lvgl/src/font/../draw/lv_draw_buf.h  lvgl/src/font/../draw/../misc/lv_types.h  lvgl/src/font/../draw/../misc/lv_area.h  lvgl/src/font/../draw/../misc/../lv_conf_internal.h  lvgl/src/font/../draw/../misc/lv_types.h  lvgl/src/font/../draw/../misc/lv_math.h  lvgl/src/font/../draw/../misc/lv_color.h  lvgl/src/font/../draw/../misc/lv_assert.h  lvgl/src/font/../draw/../misc/lv_log.h  lvgl/src/font/../draw/../misc/../stdlib/lv_mem.h  lvgl/src/font/../draw/../misc/../stdlib/../lv_conf_internal.h  lvgl/src/font/../draw/../misc/../stdlib/lv_string.h  lvgl/src/font/../draw/../misc/../stdlib/../misc/lv_types.h  lvgl/src/font/../draw/../misc/lv_palette.h  lvgl/src/font/../draw/../misc/lv_color.h  lvgl/src/font/../draw/../misc/lv_color_op.h  lvgl/src/font/../draw/../stdlib/lv_string.h  lvgl/src/font/../draw/lv_image_dsc.h  lvgl/src/font/../draw/../lv_conf_internal.h  lvgl/src/font/../misc/lv_area.h lvgl/src/font/../misc/lv_text_private.h  lvgl/src/font/../misc/lv_text.h lvgl/src/font/../misc/lv_types.h  lvgl/src/font/../misc/lv_area.h lvgl/src/font/../misc/../font/lv_font.h  lvgl/src/font/../misc/../stdlib/lv_sprintf.h  lvgl/src/font/../misc/../stdlib/../misc/lv_types.h  lvgl/src/font/../misc/lv_utils.h  lvgl/src/font/../misc/../draw/lv_draw_buf.h  lvgl/src/font/../misc/lv_log.h lvgl/src/font/../misc/lv_assert.h  lvgl/src/font/../stdlib/lv_string.h\
"
}