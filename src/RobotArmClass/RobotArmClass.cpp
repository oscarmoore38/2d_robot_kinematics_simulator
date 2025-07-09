#include "RobotArmClass.hpp"
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "./PointerClass/PointerClass.hpp"

using namespace std; 

RobotArm:: RobotArm(double l1, double l2)
    : link1Length(l1), link2Length(l2){

};


bool RobotArm:: inverseKinematics(const Pointer& targetPosition){
    double x1 = targetPosition.getxCord();
    double y1 = targetPosition.getyCord(); 

    // Distance from end point to base
    double D = sqrt(pow(x1, 2) + pow(y1, 2));

    // Check if Distance can be reached 
    if (D > (link1Length + link2Length)){
        return false; 
    }

    // Check if target is too close and arms can't bend tightly enough to reach it
    if (D < (link1Length - link2Length)){
        return false; 
    }

    // Base to target + inner triangle angle. 
    double baseToTargetAngle = atan2(y1, x1);
    double angleA = acos(clamp((pow(link1Length, 2) + pow(D, 2) - pow(link2Length, 2))/(2 * link1Length * D), -1.0, 1.0));

     // Compute Angle of forearm + upper arm, elbow down
    double theta2AngleElbowDown =  acos(clamp((pow(link1Length, 2) + pow(link2Length, 2) - pow(D, 2)) / (2 * link1Length * link2Length), -1.0, 1.0));
    double theta1AngleElbowDown = baseToTargetAngle - angleA; 

    // Compute Angle of forearm + upper arm, elbow up. 
    double theta2AngleElbowUp = -theta2AngleElbowDown;
    double theta1AngleElbowUp = baseToTargetAngle + angleA; 

    // No obstalces in program yet, choose angles based on continuity. 
    double diffDown = pow(theta1AngleElbowDown - currentTheta1, 2) + pow(theta2AngleElbowDown - currentTheta2, 2);
    double diffUp = pow(theta1AngleElbowUp - currentTheta1, 2) + pow(theta2AngleElbowUp - currentTheta2, 2);

    // Choose shortest path
    if (diffDown <= diffUp) {
        currentTheta1 = theta1AngleElbowDown;
        currentTheta2 = theta2AngleElbowDown;
    } else{
        currentTheta1 = theta1AngleElbowUp;
        currentTheta2 = theta2AngleElbowUp;
    }

};

Pointer RobotArm:: forwardKinematics(double theta1, double theta2){
    double x1 = cos(theta1) + cos(theta1 + theta2);
    double y1 = sin(theta1) + sin(theta1 + theta2);

    Pointer endEffectPos = Pointer(x1, y1);

    return endEffectPos; 
};

Pointer RobotArm:: getEndEffectorPosition() const {};

Pointer RobotArm:: getJoint1Position() const {};

