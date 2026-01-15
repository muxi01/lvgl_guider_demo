{
    files = {
        "lvgl/src/draw/sw/lv_draw_sw_utils.c"
    },
    depfiles_format = "gcc",
    depfiles = "lv_draw_sw_utils.o: lvgl/src/draw/sw/lv_draw_sw_utils.c  lvgl/src/draw/sw/lv_draw_sw_utils.h  lvgl/src/draw/sw/../../lv_conf_internal.h  lvgl/src/draw/sw/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h lvgl/src/draw/sw/../../misc/lv_area.h  lvgl/src/draw/sw/../../misc/../lv_conf_internal.h  lvgl/src/draw/sw/../../misc/lv_types.h  lvgl/src/draw/sw/../../misc/lv_math.h  lvgl/src/draw/sw/../../misc/lv_color.h  lvgl/src/draw/sw/../../misc/lv_assert.h  lvgl/src/draw/sw/../../misc/lv_log.h  lvgl/src/draw/sw/../../misc/../stdlib/lv_mem.h  lvgl/src/draw/sw/../../misc/../stdlib/../lv_conf_internal.h  lvgl/src/draw/sw/../../misc/../stdlib/lv_string.h  lvgl/src/draw/sw/../../misc/../stdlib/../misc/lv_types.h  lvgl/src/draw/sw/../../misc/lv_palette.h  lvgl/src/draw/sw/../../misc/lv_color.h  lvgl/src/draw/sw/../../misc/lv_color_op.h  lvgl/src/draw/sw/../../display/lv_display.h  lvgl/src/draw/sw/../../display/../misc/lv_types.h  lvgl/src/draw/sw/../../display/../misc/lv_timer.h  lvgl/src/draw/sw/../../display/../misc/../lv_conf_internal.h  lvgl/src/draw/sw/../../display/../misc/../tick/lv_tick.h  lvgl/src/draw/sw/../../display/../misc/../tick/../lv_conf_internal.h  lvgl/src/draw/sw/../../display/../misc/../tick/../misc/lv_types.h  lvgl/src/draw/sw/../../display/../misc/lv_types.h  lvgl/src/draw/sw/../../display/../misc/lv_ll.h  lvgl/src/draw/sw/../../display/../misc/lv_event.h  lvgl/src/draw/sw/../../display/../misc/lv_array.h  lvgl/src/draw/sw/../../display/../misc/lv_color.h  lvgl/src/draw/sw/../../display/../misc/lv_area.h\
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