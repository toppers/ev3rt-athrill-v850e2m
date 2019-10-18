#include "udp_ros_config.h"
#include "udp_ros_callback.h"
#include "ev3_vdev_common.h"

RosPubConfigType ros_pub_config[ROS_PUB_CONFIG_NUM] = {
    { .topic_name = "led_LED1", .byteoff = EV3_GPIO_LED_OFF, .bitoff = EV3_GPIO_LED_BITS_RED },
    { .topic_name = "led_LED2", .byteoff = EV3_GPIO_LED_OFF, .bitoff = EV3_GPIO_LED_BITS_GREEN },
};

static void ros_sub_push_btn_L(const std_msgs::String::ConstPtr& msg);
static void ros_sub_push_btn_R(const std_msgs::String::ConstPtr& msg);
static void ros_sub_push_btn_U(const std_msgs::String::ConstPtr& msg);
static void ros_sub_push_btn_D(const std_msgs::String::ConstPtr& msg);
static void ros_sub_push_btn_E(const std_msgs::String::ConstPtr& msg);
static void ros_sub_push_btn_B(const std_msgs::String::ConstPtr& msg);

RosSubConfigType ros_sub_config[ROS_SUB_CONFIG_NUM] = {
    { .topic_name = "push_btn_L", .subfunc = ros_sub_push_btn_L },
    { .topic_name = "push_btn_R", .subfunc = ros_sub_push_btn_R },
    { .topic_name = "push_btn_U", .subfunc = ros_sub_push_btn_U },
    { .topic_name = "push_btn_D", .subfunc = ros_sub_push_btn_D },
    { .topic_name = "push_btn_E", .subfunc = ros_sub_push_btn_E },
    { .topic_name = "push_btn_B", .subfunc = ros_sub_push_btn_E },
};

static void ros_sub_push_btn_L(const std_msgs::String::ConstPtr& msg)
{
    udp_ros_common_callback(EV3_GPIO_BTN_OFF, EV3_GPIO_BTN_BITS_LEFT, msg);
    return;
}
static void ros_sub_push_btn_R(const std_msgs::String::ConstPtr& msg)
{
    udp_ros_common_callback(EV3_GPIO_BTN_OFF, EV3_GPIO_BTN_BITS_RIGHT, msg);
    return;
}
static void ros_sub_push_btn_U(const std_msgs::String::ConstPtr& msg)
{
    udp_ros_common_callback(EV3_GPIO_BTN_OFF, EV3_GPIO_BTN_BITS_UP, msg);
    return;
}
static void ros_sub_push_btn_D(const std_msgs::String::ConstPtr& msg)
{
    udp_ros_common_callback(EV3_GPIO_BTN_OFF, EV3_GPIO_BTN_BITS_DOWN, msg);
    return;
}
static void ros_sub_push_btn_E(const std_msgs::String::ConstPtr& msg)
{
    udp_ros_common_callback(EV3_GPIO_BTN_OFF, EV3_GPIO_BTN_BITS_ENTER, msg);
    return;
}
static void ros_sub_push_btn_B(const std_msgs::String::ConstPtr& msg)
{
    udp_ros_common_callback(EV3_GPIO_BTN_OFF, EV3_GPIO_BTN_BITS_BACK, msg);
    return;
}
