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

#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"

namespace sdds
{
	class Line : LblShape
	{
		unsigned int m_length{ 0 };
	public:
		Line() = default;
		Line(const char* label, int length); 
		virtual ~Line() {};

		//Reads comma-separated specs of the Line from istream.
		void getSpecs(std::istream& istrm); 

		//This function overrides the draw function of the base class.
		void draw(std::ostream& os) const; 
	};
}
#endif // !SDDS_LINE_H
