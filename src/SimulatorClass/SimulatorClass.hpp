#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include "RobotArmClass/RobotArmClass.hpp"

/**
 * @class Simulator
 * @brief Manages the GUI, visualizes the RobotArm, and processes user input. 
 * 
 */

class Simulator {
public:

    RobotArm newRoboticArm; 
    websocketpp::server<websocketpp::config::asio> simulatorServer;

private:
    void startServer(); 

    void stopServer(); 

    void handleMessage(); 
    
};

#endif 