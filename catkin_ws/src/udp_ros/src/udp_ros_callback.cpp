#include "udp_ros_callback.h"
#include "udp_ros_config.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <vector>

static char udp_rx_buffer[UDP_BUFFER_SIZE];

std::vector<std::string> split(std::string str, char del) {
    int first = 0;
    int last = str.find_first_of(del);
 
    std::vector<std::string> result;
 
    while (first < str.size()) {
        std::string subStr(str, first, last - first);
 
        result.push_back(subStr);
 
        first = last + 1;
        last = str.find_first_of(del, first);
 
        if (last == std::string::npos) {
            last = str.size();
        }
    }
 
    return result;
}

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
    std::string tmp(msg->data);
    std::string str = split(tmp, ':')[1];
    short data = (short)atoi(str.c_str());
    short *p = (short*)&udp_rx_buffer[byteoff];

    *p = data;
    printf("msg=%s off=%d value=%d\n", msg->data.c_str(), byteoff, data);

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

void udp_ros_common_4byte_callback(int byteoff, int bitoff, const std_msgs::String::ConstPtr& msg)
{
    int sock;
    struct sockaddr_in addr;
    std::string tmp(msg->data);
    std::string str = split(tmp, ':')[1];
    short data = (short)atoi(str.c_str());
    int *p = (int*)&udp_rx_buffer[byteoff];

    *p = data;
    printf("msg=%s off=%d value=%d\n", msg->data.c_str(), byteoff, data);

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