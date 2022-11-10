#include "commonFunctions.h"



//functions////////////////////////////////////////////////////////////////////////////////////

//turns off and on the flashing underscore in the console
void CommonFunctions::showCursor(bool cursorBool) {
	//ref: https://stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console-cmd-prompt
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);  //windows only function

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = cursorBool; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);

}

//puts the thread to sleep the milliseconds entered
void CommonFunctions::waitTime(int milliseconds) {
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

//displays message telling the user why their input was wrong
//1 = too many chars, 2 = alphasymbolic chars were illegal, 3 = number inputted was out of range
void CommonFunctions::wrongInput(int errorCode) {
	returnClearScreen();

	switch (errorCode) {

		//case 0: no error

	case 1: //string was too long
		std::cout << "\tYour input had too many characters.";
		break;

	case 2: //string used alphasymbolic characters where it shouldnt
		std::cout << "\tYour input had symbols or letters which are not accepted for this input.";
		break;
	case 3: //isInt true however inputted number is out of range (isIntMax and isIntMin)
		std::cout << "\tThe number you inputted was out of range.";
		break;
	}

	std::cout << "\n\tPlease try again...";

	continueInput(2);

	returnClearScreen();
}

//asks the user to press any button to continue
//1 = continue message, 2 = goback message
void CommonFunctions::continueInput(int promptType) {

	
	std::string tempInput; //used for cin

	switch (promptType) {
	case 1: //continue
		
		if (controlMode) { 
			std::cout << "\tPress Accept to Continue.";
			waitTime(500); //slight pause so we cant just instantly exit the func
			while (1) { //stuck in loop until the user presses one of the buttons
				if (GetKeyState(VK_RETURN) & 0x8000 || GetKeyState(VK_SPACE) & 0x8000) {
					break;
				}

			}
			waitTime(500); //adding a pause and flushing the buffer so our key presses dont carry over to the next function
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); 
		}
		else { //cin mode
			
			std::cout << "\tEnter Any Character to continue...\n\n";
			std::cout << "\tEnter Input: ";
			std::cin >> tempInput;

		}
		break;

	case 2: //back

		if (controlMode) {
			std::cout << "\tPress Back to Return.";
			waitTime(500); //slight pause so we cant just instantly exit the func
			while (1) { //stuck in loop until the user presses one of the button
				if (GetKeyState(VK_BACK) & 0x8000) {
					break;
				}
			}
			waitTime(500); //adding a pause and flushing the buffer so our key presses dont carry over to the next function
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		}
		else { //cin mode
			
			std::cout << "\tEnter Any Character to Return..\n\n";
			std::cout << "\tEnter Input: ";
			std::cin >> tempInput;
			
		}
	}
}

//check if str has num char
bool CommonFunctions::strHasNum(std::string str) {

	for (int i = 0; i < str.size(); i++) { //looping through inputted string
		for (int j = 0; j < numbers.size(); j++) { //looping through numbers string
			if (str[i] == numbers[j]) { return true; } //return true if it finds a number
		}
	}
	return false; //return false if it doesnt
}

//check if str has symbol char
bool CommonFunctions::strHasSymbol(std::string str) {

	for (int i = 0; i < str.size(); i++) { //looping through inputted string
		for (int j = 0; j < symbol.size(); j++) { //looping through symbols string
			if (str[i] == symbol[j]) { return true; } //return true if it finds a symbol
		}
	}
	return false; //return false if it doesnt
}

//check if str has alphabetical char
bool CommonFunctions::strHasAlphabet(std::string str) {

	for (int i = 0; i < str.size(); i++) { //looping through inputted string
		for (int j = 0; j < alphabet.size(); j++) { //looping through alphabet string
			if (str[i] == alphabet[j]) { return true; } //return true if it finds a alphabetical char
		}
	}
	return false; //return false if it doesnt
}

//start screen
void CommonFunctions::startScreen() {
	
	for (int i = 0; i < getCenterNLsStr(""); i++) {
		std::cout << "\n";
	}
	for (int i = 0; i < getCenterSpacesStr("Press ALT + ENTER to Continue..."); i++) {
		std::cout << " ";
	}
	std::cout << "Press ALT + ENTER to Continue...";
	while (1) {
		if (GetKeyState(VK_MENU) & 0x8000 && GetKeyState(VK_RETURN) & 0x8000) {
			break;
		}
	}
	returnClearScreen();
	if (getControlMode()) { //hiding our cursor after going fullscreen
		showCursor(false);
	}


}


