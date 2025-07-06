#ifndef POINTER_HPP
#define POINTER_HPP

/**
 * @class Pointer
 * @brief Represents 2D coordinates (x, y) in Cartesian space.
 * 
 */

class Pointer{

private:
    double yCord; 
    double xCord; 
public:
    Pointer();

    Pointer(double yCord, double xCord);

    double getxCord() const; 

    double getyCord() const; 

    
};

#endif 