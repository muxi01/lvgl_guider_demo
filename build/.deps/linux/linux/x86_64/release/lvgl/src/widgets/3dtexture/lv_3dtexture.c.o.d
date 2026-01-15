{
    files = {
        "lvgl/src/widgets/3dtexture/lv_3dtexture.c"
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
    depfiles = "lv_3dtexture.o: lvgl/src/widgets/3dtexture/lv_3dtexture.c  lvgl/src/widgets/3dtexture/lv_3dtexture_private.h  lvgl/src/widgets/3dtexture/lv_3dtexture.h  lvgl/src/widgets/3dtexture/../../lv_conf_internal.h  lvgl/src/widgets/3dtexture/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
"
}