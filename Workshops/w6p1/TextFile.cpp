#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {

	Line::operator const char* () const
	{
		return (const char*)m_value;
	}

	Line& Line::operator=(const char* lineValue)
	{
		delete[] m_value;
		m_value = new char[strLen(lineValue) + 1];
		strCpy(m_value, lineValue);
		return *this;
	}

	Line::~Line()
	{
		delete[] m_value;
		m_value = nullptr; 
	}

	//----------TexFile Class-----------

	void TextFile::setEmpty()
	{
		if (m_textLines != nullptr)
		{
			delete[] m_textLines;
			m_textLines = nullptr;
		}

		if (m_filename != nullptr)
		{
			delete[] m_filename;
			m_filename = nullptr;
		}

		m_noOfLines = 0;
	}

	void TextFile::setFilename(const char* fname, bool isCopy)
	{
		if (isCopy)
		{
			// dynamically allocates m_filename and copies fname argument with a prefix
			m_filename = new char[strLen(m_prefix) + strLen(fname) + 1];
			strCpy(m_filename, m_prefix);
			strCat(m_filename, fname);
		}
		else
		{
			// dynamically allocates m_filename and copies the fname
			m_filename = new char[strLen(fname) + 1];
			strCpy(m_filename, fname);
		}
	}

	//Counts the number of lines in the file:
	void TextFile::setNoOfLines()
	{
		//creates a local object to open file in filename 
		ifstream readfile(m_filename);
		char read;

		if (readfile.is_open())
		{
			do
			{
				//read the file character by character 
				readfile.get(read);

				// gets the number of newlines in the m_noOfLines
				if (read == '\n')
				{
					m_noOfLines++;
				}

			} while (readfile);

			// increase by 1, in case  last line does not have a new line
			m_noOfLines++;
		}
		else
		{
			if (m_noOfLines == 0)
			{
				delete[] m_filename;
				m_filename = nullptr;
			}
		}

	}

	void TextFile::loadText()
	{
		if (m_filename != nullptr)
		{
			if (m_textLines != nullptr)
			{
				delete[] m_textLines;
				m_textLines = nullptr;
			}
		}

		// Dynamically allocate an array of Lines pointed by m_textLines
		m_textLines = new Line[m_noOfLines];

		ifstream readfile(m_filename);

		string m_line;
		unsigned count = 0;

		if (readfile.is_open()) //opens the file 
		{

			// Read each line into the string object until the end of file
			for (getline(readfile, m_line); count++;)
			{
				m_textLines[count].m_value = new char[strLen(m_line.c_str()) + 1];
				strCpy(m_textLines[count].m_value, m_line.c_str());
			}

			//By calling c_str(), the code passed the pointer to the char array 
			//to strLen to know its length and to strCpy to copy its contents into a newly allocated char array.

			delete[] m_textLines;
			m_noOfLines = count;
		}
		readfile.close(); //close the file 
	}

	void TextFile::saveAs(const char* fileName)const
	{
		ofstream outfile(fileName);

		if (outfile.is_open())
		{
			for (unsigned i = 0; i < m_noOfLines; i++)
			{
				outfile << m_textLines[i].m_value << '\n';
			}
		}
		else
		{
			cout << "Failed to open file for writing " << fileName << endl;
		}
	}

	//--------public member function---------

	TextFile::TextFile(unsigned pageSize)
	{
		setEmpty();
		m_pageSize = pageSize;
	}

	TextFile::TextFile(const char* filename, unsigned pageSize)
	{
		setEmpty();

		m_pageSize = pageSize;

		if (filename != nullptr && filename[0] != '\0')
		{
			m_filename = new char[strLen(filename) + 1];
			strCpy(m_filename, filename);

			setNoOfLines();
			loadText();
		}
	}

	TextFile::TextFile(const TextFile& file_src)
	{
		setEmpty();

		//setting the current object m_pagesize 
		this->m_pageSize = file_src.m_pageSize;

		// Saves the content of TextFile under the file name of the current TextFile
		if (this != &file_src)
		{
			if (file_src.m_textLines && file_src.m_noOfLines > 0) {
				// Sets the current file-name to the name of the incoming TextFile object
				setFilename(file_src.m_filename, true);

				//number of lines of the current object is set tu num of line of the src textFile object. 
				this->m_noOfLines = file_src.m_noOfLines;
				m_textLines = new Line[m_noOfLines];

				unsigned i = 0;
				while (i < m_noOfLines)
				{
					m_textLines[i].m_value = new char[strLen(file_src.m_textLines[i].m_value) + 1];
					strCpy(m_textLines[i].m_value, file_src.m_textLines[i].m_value);
					i++;
				}

				saveAs(m_filename);
			}

		}
	}

	TextFile& TextFile::operator=(const TextFile& file_src)
	{
		if (this != &file_src)
			//checking to avoid self-assignment
		{
			// deallocate the dynamic array of Text and sets the pointer to null
			if (m_textLines != nullptr)
			{
				delete[] m_textLines;
				m_textLines = nullptr;
			}

			// Saves the content of the  TextFile under the current filename
			if (file_src.m_textLines && file_src.m_noOfLines > 0)
			{
				//m_noOfLines of the current object is set to the m_noOfLines of the source object .
				this->m_noOfLines = file_src.m_noOfLines;
				m_textLines = new Line[m_noOfLines];

				unsigned i = 0;
				//copy each line's content from the source object to the current object's m_textLines array.
				for (i = 0; i < m_noOfLines; i++)
				{
					m_textLines[i].m_value = new char[strLen(file_src.m_textLines[i].m_value) + 1];
					strCpy(m_textLines[i].m_value, file_src.m_textLines[i].m_value);
				}

				saveAs(m_filename);
			}
		}

		return *this;
	}

	TextFile::~TextFile()
	{
		delete[] m_textLines;
		m_textLines = nullptr;

		delete[] m_filename;
		m_filename = nullptr;
	}

	unsigned TextFile::lines()const
	{
		return m_noOfLines;
	}

	const char* TextFile::name() const
	{
		return m_filename;
	}

	std::ostream& TextFile::view(std::ostream& ostr) const
	{
		if (m_filename != nullptr && m_filename[0] != '\0')
		{
			ostr << m_filename << endl;

			ostr.fill('=');
			ostr.width(strLen(m_filename));
			ostr << '=' << endl;

			unsigned i = 0;
			unsigned linesPrinted = 0;

			// Loop through the lines and print them one by one
			while (i < m_noOfLines)
			{
				ostr << m_textLines[i].m_value << endl;
				i++;
				linesPrinted++;
			}

			//f linesPrinted reaches the m_pageSize limit, the user to press Enter to continue
			if (i < m_noOfLines)
			{
				do
				{
					ostr << "Hit ENTER to continue...";
					char x;
					cin.get(x);

					//prints all the lines
					for (unsigned j = 0; j < m_pageSize && i < m_noOfLines; j++)
					{
						ostr << m_textLines[i] << endl;
						i++;
					}
				} while (i < m_noOfLines);
			}
		}

		return ostr;
	}

	std::istream& TextFile::getFile(std::istream& istr)
	{
		string input;
		//recieves input
		istr >> input;

		m_filename = new char[strLen(input.c_str()) + 1];
		strCpy(m_filename, input.c_str());
		istr.ignore(32767, '\n');

		setNoOfLines();
		loadText();


		return istr;
	}

	const char* TextFile::operator[](unsigned index) const
	{
		if (m_filename != nullptr && m_filename[0] != '\0')
		{
			if (index >= m_noOfLines)
				index -= m_noOfLines;
		}
		return m_textLines[index].m_value;
	}

	TextFile::operator bool() const
	{
		bool result = false;

		if (m_textLines != nullptr)
		{
			result = true;
		}
		return result;
	}

	ostream& operator<<(ostream& ostr, const TextFile& text)
	{
		text.view(ostr);

		return ostr;

	}

	std::istream& operator>>(std::istream& istr, TextFile& text)
	{
		text.getFile(istr);
		return istr;
	}
}