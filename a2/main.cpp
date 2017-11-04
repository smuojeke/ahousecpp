#include "MotorVehicle.h"
#include <iostream>
#include <string>


int main()
{
MotorVehicle ahouse (MotorVehicle::Category::SUV, 4, 8, 700, "OMONILE");

	std::cout << "MAXIMUM PASSENGERS ALLOWED: " << ahouse.getMaxPassengers() << std::endl;
	
	for (int i = 0; i < ahouse.getMaxPassengers() + 5; i++){
	std::cout << "LOOK HERE BEFORE TO KNOW IF YOU CAN COME IN: " << ahouse.addPassenger(true) << std::endl;
	std::cout << "NUMBER OF PASSENGERS INSIDE: " << ahouse.getNumPassengers() << std::endl;
	std::cout << "NUMBER OF AVAILABLE SEATS: " << ahouse.getSpotsRemaining() << std::endl;
	std::cout << "NUMBER OF DOORS: " << ahouse.getNumDoors() << std::endl;
	std::cout << "ENGINE CAPACITY: " << ahouse.getHorsepower() << std::endl;
	std::cout << "LICENSE PLATE NUMBER: " << ahouse.getLicense() << std::endl;
	}

	if (ahouse.vehicleType == MotorVehicle::Category::SUV){
	std::cout << "Hi there" << std::endl;
	}
}
	
