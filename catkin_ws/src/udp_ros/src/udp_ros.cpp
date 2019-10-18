#include "udp_ros_config.h"
#include "udp_ros_callback.h"
#include "udp_ros_publish.h"
#include <pthread.h>

using namespace ros;


int main(int argc, char **argv)
{
	int i;
	pthread_t thread;

	init(argc, argv, "udp_ros");
	NodeHandle n;
	Subscriber sub;

	for (i = 0; i < ROS_PUB_CONFIG_NUM; i++) {
		ros_pub_config[i].pub = n.advertise<std_msgs::String>(ros_pub_config[i].topic_name, 1);
	}
	for (i = 0; i < ROS_SUB_CONFIG_NUM; i++) {
		ros_sub_config[i].sub = n.subscribe(ros_sub_config[i].topic_name, 1, ros_sub_config[i].subfunc);
	}

    pthread_create(&thread, NULL, udp_ros_publish, (void *)NULL);

	spin();
	return 0;
}
