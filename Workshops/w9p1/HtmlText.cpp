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
#include "HtmlText.h"
#include "Utils.h"
using namespace std; 

namespace sdds
{
	HtmlText::HtmlText(const char* filename, const char* title) : Text(filename), m_title(nullptr)
	{
		if (title)
		{
			aloCpy(m_title, title); 
		}
		else
		{
			m_title = nullptr; 
		}
	}

	HtmlText::~HtmlText()
	{
		delete[] m_title; 
		m_title = nullptr; 
	}

	//copy constructor
	HtmlText::HtmlText(const HtmlText& htmlText) : m_title(nullptr)
	{
		*this = htmlText;
	}

	HtmlText& HtmlText::operator=(const HtmlText& htmlText)
	{
		if (this != &htmlText)
		{
			delete[] m_title; 
		}
		if (htmlText.m_title)
		{
			aloCpy(m_title, htmlText.m_title); 
		}
		else
		{
			m_title = nullptr;
		}

		return *this; 
	}

	void HtmlText::write(std::ostream& os) const
	{
		bool MS = false; 
		char t_char; 
		int i = 0; 

		cout << "<html><head><title>";
		if (m_title != nullptr)
		{
			os << m_title; 
		}
		else
		{
			os << "No Title"; 
		}

		cout << "</title></head>\n<body>\n"; 
		if (m_title)
		{
			os << "<h1>" << m_title << "</h1>\n";

			
			//while (Text::operator[](i) != '\0')
			while (Text::operator[](i) != '\0')
			{
				t_char = Text::operator[](i); 

				if (t_char == ' ')
				{
					if (MS)
					{
						os << " & nbsp;"; 
					}
					else
					{
						os << t_char; 
						MS = true; 
					}
				}
				else if (t_char == '\n')
				{
					os << "<br />\n";
					MS = false;
				}
				else if (t_char == '>')
				{
					os << "&gt;"; 
					MS = false; 
				}
				else if (t_char == '<')
				{
					os << "&lt;";
					MS = false; 
				}
				else
				{
					os << t_char; 
					MS = false; 
				}
				i++; 
			}
		}
		os << "</body>\n</html>"; 
	}


}