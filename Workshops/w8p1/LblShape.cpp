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
#include "cstring.h"

using namespace std; 

namespace sdds
{
	LblShape::LblShape(const char* label)
	{
		if (label && m_label[0] != '\0')
		{
			m_label = new char(strLen(label) + 1);
			strCpy(m_label, label); 
		}
	}

	const char* LblShape::label()const
	{
		return m_label; 
	}

	LblShape::~LblShape()
	{
		delete[] m_label; 
		m_label = nullptr; 
	}

	void LblShape::getSpecs(std::istream& is)
	{
		string label; 

		//reads untill a ,
		getline(is, label, ',');

		delete[] m_label; 
		//c_str converts a string
		m_label = new char(strLen(label.c_str()) + 1); 
		strCpy(m_label, label.c_str()); 

	}

}