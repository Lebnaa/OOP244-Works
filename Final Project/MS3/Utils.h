/***********************************************************************
// OOP244 Utils Module
// File	Utils.h
// Version
// Date
// Author
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Lebna            July 7th/2023       Project Completion
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__

namespace sdds {

	// Gets an integer as input and validates the range as well. It prints a message if the range isn't valid and prompts again
	int getIntegerInput(int minRange, int maxRange);

	bool alloCopy(char*& des, const char* str);

	/// <summary>
	/// Copies the source character string into the destination
	/// </summary>
	/// <param name="des"> Destination String </param>
	/// <param name="src"> Source String </param>
	void strCpy(char* des, const char* src);

	/// <summary>
	/// Copies the source character string into the destination upto "len" characters.
	/// The destination will be null terminated only if the number of the characters
	/// copied is less than "len".
	/// </summary>
	/// <param name="des"> Destination String </param>
	/// <param name="src"> Source String </param>
	/// <param name="len"> length of the string which you want to copy </param>
	void strnCpy(char* des, const char* src, int len);

	/// <summary>
	/// Compares two C-strings 
	/// </summary>
	/// <param name="s1"> String 1 </param>
	/// <param name="s2"> String 2 </param>
	/// <returns> 0 if strings are same </returns>
	/// <returns> >0 if s1 > s2 </returns>
	/// <returns> <0 if s1 < s2 </returns>
	int strCmp(const char* s1, const char* s2);

	/// <summary>
	/// Compares two C-strings upto "len" characters.
	/// </summary>
	/// <param name="s1"> String 1 </param>
	/// <param name="s2"> String 2 </param>
	/// <param name="len"> length of the string which you want to compare </param>
	/// <returns> 0 if strings are same </returns>
	/// <returns> >0 if s1 > s2 </returns>
	/// <returns> <0 if s1 < s2 </returns>
	int strnCmp(const char* s1, const char* s2, int len);

	/// <summary>
	/// Count length of the string [characters]
	/// </summary>
	/// <param name="s"> string </param>
	/// <returns> the length of the C-string in characters </returns>
	int strLen(const char* s);

	/// <summary>
	/// Find the address of first occurance of "str2" in "str1"
	/// </summary>
	/// <param name="str1"> string 1 </param>
	/// <param name="str2"> string 2 </param>
	/// <returns> the address of first occurance of "str2" in "str1" </returns>
	/// <returns> nullptr if no match is found </returns>
	const char* strStr(const char* str1, const char* str2);

	/// <summary>
	/// Concantinates "src" C-string to the end of "des"
	/// </summary>
	/// <param name="des"> Destination String </param>
	/// <param name="src"> Source String </param>
	void strCat(char* des, const char* src);


}
#endif // SDDS_UTILS_H__