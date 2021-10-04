# system_supervisor
システム全体の管理

管理対象は以下のリポジトリ

- [laser_scan_matcher_navigation](https://github.com/TSUKUBA-CHALLENGE/laser_scan_matcher_navigation)  
laser_scan_matcherでodom->base_linkをamclでmap->odomを算出してnavigationを実行
- [obstacle_avoidance](https://github.com/TSUKUBA-CHALLENGE/obstacle_avoidance)  
前方180度の障害物を監視し、閾値を下回った場合、指令値を0にする

今後管理予定のリポジトリ

- [joy_to_twist](https://github.com/TSUKUBA-CHALLENGE/joy_to_twist)  
PS4コントローラーでロボットの操縦を行う。自律移動以外の区間で使用

- [map_switching](https://github.com/TSUKUBA-CHALLENGE/map_switching)  
ロボットの現在位置(map->base_link)とwaypointを基にmapを切り替える

- [odrive_odometry](https://github.com/TSUKUBA-CHALLENGE/odrive_odometry)  
インホイールモーターからエンコーダ値を取得し、odom(odom->base_link)をpublish

- [sensor_fusion](https://github.com/TSUKUBA-CHALLENGE/sensor_fusion)  
robot_localizationを使用して、odom->base_link, map->base_link間の移動量推定をimu, odom, gpsから推定

- [gps_waypoint_navigation](https://github.com/TSUKUBA-CHALLENGE/gps_waypoint_navigation)  
事前に設定したwaypoint(緯度、経度)をUTM座標、map座標系に変換してgoalとして順にpublish

- [cirkit_waypoint_manager](https://github.com/TSUKUBA-CHALLENGE/cirkit_waypoint_manager)  
事前に設定したwaypoint(map->base_link)をgoalとして順にpublish

- [ira_laser_tools](https://github.com/TSUKUBA-CHALLENGE/ira_laser_tools)  
複数のlidarの/scan情報を統合

- [adi_driver](https://github.com/TSUKUBA-CHALLENGE/adi_driver)  
ADIS16470から、/imu/data (sensor_msgs/Imu)を取得

- [urg_node](https://github.com/TSUKUBA-CHALLENGE/urg_node)  
北陽lidarから/scanデータを取得

- [rplidar_ros](https://github.com/TSUKUBA-CHALLENGE/rplidar_ros)  
rplidarから/scanデータを取得

- [ublox_f9p](https://github.com/TSUKUBA-CHALLENGE/ublox_f9p)  
ZED-F9Pからgpsデータを取得

# システム構成

- sensor_fusion  
odrive_odometry, adi_driver, ublox_gpsパッケージを使用

- ira_laser_tools  
rplidar_ros, urg_nodeを使用

- 独立パッケージ  
joy_to_twist, map_switching, gps_waypoint_navigation, cirkit_waypoint_manager

# navigation方法
現時点で以下の2種類

- cirkit_waypoint_managerをベースとしたnavigation
- gps_waypoint_navigationをベースとしたnavigation

最終的に実用性のある方を採用

# 参考資料

- robot_localization

http://docs.ros.org/en/melodic/api/robot_localization/html/integrating_gps.html

- gps関連

https://github.com/ros-agriculture/ublox_f9p

https://github.com/hrjp/kcctgnss/blob/main/launch/gnss.launch

https://github.com/swri-robotics/gps_umd
