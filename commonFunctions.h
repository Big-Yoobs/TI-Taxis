#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

#include "Settings.h"

//third party lib
#include "libs/cscrutil/scrutil.h" //DO NOT INCLUDE THIS OUTSIDE OF THIS .h OR THE MAIN CPP (unless you know what you are doing)
//call scr funcs from the commonFuncs instance and write your own in the scr section of commonFunctions

namespace CommonFunctions {
	//public vars//////////////////////////////////////////////////////////////////////////////////////////
	const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; //the entire alphabet in a string first starting with lowercase then uppercase
	const std::string symbol = "`~!@#$%^&*()_-+={}[]|\\:;'\",<.>/?"; //all symbols on a normal kayboard in a string
	const std::string numbers = "0123456789"; //all numbers in a string (0123456789)
	//////////////////////////////////////////////////////////////////////////////////////////////////////////


	//puts the thread to sleep the milliseconds entered
	void waitTime(int milliseconds);

	//displays message telling the user why their input was wrong
	//1 = too many chars, 2 = alphasymbolic chars were illegal, 3 = number inputted was out of range
	void wrongInput(int errorCode);

	//asks the user to press any button to continue
	//1 = continue message, 2 = goback message
	void continueInput(int promptType);

	//check if str has num char
	bool strHasNum(std::string str);

	//check if str has symbol char
	bool strHasSymbol(std::string str);

	//check if str has alpha char
	bool strHasAlphabet(std::string str);

	//acceptSound sfx that plays when you hit enter normally (this just plays the sound)
	void acceptSound();

	//Go back sound. Sound that plays when you 'go back' normally (this just plays the sound) 
	void negativeSound();

	//Movement sound. Sound that plays normally when you use the wasd keys to move (this just plays the sound)
	void movementSound();
	
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		
	

	//scrFunctions///////////////////////////////////////////////////////////////////////////////////////////////////
	// this is a set of functions to interact with the cscutil lib

	//clears the terminal screen
	void returnClearScreen();

	//resets console text color's to our default yellowText, black background
	void resetColors();

	//takes in a string of text and outputs it in the console with a yellow background yellow text
	void highlightText(std::string text);  

	//turns on our highlight text colors (good for if you dont have a convenient string to input into highlightText(text)
	void turnOnHighlight();

	//outputs a screen transition animation using cout
	void screenTransitionAnim();

	//outputs a string to the console centered
	void centerGraphic(std::string graphic);

	//outputs a string to the console centered and animated line by line
	void centerGraphicLineAnim(std::string graphic);

	//outputs a string to the console centered and animated line by line w/ highlight
	void centerGraphicLineAnim2(std::string graphic, int waitDuration);
	void centerGraphicLineAnim2(std::string graphic);


	//outputs a string to the console vertically centered but Right aligned
	void centerGraphicR(std::string graphic);

	//outputs a string to the console in the top right corner
	void displayGraphicRU(std::string graphic);

	//returns the amount of white spaces needed to center a single line of text horizontally
	int getCenterSpacesStr(std::string text);

	//returns the amount of white spaces needed to center a horizontal vector of strings horizontally.
	int getCenterSpacesVec(std::vector<std::string> textVec);

	//returns the amount of \n's needed to center a string
	int getCenterNLsStr(std::string text);

	//returns the amount of \n's needed to center verticle vector
	int getCenterNLsVec(std::vector<std::string> textVec);


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 
	 
	 
	 
	//genericFunctions////////////////////////////////////////////////////////////////////////////////////////////////
	// these functions are for random QoL improvements


	std::string reCase(std::string input, bool uppercase); // change case of string

	std::string upperCase(std::string input); // convert strng to uppercase

	std::string lowerCase(std::string input); // convert string to lowercase


	int clamp(int value, int lower, int higher); // clamp value between two extremes

	double clamp(double value, double lower, double higher); // clamp value between two extremes

	long clamp(long value, long lower, long higher); // clamp value between two extremes


	std::string formatDistance(long distance); // format distance nicely

	std::string formatPrice(float price);
};
