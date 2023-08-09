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
#include "LibApp.h"
using namespace std; 

namespace sdds {

	bool LibApp::confirm(const char* message)
	{
		bool result = false;

		Menu menu(message); 
		menu << "Yes"; 

		int returnValue = menu.run(); 
		if (returnValue == 1)
		{
			result = true; 
		}

		return result; 
	}
	void LibApp::load()
	{
		cout << "Loading Data" << endl; 
	}

	void LibApp::save()
	{
		cout << "Saving Data" << endl; 
	}

	void LibApp::search()
	{
		cout << "Searching for publication" << endl; 
	}

	void LibApp::returnPub()
	{
		search(); 
		cout << "Returning publication" << endl; 
		cout << "Publication returned" << endl;
		cout << endl; 
		m_changed = true; 
	}

	void LibApp::newPublication()
	{
		cout << "Adding new publication to library" << endl; 
		bool confirmed = confirm("Add this publication to library?\n"); 
		if (confirmed)
		{
			m_changed = true; 
			cout << "Publication added" << endl; 
		}
		cout << endl; 
	}

	void LibApp::removePublication()
	{
		cout << "Removing publication from library" << endl; 
		search(); 
		bool confirmed = confirm("Remove this publication from the library?\n"); 
		if (confirmed)
		{
			m_changed = true; 
			cout << "Publication removed" << endl; 
		}

		cout << endl; 
	}
	void LibApp::checkOutPub()
	{
		search(); 
		bool confirmed = confirm("Check out publication?\n");
		if (confirmed)
		{
			m_changed = true; 
			cout << "Publication checked out" << endl; 
		}

		cout << endl; 
	}


	LibApp::LibApp(const char* filename)
	{
		m_mainMenu << "Add New Publication" 
			<< "Remove Publication"
			<< "Checkout publication from library"
			<< "Return publication to library"; 

		m_exitMenu << "Save changes and exit"
			<< "Cancel and go back to the main menu"; 

		load(); 
	}

	void LibApp::run()
	{
		int UserInput, UserInputExit; 

		do
		{
			UserInput = m_mainMenu.run();

			//methods based on users selections until user chose to exit
			switch (UserInput)
			{
			case 0:

				if (m_changed == true)
				{
					UserInputExit = m_exitMenu.run();

					//options according to the choice of user in the exit menu
					switch (UserInputExit)
					{
					case 0: 
						if (confirm("This will discard all the changes are you sure?\n"))
						{
							m_changed = false;
						}
						break;
					case 1:
						save();
						break;
					case 2:
						UserInput = 1;
						break;
					}
				} 
				cout << endl;
				break;

			case 1:
				newPublication();
				break;
			case 2:
				removePublication();
				break;
			case 3:
				checkOutPub();
				break;
			case 4:
				returnPub();
				break;
			}
		} while (UserInput != 0); 

		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}

	// LibApp Destructor
	LibApp::~LibApp()
	{
		for (int i = 0; i < m_NOLP; i++)
		{
			delete m_PPA[i];
		}
	}
}