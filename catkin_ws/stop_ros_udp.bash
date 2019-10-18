#!/bin/bash

ps aux | grep ros | grep -v grep | grep -v stop_ros_udp | awk '{print $2}' | xargs kill -9 
