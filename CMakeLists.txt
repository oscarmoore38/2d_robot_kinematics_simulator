cmake_minimum_required(VERSION 3.14)

set(This 2d_robot_kinematics_simulator)

project(${This} C CXX)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(googletest)

find_package(Threads REQUIRED)

add_definitions(-DASIO_STANDALONE)

include_directories(${This} PUBLIC
    ${CMAKE_SOURCE_DIR}/ThirdPartyLib/asio/asio/include
    ${CMAKE_SOURCE_DIR}/ThirdPartyLib/websocketpp
    ${CMAKE_SOURCE_DIR}/ThirdPartyLib/nlohmann
    ${CMAKE_SOURCE_DIR}/src
)

# Automatically gather all source and header files
file(GLOB_RECURSE Sources
    src/*.cpp
)

file(GLOB_RECURSE Headers
    src/*.hpp
)

# Create static library for testing
add_library(${This} STATIC ${Sources} ${Headers})

# Create an executable for main program 
add_executable(robotSimulatorExec ${Sources}) 


# Link your executable to the static library 
target_link_libraries(robotSimulatorExec PRIVATE Threads::Threads)
target_compile_definitions(robotSimulatorExec PRIVATE ASIO_STANDALONE)
target_compile_features(robotSimulatorExec PUBLIC cxx_std_17)

# # Integration Tests
enable_testing()
add_subdirectory(Tests)