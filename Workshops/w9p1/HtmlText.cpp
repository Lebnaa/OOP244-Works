/*
*****************************************************************************
							  Workshop - #9 (Part-1)
Full Name  : Lebna Noori
Student ID#: 157672205
Email      : lnoori1@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/
#include <cstring>
#include "HtmlText.h"
#include "cstring.h"
using namespace std; 

namespace sdds {
    //given constrctor
    HtmlText::HtmlText(const char* filename, const char* title) : Text(filename), m_title(nullptr)
    {
        if (title)
        {
            m_title = new char[strLen(title) + 1];
            strCpy(m_title, title);
        }
        else
        {
            m_title = nullptr;
        }
    }
    //rule of 3
    //copy assignment
    HtmlText& HtmlText::operator=(const HtmlText& htmlText) 
    {
        if (this != &htmlText)
        {
            (Text&)*this = htmlText;

            if (m_title)
            {
                delete[] m_title;
            }
            if (htmlText.m_title) 
            {
                m_title = new char[strLen(htmlText.m_title) + 1];
                strCpy(m_title, htmlText.m_title);
            }
            else
            {
                m_title = nullptr;
            }
        }

        return *this;
    }
    //copy constructor
    HtmlText::HtmlText(const HtmlText& other) : m_title(nullptr)
    {
        *this = other;
    }

    //destructor
    HtmlText::~HtmlText() 
    {
        delete[] m_title;
        m_title = nullptr;
    }

    void HtmlText::write(std::ostream& os) const 
    {
        bool MS = false;
        char tempChar;
        int i = 0;

        os << "<html><head><title>";
        if (m_title != nullptr)
        {
            os << m_title;
        }
        else
        {
            os << "No title";
        }
        os << "</title></head>\n<body>\n";

        if (m_title) {
            os << "<h1>" << m_title << "</h1>\n";

            while (Text::operator[](i) != '\0')
            {
                tempChar = Text::operator[](i);

                if (tempChar == ' ')
                {
                    if (MS)
                        os << "&nbsp;";
                    else
                    {
                        os << tempChar;
                        MS = true;
                    }
                }
                else if (tempChar == '<')
                {
                    os << "&lt;";
                    MS = false;
                }
                else if (tempChar == '>')
                {
                    os << "&gt;";
                    MS = false;
                }
                else if (tempChar == '\n')
                {
                    os << "<br />\n";
                    MS = false;
                }
                else
                {
                    os << tempChar;
                    MS = false;
                }

                i++;
            }
        }
        os << "</body>\n</html>";
    }
}