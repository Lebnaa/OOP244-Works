/*****************************************************************************
Lib.h
Full Name : Lebna Noori
Student ID# : 157672205
Email : lnoori1@myseneca.ca
Date of completion : 18 July 2023

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments,  with using Fardad's Utils files and.*/

#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <iostream>
using namespace std;
#include "Menu.h"
#include "Utils.h"
#include <cstring>
#include <ctime>
#include <limits> //for flushing content

namespace sdds {
    MenuItem::MenuItem() {
        m_menuContent = nullptr;

    }

    MenuItem::MenuItem(const char* textContent) {
        if (textContent && textContent[0])
        {
            m_menuContent = new char[strlen(textContent) + 1];
            strcpy(m_menuContent, textContent);
        }
        else
        {
            m_menuContent = nullptr;

        }
    }

    MenuItem::~MenuItem() {
        delete[] m_menuContent;
    }




    std::ostream& MenuItem::display(std::ostream& os) {
        if (*this)
        {
            os << m_menuContent;
        }

        return os;
    }

    MenuItem::operator bool() const {
        return (m_menuContent != nullptr && m_menuContent[0] != '\0');
    }

    MenuItem::operator const char* () const {
        return m_menuContent;
    }

    /// MENU CLASS
    Menu::Menu() {
        unsigned i = 0;
        m_numItems = 0;
        for (i = 0; i < MAX_MENU_ITEMS; i++) {
            m_menuItems[i] = nullptr;
        }
    };

    Menu::Menu(const char* title) : m_menuTitle(title) {
        unsigned int i = 0;
        for (i = 0; i < MAX_MENU_ITEMS; i++) {
            m_menuItems[i] = nullptr;
        }
    };

    Menu::~Menu() {
        unsigned int i;
        for (i = 0; i < MAX_MENU_ITEMS; i++)
        {
            delete m_menuItems[i];
        }
    };


    std::ostream& Menu::displayTitle(std::ostream& os) {
        if (m_menuTitle)
        {
            m_menuTitle.display();
        }
        return os;
    }
    ostream& Menu::displayMenu(ostream& os)
    {
        unsigned i = 0;
        if (m_menuTitle)
        {
            m_menuTitle.display();
            os << endl;
        }

        for (i = 0; i < m_numItems; i++)
        {
            os.width(2);
            os.setf(ios::right);
            os.fill(' ');
            os << i + 1 << "- ";
            os.unsetf(ios::right);
            m_menuItems[i]->display(os);
            os << endl;
        }

        os << " 0- Exit" << endl;
        os << "> ";
        return os;
    }

    unsigned int Menu::run() {

        unsigned int selection = 0;  //have to use unsinged int since that is what we are returning and want to avoid negative values

        displayMenu();

        selection = getIntegerInput(0, m_numItems);

        return selection;
    }
    int Menu::operator~() {
        return run();
    }
    Menu& Menu::operator<<(const char* menuItemContent) {
        if (m_numItems < static_cast<int>(MAX_MENU_ITEMS))
        {
            MenuItem* newItem = new MenuItem(menuItemContent);
            m_menuItems[m_numItems] = newItem;
            m_numItems++;
        }
        return *this;
    }

    Menu::operator int() const {
        return m_numItems;
    }

    Menu::operator unsigned int() const {
        return static_cast<unsigned int>(m_numItems); //static cast is used to cast a value in C++, preferred to sign
    }

    Menu::operator bool() const {
        return (m_numItems > 0);
    }

    std::ostream& operator<<(std::ostream& os, Menu& menu) {
        return (menu.displayTitle(os));
    }
    const char* Menu::operator[](unsigned int index) const {
        if (m_numItems > 0)
        {
            index %= m_numItems;
            return static_cast<const char*>(*m_menuItems[index]);// static cast to used to return the type as a const char*
        }
        return nullptr;
    }


}