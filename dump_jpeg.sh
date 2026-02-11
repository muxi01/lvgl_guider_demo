#!/bin/bash
    stty -F /dev/ttyGS0 raw -echo && cat /dev/ttyGS0 > ./usb.desktop.jpeg

