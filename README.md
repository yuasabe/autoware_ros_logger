# Autoware ROS Logger

- Logger helper for Autoware.
- Originally wanted to subscribe to `/perception/objects_recognition/objects` topic and count the number of objects in each message.

## How to use

Log output to file

```
$ ros2 launch autoware_ros_logger autoware_ros_logger.launch.xml > time_series_object_count_sample_rosbag.log
```

Remove beginnings and endings from file and use awk to get appropriate column.
```
$ awk '{print $5}' time_series_object_count_sample_rosbag.log > time_series_object_count_sample_rosbag.csv
```

Analyze csv file