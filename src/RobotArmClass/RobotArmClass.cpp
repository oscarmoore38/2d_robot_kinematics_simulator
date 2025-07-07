#include "RobotArmClass.hpp"
#include <string>
#include <iostream>

using namespace std; 

RobotArm:: RobotArm(){};


bool RobotArm:: inverseKinematics(const Pointer& targetPosition){};

Pointer RobotArm:: forwardKinematics(double theta1, double theta2){};

Pointer RobotArm:: getEndEffectorPosition() const {};

Pointer RobotArm:: getJoint1Position() const {};

