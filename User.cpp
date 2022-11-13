#include "User.h"


//functions
//settters
void User::setFirstName() {
	while (10 == 10) { //first name
		CommonFunctions::returnClearScreen();
		CommonFunctions::centerGraphic("meme\nmeme");  //replace param contents with the sign up menu ascii art
		std::cout << "\n\n\n";
		for (int i = 0; i < CommonFunctions::getCenterSpacesStr("SIGN UP"); i++) { std::cout << " "; }
		std::cout << "SIGN UP\n\n";
		for (int i = 0; i < CommonFunctions::getCenterSpacesStr("Enter First Name: "); i++) { std::cout << " "; }
		std::cout << "Enter First Name: ";
		std::cin >> firstNameStr;

		if (CommonFunctions::strHasNum(firstNameStr) || CommonFunctions::strHasSymbol(firstNameStr)) {
			CommonFunctions::wrongInput(2);
		}

		else {

			break;
		}

	}
}

void User::setLastName() {
	while (25 == 25) { //last name
		CommonFunctions::returnClearScreen();
		CommonFunctions::centerGraphic("meme\nmeme");  //replace param contents with the sign up menu ascii art
		std::cout << "\n\n\n";
		for (int i = 0; i < CommonFunctions::getCenterSpacesStr("SIGN UP"); i++) { std::cout << " "; }
		std::cout << "SIGN UP\n\n";
		for (int i = 0; i < CommonFunctions::getCenterSpacesStr("Enter Last Name: "); i++) { std::cout << " "; }
		std::cout << "Enter Last Name: ";
		std::cin >> lastNameStr;

		if (CommonFunctions::strHasNum(lastNameStr) || CommonFunctions::strHasSymbol(lastNameStr)) {
			CommonFunctions::wrongInput(2);
		}

		else {
			break;
		}

	}
}

void User::setEmail() {
	while (30 == 30) { //email
		CommonFunctions::returnClearScreen();
		CommonFunctions::centerGraphic("meme\nmeme");  //replace param contents with the sign up menu ascii art
		std::cout << "\n\n\n";
		for (int i = 0; i < CommonFunctions::getCenterSpacesStr("SIGN UP"); i++) { std::cout << " "; }
		std::cout << "SIGN UP\n\n";
		for (int i = 0; i < CommonFunctions::getCenterSpacesStr("Enter Email: "); i++) { std::cout << " "; }
		std::cout << "Enter Email: ";
		std::cin >> emailStr;

		//error checking
		std::string emailPrefix;
		std::string emailDomain;
		std::string symbols = "`~!@#$ % ^&*()_ - += {}[] | \\:; '\",<.>/?";
		std::string domainSymbols = "`~!@#$ % ^&*()_ += {}[] | \\:; '\",<.>/?";
		int emailPrefixCount = 0;
		bool containsErrors = false;
		int emailAtCounter = 0;
		int emailPrefixDotCounter = 0;
		int emailDomainDotCounter = 0;

		for (int i = 0; i < size(emailStr); i++) { //checking how many @ symbols

			if (emailStr[i] == '@') {
				emailAtCounter++;
			}
			if (emailStr[i] == '#') {
				containsErrors = true;
			}

			if (i != size(emailStr) - 1) { //checking to see if there are two symbols in a row
				for (int j = 0; j < size(symbols); j++) {
					if (emailStr[i] == symbols[j]) {
						for (int k = 0; k < size(symbols); k++) {
							if (emailStr[i + 1] == symbols[k]) {
								containsErrors = true;
							}
						}
					}
				}
			}


		}
		if (emailAtCounter != 1 || emailStr[size(emailStr) - 1] == '@' || emailStr[0] == '@' || emailStr[0] == '.') { containsErrors = true; }




		if (!containsErrors) { //prefix
			for (int i = 0; i < size(emailStr); i++) {

				if (emailStr[i] == '.') {
					emailPrefixDotCounter++;
				}

				if (emailStr[i] != '@') {
					emailPrefix = emailPrefix + emailStr[i];
				}
				else {
					emailPrefixCount = i;
					break;
				}
			}

			if (emailPrefixDotCounter > 1 || emailPrefix[size(emailPrefix) - 1] == '-') { //if prefix has more than one fullstop or last char is a dash
				containsErrors = true;
			}



		}

		if (!containsErrors) { //domain check

			std::string domainName;
			std::string tld;
			for (int i = emailPrefixCount; i < size(emailStr); i++) {
				if (emailStr[i] == '.') { //counting dots
					emailDomainDotCounter++;
				}
				emailDomain = emailDomain + emailStr[i];
			}
			if (emailDomainDotCounter != 1 || emailDomain[1] == '.') { containsErrors = true; }

			if (!containsErrors) {
				for (int i = 1; i < size(emailDomain); i++) {

					if (emailDomain[i] == '.') { break; }
					domainName = domainName + emailDomain[i];

				}

				for (int i = 0; i < size(domainName); i++) {
					for (int j = 0; j < size(domainSymbols); j++) {
						if (domainName[i] == domainSymbols[j]) {
							containsErrors = true;
						}
					}
				}

				for (int i = size(emailDomain) - 1; i > 0; i--) {
					if (emailDomain[i] == '.') { break; }
					tld = tld + emailDomain[i];
				}

				if (CommonFunctions::strHasNum(tld) || CommonFunctions::strHasSymbol(tld)) { containsErrors = true; }

			}

		}
		if (!containsErrors) {
			if (!isEmailTaken(emailStr)) break;
			std::cout << "\n\n\n\t\tYour Email Is Already Taken Try Again...\n\t\tPress Enter To Continue...";
			CommonFunctions::waitTime(200);
			while (1) {

				if (GetKeyState(VK_RETURN) & 0x8000) {
					while (GetKeyState(VK_RETURN) & 0x8000) {}
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					break;
				}
			}
		}
		else {
			std::cout << "\n\n\n\t\tYour Email Was Invalid Try Again...\n\t\tPress Enter To Continue...";
			CommonFunctions::waitTime(200);
			while (1) {

				if (GetKeyState(VK_RETURN) & 0x8000) {
					while (GetKeyState(VK_RETURN) & 0x8000) {}
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					break;
				}
			}
		}
	}
}

