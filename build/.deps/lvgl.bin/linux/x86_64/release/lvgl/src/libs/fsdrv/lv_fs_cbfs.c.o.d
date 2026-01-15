{
    files = {
        "lvgl/src/libs/fsdrv/lv_fs_cbfs.c"
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
    depfiles = "lv_fs_cbfs.o: lvgl/src/libs/fsdrv/lv_fs_cbfs.c\
",
    depfiles_format = "gcc"
}