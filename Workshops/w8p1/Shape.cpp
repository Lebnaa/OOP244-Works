/******************************************************************************
							  Workshop - #8 (Part-1)
Full Name  : Lebna Noori
Student ID#: 157672205
Email      : lnoori1@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/
#include <iostream>
#include "Shape.h"

namespace sdds
{
    //Returns void and receives a reference to ostream as an argument. 
    //pure virtual func
    std::ostream& operator<<(std::ostream& os, const Shape& shape)
    {
        shape.draw(os);

        return os;  
    }

    //Returns void and receives a reference to istream as an argument.
    std::istream& operator >> (std::istream& is, Shape& shape)
    {
        shape.getSpecs(is);

        return is;
    }
}