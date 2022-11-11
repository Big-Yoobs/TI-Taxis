#include "Settings.h"
#include <Windows.h>

bool controlMode; //if true we use the keyboard to navigate menus, else we use cin
bool sound; //if true sfx will play
bool quit;




void Settings::setControlMode(bool newControlMode) {
	controlMode = newControlMode;
	showCursor(!controlMode);
}

//if controlMode on turn it off and vice versa
void Settings::toggleControlMode() {
	controlMode = !controlMode;
	showCursor(!controlMode);
}

void Settings::setSound(bool newSound) {
	sound = newSound;
}

//if sound is on turn it off and vice versa
void Settings::toggleSound() {
	sound = !sound;
}

void Settings::setQuit(bool newQuit) {
	quit = newQuit;
}



//getters
bool Settings::getControlMode() {
	return controlMode;
}

bool Settings::getSound() {
	return sound;
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