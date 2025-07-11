#include <gtest/gtest.h>
#include <cmath>
#include "../src/RobotArmClass/RobotArmClass.hpp"
#include "../src/PointerClass/PointerClass.hpp"


using namespace std;

class RobotArmTestSuite : public :: testing :: Test {
protected: 
        void SetUp() override {

        }

        void TearDown() override {

        }

};


TEST_F(RobotArmTestSuite, ForwardKinematicsTest){
    // Calculate expected x, y cords using FK equation 
    double l1 = 5.0; 
    double l2 = 3.0;
    double angle1 = 30.0; 
    double angle2 = 60.0; 

    double expectedX = l1 * cos(angle1) + l2 * cos(angle1 + angle2);
    double expectedY = l1 * sin(angle1) + l2 * sin(angle1 + angle2);

    RobotArm robotArm(5.0, 3.0);

    robotArm.setJoint1Position(angle1);
    robotArm.setJoint2Position(angle2);

    // Confirm angles are set properly 
    EXPECT_EQ(angle1, robotArm.getJoint1Position());
    EXPECT_EQ(angle2, robotArm.getJoint2Position());

    // Call FK function 
    Pointer result = robotArm.forwardKinematics(robotArm.getJoint1Position(), robotArm.getJoint2Position());

    // Check x & y
    EXPECT_EQ(result.getxCord(), expectedX);
    EXPECT_EQ(result.getyCord(), expectedY);

    
}