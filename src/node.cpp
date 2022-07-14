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
    subscription_ = this->create_subscription<autoware_auto_perception_msgs::msg::PredictedObjects>("/perception/object_recognition/objects", 10, std::bind(&AutowareRosLogger::objectsCallback, this, _1));

    RCLCPP_INFO(get_logger(), "AutowareRosLogger Node Launched");
  }

  void AutowareRosLogger::objectsCallback(const autoware_auto_perception_msgs::msg::PredictedObjects::ConstSharedPtr msg){
    RCLCPP_INFO(get_logger(), "%d.%d,%d",msg->header.stamp.sec, msg->header.stamp.nanosec, static_cast<int>(msg->objects.size()));
  }
}

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(v2x::AutowareRosLogger)