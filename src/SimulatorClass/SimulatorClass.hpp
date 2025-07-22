#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <asio.hpp>
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
    RobotArm newRoboticArm; 
    server simulatorServer;
    asio::io_context io; 
    
    

private:
    void startServer(); 

    void stopServer(); 

    void handleMessage(const std::string& message); 

    void onOpen(server* s, websocketpp::connection_hdl hdl);

    void onClose(server* s, websocketpp::connection_hdl hdl);


    
};

#endif 