{
    files = {
        "lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_stm32_hal.c"
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
    depfiles = "lv_draw_nema_gfx_stm32_hal.o:  lvgl/src/draw/nema_gfx/lv_draw_nema_gfx_stm32_hal.c  lvgl/src/draw/nema_gfx/../../lv_conf_internal.h  lvgl/src/draw/nema_gfx/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
",
    depfiles_format = "gcc"
}