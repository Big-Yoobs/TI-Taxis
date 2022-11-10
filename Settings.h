#pragma once
namespace Settings {
	//turns off and on the flashing cursor in the console
	void showCursor(bool cursorBool); //taken from here https://stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console-cmd-prompt

	// getters
	void setControlMode(bool controlMode);
	void toggleControlMode(); //if controlMode on turn it off and vice versa
	void setSound(bool sound);
	void toggleSound(); //if sound is on turn it off and vice versa
	void setQuit(bool quit);

	// setters
	bool getControlMode();
	bool getSound();
	bool getQuit();
}