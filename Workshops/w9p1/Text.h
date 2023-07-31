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
#ifndef SDDS_CLASS_h
#define SDDS_CLASS_H

#include <iostream>

namespace sdds
{
	class Text
	{
		char* m_filename{};
		char* m_content{};
		int getFileLength() const; 
	protected: 
		//provides read-only access to the content of the text for the derived classes of Text.
		const char& operator[](int index)const;
	public:
		Text() = default; 
		Text(const char* filename = nullptr); 

		//rule of three
		virtual ~Text();
		Text(const Text& text); 
		Text& operator=(const Text& text); 
	
		//read will the current content of the file and then allocates memory to the size of the file on the disk
		void read(); 

		//will insert the content of the Text class into the ostream if m_content is not null.
		virtual void write(std::ostream& os = cout)const; 
	};

	std::ostream& operator<<(std::ostream& os, const Text& text); 
}
#endif // !SDDS_CLASS_h
