#include "autoware_ros_logger/node.hpp"

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include <sstream>
#include <memory>

using namespace std::chrono;

namespace v2x
{
  AutowareRosLogger::AutowareRosLogger(const rclcpp::NodeOptions &node_options) : rclcpp::Node("autoware_ros_logger", node_options)
  {
    using std::placeholders::_1;
    subscription_ = this->create_subscription<autoware_perception_msgs::msg::DynamicObjectArray>("/perception/object_recognition/objects", 10, std::bind(&AutowareRosLogger::objectsCallback, this, _1));

    // publisher_ = create_publisher<autoware_perception_msgs::msg::DynamicObjectArray>("/perception/object_recognition/objects", rclcpp::QoS{10});

    RCLCPP_INFO(get_logger(), "AutowareRosLogger Node Launched");
  }

  void AutowareRosLogger::objectsCallback(const autoware_perception_msgs::msg::DynamicObjectArray::ConstSharedPtr msg)
  {
    // if (msg->objects.size() > 0) {
    //   for (auto obj : msg->objects) {

    //   }
    // } else {

    // }
    RCLCPP_INFO(get_logger(), "%d.%d,%d",msg->header.stamp.sec, msg->header.stamp.nanosec, static_cast<int>(msg->objects.size()));
  }
}

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(v2x::AutowareRosLogger)