cmd_/home/pi/user_dev/cpp/ldt/DALI/modules.order := {   echo /home/pi/user_dev/cpp/ldt/DALI/RPi_DALI_drv.ko; :; } | awk '!x[$$0]++' - > /home/pi/user_dev/cpp/ldt/DALI/modules.order
