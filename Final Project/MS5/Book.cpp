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
#include <iomanip>
#include <cstring>
#include "Book.h"
#include "Utils.h"


using namespace std;
namespace sdds
{
    Book::Book() : Publication()
    {
        author = nullptr;
    }

    Book::~Book()
    {
        delete[] author;
    }

    Book::Book(const Book& book) : Publication(book)
    {
        if (author)
        {
            delete[]author;
            author = nullptr;
        }
        aloCpy(author, book.author); 
        /*author = new char[strlen(bk.author) + 1];
        strcpy(author, bk.author);*/
    }

    Book& Book::operator=(const Book& book)
    {
        Publication::operator=(book);
        if (author)
        {
            delete[]author;
            author = nullptr;
        }
        if (book.author)
        {
            author = new char[strlen(book.author) + 1];
            strcpy(author, book.author);
        }

        return *this;
    }

    char Book::type()const
    {
        return 'B';
    }

    ostream& Book::write(ostream& os) const
    {
        int i = 0;
        Publication::write(os);
        if (conIO(os))
        {
            size_t auth = strlen(author);
            if (auth == SDDS_AUTHOR_WIDTH)
            {
                os << " ";
                os << author;
                os << " |";
            }
            else if (auth > SDDS_AUTHOR_WIDTH)
            {
                os << " ";
                for (i = 0; i < SDDS_AUTHOR_WIDTH; i++)
                {
                    os << author[i];
                }
                os << " |";
            }
            else
            {
                os << " ";
                os << left << setw(SDDS_AUTHOR_WIDTH) << setfill(' ') << author;
                os << " |";
            }
        }
        else
        {
            os << "\t" << author;
        }

        return os;
    }

    istream& Book::read(istream& istr)
    {
        char auth[257]{ 0 };

        Publication::read(istr);

        if (author)
        {
            delete[] author;
            author = nullptr;
        }
        if (conIO(istr))
        {
            cout << "Author: ";

            if (istr)
            {
                istr.ignore(1, '\n');
                istr.get(auth, 256);
            }
        }
        else
        {
            istr.clear();
            istr.ignore(1, '\t');
            istr.get(auth, 256);
        }
        if (istr)
        {
            author = new char[strlen(auth) + 1];
            strcpy(author, auth);
        }
        else
        {
            istr.setstate(ios::failbit);
        }
        return istr;

    }

    void Book::set(int member_id)
    {
        Publication::set(member_id);
        Publication::resetDate();
    }

    Book::operator bool() const
    {
        return author && Publication::operator bool();
    }

}