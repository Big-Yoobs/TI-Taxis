#include "Address.h"

Address::Address(std::string address, std::string name) {
	this->address = address;
	this->name = name;
}

bool Address::isNamed() {
	return name != "";
}

//getters
std::string Address::getAddress() {
	return address;
}

std::string Address::getName() {
	return name;
}