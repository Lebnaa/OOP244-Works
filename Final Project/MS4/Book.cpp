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
#include <cstring>
#include <iomanip>

#include "Book.h"

using namespace std; 

namespace sdds
{
        Book::~Book()
        {
            delete[] AuthorName;
            AuthorName = nullptr; 
        }

        Book::Book(const Book& book) : Publication(book)
        {
            if (AuthorName)
            {
                delete[] AuthorName;
                AuthorName = nullptr;
            }
            AuthorName = new char[strlen(book.AuthorName) + 1];
            strcpy(AuthorName, book.AuthorName);
        }
        

        Book& Book::operator=(const Book& book)
        {
            if (this != &book)
            {

                Publication::operator=(book);
                delete[] AuthorName;
                AuthorName = nullptr; 

                if (book.AuthorName)
                {
                    AuthorName = new char[strlen(book.AuthorName) + 1];
                    strcpy(AuthorName, book.AuthorName);
                }
            }
            return *this;
        }


        char Book::type() const
        {
            return 'B';
        }


        std::ostream& Book::write(std::ostream& os) const
        {
            char t_Name[SDDS_AUTHOR_WIDTH + 1] = { 0 };

            Publication::write(os);
            if (conIO(os))
            {
                strncpy(t_Name, AuthorName, SDDS_AUTHOR_WIDTH);
                os << " ";
                os << std::setw(SDDS_AUTHOR_WIDTH) << std::left << std::setfill(' ') << t_Name << " |";
            }
            else
            {
                os << "\t" << AuthorName;
            }

            return os;
        }
        std::istream& Book::read(std::istream& is)
        {
            char t_Name[256] = { 0 };

            Publication::read(is);

            if (AuthorName)
            {
                delete[] AuthorName;
                AuthorName = nullptr;
            }

            if (conIO(is))
            {
                is.ignore();
                std::cout << "Author: ";
            }
            else
            {
                is.ignore(1000, '\t');
            }

            is.get(t_Name, 256);

            if (is)
            {
                AuthorName = new char[strlen(t_Name) + 1];
                strcpy(AuthorName, t_Name);
            }

            return is;

        }

        void Book::set(int member_id)
        {
            Publication::set(member_id);
            Publication::resetDate();
        }

        Book::operator bool() const
        {
            bool result = false;
            if (AuthorName && Publication::operator bool())
            {
                result = true;
            }
            return result;

        }
}