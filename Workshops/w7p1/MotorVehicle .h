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
#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H

#include <iostream>

namespace sdds
{
	class MotorVehicle {
		char plateNum[9]{ '\0' };
		char VehicleAddress[64]{ '\0' };
		unsigned int MakeYear{ 0 };
	public:
		MotorVehicle() {};
		MotorVehicle(const char* location = "Factory", int year, const char* license);
		~MotorVehicle() {};

		// moves the vehicle to the new address
		void moveTo(const char* _address);

		// Display the information of MotorVehicle
		std::ostream& write(std::ostream& os) const;

		// Receive new information from the user
		std::istream& read(std::istream& in);

	};

	//helper funs 
	std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& src);
	std::istream& operator>>(std::istream& istr, MotorVehicle& src);
}
#endif 