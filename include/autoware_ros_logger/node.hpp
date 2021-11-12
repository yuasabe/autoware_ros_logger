#ifndef AutowareRosLogger_NODE_HPP_EUIC2VFR
#define AutowareRosLogger_NODE_HPP_EUIC2VFR

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "autoware_perception_msgs/msg/dynamic_object_array.hpp"
#include "tf2_msgs/msg/tf_message.hpp"

namespace v2x
{
  class AutowareRosLogger : public rclcpp::Node
  {
  public:
    explicit AutowareRosLogger(const rclcpp::NodeOptions &node_options);

  private:
    void objectsCallback(
        const autoware_perception_msgs::msg::DynamicObjectArray::ConstSharedPtr msg);

    rclcpp::Subscription<autoware_perception_msgs::msg::DynamicObjectArray>::SharedPtr subscription_;
    // rclcpp::Publisher<autoware_perception_msgs::msg::DynamicObjectArray>::SharedPtr publisher_;
  };
}

#endif