//acceptSound sfx that plays when you hit enter normally (this just plays the sound)
void CommonFunctions::acceptSound() {
	if (getSound()) { 
		Beep(200, 150);
		Beep(250, 600);
	}
}

//Go back sound. Sound that plays when you 'go back' normally (this just plays the sound) 
void CommonFunctions::negativeSound() {
	if (getSound()) { 
		Beep(200, 150); 
		Beep(150, 600);
	}
}

//Movement sound. Sound that plays normally when you use the wasd keys to move (this just plays the sound)
void CommonFunctions::movementSound() {
	if (getSound()) { Beep(200, 150); }
}




//setters
void CommonFunctions::setControlMode(bool controlMode) {

	this->controlMode = controlMode;
	if (controlMode) { showCursor(false); }
	else { showCursor(true); }

}

//if controlMode on turn it off and vice versa
void CommonFunctions::toggleControlMode() {
	if (controlMode) { 
		controlMode = false;
		showCursor(true);
	}
	else { 
		controlMode = true; 
		showCursor(false);
	}
}

void CommonFunctions::setSound(bool sound) {
	this->sound = sound;
}

//if sound is on turn it off and vice versa
void CommonFunctions::toggleSound() {
	if (sound) { sound = false; }
	else { sound = true; }
}

void CommonFunctions::setQuit(bool quit) {
	this->quit = quit;
}



//getters
bool CommonFunctions::getControlMode() {
	return controlMode;
}

bool CommonFunctions::getSound() {
	return sound;
}

bool CommonFunctions::getQuit() {
	return quit;
}




//scrFunctions//////////////////////////////////////////////
// this is a set of functions to interact with the cscutil lib

//clears the terminal screen
void CommonFunctions::returnClearScreen() {
	scrClear();
}

//resets console text color's to our default yellowText, black background
void CommonFunctions::resetColors() {
	scrSetColors(scrYellow, scrBlack);

}

//takes in a string of text and outputs it in the console with a yellow background yellow text
void CommonFunctions::highlightText(std::string text) {
	scrSetColors(scrBlack, scrYellow);
	std::cout << text;
	resetColors(); //resets colors back to our default
}

//turns on our highlight text colors (good for if you dont have a convenient string to input into highlightText(text)
void CommonFunctions::turnOnHighlight() {
	scrSetColors(scrBlack, scrYellow);
}

//outputs a screen transition animation using cout
void CommonFunctions::screenTransitionAnim() {

	int consoleHeight = scrGetMaxRows();
	int consoleWidth = scrGetMaxColumns();

	//input arithmetic here
}

//outputs a string to the console centered
void CommonFunctions::centerGraphic(std::string graphic) {
	int consoleHeight = scrGetMaxRows();
	int consoleWidth = scrGetMaxColumns();
	int textLinesAmount = 0; //lines of text
	std::vector <int> charsInlineStart = { 0 }; //starting position in each line
	std::vector <int> charsInline = { 0 };  //char amount in each line
	int biggestLine = 0; //line in the graphic with the most chars

	//counting the lines of text
	for (int i = 0; i < size(graphic); i++) {
		if (graphic[i] == '\n') {
			textLinesAmount++;

		}
	}
	//counter the amount of chars in each line
	int charsInlineIndexer = 0;
	for (int i = 0; i < size(graphic); i++) {
		if (graphic[i] == '\n') {
			charsInline.push_back((i - 1) - charsInlineIndexer);

			charsInlineStart.push_back(i + 1);
			charsInlineIndexer = i;
		}
	}
	charsInline.erase(charsInline.begin()); // we remove the first element as we have to initialize our vec with a single 0 thats no longer necessary

	for (int i = 0; i < size(charsInline); i++) { //going through our vector of char amount per line and finding the biggest one
		if (charsInline[i] > biggestLine) {
			biggestLine = charsInline[i];
		}
	}


	//outputting to the console
	int counter = 0; //counter that goes up in both i and j loops
	for (int i = 0; i <= textLinesAmount; i++) {
		//(height / 2) gives us the verticle center then we go up by half of the verticle size of our graphic then we go down by the value of i to return a line each run of our loop
		//we do the same with the width of our graphic but we dont need to return a line
		scrMoveCursorTo((consoleHeight / 2) - (textLinesAmount / 2) + i, (consoleWidth / 2) - (biggestLine / 2)); 
		for (int j = 0; j < biggestLine; j++) {
			if (graphic[counter] != '\n') {
				std::cout << graphic[counter];
				counter++;
			}
			else { //if and else conditions used to skip line breaks as we are doing the line breaks with our scrMoveCursorTo arithmetic
				counter++;
				break;
			}

		}
	}

}

