#ifndef AutowareRosLogger_NODE_HPP_EUIC2VFR
#define AutowareRosLogger_NODE_HPP_EUIC2VFR

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "autoware_auto_perception_msgs/msg/predicted_objects.hpp"
#include "tf2_msgs/msg/tf_message.hpp"

namespace v2x
{
  class AutowareRosLogger : public rclcpp::Node
  {
  public:
    explicit AutowareRosLogger(const rclcpp::NodeOptions &node_options);

  private:
    void objectsCallback(
        const autoware_auto_perception_msgs::msg::PredictedObjects::ConstSharedPtr msg);

    rclcpp::Subscription<autoware_auto_perception_msgs::msg::PredictedObjects>::SharedPtr subscription_;
  };
}

#endif