#include "Settings.h"
#include "ConfigFile.h"
#include <Windows.h>
#include "Debug.h"


ConfigFile config("settings.json");
std::string userId;

bool getBool(std::string key) {
	if (config.get()[userId][key].is_boolean()) {
		return config.get()[userId][key].get<bool>();
	}
	return true;
}

bool setBool(std::string key, bool value) {
	if (userId == "") return value;
	config.get()[userId][key] = value;
	return value;
}

bool quit;


void Settings::loadForUser(std::string id) {
	if (!config.fileExists()) {
		config.get() = Json::parse("{}");
	}
	std::map<std::string, Json> users = config.get().get<std::map<std::string, Json>>();
	bool foundSettings = false;
	for (std::map<std::string, Json>::iterator i = users.begin(); i != users.end(); i++) {
		if (i->first == id) {
			foundSettings = true;
			break;
		}
	}
	if (!foundSettings) {
		config.get()[id] = Json::parse("{\"controlMode\":true,\"sound\":true}"); // default settings
		config.save();
	}
	userId = id;
}

void Settings::save() {
	config.save();
}


void Settings::setControlMode(bool newControlMode) {
	showCursor(!setBool("controlMode", newControlMode));
}

//if controlMode on turn it off and vice versa
void Settings::toggleControlMode() {
	showCursor(!setBool("controlMode", !getBool("controlMode")));
}

void Settings::setSound(bool newSound) {
	showCursor(!setBool("sound", newSound));
}

//if sound is on turn it off and vice versa
void Settings::toggleSound() {
	setBool("sound", !getBool("sound"));
}

void Settings::setQuit(bool newQuit) {
	quit = newQuit;
}



//getters
bool Settings::getControlMode() {
	return getBool("controlMode");
}

bool Settings::getSound() {
	return getBool("sound");
}

bool Settings::getQuit() {
	return quit;
}




//turns off and on the flashing underscore in the console
void Settings::showCursor(bool cursorBool) {
	//ref: https://stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console-cmd-prompt
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);  //windows only function

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = cursorBool; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);

}