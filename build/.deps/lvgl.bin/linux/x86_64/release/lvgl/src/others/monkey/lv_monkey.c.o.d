{
    files = {
        "lvgl/src/others/monkey/lv_monkey.c"
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
    depfiles = "lv_monkey.o: lvgl/src/others/monkey/lv_monkey.c  lvgl/src/others/monkey/lv_monkey_private.h  lvgl/src/others/monkey/lv_monkey.h  lvgl/src/others/monkey/../../lv_conf_internal.h  lvgl/src/others/monkey/../../lv_conf_kconfig.h ports/linux/lv_conf.h  custom/lv_conf_ext.h lvgl/src/others/monkey/../../indev/lv_indev.h  lvgl/src/others/monkey/../../indev/../core/lv_group.h  lvgl/src/others/monkey/../../indev/../core/../lv_conf_internal.h  lvgl/src/others/monkey/../../indev/../core/../misc/lv_types.h  lvgl/src/others/monkey/../../indev/../core/../misc/../lv_conf_internal.h  lvgl/src/others/monkey/../../indev/../core/../misc/lv_ll.h  lvgl/src/others/monkey/../../indev/../core/../misc/lv_types.h  lvgl/src/others/monkey/../../indev/../misc/lv_area.h  lvgl/src/others/monkey/../../indev/../misc/../lv_conf_internal.h  lvgl/src/others/monkey/../../indev/../misc/lv_types.h  lvgl/src/others/monkey/../../indev/../misc/lv_math.h  lvgl/src/others/monkey/../../indev/../misc/lv_timer.h  lvgl/src/others/monkey/../../indev/../misc/../tick/lv_tick.h  lvgl/src/others/monkey/../../indev/../misc/../tick/../lv_conf_internal.h  lvgl/src/others/monkey/../../indev/../misc/../tick/../misc/lv_types.h  lvgl/src/others/monkey/../../indev/../misc/lv_ll.h  lvgl/src/others/monkey/../../indev/../misc/lv_event.h  lvgl/src/others/monkey/../../indev/../misc/lv_array.h\
",
    depfiles_format = "gcc"
}