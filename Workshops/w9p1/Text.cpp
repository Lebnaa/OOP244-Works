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
#include <fstream>
#include <cstring>
#include "Text.h"
#include "cstring.h"
using namespace std; 

namespace sdds
{
    int Text::getFileLength() const 
    {
        int len = 0;
        ifstream fin(m_filename);
        while (fin)
        {
            fin.get();
            len += !!fin;
        }
        return len;
    }

    //index operator - read only access, behavior not defined if index OoB
    const char& Text::operator[](int index) const 
    {
        return (index >= 0 || index < getFileLength()) ? m_content[index] : m_content[getFileLength()];

    }




    //constructor implementation for given constructor
    Text::Text(const char* filename) : m_filename(nullptr), m_content(nullptr) 
    {
        if (filename)
        {
            m_filename = new char[strLen(filename) + 1];
            strCpy(m_filename, filename);
            read();
        }
    }


    //copy constructor
    Text::Text(const Text& text) : m_filename(nullptr), m_content(nullptr) {
        if (text.m_filename)
        {
            m_filename = new char[strLen(text.m_filename) + 1];
            strCpy(m_filename, text.m_filename);
        }

        if (text.m_content)
        {
            m_content = new char[strLen(text.m_content) + 1];
            strCpy(m_content, text.m_content);
        }
    }
    
    //copy assingment
    Text& Text::operator=(const Text& text) 
    {
        if (this != &text)
        {
            if (m_filename)
            {
                delete[] m_filename;
            }
            if (text.m_filename)
            {
                m_filename = new char[strLen(text.m_filename) + 1];
                strCpy(m_filename, text.m_filename);
                read();
            }
            else
            {
                m_filename = nullptr;
                m_content = nullptr;
            }
        }
        return *this;
    }
    //destructor
    Text::~Text()
    {
        delete[] m_filename;
        m_filename = nullptr;
        delete[] m_content;
        m_filename = nullptr;
    }


    //read function
    void Text::read()
    {
        ifstream readFile(m_filename);
        char tempChar;
        int i = 0;
        if (m_content)
        {
            delete[] m_content;
            m_content = nullptr;
        }
        if (readFile.is_open())
        {
            m_content = new char[getFileLength() + 1];
            while (readFile.get(tempChar))
            {
                m_content[i] = tempChar;
                i++;
            }
            m_content[i] = '\0';
        }
        else
        {
            m_content = nullptr;
        }
    }

    //write


    void Text::write(std::ostream& os) const
    {
        if (m_content)
        {
            os << m_content;
        }
    }

    //<< operator
    std::ostream& operator<<(std::ostream& os, const Text& text)
    {
        text.write(os);
        return os;
    }


}