void User::setPassword() {

	while (10) { //password

		bool passwordContainsErrors = false;
		std::string passConfirm;
		CommonFunctions::returnClearScreen();
		CommonFunctions::centerGraphic("meme\nmeme");  //replace param contents with the sign up menu ascii art
		std::cout << "\n\n\n";
		for (int i = 0; i < CommonFunctions::getCenterSpacesStr("SIGN UP"); i++) { std::cout << " "; }
		std::cout << "SIGN UP\n\n";
		for (int i = 0; i < CommonFunctions::getCenterSpacesStr("Enter Password (Min Length 8, Contain atleast 1: symbol and number): "); i++) { std::cout << " "; }
		std::cout << "Enter Password (Min Length 8, Contain atleast 1: symbol and number): ";
		std::cin >> passwordStr;

		if (size(passwordStr) < 8) {
			passwordContainsErrors = true;
			std::cout << "\n\n\t\tYour Password Was not long enough.\n\t\tPress Enter To Continue";

			CommonFunctions::waitTime(200);
			while (1) {

				if (GetKeyState(VK_RETURN) & 0x8000) {
					while (GetKeyState(VK_RETURN) & 0x8000) {}
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					break;
				}
			}
		}

		if (!CommonFunctions::strHasAlphabet(passwordStr) || !CommonFunctions::strHasNum(passwordStr) || !CommonFunctions::strHasSymbol(passwordStr)) {
			passwordContainsErrors = true;
			std::cout << "\n\n\t\tYour Password Did Not Contain The Right Characters.\n\t\tPress Enter To Continue";

			CommonFunctions::waitTime(200);
			while (1) {

				if (GetKeyState(VK_RETURN) & 0x8000) {
					while (GetKeyState(VK_RETURN) & 0x8000) {}
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					break;
				}
			}
		}

		if (!passwordContainsErrors) {
			CommonFunctions::returnClearScreen();
			CommonFunctions::centerGraphic("meme\nmeme");  //replace param contents with the sign up menu ascii art
			std::cout << "\n\n\n";
			for (int i = 0; i < CommonFunctions::getCenterSpacesStr("SIGN UP"); i++) { std::cout << " "; }
			std::cout << "SIGN UP\n\n";
			for (int i = 0; i < CommonFunctions::getCenterSpacesStr("Confirm Password: "); i++) { std::cout << " "; }
			std::cout << "Confirm Password: ";
			std::cin >> passConfirm;

			if (passwordStr != passConfirm) {
				passwordContainsErrors = true;
				std::cout << "\n\n\t\tYour Passwords Didn't Match.\n\t\tPress Enter To Continue";

				CommonFunctions::waitTime(200);
				while (1) {

					if (GetKeyState(VK_RETURN) & 0x8000) {
						while (GetKeyState(VK_RETURN) & 0x8000) {}
						FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
						break;
					}
				}
			}

		}

		if (!passwordContainsErrors) {
			break;
		}
	}

}


void User::setPortrait() {
	portraitId = Menu::displayMenu({ "Portrait 1", "Portrait 2" }, "CHOSE PORTRAIT", Graphics::get("portraitSelection"), false, true, false, false, true, true, false, -1);
}


