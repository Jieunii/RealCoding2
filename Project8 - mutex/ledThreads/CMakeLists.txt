add_executable ( led_main led_main.c led_yellow.c led_green.c )
target_link_libraries ( led_main pthread wiringPi )