//outputs a string to the console cnetered and animated line by line
void CommonFunctions::centerGraphicLineAnim(std::string graphic) {
	
	int consoleHeight = scrGetMaxRows();
	int consoleWidth = scrGetMaxColumns();
	int textLinesAmount = 0; //lines of text
	std::vector <int> charsInlineStart = { 0 }; //starting position in each line
	std::vector <int> charsInline = { 0 };  //char amount in each line
	int biggestLine = 0; //line in the graphic with the most chars

	//counting the lines of text
	for (int i = 0; i < size(graphic); i++) {
		if (graphic[i] == '\n') {
			textLinesAmount++;

		}
	}
	//counter the amount of chars in each line
	int charsInlineIndexer = 0;
	for (int i = 0; i < size(graphic); i++) {
		if (graphic[i] == '\n') {
			charsInline.push_back((i - 1) - charsInlineIndexer);

			charsInlineStart.push_back(i + 1);
			charsInlineIndexer = i;
		}
	}
	charsInline.erase(charsInline.begin()); // we remove the first element as we have to initialize our vec with a single 0 thats no longer necessary

	for (int i = 0; i < size(charsInline); i++) { //going through our vector of char amount per line and finding the biggest one
		if (charsInline[i] > biggestLine) {
			biggestLine = charsInline[i];
		}
	}


	//outputting to the console
	int counter = 0; //counter that goes up in both i and j loops
	int lineCounterStart = 0;
	int lineCounterEnd = 0;
	for (int i = 0; i <= textLinesAmount; i++) {
		//(height / 2) gives us the verticle center then we go up by half of the verticle size of our graphic then we go down by the value of i to return a line each run of our loop
		//we do the same with the width of our graphic but we dont need to return a line
		
		scrMoveCursorTo((consoleHeight / 2) - (textLinesAmount / 2) + i, (consoleWidth / 2) - (biggestLine / 2));
		for (int j = 0; j < biggestLine; j++) {
			if (graphic[counter] != '\n') {
				
				std::cout << graphic[counter];
				counter++;
				lineCounterEnd++;
			}
			else { //if and else conditions used to skip line breaks as we are doing the line breaks with our scrMoveCursorTo arithmetic
				counter++;
				
				waitTime(200);
				break;
			}

		}
		
	}
}

//outputs a string to the console cnetered and animated line by line
void CommonFunctions::centerGraphicLineAnim2(std::string graphic, int waitDuration) {

	int consoleHeight = scrGetMaxRows();
	int consoleWidth = scrGetMaxColumns();
	int textLinesAmount = 0; //lines of text
	std::vector <int> charsInlineStart = { 0 }; //starting position in each line
	std::vector <int> charsInline = { 0 };  //char amount in each line
	int biggestLine = 0; //line in the graphic with the most chars

	//counting the lines of text
	for (int i = 0; i < size(graphic); i++) {
		if (graphic[i] == '\n') {
			textLinesAmount++;

		}
	}
	//counter the amount of chars in each line
	int charsInlineIndexer = 0;
	for (int i = 0; i < size(graphic); i++) {
		if (graphic[i] == '\n') {
			charsInline.push_back((i - 1) - charsInlineIndexer);

			charsInlineStart.push_back(i + 1);
			charsInlineIndexer = i;
		}
	}
	charsInline.erase(charsInline.begin()); // we remove the first element as we have to initialize our vec with a single 0 thats no longer necessary

	for (int i = 0; i < size(charsInline); i++) { //going through our vector of char amount per line and finding the biggest one
		if (charsInline[i] > biggestLine) {
			biggestLine = charsInline[i];
		}
	}


	//outputting to the console
	
	int lineCounterStart = 0;
	int lineCounterEnd = 0;
	for (int a = 0; a <= textLinesAmount; a++) {
		int counter = 0; //counter that goes up in both i and j loops
		for (int i = 0; i <= a; i++) {
			//(height / 2) gives us the verticle center then we go up by half of the verticle size of our graphic then we go down by the value of i to return a line each run of our loop
			//we do the same with the width of our graphic but we dont need to return a line
			std::string line = "";
			scrMoveCursorTo((consoleHeight / 2) - (textLinesAmount / 2) + i, (consoleWidth / 2) - (biggestLine / 2));
			if (a == i) { turnOnHighlight(); }
			for (int j = 0; j < biggestLine; j++) {
				if (graphic[counter++] != '\n') {
					line += graphic[counter - 1]; // instead of printing each individual char to the console, we add them to a string and at the end we add the whole string to the console. less work for the console = faster
				}
				else { //if and else conditions used to skip line breaks as we are doing the line breaks with our scrMoveCursorTo arithmetic
					break;
				}
			}
			std::cout << line;
		}
		waitTime(waitDuration); // fixed so we wait at the end of each frame instead of at the end of each line in each frame
		Beep(100, waitDuration + 100);
		resetColors();
	}
	Beep(200, waitDuration + 100);
	Beep(250, waitDuration + 500);
}

