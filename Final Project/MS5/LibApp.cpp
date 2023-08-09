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
#include "LibApp.h"
#include "Utils.h"


#include "PublicationSelector.h"
//#include <cstring>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;


namespace sdds {

    //checked it looks good
    LibApp::LibApp() {

        m_filename[0] = '\0';
        m_changed = false;
        m_NOLP = 0;
        m_LLRN = 0;
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

        m_PTM << "Book" << "Publication";

        load();
    }
    // checked if it looks good
    LibApp::LibApp(const char* filename) 
    {
        if (filename)
        {
            strCpy(m_filename, filename);
        }
        else
        {
            m_filename[0] = '\0';
        }

        m_changed = false;
        m_NOLP = 0;
        m_LLRN = 0;
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";

        m_PTM << "Book" << "Publication";

        load();
    }


    LibApp::~LibApp() 
    {
        int i = 0;
        for (i = 0; i < SDDS_LIBRARY_CAPACITY; i++)
        {
            delete m_PPA[i];
        }
    }



    //previous milestone
    bool LibApp::confirm(const char* message)
    {
        bool check = false;
        int value = 0;
        Menu menu(message);
        menu << "Yes";
        value = menu.run();
        if (value)
        {
            check = true;
        }
        else
        {
            check = false;
        }
        return check;

    }

    void LibApp::load() {

        char temp;
        ifstream loadFile(m_filename);


        cout << "Loading Data" << endl;

        while (loadFile >> temp)
        {
            if (temp == 'P')
            {
                m_PPA[m_NOLP] = new Publication;
                loadFile >> *m_PPA[m_NOLP];
                m_LLRN = m_PPA[m_NOLP]->getRef();
                m_NOLP++;
            }
            else if (temp == 'B')
            {
                m_PPA[m_NOLP] = new Book;
                loadFile >> *m_PPA[m_NOLP];
                m_LLRN = m_PPA[m_NOLP]->getRef();
                m_NOLP++;
            }
        }
    }


    void LibApp::save() {
        int i = 0;
        cout << "Saving Data" << endl;

        ofstream saveData(m_filename); //create output file stream object

        for (i = 0; i < m_NOLP; i++)
        {
            if (m_PPA[i]->getRef() != 0) //use the getref method to check wheter the ref is 0
            {
                saveData << *m_PPA[i] << endl;
            }
        }
        saveData.close();// close the created file object
    }



    int LibApp::search(int method)
    {
        int pubSelect = -1;
        int count = 0;
        int userChoice = -1;
        int i = 0;
        char pubType{};
        PublicationSelector filterMenu("Select one of the following found matches:");
        string titleFilter;

        cout << "Choose the type of publication:" << endl;

        pubSelect = m_PTM.run();
        if (pubSelect == 0)
        {
            cout << "Aborted!" << endl;
            return 0;
        }
        else if (pubSelect == 1)
        {
            pubType = 'B';
        }
        else if (pubSelect == 2)
        {
            pubType = 'P';
        }


        if (pubSelect > 0)
        {
            cout << "Publication Title: ";
            cin.clear();
            cin.ignore(1000, '\n');

            getline(cin, titleFilter);

            for (i = 0; i < m_NOLP; i++)
            {
                if (m_PPA[i]->type() == pubType)
                {
                    if (strStr(static_cast<const char*>(*m_PPA[i]), titleFilter.c_str()))
                    {
                        if (method == 0)
                        {
                            filterMenu << m_PPA[i];
                            count++;
                        }
                        if (method == 1)
                        {
                            if (!m_PPA[i]->onLoan())
                            {
                                filterMenu << m_PPA[i];
                                count++;
                            }
                        }
                        if (method == 2)
                        {
                            if (m_PPA[i]->onLoan())
                            {
                                filterMenu << m_PPA[i];
                                count++;
                            }
                        }

                    }
                }
            }

            if (count > 0)
            {
                filterMenu.sort();
                userChoice = filterMenu.run();
                for (i = 0; i < m_NOLP; i++)
                {
                    if (m_PPA[i]->getRef() == userChoice)
                    {
                        cout << *m_PPA[i] << endl;
                    }
                }
                if (userChoice == 0)
                {
                    cout << "Aborted!" << endl;
                }
            }
            else
            {
                cout << "No matches found!" << endl;
            }
        }
        return userChoice;
    }


    Publication* LibApp::getPub(int libRef) 
    {

        int i = 0;
        Publication* pub = nullptr;

        for (i = 0; i < m_NOLP; i++)
        {
            if (m_PPA[i]->getRef() == libRef)
            {
                pub = m_PPA[i];
            }
        }
        return pub;
    }


