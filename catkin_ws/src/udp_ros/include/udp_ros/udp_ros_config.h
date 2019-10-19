#ifndef _UDP_ROS_CONFIG_H_
#define _UDP_ROS_CONFIG_H_

#include "ros/ros.h"
#include "std_msgs/String.h"

using namespace ros;

#define UDP_BUFFER_SIZE		4096U

typedef struct {
	const char *topic_name;
	int byteoff;
	int bitoff;
	Publisher pub;
} RosPubConfigType;

typedef struct {
	const char *topic_name;
	void (*subfunc) (const std_msgs::String::ConstPtr& msg);
	Subscriber sub;
} RosSubConfigType;

#define ROS_PUB_CONFIG_NUM  2U
#define ROS_SUB_CONFIG_NUM  (6U + 28U)


#define UDP_SERVER_IPADDR	"127.0.0.1"
#define UDP_SERVER_PORTNO	4002
#define UDP_LOCAL_IPADDR	"127.0.0.1"
#define UDP_LOCAL_PORTNO	4001

extern RosPubConfigType ros_pub_config[ROS_PUB_CONFIG_NUM];
extern RosSubConfigType ros_sub_config[ROS_SUB_CONFIG_NUM];

#endif /* _UDP_ROS_CONFIG_H_ */