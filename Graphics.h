#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Debug.h"

class Graphics
{
private:

	

public:
	//main.ascii
	std::string main;

	//settings.ascii
	std::string settings;

	//user1.ascii
	std::string user1;

	//user2.ascii
	std::string user2;

	//user3.ascii
	std::string user3;

	void iniGraphics(); //assigns ascii file contents to strings

	

};

