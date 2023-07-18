/*
*****************************************************************************
							 MS2
Full Name  : Lebna Noori
Student ID#: 157672205
Email      : lnoori1@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/
#include <iostream>
#include "cstring.h"

using namespace std;

namespace sdds {

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

	int strLen(const char* s) {
		int i;
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