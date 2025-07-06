cmake_minimum_required(VERSION 3.14)

set(This RobotSimTests)

set(Sources
    RobotSimTests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    2d_robot_kinematics_simulator
)

add_test(
    NAME ${This}
    COMMAND ${This}
)