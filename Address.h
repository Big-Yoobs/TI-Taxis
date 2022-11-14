#pragma once

#include "string"

struct Address {
	std::string address;
	std::string name;

	bool isNamed();
	Address(std::string address, std::string name);
};