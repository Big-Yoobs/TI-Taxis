#include "Debug.h"

bool debug = false; // debug mode

namespace Debug {
	void out(std::string message) { // prints message only if debug mode is enabled
		if (debug) std::cout << "\nDEBUG >> " << message << "\n";
	}
	void setDebug(bool newMode) { // change debug mode
		debug = newMode;
	}
	bool isOn() {
		return debug;
	}
}