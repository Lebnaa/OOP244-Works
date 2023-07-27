/*****************************************************************************
Lib.h
Full Name : Lebna Noori
Student ID# : 157672205
Email : lnoori1@myseneca.ca
Date of completion : 18 July 2023

I have done all the coding by myself and only copied the code that my 
professor provided to complete my workshops and assignments,  with using Fardad's Utils files and.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Publication.h"
#include "Lib.h"
#include "Utils.h"
//#include <cstring>

using namespace std; 

namespace sdds
{
	Publication::Publication()
	{
		setEmpty();
	}


	Publication::~Publication()
	{
		delete[] m_title; 
	}

	void Publication::setRef(int value)
	{
		m_libRef = value;
	}

	void Publication::resetDate()
	{
		m_date = Date();
	}

	void Publication::setEmpty()
	{
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		resetDate();
	}

	// copy constructor copying is allowed 
	Publication::Publication(const Publication& publication)
	{
		*this = publication; 
	}

	//copy assignment operator copying is allowed. 
	Publication& Publication::operator=(const Publication& publication)
	{
		//setting the variables 
		set(publication.m_membership); 
		setRef(publication.m_libRef); 
		strCpy(m_shelfId, publication.m_shelfId); 
		m_date = publication.m_date; 

		if (m_title)
		{
			delete[] m_title;
			m_title = nullptr;
		}
		return *this; 
	}

	// Sets the membership attribute to either zero or a five-digit integer.
	void Publication::set(int member_id) 
	{
		m_membership = member_id;
	}

	//Returns the character 'P' to identify this object as a "Publication object
	char Publication::type()const
	{
		return 'P';
	}

	bool Publication::onLoan()const
	{
		bool result = false;

		if (m_membership != 0)
		{
			result = true;
		}

		return result;
	}

	Date Publication::checkoutDate()const
	{
		return m_date;
	}

	bool Publication::operator==(const char* title)const
	{
		return strStr(m_title, title) != nullptr;
	}

	Publication::operator const char* () const
	{
		return m_title;
	}

	int Publication::getRef()const
	{
		return m_libRef;
	}

	bool Publication::conIO(std::ios& io)const
	{
		bool result = false;

		if (&io == &std::cin || &io == &std::cout)
		{
			result = true;
		}

		return result;
	}

	std::ostream& Publication::write(std::ostream& ostr) const
	{
		if (conIO(ostr))
		{
			ostr << "|" << m_shelfId << "|";
			ostr.width(30); 
			ostr << std::left << ostr.fill('.') << m_title << "|";

			if (m_membership != 0)
			{
				ostr << m_membership;
			}
			else
			{
				ostr << "N/A";
			}
			ostr << "\t" << m_date;
		}
		else
		{
			ostr << type() << "\t";
			ostr << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";

			if (m_membership != 0)
			{
				ostr << m_membership;
			}
			else
			{
				ostr << "N/A";
			}
			ostr << "\t" << m_date;
		}
		return ostr;
	}

	std::istream& Publication::read(std::istream& istr)
	{
		// Temporary variables
		char t_title[SDDS_TITLE_WIDTH + 1]{}, t_shelfId[SDDS_SHELF_ID_LEN + 1]{};
		int t_libRef = -1, t_membership = 0;
		Date t_date;


		//freeing the memory and setting everything to their default values.
		if (m_title)
		{
			delete[] m_title;
			m_title = nullptr;
		}

		setEmpty();

		if (conIO(istr))
		{
			std::cout << "Shelf No: ";
			//read the shelf number up to its limit (see Lib.h).
			istr.getline(t_shelfId, SDDS_SHELF_ID_LEN + 1);

			//if the number is not exactly the length it is supposed to be
			if (strLen(t_shelfId) != SDDS_SHELF_ID_LEN)
			{
				//set the istr to a fail state manually 
				istr.setstate(ios::failbit);
			}

			std::cout << "Title: ";
			istr.getline(t_title, SDDS_TITLE_WIDTH + 1);

			std::cout << "Date: ";
			istr >> t_date;
		}
		else
		{
			istr >> t_libRef;
			istr.ignore();
			istr.getline(t_shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
			istr.getline(t_title, SDDS_TITLE_WIDTH + 1, '\t');
			istr >> t_membership;
			istr.ignore();
			istr >> t_date;
		}

		// if the date is in an invalid state set the istr to a fail state manually
		if (!m_date)
		{
			istr.setstate(ios::failbit);
		}

		if (istr)
		{
			/*m_title = new char[strlen(t_title) + 1];
			strCpy(m_title, t_title);*/

			aloCpy(m_title, t_title); 

			strCpy(m_shelfId, t_shelfId);
			m_membership = t_membership;
			m_date = t_date;
			m_libRef = t_libRef;
		}

		return istr;

	}

	// Overloads of this method will return if the Streamable object is in a valid state or not
	Publication::operator bool() const
	{
		bool result = false;

		if (m_title != nullptr && m_shelfId[0] != '\0')
		{
			result = true;
		}

		return result;
	}
}