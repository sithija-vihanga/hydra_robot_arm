#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <trajectory_msgs/msg/joint_trajectory.hpp>
#include <trajectory_msgs/msg/joint_trajectory_point.hpp>

#include <chrono>


using namespace std::chrono_literals;
using std::placeholders::_1;

class ControlInterface : public rclcpp::Node
{
public:
  ControlInterface() : Node("control_interface")
  {
    sub_ = create_subscription<sensor_msgs::msg::JointState>(
        "joint_commands", 10, std::bind(&ControlInterface::sliderCallback, this, _1));
    arm_pub_ = create_publisher<trajectory_msgs::msg::JointTrajectory>("arm_controller/joint_trajectory", 10);
    gripper_pub_ = create_publisher<trajectory_msgs::msg::JointTrajectory>("gripper_controller/joint_trajectory", 10);
    RCLCPP_INFO(get_logger(), "Control interface started");
  }

private:
  rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr sub_;
  rclcpp::Publisher<trajectory_msgs::msg::JointTrajectory>::SharedPtr arm_pub_;
  rclcpp::Publisher<trajectory_msgs::msg::JointTrajectory>::SharedPtr gripper_pub_;

  void sliderCallback(const sensor_msgs::msg::JointState &msg) const
  {
    trajectory_msgs::msg::JointTrajectory arm_command, gripper_command;
    arm_command.joint_names = {"joint_0", "joint_1", "joint_2", "joint_3", "joint_4"};
    gripper_command.joint_names = {"joint_5"};

    trajectory_msgs::msg::JointTrajectoryPoint arm_goal, gripper_goal;
    arm_goal.positions.insert(arm_goal.positions.end(), msg.position.begin(), msg.position.begin() + 5);
    gripper_goal.positions.push_back(msg.position.at(5));
    
    arm_command.points.push_back(arm_goal);
    gripper_command.points.push_back(gripper_goal);
    
    arm_pub_->publish(arm_command);
    gripper_pub_->publish(gripper_command);
  }
};


int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<ControlInterface>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}