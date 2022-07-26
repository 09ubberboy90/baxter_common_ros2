#include <baxter_bridge/solve_ik.h>
#include <baxter_bridge/bridge_1to2.h>
#include <baxter_bridge/topic_poller.h>
#include <rclcpp/rclcpp.hpp>

using namespace baxter_bridge;

int main(int argc, char** argv)
{
  if(!Bridge::init(argc, argv))
    return 0;

  std::unique_ptr<TopicPoller> poller;
  if(Bridge::onBaxter())
  {
    RCLCPP_INFO(Bridge::ros2()->get_logger(), "Connected to real Baxter");
    // other cheap bridges we are usually interested in
    // makes it easier to spawn in RViz2 if they are advertized in ROS 2
    Factory::createBridge("/robot/range/left_hand_range/state");
    Factory::createBridge("/robot/range/right_hand_range/state");
    Factory::createBridge("/robot/sonar/head_sonar/state");

    Factory::createBridge("/robot/end_effector/left_gripper/command");
    Factory::createBridge("/robot/end_effector/left_gripper/properties");
    Factory::createBridge("/robot/end_effector/left_gripper/rsdk/set_properties");
    Factory::createBridge("/robot/end_effector/left_gripper/rsdk/set_state");
    Factory::createBridge("/robot/end_effector/left_gripper/state");



    Factory::createBridge("/robot/end_effector/right_gripper/command");
    Factory::createBridge("/robot/end_effector/right_gripper/properties");
    Factory::createBridge("/robot/end_effector/right_gripper/rsdk/set_properties");
    Factory::createBridge("/robot/end_effector/right_gripper/rsdk/set_state");
    Factory::createBridge("/robot/end_effector/right_gripper/state");

    if(Bridge::isStatic())
      Factory::createRemainingBridges();
    else
      poller = std::make_unique<TopicPoller>(Bridge::ros2());
  }
  else
  {
    RCLCPP_WARN(Bridge::ros2()->get_logger(), "Not connected to real Baxter");
  }

  // basic command and inverse kinematics for both arms
  SolveIK left("left"), right("right");
  // we always like to have joint states
  Factory::createBridge("/robot/joint_states");

  ros::AsyncSpinner async(1);
  async.start();

  while(ros::ok() && rclcpp::ok())
  {
    Bridge::spinOnce();

    // create new bridges if needed
    if(poller)
    {
      for(const auto &topic: poller->pendingBridges())
        Factory::createBridge(topic);
    }
  }
}
