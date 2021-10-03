# supervisor
システム全体の管理

管理対象は以下のリポジトリ

- [laser_scan_matcher_navigation](https://github.com/TSUKUBA-CHALLENGE/laser_scan_matcher_navigation)  
laser_scan_matcherでodom->base_linkをamclでmap->odomを算出してnavigationを実行
- [obstacle_avoidance](https://github.com/TSUKUBA-CHALLENGE/obstacle_avoidance)  
前方180度の障害物を監視し、閾値を下回った場合、指令値を0にする
