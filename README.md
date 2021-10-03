# supervisor
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
インホイールモーターからエンコーダ値を取得し、odom(odom->base_link)を
