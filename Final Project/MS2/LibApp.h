/*
*****************************************************************************
							 MS2
Full Name  : Lebna Noori
Student ID#: 157672205
Email      : lnoori1@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include <iostream>
#include "Menu.h"
#include "Publication.h"
#include "Lib.h"

namespace sdds {
    class LibApp {
        bool m_changed{ false };
        Menu m_mainMenu{ "Seneca Library Application\n" };
        Menu m_exitMenu{ "Changes have been made to the data, what would you like to do?\n" };
        
        //ms5 
        char m_filename[256]; 
        Publication* m_PPA[SDDS_LIBRARY_CAPACITY]; 
        int m_NOLP; 
        int m_LLRN; 
        Menu m_menuType{ "Choose the type of publication:" }; //menu type 

        //not new 
        bool confirm(const char* message);
        void load();  // prints: "Loading Data"<NEWLINE>
        void save();  // prints: "Saving Data"<NEWLINE>
        void search();  // prints: "Searching for publication"<NEWLINE>

        void returnPub();  /*  Calls the search() method.
                               prints "Returning publication"<NEWLINE>
                               prints "Publication returned"<NEWLINE>
                               sets m_changed to true;
                           */
        void newPublication();
        void removePublication();
        void checkOutPub();

    public:
        LibApp(const char* filenamw);

        void run();
        ~LibApp(); 
    }; 
}
#endif // !SDDS_LIBAPP_H