void User::setLoginSuccessfulM(bool loginSuccess) {
	this->loginSuccessfulM = loginSuccess;
}

//creditcard
void setCardNo();
void setCardSecCode();
void setCardExpMonth();
void setCardExpYear();


ConfigFile User::userConfig = ConfigFile("users.json");

void User::saveUserInfo() {
	if (!userConfig.fileExists()) {
		userConfig.get() = Json::parse("{}");
	}
	if (userID < 0) {
		std::map<std::string, Json> users = userConfig.get().get<std::map<std::string, Json>>();
		std::vector<int> takenIds;
		for (std::map<std::string, Json>::iterator i = users.begin(); i != users.end(); i++) {
			takenIds.push_back(stoi(i->first.substr(5, i->first.length() - 5)));
		}
		do {
			userID = rand();
		} while (std::count(takenIds.begin(), takenIds.end(), userID));
	}
	userConfig.get()["user-" + std::to_string(userID)] = {
		{"firstName", firstNameStr},
		{"lastName", lastNameStr},
		{"email", emailStr},
		{"password", passwordStr},
		{"portrait", portraitId},
		{"creditCardNumber", creditCardNoStr},
		{"creditCardLuckyNumbers", creditCardSecCodeStr},
		{"creditCardExpiryYear", creditCardExpYearStr},
		{"creditCardExpiryMonth", creditCardExpMonthStr}
	};
	userConfig.save();
	Settings::loadForUser("user-" + std::to_string(userID));
	signedIn = true;
}

bool User::loadFromFile(std::string email) {
	if (!userConfig.fileExists()) return false; // file is empty, so no accounts exist
	std::map<std::string, Json> users = userConfig.get().get<std::map<std::string, Json>>(); // convert JSON to map

	for (std::map<std::string, Json>::iterator i = users.begin(); i != users.end(); i++) { // iterate through map
		try {
			if (i->second.contains("email") && i->second["email"] == email) { // found user with email, load data
				userID = stoi(i->first.substr(5, i->first.length() - 5));
				if (i->second.contains("firstName")) firstNameStr = i->second["firstName"];
				if (i->second.contains("lastName")) lastNameStr = i->second["lastName"];
				if (i->second.contains("email")) emailStr = i->second["email"];
				if (i->second.contains("password")) passwordStr = i->second["password"];
				if (i->second.contains("portrait")) portraitId = i->second["portrait"];
				if (i->second.contains("creditCardNumber")) creditCardNoStr = i->second["creditCardNumber"];
				if (i->second.contains("creditCardLuckyNumbers")) creditCardSecCodeStr = i->second["creditCardLuckyNumbers"];
				if (i->second.contains("creditCardExpiryYear")) creditCardExpYearStr = i->second["creditCardExpiryYear"];
				if (i->second.contains("creditCardExpiryMonth")) creditCardExpMonthStr = i->second["creditCardExpiryMonth"];
				signedIn = true;
				Settings::loadForUser("user-" + std::to_string(userID)); // load settings for user
				return true;
			}
		} catch (int e) {}
	}
	return false; // no user found
}

bool User::isEmailTaken(std::string email) {
	if (!userConfig.fileExists()) return false; // file is empty, so no accounts exist
	std::map<std::string, Json> users = userConfig.get().get<std::map<std::string, Json>>(); // convert JSON to map
	for (std::map<std::string, Json>::iterator i = users.begin(); i != users.end(); i++) { // iterate through map
		if (i->second.contains("email") && i->second["email"] == email) return true; // found user with email
	}
	return false; // no user found
}

bool User::signIn(std::string email, std::string password) {
	if (!userConfig.fileExists()) return false; // file is empty, so no accounts exist
	std::map<std::string, Json> users = userConfig.get().get<std::map<std::string, Json>>(); // convert JSON to map
	for (std::map<std::string, Json>::iterator i = users.begin(); i != users.end(); i++) { // iterate through map
		if (i->second.contains("email") && i->second.contains("password") && i->second["email"] == email && i->second["password"] == password) { // found user with email and password
			return loadFromFile(email); // load user from file
		}
	}
	return false; // no user found
}

bool User::isSignedIn() {
	return signedIn;
}

std::string User::getFirstName() {
	return firstNameStr;
}

std::string User::getLastName() {
	return lastNameStr;
}

std::string User::getName() {
	return firstNameStr + " " + lastNameStr;
}

int User::getPortraitId() {
	return portraitId;
}

int User::getId() {
	return userID;
}

std::string User::getStringId() {
	return "user-" + std::to_string(userID);
}

bool User::getLoginSuccessfulM() {
	return loginSuccessfulM;
}