{
    files = {
        "lvgl/src/misc/lv_templ.c"
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
    depfiles = "lv_templ.o: lvgl/src/misc/lv_templ.c\
",
    depfiles_format = "gcc"
}