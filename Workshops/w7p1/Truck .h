/*
*****************************************************************************
							  Workshop - #6 (Part-1)
Full Name  : Lebna Noori
Student ID#: 157672205
Email      : lnoori1@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************/
#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H

#include <iostream>
#include "MotorVehicle .h"
namespace sdds {

	class Truck : public MotorVehicle 
	{
		double MaxCapacity{ 0.00 }; 
		double CurrCapacity{ 0.00 };
	public:
		Truck() {};
		Truck(const char* _license, int _year, double _capacity, const char* address = nullptr); 
		~Truck() {}; 

		//adds to the attribute that stores the current cargo load the
		//weight specified as a parameter
		bool addCargo(double cargo); 

		//unloads current cargo (sets the attribute to 0).
		bool unloadCargo();
	};

	std::ostream& operator<<(std::ostream& ostr, const Truck& src);
	std::istream& operator>>(std::istream& istr, Truck& src);

}
