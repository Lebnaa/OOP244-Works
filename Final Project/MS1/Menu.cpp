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
#include "cstring.h"

using namespace std; 
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
		return (menuContent && menuContent[0]); 
	}

	//return the address of content csrting 
	MenuItem::operator const char* () const
	{
		return menuContent; 
	}

	std::ostream& MenuItem::display(std::ostream& os = std::cout)
	{
		//checks if the MenuItem object  true
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
	}

	Menu::Menu(const char* title) : menutitle(title) { }; 

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
	}; 




}
