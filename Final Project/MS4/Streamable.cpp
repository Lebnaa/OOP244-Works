/*
*****************************************************************************
Lib.h
Full Name : Lebna Noori
Student ID# : 157672205
Email : lnoori1@myseneca.ca
Date of completion : 18 July 2023

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments,  with using Fardad's Utils files and.*/

#include "Streamable.h"

namespace sdds 
{
    // Insertion and Extraction operator overloads
    std::ostream& operator<<(std::ostream& os, const Streamable& s)
    {
        // Object of type Streamable can be written on an ostream object only if the Streamable object is in a valid state
        if (s) {
            s.write(os);
        }
        return os;
    }

    std::istream& operator>>(std::istream& is, Streamable& s)
    {
        return (s.read(is));
    }
}