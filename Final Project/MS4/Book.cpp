#include <iostream>
#include <cstring>
#include "Book.h"
#include "Utils.h"


using namespace std; 

namespace sdds
{
	//copy constructor 
	Book::Book(const Book& book) : Publication(book)
	{
		if (AuthorName)
		{
			delete[] AuthorName; 
			AuthorName = nullptr; 
		}

		//aloCpy(AuthorName, book.AuthorName); 
		AuthorName = new char[strlen(book.AuthorName) + 1];
		strCpy(AuthorName, book.AuthorName); 
	}

	//copy assignment 
	Book& Book::operator=(const Book& book)
	{
		Publication::operator=(book); 

		if (AuthorName)
		{
			delete[] AuthorName; 
			AuthorName = nullptr; 
		}

		if (book.AuthorName)
		{
			//aloCpy(AuthorName, book.AuthorName); 
			AuthorName = new char[strlen(book.AuthorName) + 1]; 
			strCpy(AuthorName, book.AuthorName); 
		}

		return *this; 
	}

	Book::~Book()
	{
		delete[] AuthorName; 
	}

	void Book::set(int member_id)
	{
		Publication::set(member_id); 
		Publication::resetDate(); 
	}

	char Book::type() const
	{
		return 'B'; 
	}

	std::ostream& Book::write(std::ostream& os) const
	{
		//calling it's base class write func 
		Publication::write(os); 

		if (conIO(os)) 
		{
			char author[SDDS_AUTHOR_WIDTH + 1] = { 0 };
			strnCpy(author, AuthorName, SDDS_AUTHOR_WIDTH);
			os << " "; 
			os << os.width(SDDS_AUTHOR_WIDTH) << std::left << os.fill(' ') << author << " |";
		}
		else
		{
			os << "\t" << AuthorName; 
		}

		return os; 
	}

	std::istream& Book::read(std::istream& is)
	{
		char t_AthrName[256]{ 0 }; 

		Publication::read(is); 

		if (AuthorName)
		{
			delete[] AuthorName; 
			AuthorName = nullptr; 
		}

		if (conIO(is))
		{
			//ignore \n
			is.ignore('\n'); 
			cout << "Author: "; 
		}
		else
		{
			is.ignore(1000, '\t'); 
		}

		// Read up to 249 characters into authName
		is.get(t_AthrName, 250);

		// if object is not in a fail state,
		if (is)
		{
			//dynamically hold the author's name in the char 
			//pointer attribute of the book class.
			//aloCpy(AuthorName, t_AthrName);
			AuthorName = new char[strlen(t_AthrName) + 1];
			strCpy(AuthorName, t_AthrName); 
		}

		return is; 

	}

	Book::operator bool() const
	{
		return AuthorName && Publication::operator bool(); 
	}









}