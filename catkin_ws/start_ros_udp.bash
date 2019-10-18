#!/bin/bash

roslaunch rosbridge_server rosbridge_websocket.launch &
sleep 15

rosrun udp_ros udp_ros

