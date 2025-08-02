#include "SimulatorClass/SimulatorClass.hpp"
#include <iostream>
#include <string> 

using namespace std; 

int main(int argc, char* argv[]) {

    Simulator newRobotSim; 

    try{
        newRobotSim.startServer();
    } catch(websocketpp:: exception const & e){
        cout << "Server error: " << e.what() << endl; 
    } catch(...){
        cout << "Unknown server error occurred" << endl; 
    }

}