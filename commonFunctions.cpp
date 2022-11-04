#include "commonFunctions.h"


void CommonFunctions::returnClearScreen() { //clears the screen by returning so many lines
	std::cout << "\x1B[2J\x1B[H"; //ascii escape code to clear the screen
	std::cout << "\n\n\n"; //adding three return lines to make the next set of console outputs not at the complete top of the screen
}

void CommonFunctions::returnLine(int amount) {
	for (int i = 0; i <= amount; i++) {
		std::cout << "\n";
	}
}

void CommonFunctions::createLine(char symbol, int amount) {
	for (int i = 0; i <= amount; i++) {
		std::cout << symbol;
	}
	std::cout << "\n";
}

bool CommonFunctions::userInput(bool isInt, bool isStr, bool isSymbol, int isIntMin, int isIntMax, int lengthAllowed) { //takes in a number of variables and returns whether it is acceptable or not
    correctInput = true;
    wrongInputCode = 0;

    std::cout << "\n\nEnter Input: ";
    std::cin >> userInputStr;

    if (size(userInputStr) > lengthAllowed) { //checking to see if the input is longer than what is acceptable
        correctInput = false;
        wrongInputCode = 1;         

    }

    if (isInt && correctInput) { //is int
        for (int i = 0; i < size(userInputStr); i++) { //looping through inputStr the string the user inputs
			for (int j = 0; j < size(alphabet); j++) { //comparing to every letter of the alphabet
				if (userInputStr[i] == alphabet[j]) {
					correctInput = false;
					wrongInputCode = 2;
				}
			}
			for (int k = 0; k < size(symbol); k++) { //comparing to every symbol
				if (userInputStr[i] == symbol[k]) {
					correctInput = false;
					wrongInputCode = 2;
				}
			}
		}

		if (correctInput) { //if the isInt has no alphasymbol characters now see if it is potentially out of range for the input
			if (std::stoi(userInputStr) < isIntMin || std::stoi(userInputStr) > isIntMax) {
				correctInput = false;
				wrongInputCode = 3;
			}
		}
    }

    if (isStr && correctInput) { //if its supposed to be a string with no symbonumeric characters

		for (int i = 0; i < size(userInputStr); i++) {
			for (int j = 0; j < size(numbers); j++) {
				if (userInputStr[i] == numbers[j]) {
					correctInput = false;
					wrongInputCode = 2;
				}
			}
			for (int k = 0; k < size(symbol); k++) {
				correctInput = false;
				wrongInputCode = 2;
			}			
		}
	}
    
    if (!correctInput) {
		wrongInput(wrongInputCode);
		return false;
	}
	else {
		return true;
	}

}

void CommonFunctions::wrongInput(int errorCode) {
    
	std::cout << "\n\n";

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

void CommonFunctions::continueInput(int selector) { //gives a prompt to the user to enter any character to continue or go back 1 = continue 2 = go back
    std::string tempInput = "";
	std::cout << "\n";

	switch (selector) {

	case 1: //continue
		std::cout << "\tEnter any character to continue: ";
		break;
	case 2: //go back
		std::cout << "\tEnter any character to go back: ";
		break;
	}
	std::cin >> tempInput;
	tempInput = "";
	returnClearScreen();
}




//getters
std::string CommonFunctions::getUserInput() {
	return userInputStr;
}
std::string CommonFunctions::getAlphabet() {
	return alphabet;
}
std::string CommonFunctions::getNumbers() {
	return numbers;
}
std::string CommonFunctions::getSymbol() {
	return symbol;
}