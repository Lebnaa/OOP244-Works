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
#include <iostream>
#include "Utils.h"
using namespace std;
namespace sdds {
	// Gets an integer as input and validates the range as well. It prints a message if the range isn't valid and prompts again
	int getIntegerInput(int minRange, int maxRange)
	{
		int input;

		bool validInt = false;
		do
		{
			cin >> input;
			if (!cin || input < minRange || input > maxRange)
			{
				std::cout << "Invalid Selection, try again: ";
				cin.clear();
				cin.ignore(1000, '\n');
				validInt = false;
			}
			else
			{
				validInt = true;
			}
		} while (validInt == false);

		return input;
	}

}