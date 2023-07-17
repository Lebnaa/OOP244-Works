/*
*****************************************************************************
							  Workshop - #7 (Part-2)
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
#include "MotorVehicle.h"
#include "cstring.h"

using namespace std; 

namespace sdds {
	MotorVehicle::MotorVehicle(const char* license, int year, const char* location)
	{
		if (license)
		{
			strCpy(plateNum, license);
			MakeYear = year;
			strCpy(VehicleAddress, location);
		}
	}
		void MotorVehicle::moveTo(const char* address) 
		{
			if (strCmp(VehicleAddress, address) != 0)
			{
				cout << "|";
				cout.width(8);
				cout <<  plateNum << "| |";

				cout.width(20);
				cout << VehicleAddress << " ---> ";

				cout.width(20);
				cout << left << address << "|" << right << endl;

				strCpy(VehicleAddress, address);
			}
		}

		std::ostream& MotorVehicle::write(std::ostream & os) const
		{
			os << "|";
			os.width(5);
			os << MakeYear << " | " << plateNum << " | " << VehicleAddress;

			return os;
		}

		std::istream& MotorVehicle::read(std::istream & in)
		{
			cout << "Built year: ";
			in >> MakeYear;

			while (!in)
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Invaild year, Retry to enter: ";
				cin >> MakeYear;
			}

			cout << "License plate: ";
			in >> plateNum;

			cout << "Current location: ";
			in >> VehicleAddress;

			while (VehicleAddress[0] < 65 || VehicleAddress[0] > 122)
			{
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "Invalid location, Retry to enter: ";
				cin >> VehicleAddress;
			}

			return in;
		}

		std::ostream& operator<<(std::ostream & ostr, const MotorVehicle & src)
		{
			return src.write(ostr);
		}

		std::istream& operator>>(std::istream & istr, MotorVehicle & src)
		{
			return src.read(istr);
		}

	}

