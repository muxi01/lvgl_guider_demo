{
    files = {
        "lvgl/src/stdlib/uefi/lv_mem_core_uefi.c"
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
    depfiles = "lv_mem_core_uefi.o: lvgl/src/stdlib/uefi/lv_mem_core_uefi.c  lvgl/src/stdlib/uefi/../lv_mem.h  lvgl/src/stdlib/uefi/../../lv_conf_internal.h  lvgl/src/stdlib/uefi/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h lvgl/src/stdlib/uefi/../lv_string.h  lvgl/src/stdlib/uefi/../../misc/lv_types.h  lvgl/src/stdlib/uefi/../../misc/../lv_conf_internal.h\
"
}