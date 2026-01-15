{
    files = {
        "lvgl/src/drivers/glfw/lv_opengles_driver.c"
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
    depfiles = "lv_opengles_driver.o: lvgl/src/drivers/glfw/lv_opengles_driver.c  lvgl/src/drivers/glfw/../../display/lv_display.h  lvgl/src/drivers/glfw/../../display/../misc/lv_types.h  lvgl/src/drivers/glfw/../../display/../misc/../lv_conf_internal.h  lvgl/src/drivers/glfw/../../display/../misc/../lv_conf_kconfig.h  ports/linux/lv_conf.h custom/lv_conf_ext.h  lvgl/src/drivers/glfw/../../display/../misc/lv_timer.h  lvgl/src/drivers/glfw/../../display/../misc/../tick/lv_tick.h  lvgl/src/drivers/glfw/../../display/../misc/../tick/../lv_conf_internal.h  lvgl/src/drivers/glfw/../../display/../misc/../tick/../misc/lv_types.h  lvgl/src/drivers/glfw/../../display/../misc/lv_types.h  lvgl/src/drivers/glfw/../../display/../misc/lv_ll.h  lvgl/src/drivers/glfw/../../display/../misc/lv_event.h  lvgl/src/drivers/glfw/../../display/../misc/lv_array.h  lvgl/src/drivers/glfw/../../display/../misc/lv_color.h  lvgl/src/drivers/glfw/../../display/../misc/lv_assert.h  lvgl/src/drivers/glfw/../../display/../misc/lv_log.h  lvgl/src/drivers/glfw/../../display/../misc/../stdlib/lv_mem.h  lvgl/src/drivers/glfw/../../display/../misc/../stdlib/../lv_conf_internal.h  lvgl/src/drivers/glfw/../../display/../misc/../stdlib/lv_string.h  lvgl/src/drivers/glfw/../../display/../misc/../stdlib/../misc/lv_types.h  lvgl/src/drivers/glfw/../../display/../misc/lv_math.h  lvgl/src/drivers/glfw/../../display/../misc/lv_palette.h  lvgl/src/drivers/glfw/../../display/../misc/lv_color.h  lvgl/src/drivers/glfw/../../display/../misc/lv_color_op.h  lvgl/src/drivers/glfw/../../display/../misc/lv_area.h  lvgl/src/drivers/glfw/../../misc/lv_area_private.h  lvgl/src/drivers/glfw/../../misc/lv_area.h\
",
    depfiles_format = "gcc"
}