#ifndef _UDP_ROS_CALLBACK_H_
#define _UDP_ROS_CALLBACK_H_

#include "ros/ros.h"
#include "std_msgs/String.h"

extern void udp_ros_common_callback(int byteoff, int bitoff, const std_msgs::String::ConstPtr& msg);

#endif /* _UDP_ROS_CALLBACK_H_ */