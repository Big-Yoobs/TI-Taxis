#include "Debug.h"

bool debug = false; // debug mode

namespace Debug {
	void out(std::string message) {
		if (debug) std::cout << "\nDEBUG >> " << message << "\n";
	}
	void setDebug(bool newMode) {
		debug = newMode;
	}
}