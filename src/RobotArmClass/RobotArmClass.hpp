#ifndef ROBOTARM_HPP
#define ROBOTARM_HPP

/**
 * @class RobotArm
 * @brief Represents a 2-DOF Robotic arm. Handles geometric calculations and updates position of arm. 
 * 
 */

class RobotArm{
public:
    RobotArm();

private:
    double link1Length;
    double link2Length; 
    double currentTheta1;
    double currentTheta2; 
    
};

#endif 