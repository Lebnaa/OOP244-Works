/*
*****************************************************************************
							  Workshop - #7 (Part-1)
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
#include "Truck.h"

using namespace std; 

	namespace sdds {

		Truck::Truck(const char* _license, int _year, double _capacity, const char* address) : MotorVehicle(_license, _year)
		{
			if (_capacity > 0) MaxCapacity = _capacity; 
			if (address) this->moveTo(address); 
		}

		bool Truck::addCargo(double cargo)
		{
			bool result = false; 

			if (cargo > 0 && (CurrCapacity != MaxCapacity))
			{
				CurrCapacity += cargo; 
				result = true; 

				if (CurrCapacity > MaxCapacity)
				{
					CurrCapacity = MaxCapacity; 
				}
			}

			return result; 
		}

		bool Truck::unloadCargo()
		{
			bool result = false; 

			if (CurrCapacity > 0)
			{
				CurrCapacity = 0; 
				result = true; 
			}

			return result; 
		}

		ostream& Truck::write(ostream& os) const {

			MotorVehicle::write(os);
			os << " | " << CurrCapacity << "/" << MaxCapacity;
			return os;
		}

		std::istream& Truck::read(std::istream& in)
		{
			MotorVehicle::read(in); 

			cout << "Capacity: "; 
			in >> MaxCapacity; 
			while (!in)
			{
				cin.clear(); 
				//getting rid of extra characters 
				cin.ignore(32767, '\n'); 
				cout << "Invaild Max Capacity, Retry to enter: ";
				in >> MaxCapacity; 
			}

			cout << "Cargo: "; 
			in >> CurrCapacity; 
			while (!in)
			{
				cin.clear(); 
				cin.ignore(32767, '\n'); 
				cout << "Invaild cargo amount, Retry to enter: ";
				in >> CurrCapacity; 
			}

			return in; 
		}


		std::ostream& operator<<(std::ostream& ostr, const Truck& truck)
		{
			return truck.write(ostr);
		}

		std::istream& operator>>(std::istream& istr, Truck& truck)
		{
			return truck.read(istr);
		}

}
