#ifndef ROBOTARM_HPP
#define ROBOTARM_HPP
#include "../PointerClass/PointerClass.hpp"

/**
 * @class RobotArm
 * @brief Represents a 2-DOF Robotic arm. Handles geometric calculations and updates position of arm. 
 * 
 */

class RobotArm{
public:
    RobotArm(double l1, double l2);

    RobotArm(); 

    Pointer forwardKinematics(double theta1, double theta2); 

    bool inverseKinematics(const Pointer& targetPosition);

    double getJoint1Position() const; 

    double getJoint2Position() const; 

    Pointer getEndEffectorPosition() const; 

    void setJoint1Position(double theta1); 

    void setJoint2Position(double theta2); 

    void setLinkLength1(double linkLength1);

    void setLinkLength2(double linkLength2);

    double getLinkLength1();

    double getLinkLength2();

private: 
    double link1Length;
    double link2Length; 
    double currentTheta1;
    double currentTheta2; 
    Pointer currentCoords;
};

#endif 