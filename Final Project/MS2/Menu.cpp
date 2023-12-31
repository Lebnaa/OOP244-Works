/*****************************************************************************
Lib.h
Full Name : Lebna Noori
Student ID# : 157672205
Email : lnoori1@myseneca.ca
Date of completion : 18 July 2023

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments,  with using Fardad's Utils files and.*/

#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "Utils.h"
#include "cstring"

namespace sdds {
    // MenuItem Class
    MenuItem::MenuItem()
    {
        menuContent = nullptr;
    }

    MenuItem::MenuItem(const char* text)
    {
        if (text && text[0]) {
            menuContent = new char[strlen(text) + 1];
            strcpy(menuContent, text);
        }
        else {
            menuContent = nullptr;
        }
    }

    MenuItem::~MenuItem() {
        delete[] menuContent;
    }

    // Return true, if it is not empty and it should return false if it is empty
    MenuItem::operator bool() const {
        return (menuContent && menuContent[0]);
    };

    // return the address of the content Cstring.
    MenuItem::operator const char* () const {
        return menuContent;
    }

    // printing the content of the MenuItem on ostream
    std::ostream& MenuItem::display(std::ostream& os)
    {
        if (*this)
        {
            os << menuContent;
        }

        return os;
    }

    // Menu Class
    Menu::Menu() {
        ptrCount = 0;
    };

    Menu::Menu(const char* title) : menutitle(title) {};

    Menu::~Menu()
    {
        unsigned int i;
        for (i = 0; i < MAX_MENU_ITEMS; i++)
        {
            delete menuItems[i];
        }
    };

    // Function to display the title of the menu
    std::ostream& Menu::displayMenuTitle(std::ostream& os)
    {
        if (menutitle)
        {
            menutitle.display();
        }

        return os;
    }

    // Display the content of Menu on ostream
    std::ostream& Menu::displayMenu(std::ostream& os)
    {
        if (menutitle)
        {
            menutitle.display();
            //os << ":" << std::endl;
        }

        unsigned int i;
        for (i = 0; i < ptrCount; i++)
        {
            os.width(2);
            os.setf(std::ios::right);
            os.fill(' ');
            os << i + 1 << "- ";
            os.unsetf(std::ios::right);
            menuItems[i]->display(os);
            os << std::endl;
        }
        os << " 0- Exit" << std::endl;
        os << "> ";

        return os;
    }

    // Return the number of MenuItems on the Menu.
    Menu::operator int()
    {
        return ptrCount;
    }

    Menu::operator unsigned int()
    {
        return ptrCount;
    }

    // Return true if the Menu has one or more MenuItems otherwise, false;
    Menu::operator bool()
    {
        return (ptrCount > 0);
    }

    // Overloading  insertion operator
    std::ostream& operator<<(std::ostream& os, Menu& menu)
    {
        return (menu.displayMenuTitle(os));
    }

    // Displays the Menu and gets the user selection.
    int Menu::run()
    {
        int input = 0; //avoid negative nums
        displayMenu();
        input = getIntegerInput(0, ptrCount);

        return input;
    }

    int Menu::operator~()
    {
        return run();
    }

    Menu& Menu::operator<<(const char* menuitemContent)
    {
        if (ptrCount < MAX_MENU_ITEMS)
        {
            MenuItem* newMenuItem = new MenuItem(menuitemContent);
            menuItems[ptrCount] = newMenuItem;
            ptrCount++;
        }

        return *this;
    }

    const char* Menu::operator[](unsigned int index) const
    {
        if (index > ptrCount)
        {
            return menuItems[index %= ptrCount]->menuContent;
        }
        else
        {
            return menuItems[index]->menuContent;
        }
    }
};