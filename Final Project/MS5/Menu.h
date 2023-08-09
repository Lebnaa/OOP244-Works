/*****************************************************************************
Lib.h
Full Name : Lebna Noori
Student ID# : 157672205
Email : lnoori1@myseneca.ca
Date of completion : 18 July 2023

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments,  with using Fardad's Utils files and.*/

#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__

#define MAX_MENU_ITEMS 20 

#include <iostream>

namespace sdds {

	class MenuItem {
	private:
		char* menuContent{};

		MenuItem();
		MenuItem(const char* text);
		~MenuItem();


		//copy constructors but NO COPYING ALLOWED
		MenuItem(const MenuItem& menuItem) = delete;
		void operator = (const MenuItem& menu_Item) = delete;

		operator bool() const;

		operator const char* () const;

		std::ostream& display(std::ostream& os = std::cout);

		friend class Menu;

	};

	class Menu {
	private:
		MenuItem menutitle{};
		MenuItem* menuItems[MAX_MENU_ITEMS]{};
		unsigned int ptrCount = 0;
	public:
		Menu();
		Menu(const char* title);
		~Menu();

		//copy constructor but copying not allowed
		Menu(const Menu& menu) = delete;
		void operator = (const Menu& menuItem) = delete;

		// Function to display the title of the menu
		std::ostream& displayMenuTitle(std::ostream& os);

		//display the content of the menu 
		std::ostream& displayMenu(std::ostream& os = std::cout);

		//reutrns the num of menuitems on menu 
		operator int();

		//Return the number of MenuItems on the Menu.
		operator unsigned int();

		//eturn true if the Menu has one or more MenuItems otherwise, false;
		operator bool();

		//display menu and gets user selection 
		int run();

		//does what we want the function to do. 
		int operator~();

		Menu& operator<<(const char* menuitemConent);

		//If the index passes the number of MenuItems in the Menu, 
		//loop back to the beginning
		const char* operator[] (unsigned int index) const;

	};

	std::ostream& operator<<(std::ostream& os, Menu& menu);
}
#endif // SDDS_UTILS_H__
