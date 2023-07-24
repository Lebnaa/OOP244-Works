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

	bool alloCopy(char*& des, const char* str)
	{
		if (str && str[0])
		{
			des = new char[strLen(str) + 1];
			strCpy(des, str);
		}
		return str && str[0];

		delete[] des;
	}

	void strCpy(char* des, const char* src) {
		int i;
		for (i = 0; src[i] != 0; i++) {
			des[i] = src[i];
		}
		des[i] = 0;
	}

	void strnCpy(char* des, const char* src, int len) {
		int i;
		for (i = 0; i < len && src[i] != 0; i++) {
			des[i] = src[i];
		}
		if (src[len - 1] < i) {
			des[i] = 0;
		}
	}

	int strCmp(const char* s1, const char* s2) {
		int i;
		int result = 0;
		for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
		if (s1[i] || s2[i]) {
			result = s1[i] > s2[i] ? 1 : -1;
		}
		return result;
	}

	int strnCmp(const char* s1, const char* s2, int len) {
		int i;
		int result = 0;
		for (i = 0; i < len && s1[i] && s2[i] && s1[i] == s2[i]; i++);
		if (i < len && (s1[i] || s2[i])) {
			result = s1[i] > s2[i] ? 1 : -1;
		}
		return result;
	}

	int strLen(const char* s)
	{
		int i = 0;
		for (i = 0; s[i] != 0; i++);
		return i;
	}

	const char* strStr(const char* str1, const char* str2) {
		int i, j;
		if (str1 == 0 || str2 == 0) {
			return 0;
		}
		for (i = 0; str1[i] != 0; i++) {
			bool match = true;
			for (j = 0; str2[j] != 0; j++) {
				if (str1[i + j] != str2[j]) {
					match = false;
				}
			}
			if (match) {
				return &str1[i];
			}
		}
		return 0;
	}

	void strCat(char* des, const char* src) {
		int i, j;
		for (i = 0; des[i] != 0; i++) {
		}
		for (j = 0; src[j] != 0; j++) {
			des[i] = src[j];
			i++;
		}
		des[i] = 0;
	}


}