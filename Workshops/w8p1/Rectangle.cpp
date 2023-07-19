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
#include "cstring.h"
#include "Rectangle.h"

using namespace std; 

namespace sdds
{
    Rectangle::Rectangle(int width, int height, const char* label)
    {
        int compareWidth = strLen(LblShape::label()) + 2;

        // if not meet the condition, rectangle will be set to empty
        if (width > compareWidth && height > 3)
        {
            m_width = width;
            m_height = height;
        }
    }

    void Rectangle::getSpecs(std::istream& is)
    {
        int height, width;
        char comma;
        bool result;

        do
        {
            //reads label with base class's getspecs 
            LblShape::getSpecs(is);

            is >> width >> comma >> height;

            if (!is)
            {
                is.clear();
                is.ignore(2000, '\n');
            }
            else
            {
                is.ignore();
                m_height = height;
                m_width = width;
                result = true;

            }
        } while (!result);
    }

    void Rectangle::draw(std::ostream& os) const
    {
        if (m_width > 0 && m_height > 00)
        {
            os << '+';
            os.width(m_width - 2);
            os.fill('-');
            os << '-' << '+' << endl;

            //second line 
            os << '|';
            os.width(m_width - 2);
            os.fill('-');
            os << left << LblShape::label() << '|' << endl;

            //middle line 
            for (unsigned int i = 0; i < (m_height - 3); i++)
            {
                os << '|';
                os.width(m_width - 2);
                os.fill('-');
                os << ' ' << '|' << endl;
            }

            //last line 
            os << '+';
            os.width(m_width - 2);
            os.fill('-');
            os << '-' << '+';
        }
    }
}