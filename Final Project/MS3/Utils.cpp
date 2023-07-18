/***********************************************************************
// OOP244 Utils Module
/*****************************************************************************
Lib.h
Full Name : Lebna Noori
Student ID# : 157672205
Email : lnoori1@myseneca.ca
Date of completion : 18 July 2023

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
* ****************************************************************************/
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