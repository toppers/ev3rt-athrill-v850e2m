#include "ros/ros.h"
#include "std_msgs/String.h"
#include "udp_ros_config.h"
#include "udp_ros_publish.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

static char udp_tx_buffer[UDP_BUFFER_SIZE];

static void do_publish_one(int index) 
{
    std_msgs::String msg;
    if ((udp_tx_buffer[ros_pub_config[index].byteoff] & (1U << ros_pub_config[index].bitoff)) != 0U) {
        msg.data = "bit_on";
    }
    else {
        msg.data = "bit_off";
    }
    ros_pub_config[index].pub.publish(msg);
    return;
}

static void do_publish(void)
{
    int i;

    for (i = 0; i < ROS_PUB_CONFIG_NUM; i++) {
        do_publish_one(i);
    }
    return;
}

void *udp_ros_publish(void* arg)
{
    int sock;
    struct sockaddr_in addr;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(UDP_LOCAL_IPADDR);
    addr.sin_port = htons(UDP_LOCAL_PORTNO);

    int ret = bind(sock, (const struct sockaddr *)&addr, sizeof(addr));
    if (ret < 0) {
        printf("ERROR: udp_ros_publish() bind() error=%d\n", errno);
        return NULL;
    }

    while (true) {
        ssize_t ret = recv(sock, udp_tx_buffer, UDP_BUFFER_SIZE, 0);
        if (ret != UDP_BUFFER_SIZE) {
            continue;
        }
        do_publish();
    }
    return NULL;
}