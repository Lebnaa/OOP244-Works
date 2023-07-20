/*****************************************************************************
Lib.h
Full Name : Lebna Noori
Student ID# : 157672205
Email : lnoori1@myseneca.ca
Date of completion : 18 July 2023

I have done all the coding by myself and only copied the code that my 
professor provided to complete my workshops and assignments.*/

#include <iostream>
#include "Publication.h"
#include "Lib.h"
#include "Utils.h"

using namespace std; 

namespace sdds
{
	Publication::Publication()
	{
		setEmpty();
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
		bool result;

		if (&io == &cin || &io == &cout)
		{
			result = true;
		}

		return result;
	}

	std::ostream& Publication::write(std::ostream& os) const
	{
		if (conIO(os))
		{
			os << "|" << m_shelfId << "|" << cout.width(30) << left << cout.fill('.') << m_title << "|";

			if (m_membership != 0)
			{
				os << m_membership;
			}
			else
			{
				os << "N/A";
			}
			os << "\t" << m_date;
		}
		else
		{
			os << type() << "\t";
			os << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";

			if (m_membership != 0)
			{
				os << m_membership;
			}
			else
			{
				os << "N/A";
			}
			os << "\t" << m_date;
		}
		return os;
	}

	std::istream& Publication::read(std::istream& istr)
	{
		//Read values in local variables before setting the attributes to any values.

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
			cout << "Shelf No: ";
			//read the shelf number up to its limit (see Lib.h).
			istr.getline(t_shelfId, SDDS_SHELF_ID_LEN + 1);

			//if the number is not exactly the length it is supposed to be
			if (strLen(t_shelfId) != SDDS_SHELF_ID_LEN)
			{
				//set the istr to a fail state manually 
				istr.setstate(ios::failbit);
			}

			cout << "Title: ";
			istr.getline(t_title, SDDS_TITLE_WIDTH + 1);

			cout << "Date: ";
			istr >> t_date;
		}
		else
		{
			istr >> t_libRef;
			istr.ignore();
			istr >> t_shelfId;
			istr.ignore();
			istr >> t_title;
			istr.ignore();
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
			m_title = new char(strLen(t_title) + 1);
			strCpy(m_title, t_title);
			strCpy(m_shelfId, t_shelfId);
			m_membership = t_membership;
			m_date = t_date;
			m_libRef = t_libRef;
		}

		return istr;

	}

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