#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include "RobotArmClass/RobotArmClass.hpp"
#include <string> 

using server = websocketpp::server<websocketpp::config::asio>;

/**
 * @class Simulator
 * @brief Manages the GUI, visualizes the RobotArm, and processes user input. 
 * 
 */

class Simulator {
public:
    server simulatorServer;   
    RobotArm RoboticArm; 

    Simulator(); 

    void startServer(); 

    void stopServer(); 

    void handleMessage(const std::string& message, websocketpp::connection_hdl hdl); // For Testing, make private 

private:
    // void handleMessage(const std::string& message); 

    void onOpen(websocketpp::connection_hdl hdl);

    void onClose(websocketpp::connection_hdl hdl);

    void onMessage(websocketpp::connection_hdl hdl, server::message_ptr msg);


    
};

#endif 