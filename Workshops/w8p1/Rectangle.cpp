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
#include <cstring>
//#include "Utils.h"
#include "Rectangle.h"

using namespace std; 

namespace sdds
{
    Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label)
    {
        //calcultaed based on the length of the label of the LblShape class.
        int compareWidth = strlen(LblShape::label()) + 2;

        // if not meet the condition, rectangle will be set to empty
        if (width > compareWidth && height > 3)
        {
            m_width = width;
            m_height = height;
        }
    }


    //Reads comma-separated specs of the Rectangle from istream.
    //This function overrides the getSpecs function of the base class.
    void Rectangle::getSpecs(std::istream& istr)
    {
        int width, height;
        char comma;
        bool result = false;

        do {
            // read the label by using base class's getSpecs
            LblShape::getSpecs(istr);

            // read the value of the m_width and the comma and the value of the m_height
            istr >> width >> comma >> height;

            if (!istr) {
                istr.clear();
                istr.ignore(3000, '\n');
            }
            else {
                // it will ignore The rest of the characters up to and including '\n'
                istr.ignore();
                m_width = width;
                m_height = height;
                result = true;
            }
        } while (!result);
    }

    //Returns void and receives a reference to ostream as an argument.
    //This function overrides the getSpecs function of the base class.
    void Rectangle::draw(std::ostream& os) const
    {
        if (m_width > 0 && m_height >> 0) 
        {
            // first line
            os << '+';
            os.width(m_width - 2);
            os.fill('-');
            os << '-' << '+' << endl;

            //  second line
            os << '|';
            os.width(m_width - 2);
            os.fill(' ');
            os << left << LblShape::label() << '|' << endl;

            //  middle lines
            for (unsigned int i = 0; i < (m_height - 3); i++) {
                os << '|';
                os.width(m_width - 2);
                os.fill(' ');
                os << ' ' << '|' << endl;
            }

            //  last line
            os << '+';
            os.width(m_width - 2);
            os.fill('-');
            os << '-' << '+';
        }
    }
}