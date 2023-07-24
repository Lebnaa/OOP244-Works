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
#include "Line.h"
//#include "Utils.h"

using namespace std; 

namespace sdds 
{
    // initializes the Line by calling the constructor of the base class
    //LblShape and passes label to the base class constructor.
    Line::Line(const char* label, int length) : LblShape(label)
    {
        if (length > 0)  m_length = length;
    }

    ////Reads comma-separated specs of the Line from istream.
	// Override the base class's getSpecs virtual function
    void Line::getSpecs(std::istream& is)
    {
        int length;
        bool result = false;

        do {
            // read label using base class's getSpecs
            LblShape::getSpecs(is);

            // read the value of the m_length
            is >> length;

            if (!is) {
                is.clear();
                is.ignore(32767, '\n');
            }
            else {
                // ignore The rest of the characters up to and including '\n'
                is.ignore();
                m_length = length;
                result = true;
            }
        } while (!result);
    }

    void Line::draw(std::ostream& os) const
    {
        if (m_length > 0 && LblShape::label()) 
        {
            // draw the label and symbol following the provided format
            os << LblShape::label() << endl;
            os.width(m_length);
            os.fill('=');
            os << '=';
        }
    }
}