void CommonFunctions::centerGraphicLineAnim2(std::string graphic) {
	centerGraphicLineAnim2(graphic, 20);
}

// outputs a string to the console vertically centered but Right aligned
void CommonFunctions::centerGraphicR(std::string graphic) {
	int consoleHeight = scrGetMaxRows();
	int consoleWidth = scrGetMaxColumns();
	int textLinesAmount = 0; //lines of text
	std::vector <int> charsInlineStart = { 0 }; //starting position in each line
	std::vector <int> charsInline = { 0 };  //char amount in each line
	int biggestLine = 0; //line in the graphic with the most chars

	//counting the lines of text
	for (int i = 0; i < size(graphic); i++) {
		if (graphic[i] == '\n') {
			textLinesAmount++;

		}
	}
	//counter the amount of chars in each line
	int charsInlineIndexer = 0;
	for (int i = 0; i < size(graphic); i++) {
		if (graphic[i] == '\n') {
			charsInline.push_back((i - 1) - charsInlineIndexer);

			charsInlineStart.push_back(i + 1);
			charsInlineIndexer = i;
		}
	}
	charsInline.erase(charsInline.begin()); // we remove the first element as we have to initialize our vec with a single 0 thats no longer necessary

	for (int i = 0; i < size(charsInline); i++) { //going through our vector of char amount per line and finding the biggest one
		if (charsInline[i] > biggestLine) {
			biggestLine = charsInline[i];
		}
	}


	//outputting to the console
	int counter = 0; //counter that goes up in both i and j loops
	for (int i = 0; i <= textLinesAmount; i++) {
		//(height / 2) gives us the verticle center then we go up by half of the verticle size of our graphic then we go down by the value of i to return a line each run of our loop
		//instead of doing the same horizontally we go to furthest right of the console minus the biggest line, minus a tab or so
		scrMoveCursorTo((consoleHeight / 2) - (textLinesAmount / 2) + i, consoleWidth - biggestLine - 5);
		for (int j = 0; j < biggestLine; j++) {
			if (graphic[counter] != '\n') {
				std::cout << graphic[counter];
				counter++;
			}
			else { //if and else conditions used to skip line breaks as we are doing the line breaks with our scrMoveCursorTo arithmetic
				counter++;
				break;
			}

		}
	}

}

//outputs a string to the console in the top right corner
void CommonFunctions::displayGraphicRU(std::string graphic) {
	int consoleHeight = scrGetMaxRows();
	int consoleWidth = scrGetMaxColumns();
	int textLinesAmount = 0; //lines of text
	std::vector <int> charsInlineStart = { 0 }; //starting position in each line
	std::vector <int> charsInline = { 0 };  //char amount in each line
	int biggestLine = 0; //line in the graphic with the most chars

	//counting the lines of text
	for (int i = 0; i < size(graphic); i++) {
		if (graphic[i] == '\n') {
			textLinesAmount++;

		}
	}
	//counter the amount of chars in each line
	int charsInlineIndexer = 0;
	for (int i = 0; i < size(graphic); i++) {
		if (graphic[i] == '\n') {
			charsInline.push_back((i - 1) - charsInlineIndexer);

			charsInlineStart.push_back(i + 1);
			charsInlineIndexer = i;
		}
	}
	charsInline.erase(charsInline.begin()); // we remove the first element as we have to initialize our vec with a single 0 thats no longer necessary

	for (int i = 0; i < size(charsInline); i++) { //going through our vector of char amount per line and finding the biggest one
		if (charsInline[i] > biggestLine) {
			biggestLine = charsInline[i];
		}
	}


	//outputting to the console
	int counter = 0; //counter that goes up in both i and j loops
	for (int i = 0; i <= textLinesAmount; i++) {
		//vertically we go down three lines to not be hugging the border and then we increment down with i
		//instead of doing the same horizontally we go to furthest right of the console minus the biggest line, minus a tab or so
		scrMoveCursorTo(3 + i, consoleWidth - biggestLine - 5);
		for (int j = 0; j < biggestLine; j++) {
			if (graphic[counter] != '\n') {
				std::cout << graphic[counter];
				counter++;
			}
			else { //if and else conditions used to skip line breaks as we are doing the line breaks with our scrMoveCursorTo arithmetic
				counter = counter + 2;
				break;
			}

		}
	}

}


