
#include "RobotArmClass/RobotArmClass.hpp"
#include "SimulatorClass.hpp"
#include "PointerClass/PointerClass.hpp"
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <typeinfo>
#include <nlohmann/json.hpp>
#include <iostream>
#include <string> 
#include <functional> 

using namespace std; 
using server = websocketpp::server<websocketpp::config::asio>;
using json = nlohmann::json;

Simulator::Simulator(){
    RobotArm RoboticArm;
} 

void Simulator::startServer(){
    try{ 
        // Config logging
        simulatorServer.set_access_channels(websocketpp::log::alevel::all);
        simulatorServer.clear_access_channels(websocketpp::log::alevel::frame_payload);

        simulatorServer.init_asio();  
        simulatorServer.set_reuse_addr(true);

        // Using bind to take non-static member functions and make them regular callables for set_handlers
        simulatorServer.set_open_handler(std::bind(&Simulator::onOpen, this, placeholders::_1));
        simulatorServer.set_close_handler(std::bind(&Simulator::onClose, this, placeholders::_1));
        simulatorServer.set_message_handler(std::bind(&Simulator::onMessage, this, placeholders::_1, placeholders::_2));

        simulatorServer.listen(9002);
        simulatorServer.start_accept();

        cout << "Starting server on port 9002" << endl; // TEST, remove later. 
        
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
    
    handleMessage(msg->get_payload(), hdl);
};

void Simulator::handleMessage(const std::string& message, websocketpp::connection_hdl hdl){
    string returnMsg; 
    string extractedMsgType; 
    string extractedValue1;
    string extractedValue2; 
    double value1 = 0.0; 
    double value2 = 0.0; 
    
    //Parse message 
    try{
        //Type of message
        size_t msgTypePOS = message.find(":");
        size_t msgTypeEndPOS = message.find(",");
        extractedMsgType = message.substr(msgTypePOS+1, (msgTypeEndPOS - msgTypePOS - 1));
        
        // value 1 
        string values1 = message.substr(msgTypeEndPOS+1);
        size_t value1StartPOS = values1.find(":");
        size_t value1EndPOS = values1.find(",");
        extractedValue1 = values1.substr(value1StartPOS+1, (value1EndPOS - value1StartPOS - 1));
        value1 = stod(extractedValue1);

        // value 2
        string values2 = values1.substr(value1EndPOS+1);
        size_t values2StartPOS = values2.find(":");
        size_t value2EndPOS = values2.find("}");
        extractedValue2 = values2.substr(values2StartPOS+1, (value2EndPOS - values2StartPOS - 1));
        value2 = stod(extractedValue2);

    } catch(exception const& e){
        cerr << "Error parsing message payload: " << e.what() << endl; 
    }

    if (extractedMsgType == "joint_angles"){
        Pointer newCords = RoboticArm.forwardKinematics(value1, value2);
    } else if (extractedMsgType == "link_lengths"){
        RoboticArm.setLinkLength1(value1);
        RoboticArm.setLinkLength2(value2);
    }else {
        Pointer IkCords(value1, value2);
        RoboticArm.inverseKinematics(IkCords)

    }

    double updatedTheta1 = RoboticArm.getJoint1Position(); 
    double updatedTheta2 = RoboticArm.getJoint2Position(); 
    double xCord = newCords.getxCord(); 
    double yCord = newCords.getyCord(); 
    double link1 = RoboticArm.getLinkLength1(); 
    double link2 = RoboticArm.getLinkLength2();  

    json payload = {
        {"theta1", updatedTheta1},
        {"theta2", updatedTheta2}, 
        {"endx", xCord},
        {"endy", yCord},
        {"link1", link1},
        {"link2", link2},
    };

    string jsonString = payload.dump(); 
    simulatorServer.send(hdl, jsonString, websocketpp::frame::opcode::text);
   
    return; 
};

