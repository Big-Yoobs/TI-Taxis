#include "Driver.h"

Driver::Driver(std::string name, std::string numberPlate) {
	this->name = name;
	this->numberPlate = numberPlate;
}

std::string Driver::getName() {
	return name;
}

std::string Driver::getNumberPlate() {
	return numberPlate;
}