//returns amount of white spaces needed to center a single line of text horizontally
int CommonFunctions::getCenterSpacesStr(std::string text) {

	int spaces = 0;
	int consoleWidth = scrGetMaxColumns();

	spaces = (consoleWidth / 2) - (size(text) / 2); //same arithmetic from centerGraphic(std::string graphic) but for a single line
	return spaces;

}

//returns the amount of white spaces needed to center a horizontal vector of strings horizontally.
int CommonFunctions::getCenterSpacesVec(std::vector<std::string> textVec) {
	std::string textVecStr;
	int spaces = 0;
	int consoleWidth = scrGetMaxColumns();

	for (int i = 0; i < size(textVec); i++) {
		textVecStr = textVecStr + textVec[i];
	}
	spaces = (consoleWidth / 2) - (size(textVecStr) / 2); //same arithmetic from getCenterSpacesStr()
	spaces = spaces - size(textVec); //assumes you are going to output the vector with a space between each element

	return spaces;
}

//returns the amount of \n's needed to center a string (input a single element of a vector to get a horizontal vector nl amount)
int CommonFunctions::getCenterNLsStr(std::string text) {
	int newLines = 0;
	int textLines = 0;
	int consoleHeight = scrGetMaxRows();

	for (int i = 0; i < size(text); i++) { //getting the total amount of lines in our input str
		if (text[i] == '\n') { textLines++; }
	}

	if (textLines > 0) { //avoiding dividing by zero
		newLines = (consoleHeight / 2) - (textLines / 2); //same arithmetic from getCenterSpacesStr()
	}
	else { newLines = consoleHeight / 2; }
	return newLines;
}

//returns the amount of \n's needed to center verticle vector (assumes each element is one line)
int CommonFunctions::getCenterNLsVec(std::vector<std::string> textVec) {
	int newLines = 0;
	int textLines = size(textVec);
	int consoleHeight = scrGetMaxRows();

	newLines = (consoleHeight / 2) - (textLines / 2); //same arithmetic from before
	return newLines;
}

std::string CommonFunctions::reCase(std::string input, bool uppercase) {
	for (int i = 0; i < size(input); i++) {
		input[i] = uppercase ? toupper(input[i]) : tolower(input[i]);
	}
	return input;
}

std::string CommonFunctions::upperCase(std::string input) {
	return reCase(input, true);
}

std::string CommonFunctions::lowerCase(std::string input) {
	return reCase(input, false);
}



int CommonFunctions::clamp(int value, int lower, int higher) {
	if (value < lower) value = lower;
	if (value > higher) value = higher;
	return value;
}

double CommonFunctions::clamp(double value, double lower, double higher) {
	if (value < lower) value = lower;
	if (value > higher) value = higher;
	return value;
}

long CommonFunctions::clamp(long value, long lower, long higher) {
	if (value < lower) value = lower;
	if (value > higher) value = higher;
	return value;
}



std::string CommonFunctions::formatDistance(long distance) {
	if (distance < 1000) return distance + "m";
	double newDistance = round(distance / 10) / 100;
	int decimal = (int) (newDistance * 100) % 100;
	std::string km = std::to_string((int) newDistance);
	std::string out = "km";
	if (decimal) {
		out = "." + std::to_string(decimal) + out;
	}
	for (int i = size(km) - 1; i >= 0; i--) {
		out = km[i] + out;
		if (!((size(km) - i) % 3) && i > 0) out = "," + out;
	}
	return out;
}