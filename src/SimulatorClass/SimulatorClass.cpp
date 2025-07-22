#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include "RobotArmClass/RobotArmClass.hpp"
#include "SimulatorClass.hpp"

#include <iostream>
#include <string> 

using namespace std; 


void Simulator::startServer(){
    try{
        // Config logging
        
        simulatorServer.set_access_channels(websocketpp::log::alevel::all);
        simulatorServer.clear_access_channels(websocketpp::log::alevel::frame_payload);

        simulatorServer.init_asio();  

        simulatorServer.set_reuse_addr(true);

        simulatorServer.set_open_handler(&onOpen);
        simulatorServer.set_close_handler(&onClose);
        simulatorServer.set_message_handler(&handleMessage);

    } catch (websocketpp::exception const & e){
        cerr << "Error: " << e.what() << endl; 
    }

    return; 
};

void Simulator:: stopServer(){};

void Simulator:: onOpen(server* s, websocketpp::connection_hdl hdl){};
void Simulator:: onClose(server* s, websocketpp::connection_hdl hdl){};
void Simulator::handleMessage(const std::string& message){};

