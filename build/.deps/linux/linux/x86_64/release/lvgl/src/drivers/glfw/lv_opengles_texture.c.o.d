{
    files = {
        "lvgl/src/drivers/glfw/lv_opengles_texture.c"
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
    depfiles = "lv_opengles_texture.o: lvgl/src/drivers/glfw/lv_opengles_texture.c  lvgl/src/drivers/glfw/lv_opengles_texture.h  lvgl/src/drivers/glfw/../../lv_conf_internal.h  lvgl/src/drivers/glfw/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
"
}