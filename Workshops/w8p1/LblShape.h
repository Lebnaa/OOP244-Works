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

#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include "Shape.h"

namespace sdds
{
	class LblShape : public Shape
	{
		char* m_label{};
	protected:
		//returns the unmodifiable value of m_label member variabl
		const char* label() const; 
	public:
		LblShape() = default; 
		//Allocates memory large enough to hold the incoming 
		//Cstring argument pointed by the m_label member variable
		LblShape(const char* label); 
		virtual ~LblShape();

		//to not copy 
		LblShape(const LblShape& src) = delete; 
		LblShape& operator=(const LblShape& src) = delete; 

		//Override the Shape::getSpecs pure virtual function to receive a Cstring (a label) from istream
		void getSpecs(std::istream& is) override;

	};
}
#endif // !SDDS_LBLSHAPE_H
