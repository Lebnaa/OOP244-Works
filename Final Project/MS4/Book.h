#pragma once
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include "Publication.h"

namespace sdds
{
	class Book : public Publication
	{
		char* AuthorName{};
	public:
		Book() = default;

		//rule of three
		Book(const Book& book); 
		Book& operator=(const Book& book);
		~Book(); 

		// Sets the membership attribute to either zero or a five-digit integer.
		virtual void set(int member_id);

		// Queries / Getters
		// Returns the character 'P' to identify this object as a "Publication object"
		char type() const;

		// Write into an ostream object
		std::ostream& write(std::ostream& os) const;

		// Read from an istream object.
		std::istream& read(std::istream& is);

		// Overloads of this method will return if the Streamable object is in a valid state or not
		operator bool() const;

	};
}
#endif // !SDDS_BOOK_H