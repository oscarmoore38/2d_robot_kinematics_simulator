#include <iostream>
#include "PointerClass.hpp"

using namespace std;

Pointer:: Pointer() 
    : xCord(0.0), yCord(0.0) {

    };

Pointer:: Pointer(double xCord, double YCord)
    : xCord(xCord), yCord(YCord){
    };

double Pointer:: getxCord() const{
    return xCord; 
}

double Pointer:: getyCord() const{
    return yCord; 
}

void Pointer:: setyCord(double yCord){
    this->yCord = yCord; 
}

void Pointer:: setxCord(double xCord){
    this->xCord = xCord; 
}
