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
#include "Text.h"
#include "Utils.h"
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

    const char& Text::operator[](int index) const 
    {
        return (index >= 0 || index < getFileLength()) ? m_content[index] : m_content[getFileLength()];

    }

    Text::Text(const char* filename) : m_filename(nullptr), m_content(nullptr)
    {
        if (filename)
        {
            aloCpy(m_filename, filename);
            read(); 
        }
    }

    Text::~Text()
    {
        delete[] m_filename; 
        m_filename = nullptr; 
        delete[] m_content; 
        m_content = nullptr; 
    }

    //copy constructor 
    Text::Text(const Text& text) : m_filename(nullptr), m_content(nullptr)
    {
        if (text.m_filename)
        {
            aloCpy(m_filename, text.m_filename); 
        }
        if (text.m_content)
        {
            aloCpy(m_content, text.m_content); 
        }
    }

    //copy assignment 
    Text& Text::operator=(const Text& text)
    {
        if (this != &text)
        {
            delete[] m_filename; 
        }
        if (text.m_content)
        {
            aloCpy(m_filename, text.m_filename); 
            read(); 
        }
        else
        {
            m_filename = nullptr; 
            m_content = nullptr; 
        }

        return *this; 
    }

    void Text::read()
    {
        ifstream readFile(m_filename); 
        char t_char; 
        int i = 0; 

        if (m_content)
        {
            delete[] m_content; 
            m_content = nullptr; 
        }
        if (readFile.is_open())
        {
            m_content = new char[getFileLength() + 1]; 
            while (readFile.get(t_char))
            {
                m_content[i] = t_char; 
                i++; 
            }
            m_content[0] = '\0'; 
        }

        else
        {
            m_content = nullptr; 
        }

    }

    void Text::write(std::ostream& os) const
    {
        if (m_content)
        {
            os << m_content;
        }
    }

    std::ostream& operator<<(std::ostream& os, const Text& text)
    {
        text.write(os); 
        return os; 
    }
}