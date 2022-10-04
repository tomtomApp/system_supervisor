# system_supervisor

管理対象は以下のリポジトリ

- [mobile_robot_simulator](https://github.com/Arcanain/mobile_robot_simulator)  

- [odrive_motor_control](https://github.com/Arcanain/odrive_motor_control)  

- [raspicat_speak](https://github.com/Arcanain/raspicat_speak)  

- [rpi_led_tape](https://github.com/Arcanain/rpi_led_tape) 

- [joy_to_twist](https://github.com/TSUKUBA-CHALLENGE/joy_to_twist)  

- [gnss_imu_odom_ESKF](https://github.com/Arcanain/gnss_imu_odom_ESKF) 

- [nmea_navsat_driver](https://github.com/Arcanain/nmea_navsat_driver) 

- [nmea_msgs](https://github.com/Arcanain/nmea_msgs) 

- [ublox_f9p](https://github.com/Arcanain/ublox_f9p)  

- [wit_node](https://github.com/Arcanain/wit_node)  

Todolist

- [rplidar_ros](https://github.com/Arcanain/rplidar_ros)  

# システム構成

# data collect
## STEP1
```
lsusb
Bus 001 Device 009: ID 1209:0d32 Generic ODrive Robotics ODrive v3
```

```
ls -al /dev/bus//usb//001/009
crw-rw-r-- 1 root root 189, 8 5月 29 14:49 /dev/bus//usb//001/009
```

```
sudo chmod 666 /dev/bus/usb/001/009
```

## STEP2
```
roslaunch system_supervisor collect_path.launch 
```

or

```
roslaunch system_supervisor collect_estimated_path.launch 
```

# navigation方法
## STEP1
```
lsusb
Bus 001 Device 009: ID 1209:0d32 Generic ODrive Robotics ODrive v3
```

```
ls -al /dev/bus//usb//001/009
crw-rw-r-- 1 root root 189, 8 5月 29 14:49 /dev/bus//usb//001/009
```

```
sudo chmod 666 /dev/bus/usb/001/009
```
## STEP2
```
roslaunch system_supervisor navigation.launch 
```