    void LibApp::returnPub() 
    {
        bool flag = false;
        bool confirmation = false;

        int libRef = 0; // temp libref to find the item
        int loanDays = 0;// total loan days
        int daysLate = 0; // to display the number of days ate
        double lateFee = 0.0; // to dispaly late fees

        cout << "Return publication to the library" << endl;
        libRef = search(2); //search only members that are in pibrar

        if (libRef <= 0)
        {
            flag = true;
        }
        if (!flag)
        {
            confirmation = confirm("Return Publication?");
            if (confirmation)
            {
                loanDays = Date() - getPub(libRef)->checkoutDate(); // get the date and subtract the checkout date.

                if (loanDays > SDDS_MAX_LOAN_DAYS) // if it is over the max num days calculation nessecary payment
                {
                    lateFee = (loanDays - SDDS_MAX_LOAN_DAYS) * 0.5; //divide by 0.5 since 50 cents a day
                    daysLate = (loanDays - SDDS_MAX_LOAN_DAYS);// calc num days over max days
                    cout << fixed << setprecision(2);// set percision to output only 2 digits for cents
                    cout << "Please pay $" << lateFee << " penalty for being " << daysLate << " days late!" << endl;
                }

                getPub(libRef)->set(0);// return the libRef item
                m_changed = true; // indicate thaat the item is returned
            }
            cout << "Publication returned" << endl;
        }
        cout << endl;
    }

    void LibApp::newPublication() {
        bool confirmation = false;
        int tempPubType = 0;

        if (m_NOLP != SDDS_LIBRARY_CAPACITY)
        {
            cout << "Adding new publication to the library" << endl;
            cout << "Choose the type of publication:" << endl;
            tempPubType = m_PTM.run();

            if (tempPubType == 1)
            {
                m_PPA[m_NOLP] = new Book;

                if (cin >> *m_PPA[m_NOLP])
                {
                    confirmation = confirm("Add this publication to the library?");

                }
                else
                {
                    cout << "Aborted!" << endl;
                }

            }
            else if (tempPubType == 2)
            {
                m_PPA[m_NOLP] = new Publication;


                if (cin >> *m_PPA[m_NOLP])
                {
                    confirmation = confirm("Add this publication to the library?");

                }
                else
                {
                    cout << "Aborted!" << endl;
                }

            }

            if (tempPubType == 0)
            {
                cout << "Aborted!" << endl;

            }

            if (confirmation)
            {
                m_changed = true;
                cout << "Publication added" << endl << endl;
                m_LLRN++;
                m_PPA[m_NOLP]->setRef(m_LLRN);
                m_NOLP++;
            }
            else
            {
                delete m_PPA[m_NOLP];
                m_PPA[m_NOLP] = nullptr;
                cout << endl;
            }


        }
        else if (m_NOLP == SDDS_LIBRARY_CAPACITY)
        {
            cout << "Library is at its maximum capacity!" << endl;
            confirmation = true;
        }
        cout << endl;
    }


    // Function to remove a publication from the library
    void LibApp::removePublication()
    {
        cout << "Removing publication from the library" << endl;
        int libref = search(1);
        if (libref)
        {
            if (confirm("Remove this publication from the library?"))
            {
                getPub(libref)->setRef(0);
                m_changed = true;
                cout << "Publication removed" << endl;
            }
        }
        cout << endl;
    }

    // Function to checkout a publication from the library
    void LibApp::checkOutPub()
    {
        cout << "Checkout publication from the library" << endl;

        //passes arg of 3 to search for publication
        int libref = search(3);
        if (libref)
        {
            if (confirm("Check out publication?"))
            {
                cout << "Enter Membership number: ";
                int memberId = 0;
                bool result = false;

                while (!result)
                {
                    cin >> memberId;
                    if (!cin || memberId < 10000 || memberId > 99999) {
                        cout << "Invalid membership number, try again: ";
                        cin.clear();
                        cin.ignore(3000, '\n');
                    }
                    else
                    {
                        result = true;
                    }
                } 
                cout << "Publication checked out" << endl;
            }
        }
        cout << endl;
    }

    void LibApp::run() {
        int menuInput = 0;
        int exitInput = 0;

        do {
            menuInput = m_mainMenu.run();
            if (menuInput == 0)
            {
                if (m_changed == true)
                {
                    exitInput = m_exitMenu.run();

                    if (exitInput == 0)
                    {
                        if (confirm("This will discard all the changes are you sure?"))
                        {
                            m_changed = false;
                        }
                    }
                    else if (exitInput == 1)
                    {
                        save();
                    }
                    else if (exitInput == 2)
                    {
                        menuInput = 1;
                    }
                }

                cout << endl;

            }
            else if (menuInput == 1)
            {
                newPublication();
            }
            else if (menuInput == 2)
            {
                removePublication();
            }

            else if (menuInput == 3) {
                checkOutPub();
            }
            else if (menuInput == 4)
            {
                returnPub();
            }
        } while (menuInput != 0);

        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }
}