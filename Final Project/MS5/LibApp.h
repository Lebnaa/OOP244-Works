/*****************************************************************************
Lib.h
Full Name : Lebna Noori
Student ID# : 157672205
Email : lnoori1@myseneca.ca
Date of completion : 18 July 2023

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments,  with using Fardad's Utils files and.*/

#ifndef LIBAPP_H
#define LIBAPP_H
#include <iomanip>
#include "Menu.h"
#include "Lib.h"
#include "Streamable.h"
#include "Publication.h"
#include "Book.h"

namespace sdds {

    class LibApp {

        //ms5 member variables

        char m_filename[256]{};
        Publication* m_PPA[SDDS_LIBRARY_CAPACITY]{};
        int m_NOLP{};
        int m_LLRN{};
        bool m_changed{};


        //previous milestone member variables
        Menu m_PTM;
        Menu m_mainMenu{ "Seneca Library Application" };
        Menu m_exitMenu{ "Changes have been made to the data, what would you like to do?" };


        //previous milestone 
        bool confirm(const char* message);
        void load();  // prints: "Loading Data"<NEWLINE>
        void save();  // prints: "Saving Data"<NEWLINE>
        int search(int searchSelect);  // prints: "Searching for publication"<NEWLINE> //change it to return libref int

        void returnPub();  /*  Calls the search() method.
                               prints "Returning publication"<NEWLINE>
                               prints "Publication returned"<NEWLINE>
                               sets m_changed to true;
                           */
                           //previous milestone implementation
        void newPublication();
        void removePublication();
        void checkOutPub();


    public:
        LibApp(const char* filename);
        ~LibApp(); // include destructor since dynamic allocation exists now
        void run();//run method
        Publication* getPub(int libRef);
        LibApp();

    };


}



#endif