/*****************************************************************************
Lib.h
Full Name : Lebna Noori
Student ID# : 157672205
Email : lnoori1@myseneca.ca
Date of completion : 18 July 2023

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments,  with using Fardad's Utils files and.*/

#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include <iostream>
#include "Publication.h"
#include "Streamable.h"

using namespace std;
namespace sdds
{
    class Book : public Publication
    {
    private:
        char* author;

    public:
        Book();

        ~Book();

        Book(const Book& bk);

        Book& operator=(const Book& bk);

        char type()const;

        virtual void set(int member_id);

        ostream& write(ostream& os) const;

        istream& read(istream& istr);

        operator bool() const;

    };
}
#endif 