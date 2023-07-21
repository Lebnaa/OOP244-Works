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

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "LblShape.h"

namespace sdds
{
	class Rectangle : LblShape
	{
		size_t m_width{ 0 }; 
		size_t m_height{ 0 }; 
	public:
		Rectangle() = default;
		Rectangle(int width, int height, const char* label); 
		virtual ~Rectangle() {};

		void getSpecs(std::istream& is);
		
		void draw(std::ostream& os) const; 
	};
}
#endif // !SDDS_RECTANGLE_H
