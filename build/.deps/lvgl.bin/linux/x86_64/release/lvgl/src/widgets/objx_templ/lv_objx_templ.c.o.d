{
    files = {
        "lvgl/src/widgets/objx_templ/lv_objx_templ.c"
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
    depfiles = "lv_objx_templ.o: lvgl/src/widgets/objx_templ/lv_objx_templ.c\
",
    depfiles_format = "gcc"
}