/*****************************************************************************
Lib.h
Full Name : Lebna Noori
Student ID# : 157672205
Email : lnoori1@myseneca.ca
Date of completion : 18 July 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* ****************************************************************************/
#ifndef SDDS_STREAMABLE_H
#define SDDS_STREAMABLE_H

#include <iostream>

namespace sdds {
	class Streamable
	{
	public:
		//write receives and returns a reference of an ostream object.
		virtual std::ostream& write(std::ostream& os) const = 0;

		//read receives and returns a reference of an istream object.
		virtual std::istream& read(std::istream& is) const = 0; 

		//conIo receives a reference of an ios object and returns a Boolean.
		virtual bool conIo(std::ios& io) const = 0; 

		//Boolean conversion overloads of this method will return if the Streamable object is in a valid state or not.
		virtual operator bool() const = 0; 

		//empty virtual destructor to this interface to guaranty no leak.
		virtual ~Streamable(); 

	};

	std::ostream& operator >> (std::ostream& os, const Streamable& s); 
	std::istream& operator <<(std::istream& is, Streamable& s); 

}
#endif // !SDDS_STREAMABLE_H
