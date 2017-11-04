#include "MotorVehicle.h"
#include <iostream>
#include <string>

MotorVehicle::MotorVehicle(Category vehicleType, unsigned int numDoors,
                 unsigned int maxPassengers, double engineHP,
                 std::string licensePlate)
	:vehicleType(vehicleType), maxPassengers(maxPassengers), doors(numDoors), plate(licensePlate), horsepower(engineHP), currentPassengers(0)
{

}

bool MotorVehicle::addPassenger(bool overrideLimit)
{
	if(currentPassengers < maxPassengers){
		currentPassengers++;
		return true;
	}else if(currentPassengers - maxPassengers < 2 && overrideLimit){
		currentPassengers++;
		return true;
	}
	else{
		return false;
	}
}

unsigned int MotorVehicle::getMaxPassengers() const
{
	return maxPassengers;
}

unsigned int MotorVehicle::getNumPassengers() const
{
	return currentPassengers;
}

int MotorVehicle::getSpotsRemaining() const
{
	int spotsRemaining = maxPassengers;
	if (currentPassengers >= maxPassengers){
		return 0;
	}
	
	else{
		/**spotsRemaining -= currentPassengers;**/ spotsRemaining = spotsRemaining - currentPassengers;
		return spotsRemaining;
	}
}

unsigned int MotorVehicle::getNumDoors() const
{
	return doors;
}

double MotorVehicle::getHorsepower() const
{
	return horsepower;
}

void MotorVehicle::setHorsepower(double newHP)
{
	horsepower = newHP;
}

std::string MotorVehicle::getLicense() const
{
	return plate;
}
