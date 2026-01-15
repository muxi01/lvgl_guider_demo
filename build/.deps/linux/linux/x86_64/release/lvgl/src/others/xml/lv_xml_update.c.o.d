{
    files = {
        "lvgl/src/others/xml/lv_xml_update.c"
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
    depfiles = "lv_xml_update.o: lvgl/src/others/xml/lv_xml_update.c  lvgl/src/others/xml/lv_xml_update.h  lvgl/src/others/xml/../../misc/lv_types.h  lvgl/src/others/xml/../../misc/../lv_conf_internal.h  lvgl/src/others/xml/../../misc/../lv_conf_kconfig.h  ports/linux/lv_conf.h custom/lv_conf_ext.h\
"
}