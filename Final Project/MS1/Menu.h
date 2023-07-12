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
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__

#define MAX_MENU_ITEMS 20 

#include <iostream>

namespace sdds {

	class MenuItem{
private: 
		char* menuContent{};

		MenuItem(); 
		MenuItem(const char* text); 
		~MenuItem();


		//copy constructors but NO COPYING ALLOWED
		MenuItem(const MenuItem& menuItem) = delete; 
		void operator = (const MenuItem& menu_Item) = delete; 

		void setEmpty(); 

		operator bool() const; 

		operator const char*() const; 

		std::ostream& display(std::ostream& os = std::cout); 

		friend class Menu;

	};

	class Menu {
	private :
		MenuItem* menutitle{};
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

		//
		int operator~(); 

		Menu& operator<<(const char* menuitemConent);

		//If the index passes the number of MenuItems in the Menu, 
		//loop back to the beginning
		const char* operator[] (unsigned int index) const; 


	};
}
#endif // SDDS_UTILS_H__