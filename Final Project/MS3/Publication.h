/*****************************************************************************
Lib.h
Full Name : Lebna Noori
Student ID# : 157672205
Email : lnoori1@myseneca.ca
Date of completion : 18 July 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/ 

#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include <iostream>

#include "Date.h"
#include "Streamable.h"


namespace sdds {
	class Publication : public Streamable 
	{
	private: 
		char* m_title{};
		char m_shelfId[4]{ '\0' }; 
		int m_membership; 
		int m_libRef{ -1 };
		Date m_date; 
	public :
		Publication() { setEmpty }; 
		~Publication() {}; 

		virtual void set(int member_id);
		// Sets the membership attribute to either zero or a five-digit integer.
		void setRef(int value);
		// Sets the **libRef** attribute value
		void resetDate();
		// Sets the date to the current date of the system.

		// Sets to default values
		void setEmpty();

		virtual char type()const;
		//Returns the character 'P' to identify this object as a "Publication object"
		bool onLoan()const;
		//Returns true is the publication is checkout (membership is non-zero)
		Date checkoutDate()const;
		//Returns the date attribute
		bool operator==(const char* title)const;
		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		operator const char* ()const;
		//Returns the title attribute
		int getRef()const;
		//Returns the libRef attirbute. 

		//Returns true if the address of the io object
		bool conIO(std::ios& io)const; 

		//print shelfId, title, membership and date attributes
		std::ostream& write(std::ostream& os) const; 

		std::istream& read(std::istream& istr); 

		//Returns true if neither of the title or shelfId attributes is null. Otherwise  false.
		operator bool() const; 

	};
}
#endif // !SDDS_PUBLICATION_H
