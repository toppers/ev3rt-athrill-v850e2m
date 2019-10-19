#include "udp_ros_callback.h"
#include "udp_ros_config.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

static char udp_rx_buffer[UDP_BUFFER_SIZE];

void udp_ros_common_bits_callback(int byteoff, int bitoff, const std_msgs::String::ConstPtr& msg)
{
    int sock;
    struct sockaddr_in addr;
    //update data
    if (msg->data == "bit_on") {
        udp_rx_buffer[byteoff] |= (1U << bitoff);
    }
    else {
        udp_rx_buffer[byteoff] &= ~(1U << bitoff);
    }
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(UDP_SERVER_IPADDR);
    addr.sin_port = htons(UDP_SERVER_PORTNO);
    ssize_t res = sendto(sock, udp_rx_buffer, UDP_BUFFER_SIZE, 0, (struct sockaddr *)&addr, sizeof(addr));
    if (res != UDP_BUFFER_SIZE) {
        printf("ERROR: udp_ros_common_callback() sendto() error=%d\n", errno);
    }
    return;
}

void udp_ros_common_2byte_callback(int byteoff, int bitoff, const std_msgs::String::ConstPtr& msg)
{
    int sock;
    struct sockaddr_in addr;
    short data = (short)atoi(msg->data.c_str());
    short *p = (short*)&udp_rx_buffer[byteoff];

    *p = data;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(UDP_SERVER_IPADDR);
    addr.sin_port = htons(UDP_SERVER_PORTNO);
    ssize_t res = sendto(sock, udp_rx_buffer, UDP_BUFFER_SIZE, 0, (struct sockaddr *)&addr, sizeof(addr));
    if (res != UDP_BUFFER_SIZE) {
        printf("ERROR: udp_ros_common_callback() sendto() error=%d\n", errno);
    }
    return;
}