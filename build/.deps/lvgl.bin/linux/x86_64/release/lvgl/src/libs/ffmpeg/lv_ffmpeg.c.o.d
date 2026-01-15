{
    files = {
        "lvgl/src/libs/ffmpeg/lv_ffmpeg.c"
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
    depfiles = "lv_ffmpeg.o: lvgl/src/libs/ffmpeg/lv_ffmpeg.c  lvgl/src/libs/ffmpeg/lv_ffmpeg_private.h  lvgl/src/libs/ffmpeg/lv_ffmpeg.h  lvgl/src/libs/ffmpeg/../../lv_conf_internal.h  lvgl/src/libs/ffmpeg/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h\
",
    depfiles_format = "gcc"
}