#pragma once
#include <string>
struct Driver {
	private:
		std::string name;
		std::string numberPlate;
	public:
		Driver(std::string name, std::string numberPlate);
		std::string getName();
		std::string getNumberPlate();
};

