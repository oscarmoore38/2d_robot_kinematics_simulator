#ifndef ROBOTARM_HPP
#define ROBOTARM_HPP
#include "./PointerClass/PointerClass.hpp"

/**
 * @class RobotArm
 * @brief Represents a 2-DOF Robotic arm. Handles geometric calculations and updates position of arm. 
 * 
 */

class RobotArm{
public:
    RobotArm(double l1, double l2);

    Pointer forwardKinematics(double theta1, double theta2); 

    bool inverseKinematics(const Pointer& targetPosition);

    Pointer getJoint1Position() const; 

    Pointer getEndEffectorPosition() const; 

private: 
    double link1Length;
    double link2Length; 
    double currentTheta1;
    double currentTheta2; 
    
};

#endif 