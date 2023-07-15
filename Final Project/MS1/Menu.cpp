/***********************************************************************
// OOP244 Utils Module
// File	Utils.cpp
// Version 1.0
// Date		July 7th/2023
// Author	Lebna Noori
// Description   Completing Utils.cpp
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Lebna            July 7th/2023       Project Completion
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Menu.h"
#include "Utils.h"
#include "cstring.h"

namespace sdds {
	//------Menu Class---------

	MenuItem::MenuItem()
	{
		setEmpty();
	}

	MenuItem::MenuItem(const char* text)
	{
		if (text && text[0])
		{
			menuContent = new char[strLen(text) + 1];
			strCpy(menuContent, text);
		}
		else
		{
			setEmpty();
		}
	}

	MenuItem::~MenuItem()
	{
		delete[] menuContent;
	}

	void MenuItem::setEmpty()
	{
		menuContent = nullptr;
	}

	//return true if not empty otherwise false 
	MenuItem::operator bool() const
	{
		return (menuContent != nullptr && menuContent[0] != '\0');
	}

	//return the address of content csrting 
	MenuItem::operator const char*() const
	{
		return menuContent;
	}

	//display the content of menuitem with ostream 
	std::ostream& MenuItem::display(std::ostream& os)
	{
		//checks if the MenuItem object true
		if (*this)
		{
			os << menuContent;
		}

		return os;
	}

	//-----------Menu Class-------------

	Menu::Menu()
	{
		ptrCount = 0;
		unsigned int i = 0;
		for (i = 0; i < MAX_MENU_ITEMS; i++)
		{
			menuItems[i] = nullptr;
		}
	}; 

	// Constructor with member initialization list
	Menu::Menu(const char* title) : menutitle(title) {
		unsigned int i = 0;
		for (i = 0; i < MAX_MENU_ITEMS; i++) 
		{
			menuItems[i] = nullptr;
		}
	};

	Menu::~Menu()
	{
		unsigned int i;
		for (i = 0; i < MAX_MENU_ITEMS; i++)
		{
			delete menuItems[i];
		}

	};

	//displays the menus title 
	std::ostream& Menu::displayMenuTitle(std::ostream& os)
	{
		if (menutitle)
		{
			menutitle.display();
		}

		return os;
	}

	//display the content 
	std::ostream& Menu::displayMenu(std::ostream& os)
	{
		menutitle.display();
		unsigned int i = 0;
		if (menutitle != nullptr)
		{
			os << ":" << std::endl;
		}
		
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

	//return the menus menuitems 
	Menu::operator int() const 
	{
		return ptrCount;
	}

	//return the menues menuitems 
	Menu::operator unsigned int() const 
	{
		return static_cast<unsigned int>(ptrCount);
	}

	//return true if menus has content if not false 
	Menu::operator bool() const 
	{
		return (ptrCount > 0);
	}

	//
	unsigned int Menu::run()
	{
		int input = 0; //avoid negative numbers 
		displayMenu();
		input = getIntegerInput(0, ptrCount);

		return input;
	}

	int Menu::operator~()
	{
		return run();
	}

	Menu& Menu::operator<<(const char* menuitemConent)
	{
		//checking if spot is avaliable 
		if (ptrCount <static_cast<int> (MAX_MENU_ITEMS))
		{
			//allocate memory and create a new menuitem 
			MenuItem* newMenuItem = new MenuItem(menuitemConent);
			//sotring the address 
			menuItems[ptrCount] = newMenuItem;
			ptrCount++;
		}

		return *this;

	}

	std::ostream& operator<<(std::ostream& os, Menu& menu) {
		return (menu.displayMenuTitle(os));
	}

	const char* Menu::operator[] (unsigned int index) const
	{
		if (index > ptrCount)
		{
			//
			return menuItems[index %= ptrCount]->menuContent;
		}
		else
		{
			return menuItems[index]->menuContent;
		}
	}

}; 
