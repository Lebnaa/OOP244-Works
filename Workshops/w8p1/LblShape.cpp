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
#include <iostream> 
#include <string>
#include "LblShape.h"
#include "Utils.h"
//#include "cstring.h"

using namespace std; 

namespace sdds
{
	//Allocates memory large enough to hold the 
	//Cstring argument pointed by the m_label member variable
	LblShape::LblShape(const char* label)
	{

		alloCopy(m_label, label); 
	}

	//returns const value of m_label member variabl
	const char* LblShape::label() const
	{
		return m_label; 
	}

	LblShape::~LblShape()
	{
		delete[] m_label; 
		m_label = nullptr; 
	}

	//Override the Shape::getSpecs func to receive a Cstring from istream up to the ','
	void LblShape::getSpecs(std::istream& is)
	{
		string label; 

		//reads untill a ,
		getline(is, label, ',');

		//c_str converts a string into int 
		alloCopy(m_label, label.c_str()); 
	}

}