/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2013, University of Colorado, Boulder
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Univ of CO, Boulder nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/* Author: Dave Coleman
   Desc:   Tests the rviz_tool
*/

// ROS
#include <ros/ros.h>

// Grasp generation
#include <block_grasp_generator/visualization_tools.h>

// Baxter specific
//static const std::string EE_LINK = "gripper_roll_link";
static const std::string EE_PARENT_LINK = "right_wrist";
static const std::string PLANNING_GROUP_NAME = "right_arm";
static const std::string EE_GROUP = "right_hand";
static const std::string BASE_LINK = "/base";



int main(int argc, char *argv[])
{
  ros::init(argc, argv, "visualization_tool_test");
  ros::AsyncSpinner spinner(1);
  spinner.start();

  ros::NodeHandle nh;
  ros::Duration(1.0).sleep();

  // ---------------------------------------------------------------------------------------------
  // Load the Robot Viz Tools for publishing to Rviz
  ROS_INFO_STREAM_NAMED("temp","Loading visualiztion tools");
  block_grasp_generator::VisualizationToolsPtr visual_tools_;
  visual_tools_.reset(new block_grasp_generator::VisualizationTools( BASE_LINK));
  visual_tools_->setEEGroupName(EE_GROUP);
  visual_tools_->setPlanningGroupName(PLANNING_GROUP_NAME);

  //  ros::Duration(1.0).sleep(); // let rviz markers finish publishing

  ROS_DEBUG_STREAM_NAMED("temp","ending early");
  return 0;
}
