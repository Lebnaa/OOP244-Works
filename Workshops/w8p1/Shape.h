/*
*****************************************************************************
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
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

#include <iostream>

namespace sdds
{
	class Shape
	{
		public:
		virtual ~Shape() {};
		virtual void draw(std::ostream& os) const = 0; 
		virtual void getSpecs(std::istream& is) = 0; 
	};

	std::ostream& operator << (std::ostream& os, const Shape& shape);
	std::istream& operator >> (std::istream& is, Shape &shape); 
}
#endif // !SDDS_SHAPE_H
