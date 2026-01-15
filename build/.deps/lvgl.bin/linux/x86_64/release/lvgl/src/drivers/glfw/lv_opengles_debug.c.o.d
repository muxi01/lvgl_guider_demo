{
    files = {
        "lvgl/src/drivers/glfw/lv_opengles_debug.c"
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
    depfiles = "lv_opengles_debug.o: lvgl/src/drivers/glfw/lv_opengles_debug.c  lvgl/src/drivers/glfw/lv_opengles_debug.h  lvgl/src/drivers/glfw/../../lv_conf_internal.h  lvgl/src/drivers/glfw/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
",
    depfiles_format = "gcc"
}