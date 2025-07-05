#include <iostream>
#include "PointerClass.hpp"

using namespace std;

Pointer:: Pointer() 
    : xCord_(0.0), yCord_(0.0) {

    };

Pointer:: Pointer(double xCord, double YCord)
    : xCord_(xCord), yCord_(YCord){

    };

double Pointer:: getXCord_() const{
    return xCord_; 
}

double Pointer:: getYCord_() const{
    return yCord_; 
}

void Pointer:: CalculateFK(){};

void Pointer:: CalculateIK(){};




