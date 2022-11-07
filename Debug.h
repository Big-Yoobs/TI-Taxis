#pragma once
#include <string>
#include <iostream>

namespace Debug {
	void out(std::string message); // sends debug message to console only if debug mode is enabled
	void setDebug(bool newMode); // set debug mode
}