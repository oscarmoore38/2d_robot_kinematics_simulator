#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include "RobotArmClass/RobotArmClass.hpp"
#include "SimulatorClass.hpp"

#include <iostream>
#include <string> 

using namespace std; 
using server = websocketpp::server<websocketpp::config::asio>;


void Simulator::startServer(){
    try{
        // Config logging
        simulatorServer.set_access_channels(websocketpp::log::alevel::all);
        simulatorServer.clear_access_channels(websocketpp::log::alevel::frame_payload);

        simulatorServer.init_asio();  

        simulatorServer.set_reuse_addr(true);

        // Take non-static memeber functions and make them regular callable for set_handlers
        simulatorServer.set_open_handler(bind(&onOpen, this, placeholders::_1));
        simulatorServer.set_close_handler(bind(&onClose, this, placeholders::_1));
        simulatorServer.set_message_handler(bind(&onMessage, this, placeholders::_1, placeholders::_2));

        simulatorServer.listen(9002);
        simulatorServer.start_accept();
        simulatorServer.run(); 

    } catch (websocketpp::exception const & e){
        cerr << "Error: " << e.what() << endl; 
    }

    return; 
};

void Simulator:: stopServer(){};
void Simulator:: onOpen(websocketpp::connection_hdl hdl){
    cout << "New connection!" << endl;
};
void Simulator:: onClose(websocketpp::connection_hdl hdl){
    cout << "Connection closed!" << endl;
};
void Simulator::onMessage(websocketpp::connection_hdl hdl, server::message_ptr msg){
    cout << "Received: " << msg->get_payload() << endl;
    simulatorServer.send(hdl, "Echo: " + msg->get_payload(), websocketpp::frame::opcode::text);
};
void Simulator::handleMessage(const std::string& message){};

