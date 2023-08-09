/*****************************************************************************
Lib.h
Full Name : Lebna Noori
Student ID# : 157672205
Email : lnoori1@myseneca.ca
Date of completion : 18 July 2023

I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments,  with using Fardad's Utils files and.*/

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
namespace sdds
{

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
	int strLen(const char* str);
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

	void reAloCpy(char*& des, const char* src);
	void aloCpy(char*& des, const char* src);
}

#endif // !SDDS_UTILS_H