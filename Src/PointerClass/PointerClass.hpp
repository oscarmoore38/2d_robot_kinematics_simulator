#ifndef POINTER_HPP
#define POINTER_HPP

/**
 * @class Pointer
 * @brief Represents a 2D coordinate (x, y) in Cartesian space and also handles geometric calculations.
 * 
 */

class Pointer{

private:
    double yCord_; 
    double xCord_; 
public:
    Pointer();

    Pointer(double yCord, double xCord);

    double getXCord_() const; 

    double getYCord_() const; 

    void CalculateIK();

    void CalculateFK(); 
    
};

#endif 