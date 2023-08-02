/*****************************************************************************
Lib.h
Full Name : Lebna Noori
Student ID# : 157672205
Email : lnoori1@myseneca.ca
Date of completion : 18 July 2023

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments,  with using Fardad's Utils files and.*/


#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <iostream>
//#include <cstring>
#include <iomanip>

#include "Utils.h"
using namespace std; 
namespace sdds 
{

    Book::~Book() {
        delete[] authorName;
        authorName = nullptr; 
    }

    // Copying is allowed
    Book::Book(const Book& book) : Publication(book)
    {
        if (authorName)
        {
            delete[] authorName;
            authorName = nullptr;
        }
        aloCpy(authorName, book.authorName); 

        /*authorName = new char[strlen(book.authorName) + 1];
        strcpy(authorName, book.authorName);*/
    }

    Book& Book::operator=(const Book& book) 
    {
        Publication::operator=(book);

        if (authorName)
        {
            delete[] authorName;
            authorName = nullptr;
        }

        if (book.authorName) 
        {
            aloCpy(authorName, book.authorName);

            /*authorName = new char[strlen(book.authorName) + 1];
            strcpy(authorName, book.authorName);*/
        }

        return *this;
    }

    // Returns the character 'B' to identify this object as a "Book object"
    char Book::type() const 
    {
        return 'B';
    }

    // Write into an ostream object

    std::ostream& Book::write(std::ostream& os) const
    {
        char tempName[SDDS_AUTHOR_WIDTH + 1] = { 0 };

        Publication::write(os);
        if (conIO(os))
        {
            strnCpy(tempName, authorName, SDDS_AUTHOR_WIDTH);
            os << " ";
            os << setw(SDDS_AUTHOR_WIDTH) << left << setfill(' ') << tempName << " |";
        }
        else
        {
            os << "\t" << authorName;
        }

        return os;
    }

    // Read from an istream object.
    std::istream& Book::read(std::istream& is)
    {
        char t_auther[256] = { 0 };

        Publication::read(is);

        if (authorName) 
        {
            delete[] authorName;
            authorName = nullptr;
        }

        if (conIO(is)) 
        {
            is.ignore(); //ignore '\n'
            std::cout << "Author: ";
        }
        else 
        {
            is.ignore(1000, '\t'); //ignores '\t'
        }

        is.get(t_auther, 256);

        if (is) 
        {
            aloCpy(authorName, t_auther);

           /* authorName = new char[strlen(authName) + 1];
            strcpy(authorName, authName);*/
        }

        return is;
    }

    // Sets the membership attribute to either zero or a five-digit integer.
    void Book::set(int member_id) 
    {
        Publication::set(member_id);
        Publication::resetDate();
    }

    // Overloads of this method will return if the Streamable object is in a valid state or not
    Book::operator bool() const 
    {
        bool result = false; 

        if(authorName && Publication::operator bool())
        {
                result = true; 
        }

        return result; 
    }
}