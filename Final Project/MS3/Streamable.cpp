/*****************************************************************************
Lib.h
Full Name : Lebna Noori
Student ID# : 157672205
Email : lnoori1@myseneca.ca
Date of completion : 18 July 2023

I have done all the coding by myself and only copied the code that my 
professor provided to complete my workshops and assignments.*/

#include <iostream>
#include "Streamable.h"
#include "Lib.h"

namespace sdds
{
	//setting the contructor to defult 
	Streamable::~Streamable() {}; 

	std::ostream& operator>>(std::ostream& os, const Streamable& s) 
	{
		//Streamable can be written on an ostream object only if the Streamable object is in a valid state
		//other wise ignore insertation 
		if (s)
		{
			s.write(os); 
		}

		return os; 
	}

	std::istream& operator<<(std::istream& is, Streamable& s) 
	{
		return (s.read(is)); 
	}
}
