{
    files = {
        "lvgl/src/drivers/display/drm/lv_linux_drm.c"
    },
    depfiles_format = "gcc",
    depfiles = "lv_linux_drm.o: lvgl/src/drivers/display/drm/lv_linux_drm.c  lvgl/src/drivers/display/drm/lv_linux_drm.h  lvgl/src/drivers/display/drm/../../../display/lv_display.h  lvgl/src/drivers/display/drm/../../../display/../misc/lv_types.h  lvgl/src/drivers/display/drm/../../../display/../misc/../lv_conf_internal.h  lvgl/src/drivers/display/drm/../../../display/../misc/../lv_conf_kconfig.h  ports/linux/lv_conf.h custom/lv_conf_ext.h  lvgl/src/drivers/display/drm/../../../display/../misc/lv_timer.h  lvgl/src/drivers/display/drm/../../../display/../misc/../tick/lv_tick.h  lvgl/src/drivers/display/drm/../../../display/../misc/../tick/../lv_conf_internal.h  lvgl/src/drivers/display/drm/../../../display/../misc/../tick/../misc/lv_types.h  lvgl/src/drivers/display/drm/../../../display/../misc/lv_types.h  lvgl/src/drivers/display/drm/../../../display/../misc/lv_ll.h  lvgl/src/drivers/display/drm/../../../display/../misc/lv_event.h  lvgl/src/drivers/display/drm/../../../display/../misc/lv_array.h  lvgl/src/drivers/display/drm/../../../display/../misc/lv_color.h  lvgl/src/drivers/display/drm/../../../display/../misc/lv_assert.h  lvgl/src/drivers/display/drm/../../../display/../misc/lv_log.h  lvgl/src/drivers/display/drm/../../../display/../misc/../stdlib/lv_mem.h  lvgl/src/drivers/display/drm/../../../display/../misc/../stdlib/../lv_conf_internal.h  lvgl/src/drivers/display/drm/../../../display/../misc/../stdlib/lv_string.h  lvgl/src/drivers/display/drm/../../../display/../misc/../stdlib/../misc/lv_types.h  lvgl/src/drivers/display/drm/../../../display/../misc/lv_math.h  lvgl/src/drivers/display/drm/../../../display/../misc/lv_palette.h  lvgl/src/drivers/display/drm/../../../display/../misc/lv_color.h  lvgl/src/drivers/display/drm/../../../display/../misc/lv_color_op.h  lvgl/src/drivers/display/drm/../../../display/../misc/lv_area.h  /usr/include/drm/drm_fourcc.h  lvgl/src/drivers/display/drm/../../../stdlib/lv_sprintf.h  lvgl/src/drivers/display/drm/../../../stdlib/../misc/lv_types.h  lvgl/src/drivers/display/drm/../../../draw/lv_draw_buf.h  lvgl/src/drivers/display/drm/../../../draw/../misc/lv_types.h  lvgl/src/drivers/display/drm/../../../draw/../misc/lv_area.h  lvgl/src/drivers/display/drm/../../../draw/../misc/lv_color.h  lvgl/src/drivers/display/drm/../../../draw/../stdlib/lv_string.h  lvgl/src/drivers/display/drm/../../../draw/lv_image_dsc.h  lvgl/src/drivers/display/drm/../../../draw/../lv_conf_internal.h\
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