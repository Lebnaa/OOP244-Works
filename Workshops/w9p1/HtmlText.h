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
#pragma once
#define SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H

#include "Text.h"

namespace sdds
{
	class HtmlText : public Text
	{
		char* m_title{};
	public:
		HtmlText(const char* filename = nullptr, const char* titile = nullptr);

		//rule of three
		~HtmlText();
		HtmlText(const HtmlText& htmlText); 
		HtmlText& operator=(const HtmlText& htmlText); 

		void write(std::ostream& os)const; 
	};
}
