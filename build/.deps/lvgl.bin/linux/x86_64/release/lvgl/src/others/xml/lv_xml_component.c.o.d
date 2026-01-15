{
    files = {
        "lvgl/src/others/xml/lv_xml_component.c"
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
    depfiles = "lv_xml_component.o: lvgl/src/others/xml/lv_xml_component.c  lvgl/src/others/xml/lv_xml_component.h  lvgl/src/others/xml/../../misc/lv_types.h  lvgl/src/others/xml/../../misc/../lv_conf_internal.h  lvgl/src/others/xml/../../misc/../lv_conf_kconfig.h  ports/linux/lv_conf.h custom/lv_conf_ext.h\
",
    depfiles_format = "gcc"
}