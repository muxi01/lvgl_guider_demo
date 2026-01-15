{
    files = {
        "lvgl/src/others/xml/lv_xml_utils.c"
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
    depfiles = "lv_xml_utils.o: lvgl/src/others/xml/lv_xml_utils.c  lvgl/src/others/xml/lv_xml_utils.h  lvgl/src/others/xml/../../lv_conf_internal.h  lvgl/src/others/xml/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h lvgl/src/others/xml/../../stdlib/lv_string.h  lvgl/src/others/xml/../../stdlib/../lv_conf_internal.h  lvgl/src/others/xml/../../stdlib/../misc/lv_types.h  lvgl/src/others/xml/../../stdlib/../misc/../lv_conf_internal.h\
",
    depfiles_format = "gcc"
}