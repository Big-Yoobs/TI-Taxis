#include "Menu.h"
#include "Settings.h"
#include "CommonFunctions.h"
#include "Session.h"
#include "DriverIndex.h"

//functions

int Menu::displayMenu(std::vector<std::string> menuItems, std::string menuTitle, std::string menuGraphic, bool isVerticle, bool isGraphicCentered, bool isGraphicCenteredR, bool isDisplayGraphicRU, bool isMenuCentered, bool isMenuTitleCentered, bool isAnimate, int back) {

	int menuItemSize = size(menuItems);

	int selectedMenuItem = 0;
	std::string selectedMenuItemStr;
	if (Settings::getControlMode()) {
		bool inMenu = true;
		while (inMenu) {

			CommonFunctions::returnClearScreen(); //clearing the screen

			//menu graphic
			if (menuGraphic != "") { 
				if (isGraphicCentered) { //centered 
					CommonFunctions::centerGraphic(menuGraphic);
				}
				if (isGraphicCenteredR) { //centered vertically but right aligned (pick one!)
					CommonFunctions::centerGraphicR(menuGraphic);
				}
				if (isDisplayGraphicRU) { //display the graphic in the top right corner (pick one!)
					CommonFunctions::displayGraphicRU(menuGraphic);
				}
				if (!isGraphicCentered && !isGraphicCenteredR && !isDisplayGraphicRU) { std::cout << menuGraphic; } //not centered
			}


			if (menuTitle != "") { //menu title
				std::cout << "\n\n\n";
				if (isMenuTitleCentered) { //centered horizontally
					int titleSpaces = CommonFunctions::getCenterSpacesStr(menuTitle);
					for (int i = 0; i < titleSpaces; i++) {
						std::cout << " ";
					}
					std::cout << menuTitle;
				}
				else { //not centered
					std::cout << "\t" << menuTitle;
				}

			}


			std::cout << "\n\n"; //menu display
			int menuSpacesV = 0;
			if (!isVerticle && isMenuCentered) { //horizontal
				int menuSpacesH = CommonFunctions::getCenterSpacesVec(menuItems);
				std::string spaces;
				for (int i = 0; i < menuSpacesH; i++) spaces += " ";
				std::cout << spaces;
			}
			if (!isVerticle && !isMenuCentered) { std::cout << "\t"; }
			if (isVerticle && isMenuCentered) { //verticle

				menuSpacesV = CommonFunctions::getCenterSpacesStr(menuItems[0]);
				std::string spaces;
				for (int i = 0; i < menuSpacesV; i++) spaces += " ";
				std::cout << spaces;
			}

			for (int i = 0; i < menuItemSize; i++) {
				if (i == selectedMenuItem) {
					if (isVerticle && isMenuCentered) {
						menuSpacesV = CommonFunctions::getCenterSpacesStr(menuItems[i]);
						if (i != 0) {
							std::string spaces;
							for (int i = 0; i < menuSpacesV; i++) spaces += " ";
							std::cout << spaces;
						}
					}
					//if (isVerticle && !isMenuCentered && isAnimate) { std::cout << "\t"; }
					if (isVerticle && !isMenuCentered) { std::cout << "\t"; }
					CommonFunctions::highlightText(menuItems[i]);
				}
				else {
					if (isVerticle && isMenuCentered) {
						menuSpacesV = CommonFunctions::getCenterSpacesStr(menuItems[i]);
						if (i != 0) {
							std::string spaces;
							for (int i = 0; i < menuSpacesV; i++) spaces += " ";
							std::cout << spaces;
						}
					}
					if (!isMenuCentered && isVerticle) { std::cout << '\t'; }
					std::cout << menuItems[i];
				}
				if (isVerticle) {
					std::cout << "\n";

				}
				else if (!isVerticle && i != menuItemSize - 1) { std::cout << " | "; }
			}




			//CommonFunctions::waitTime(200);
			while (1) {
				if (isVerticle) {
					if (GetKeyState('W') & 0x8000 || GetKeyState(VK_UP) & 0x8000) {
						while (GetKeyState('W') & 0x8000 || GetKeyState(VK_UP) & 0x8000) {}
						if (selectedMenuItem > 0) {
							selectedMenuItem--;
							CommonFunctions::movementSound();
							break;
						}
						else if (selectedMenuItem == 0) {
							selectedMenuItem = menuItemSize - 1;
							CommonFunctions::movementSound();
							break;
						}
						
					}
					else if (GetKeyState('S') & 0x8000 || GetKeyState(VK_DOWN) & 0x8000) {
						while (GetKeyState('S') & 0x8000 || GetKeyState(VK_DOWN) & 0x8000) {}
						if (selectedMenuItem < menuItemSize - 1) {
							selectedMenuItem++;
							CommonFunctions::movementSound();
							break;
						}
						else if (selectedMenuItem == menuItemSize - 1) {
							selectedMenuItem = 0;
							CommonFunctions::movementSound();
							break;
						}
						
					}
				}
				else {
					if (GetKeyState('A') & 0x8000 || GetKeyState(VK_LEFT) & 0x8000) {
						while (GetKeyState('A') & 0x8000 || GetKeyState(VK_LEFT) & 0x8000) {}
						if (selectedMenuItem > 0) {
							selectedMenuItem--;
							CommonFunctions::movementSound();
							break;
						}
						else if (selectedMenuItem == 0) {
							selectedMenuItem = menuItemSize - 1;
							CommonFunctions::movementSound();
							break;
						}
						
					}
					else if (GetKeyState('D') & 0x8000 || GetKeyState(VK_RIGHT) & 0x8000) {
						while (GetKeyState('D') & 0x8000 || GetKeyState(VK_RIGHT) & 0x8000) {}
						if (selectedMenuItem < menuItemSize - 1) {
							selectedMenuItem++;
							CommonFunctions::movementSound();
							break;
						}
						else if (selectedMenuItem == menuItemSize - 1) {
							selectedMenuItem = 0;
							CommonFunctions::movementSound();
							break;
						}
						
					}
				}
				if (GetKeyState(VK_RETURN) & 0x8000 || GetKeyState(VK_SPACE) & 0x8000) {
					while (GetKeyState(VK_RETURN) & 0x8000 || GetKeyState(VK_SPACE) & 0x8000) {}
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					
					return selectedMenuItem + 1;
				}
				else if (GetKeyState(VK_BACK) & 0x8000) {
					while (GetKeyState(VK_BACK) & 0x8000) {}
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

					if (back > 0) { return back; }
				}
			}
			
		}
	}
	else { //cin mode
		while (1) {

			CommonFunctions::returnClearScreen();

			if (menuGraphic != "") { //menu graphic
				if (isGraphicCentered) { //centered
					CommonFunctions::centerGraphic(menuGraphic);
				}
				else { std::cout << menuGraphic; } //not centered
			}

			if (menuTitle != "") { //menu title
				std::cout << "\n\n\n";
				if (isMenuTitleCentered) { //centered horizontally
					int titleSpaces = CommonFunctions::getCenterSpacesStr(menuTitle);
					std::string spaces;
					for (int i = 0; i < titleSpaces; i++) spaces += " ";
					std::cout << spaces + menuTitle;
				}
				else { //not centered
					std::cout << "\t" << menuTitle;
				}

			}
			std::cout << "\n\n";
			int menuSpacesVD;
			int menuSpacesHD;
			if (!isMenuCentered) { std::cout << "\t"; } //tabbing first element in our menu
			if (isMenuCentered && !isVerticle) {
				menuSpacesHD = (CommonFunctions::getCenterSpacesVec(menuItems) - size(menuItems) - size(menuItems));
				std::string spaces;
				for (int i = 0; i < menuSpacesHD; i++) spaces += " ";
				std::cout << spaces;
			}
			for (int i = 0; i < size(menuItems); i++) {
				if (isVerticle) {
					std::cout << "\n";
					if (!isMenuCentered) { std::cout << "\t"; }
					else {
						menuSpacesVD = 0;
						std::string menuItemsZeroes = std::to_string(size(menuItems));
						int menuSpacesVDSUB = 4 * size(menuItemsZeroes);
						for (int i = 0; i < size(menuItems); i++) {
							if (CommonFunctions::getCenterSpacesStr(menuItems[i]) > menuSpacesVD) { menuSpacesVD = CommonFunctions::getCenterSpacesStr(menuItems[i]); }
						}
						menuSpacesVD = menuSpacesVD - menuSpacesVDSUB;
						std::string spaces;
						for (int i = 0; i < menuSpacesVD; i++) spaces += " ";
						std::cout << spaces;
					}
				}
				else if (!isVerticle && i != 0) { std::cout << " | "; }

				std::cout << "[" << i + 1 << "] " << menuItems[i];
			}
			std::cout << "\n\n\tEnter Input: ";
			std::cin >> selectedMenuItemStr;

			if (CommonFunctions::strHasAlphabet(selectedMenuItemStr) || CommonFunctions::strHasSymbol(selectedMenuItemStr)) {
				CommonFunctions::wrongInput(2);
			}
			else {
				if (std::stoi(selectedMenuItemStr) < 1 || std::stoi(selectedMenuItemStr) > size(menuItems)) { //wrongInput
					CommonFunctions::wrongInput(2);

				}
				else {
					selectedMenuItem = std::stoi(selectedMenuItemStr);
					return selectedMenuItem;
				}
			}

		}
	}
}

void Menu::iniLoginMenu() {
	User& user = Session::getUser();
	bool iniLoginMenuLoop = true;

	while (iniLoginMenuLoop) {


		switch (displayMenu({ "Login", "Sign Up", "Exit" }, "THOMAS & ISAIAH TAXIS", Graphics::get("login"), true, true, false, false, true, true, false, 3)) {

		case 1: //login
			loginMenu();
			
			if (user.getLoginSuccessfulM()) {
				iniLoginMenuLoop = false;
				Settings::setQuit(false);
			}
			break;

		case 2: //sign up
			signUpMenu();
			//Settings::setQuit(false);
			//iniLoginMenuLoop = false;
			break;

		case 3: //Exit
			Settings::setQuit(true);
			iniLoginMenuLoop = false;
			break;

		}
	}
	CommonFunctions::returnClearScreen();
}

void Menu::signUpMenu() {
	User& user = Session::getUser();
	user.setEmail();
	user.setFirstName();
	user.setLastName();
	user.setPassword();
	user.setPortrait();

	user.saveUserInfo();
}

void Menu::loginMenu() {
	User& user = Session::getUser();

	
	user.setLoginSuccessfulM(true);
	bool emailMenuOn = true;
	bool passMenuOn = true;
	std::string emailInput;
	std::string passInput;

	while (emailMenuOn) { //entering email
		
		CommonFunctions::returnClearScreen();
		CommonFunctions::centerGraphic(Graphics::get("login"));
		std::cout << "\n\n\n";
		for (int i = 0; i < CommonFunctions::getCenterSpacesStr("LOGIN"); i++) std::cout << " ";
		std::cout << "LOGIN\n\n";
		for (int i = 0; i < CommonFunctions::getCenterSpacesStr("Enter Email: "); i++) std::cout << " ";
		std::cout << "Enter Email: ";
		std::cin >> emailInput;

		emailInput = CommonFunctions::reCase(emailInput, true);

		if (user.isEmailTaken(emailInput)) { //if email matches 
			emailMenuOn = false;
			break;
		}

		else { //wrong email
			std::cout << "\n\n";
			for (int i = 0; i < CommonFunctions::getCenterSpacesStr("No Email Matches Your Input..."); i++) {
				std::cout << " ";
			}
			std::cout << "No Email Matches Your Input...";
			CommonFunctions::continueInput(3);
			CommonFunctions::returnClearScreen();
			switch (Menu::displayMenu({ "Try Again", "Go Back" }, "LOGIN", Graphics::get("login"), true, true, false, false, false, false, true, 2)) {

			case 1: //try again

				break;

			case 2: //go back
				emailMenuOn = false;
				user.setLoginSuccessfulM(false);
				break;

			}
		}

	}

	if (user.getLoginSuccessfulM()) { //entering password
		while (passMenuOn) { 
			
			CommonFunctions::returnClearScreen();
			CommonFunctions::centerGraphic(Graphics::get("login"));
			std::cout << "\n\n\n";
			for (int i = 0; i < CommonFunctions::getCenterSpacesStr("LOGIN"); i++) std::cout << " ";
			std::cout << "LOGIN\n\n";
			for (int i = 0; i < CommonFunctions::getCenterSpacesStr("Enter Password: "); i++) std::cout << " ";
			std::cout << "Enter Password: ";
			std::cin >> passInput;

			if (user.signIn(emailInput, passInput)) {
				passMenuOn = false;
				break;
			}

			else { //wrong input
				std::cout << "\n\n";
				for (int i = 0; i < CommonFunctions::getCenterSpacesStr("No Email Password Your Input..."); i++) {
					std::cout << " ";
				}
				std::cout << "No Password Matches Your Input...";
				CommonFunctions::continueInput(2);
				CommonFunctions::returnClearScreen();
				switch (Menu::displayMenu({ "Try Again", "Go Back" }, "LOGIN", Graphics::get("login"), true, true, false, false, false, false, true, 2)) {

				case 1: //try again

					break;

				case 2: //go back
					passMenuOn = false;
					user.setLoginSuccessfulM(false);
					break;

				}
			}
		}
	}
}





void Menu::mainMenu() {

	std::ifstream helpFile;
	std::stringstream helpFileData;

	Settings::showCursor(!Settings::getControlMode());

	switch (displayMenu({ "Book A Trip", "Address Book", Session::getUser().getFirstName(), "Help", "Exit"}, "MAIN MENU", Graphics::get("main"), false, true, false, false, true, true, false, -1)) {

	case 1: //Book a Trip
		CommonFunctions::acceptSound();
		bookATrip();
		break;

	case 2: //Address Book
		CommonFunctions::acceptSound();
		openAddressBook();
		break;

	case 3: //{UserName}
		CommonFunctions::acceptSound();
		userMenu();
		break;

	case 4: //Help
		CommonFunctions::acceptSound();
		CommonFunctions::returnClearScreen();
		helpFile.open("data/help.txt");
		if (!helpFile.is_open()) Debug::out("Couldn't open \"data/help.txt\"");
		else {
			helpFileData << helpFile.rdbuf();
			helpFile.close();
			std::cout << "\n\n\n" << helpFileData.str() << "\n\n";
			CommonFunctions::continueInput(2);
		}
		break;

	case 5: //exit
		Beep(200, 150);
		Beep(150, 200);
		Beep(100, 600);
		Settings::setQuit(true);
		break;
	}
}

std::string Menu::getAddress(std::vector<Address>* userAddressBook, std::string message) {
	std::vector<Address> addressBook;
	CommonFunctions::returnClearScreen();
	for (Address address : *userAddressBook) {
		addressBook.push_back(address);
		if (addressBook.size() == 1) std::cout << "Your saved addresses:\n\n";
		std::cout << "\t" << address.getName() << "\n\t" << address.getAddress() << "\n\n";
	}
	std::cout << "Enter an address or a place from your address book. \n\n" << message << " ";
	std::string userAddress;
	std::getline(std::cin, userAddress);
	std::string lowercaseAddress = CommonFunctions::lowerCase(userAddress);
	bool foundAddress = false;
	for (Address address : addressBook) {
		if (lowercaseAddress == CommonFunctions::lowerCase(address.getAddress()) || lowercaseAddress == CommonFunctions::lowerCase(address.getName())) {
			userAddress = address.getAddress();
			foundAddress = true;
			break;
		}
	}
	if (!foundAddress) {
		// check address database here
	}
	return userAddress;
}

void Menu::bookATrip() {
	User& user = Session::getUser();
	std::vector<Address>* addressBook = AddressBook::getAddresses(user.getStringId());
	CommonFunctions::waitTime(1000);
	std::string userAddress;
	do {
		CommonFunctions::returnClearScreen();
		userAddress = getAddress(addressBook, "Enter where you'd like to be picked up:");
	} while (userAddress.empty());
	std::string userDestination;
	do {
		userDestination = getAddress(addressBook, "Enter where you'd like to go:");
		if (userDestination == userAddress) {
			userDestination.clear();
			std::cout << "\n\nDestination and current location cannot be the same!\n\n\n";
			CommonFunctions::continueInput(2);
		}
	} while (userDestination.empty());

	Driver driver = DriverIndex::getFreeDriver();

	ConfigFile file("MIDI/tokyo-drift.json");
	struct Note {
		bool audible;
		int frequency;
		int duration;
		Note(bool audible, int frequency, int duration) {
			this->audible = audible;
			this->frequency = frequency;
			this->duration = duration;
		}
	};
	std::vector<Note> notes;
	for (Json object : file.get()) {
		if (object["type"].get<std::string>() == "note") {
			notes.push_back(Note(
				true,
				object["frequency"].get<int>(),
				object["duration"].get<int>()
			));
		} else {
			notes.push_back(Note(
				false,
				0,
				object["duration"].get<int>()
			));
		}
	}
	float speed = 1;

	std::vector<std::string> animationFrames; // put the ASCII art animation frames in here
	for (int i = 1; i <= 31; i++) {
		animationFrames.push_back("driftAnim/drift" + std::to_string(i));
	}
	for (int i = 30; i > 0; i--) {
		animationFrames.push_back("driftAnim/drift" + std::to_string(i));
	}
	for (int i = 0, frame = 0; i < notes.size(); i++) {
		Note note = notes[i];
		if (note.audible) {
			CommonFunctions::returnClearScreen();
			CommonFunctions::centerGraphic(Graphics::get(animationFrames[frame++ % animationFrames.size()]));
			std::cout << "\n\n";
			for (std::string entry : std::vector<std::string>{ "A taxi is on its way!", "Picking you up from " + userAddress, "Taking you to " + userDestination, "Driver: " + driver.getNumberPlate() + " - " + driver.getName()}) {
				std::cout << "\n";
				int spaces = CommonFunctions::getCenterSpacesStr(entry);
				for (int i = 0; i < spaces; i++) std::cout << " ";
				std::cout << entry;
			}
			Beep(note.frequency, note.duration * speed);
		} else {
			CommonFunctions::waitTime(note.duration * speed);
		}
	}
	Trip trip;
	trip.setCost((rand() % 16) + 10);
	trip.setDestination(userDestination);
	trip.setDriver(driver.getName());
	trip.setNumberPlate(driver.getNumberPlate());
	trip.setOrigin(userAddress);
	trip.setStage(ENDED);
	trip.setDistance(rand());
	TripManager tripManager("trips.json", user.getStringId());
	float rating;
	CommonFunctions::returnClearScreen();
	std::cout << "You have arrived at " << userDestination << "!\n\n";
	while (1) {
		std::cout << "Please rate your experience out of five : ";
		std::string input;
		std::cin >> input;
		try {
			rating = std::stof(input);
			break;
		} catch (...) {
			std::cout << "\n\nThat's not a valid rating!\n\n\n";
			CommonFunctions::continueInput(2);
			CommonFunctions::returnClearScreen();
		}
	}
	trip.setRating(rating);
	if (trip.getRating() < 5) {
		CommonFunctions::returnClearScreen();
		std::cout << "Please enter any complaints you have: ";
		std::string input;
		std::cin.ignore();
		CommonFunctions::waitTime(500);
		std::getline(std::cin, input);
		if (!input.empty()) {
			trip.setComplaint(input);
		}
	}
	tripManager.getTrips()->push_back(trip);
	tripManager.save();
	CommonFunctions::waitTime(500);
}

void Menu::openAddressBook() {
	while (1) {
		User& user = Session::getUser();
		std::vector<std::string> addressStrVec;
		
		std::vector<Address> addressVec;

		for (Address address : *AddressBook::getAddresses(user.getStringId())) {
			addressVec.push_back(address);
		}
		int userChoice;

		addressStrVec.push_back("Add New Address");
		for (int i = 0; i < size(addressVec); i++) {

			addressStrVec.push_back(addressVec[i].getName() + " | " + addressVec[i].getAddress());

		}
		addressStrVec.push_back("Go Back");


		userChoice = displayMenu(addressStrVec, "ADDRESS BOOK", "", true, false, false, false, false, false, false, size(addressStrVec));

		//go back
		if (userChoice == size(addressStrVec)) { break; }

		//add a new address
		else if (userChoice == 1) {
			std::string streetNumber;
			std::string streetNameStr;
			std::string suburbNameStr;
			std::string addressNameInput;

			while (1) { //street number
				
				std::cout << "\n\n\n";
				std::cout << "Enter Street Number: ";
				std::cin >> streetNumber;

				//wrong input
				if (CommonFunctions::strHasAlphabet(streetNumber) || CommonFunctions::strHasSymbol(streetNumber)) {
					CommonFunctions::wrongInput(2);
				}
				else { //moving next var
					break;
				}
			}

			while (1) { //streetName
				
				std::cout << "Enter Street Name: " << streetNumber << " ";
				std::cin.ignore();
				std::getline(std::cin, streetNameStr);

				//wrong input
				if (CommonFunctions::strHasNum(streetNameStr) || CommonFunctions::strHasSymbol(streetNameStr)) {
					CommonFunctions::wrongInput(2);
				}

				else { //moving to next var
					break;
				}
			}

			while (1) { //suburb

				std::cout << "Enter Suburb: ";
				//std::cin.ignore();
				std::getline(std::cin, suburbNameStr);

				//wrong input
				if (CommonFunctions::strHasNum(suburbNameStr) || CommonFunctions::strHasSymbol(suburbNameStr)) {
					CommonFunctions::wrongInput(2);
				}

				else { //correct input breaking loop
					break;
				}
			}

			//address name
			std::cout << "Enter Name (eg. home, work, etc.): ";
			std::getline(std::cin, addressNameInput);


			
			while (1) {
				
				int addAddressChoice = displayMenu({ "Yes", "No" }, "ADD ADDRESS?", "\n\nNAME: " + addressNameInput + "\nADDRESS : " + streetNumber + " " + streetNameStr + ", " + suburbNameStr + ".", false, false, false, false, true, true, false, -1);

				if (addAddressChoice == 1) { //yes
					
					AddressBook::addAddress(user.getStringId(), streetNumber + " " + streetNameStr + ", " + suburbNameStr, addressNameInput);
					AddressBook::save();
					break;
				}
				else { //no
					break;

				}
			}
		}

		else { //selecting an address
			bool addressEditMenuOn = true;
			while (addressEditMenuOn) {
				addressVec = *AddressBook::getAddresses(user.getStringId());
				std::string streetNumber;
				std::string streetNameStr;
				std::string suburbNameStr;
				int addAddressChoice;
				std::string addressEditStr = addressVec[userChoice - 2].getAddress();
				std::string addressNameEditStr = addressVec[userChoice - 2].getName();
				std::string addressNameEditInput;
				switch(displayMenu({ "Edit Address", "Edit Address Name", "Delete Address", "Go Back" }, "", "\n\nNAME: " + addressNameEditStr + "\nADDRESS: " + addressEditStr + "\n", false, true, false, false, true, true, false, 4)) {

				case 1: //edit address

					while (1) { //street number

						std::cout << "\n\n\n";
						std::cout << "Enter Street Number: ";
						std::cin >> streetNumber;

						//wrong input
						if (CommonFunctions::strHasAlphabet(streetNumber) || CommonFunctions::strHasSymbol(streetNumber)) {
							CommonFunctions::wrongInput(2);
						}
						else { //moving next var
							break;
						}
					}

					while (1) { //streetName

						std::cout << "Enter Street Name: " << streetNumber << " ";
						std::cin.ignore();
						std::getline(std::cin, streetNameStr);

						//wrong input
						if (CommonFunctions::strHasNum(streetNameStr) || CommonFunctions::strHasSymbol(streetNameStr)) {
							CommonFunctions::wrongInput(2);
						}

						else { //moving to next var
							break;
						}
					}

					while (1) { //suburb

						std::cout << "Enter Suburb: ";
						//std::cin.ignore();
						std::getline(std::cin, suburbNameStr);

						//wrong input
						if (CommonFunctions::strHasNum(suburbNameStr) || CommonFunctions::strHasSymbol(suburbNameStr)) {
							CommonFunctions::wrongInput(2);
						}

						else { //correct input breaking loop
							break;
						}
					}

					while (1) {

						addAddressChoice = displayMenu({ "Yes", "No" }, "CONFIRM EDIT?", "\n\nADDRESS : " + streetNumber + " " + streetNameStr + ", " + suburbNameStr + ".", false, false, false, false, true, true, false, -1);

						if (addAddressChoice == 1) { //yes
							AddressBook::removeAddress(user.getStringId(), addressEditStr);
							AddressBook::addAddress(user.getStringId(), streetNumber + " " + streetNameStr + ", " + suburbNameStr, addressNameEditStr);
							AddressBook::save();
							
							break;
						}
						else { //no

							break;

						}
					}
					addressEditMenuOn = false;
					
					break;

				case 2: //edit address name
					std::cout << "\n\n\n";
					//address name
					std::cout << "Enter Name (eg. home, work, etc.): ";
					//std::cin.ignore();
					std::getline(std::cin, addressNameEditInput);					

					AddressBook::removeAddress(user.getStringId(), addressEditStr);
					AddressBook::addAddress(user.getStringId(), addressEditStr, addressNameEditInput);
					AddressBook::save();
					addressEditMenuOn = false;
					while (GetKeyState(VK_RETURN) & 0x8000) {}
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					break;

				case 3: //delete address
					addAddressChoice = displayMenu({ "Yes", "No" }, "CONFIRM DELETION?", "NAME: " + addressNameEditStr + "\nADDRESS: " + addressEditStr + "\n", false, true, false, false, true, true, false, -1);
					if (addAddressChoice == 1) {
						AddressBook::removeAddress(user.getStringId(), addressEditStr);
						AddressBook::save();
						addressEditMenuOn = false;

					}
					break;
					
				case 4: //go back
					addressEditMenuOn = false;
					break;
				}

			}

		}


	}


}

void Menu::userMenu() {
	
	bool userMenuOn = true;
	while (userMenuOn) {

		//Graphic->user1 make this dynamic with the actual user's portrait please
		switch (displayMenu({ "Change User Details", "Trip History", "Settings", "Go Back" }, Session::getUser().getFirstName(), Graphics::get("user" + std::to_string(Session::getUser().getPortraitId())), true, false, false, true, false, false, true, 4)) {

		case 1: //Change User Details
			CommonFunctions::acceptSound();
			userDetailsMenu();
			break;

		case 2: //Trip History
			CommonFunctions::acceptSound();
			tripHistoryMenu();
			break;


		case 3: //settings
			CommonFunctions::acceptSound();
			settingsMenu();
			break;

		case 4: //Go Back
			CommonFunctions::returnClearScreen();
			CommonFunctions::negativeSound();
			userMenuOn = false;
			break;


		}
	}
}

void Menu::settingsMenu() {

	bool settingsMenuOn = true;

	while (settingsMenuOn) {

		std::string controlModeStatus;
		std::string soundStatus;
		if (Settings::getControlMode()) { controlModeStatus = "Control"; }
		else { controlModeStatus = "Cin"; }
		if (Settings::getSound()) { soundStatus = "On"; }
		else { soundStatus = "Off"; }

		switch (displayMenu({ "Change Control Mode (Currently: " + controlModeStatus + ")", "Sound (Currently: " + soundStatus + ")", "Go Back" }, "SETTINGS", Graphics::get("settings"), true, false, false, true, false, false, false, 3)) {

		case 1: //Change Control Mode
			CommonFunctions::acceptSound();
			Settings::toggleControlMode();
			break;

		case 2: //toggle sound
			Settings::toggleSound();
			CommonFunctions::acceptSound();
			break;

		case 3: //Go Back
			CommonFunctions::negativeSound();
			Settings::save();
			settingsMenuOn = false;
			break;

		}
	}
}

void Menu::startScreen() {
	Settings::showCursor(false);
	for (int i = 0; i < CommonFunctions::getCenterNLsStr(""); i++) {
		std::cout << "\n";
	}
	for (int i = 0; i < CommonFunctions::getCenterSpacesStr("Press ALT + ENTER to Continue..."); i++) {
		std::cout << " ";
	}
	std::cout << "Press ALT + ENTER to Continue...";
	while (1) {
		if (GetKeyState(VK_MENU) & 0x8000 && GetKeyState(VK_RETURN) & 0x8000) {
			break;
		}
	}
	CommonFunctions::returnClearScreen();
	if (Settings::getControlMode()) { //hiding our cursor after going fullscreen
		Settings::showCursor(false);
	}
}

void Menu::userDetailsMenu() {
	bool userDetailsMenuOn = true;
	User& user = Session::getUser();
	while (userDetailsMenuOn) {

		switch (displayMenu({ "Change Portrait", "Change First Name", "Change Last Name", "Change Email", "Change Password", "Go Back" }, "USER DETAILS\n\t" + user.getName() + "\n\tEmail: " + CommonFunctions::reCase(user.getEmail(), false), Graphics::get("user" + std::to_string(Session::getUser().getPortraitId())), true, false, false, true, false, false, true, 6)) {

		case 1: //change portrait
			user.setPortrait();
			user.saveUserInfo();
			break;

		case 2: //change first name
			user.setFirstName();
			user.saveUserInfo();
			break;

		case 3: //change last name
			user.setLastName();
			user.saveUserInfo();
			break;

		case 4: //change email
			user.setEmail();
			user.saveUserInfo();
			break;

		case 5: //change password
			user.setPassword();
			user.saveUserInfo();
			break;

		case 6: //go back
			userDetailsMenuOn = false;
			break;


		}

	}
}


void Menu::tripHistoryMenu() {
	while (1) {
		//setting vars
		TripManager tripManager("trips.json", Session::getUser().getStringId());
		std::vector<Trip>* trips = tripManager.getTrips();
		std::vector<std::string> tripsStrs;

		//adding necessary data to vector for displayMenu
		for (Trip trip : *trips) {
			tripsStrs.push_back(trip.getDriver() + " | " + trip.getOrigin() + " - " + trip.getDestination());
		}
		tripsStrs.push_back("Go Back");

		//displaying menu
		int userChoice = displayMenu(tripsStrs, "TRIP HISTORY", "", true, false, false, false, false, false, false, size(tripsStrs));

		//acting on user input
		if (userChoice == size(tripsStrs)) { //go back
			break;
		}

		else { //selecting an item

			//adding all the details of a trip to a string we can use in the displayMenu graphic param
			std::string tripDetails = "\n\n\n\tDRIVER: " + (*trips)[userChoice - 1].getDriver() + "\n\tLICENSE PLATE: " + (*trips)[userChoice - 1].getNumberPlate() + "\n\tFROM: " + (*trips)[userChoice - 1].getOrigin() + " - TO: " + (*trips)[userChoice - 1].getDestination() + "\n\tDISTANCE: " + CommonFunctions::formatDistance(std::stof((*trips)[userChoice - 1].getDistanceStr())) + "\n\tCOST: $" + CommonFunctions::formatPrice(std::stof((*trips)[userChoice - 1].getCostStr())) + "\n\tRATING: " + (*trips)[userChoice - 1].getRatingString() +"\n";
			std::string complaint = (*trips)[userChoice - 1].getComplaint();
			if (!complaint.empty()) {
				tripDetails += "\tCOMPLAINT: " + complaint + "\n";
			}
			if (size((*trips)[userChoice - 1].getLostItems()) > 0) {
				tripDetails = tripDetails + "\n\tLOST ITEMS: ";
				for (int i = 0; i < size((*trips)[userChoice - 1].getLostItems()); i++) {
					if (i) tripDetails += " | ";
					tripDetails += (*trips)[userChoice - 1].getLostItems()[i];
				}
			}
			std::string lostItemInput;
			switch (displayMenu({ "Add Lost Item", "Go Back" }, "TRIP OVERVIEW", tripDetails, true, false, false, false, false, false, true, 2)) {

			case 1: //add lost item
				
				std::cout << "\n\n\n\tEnter Lost Item: ";
				CommonFunctions::waitTime(500);
				std::getline(std::cin, lostItemInput);
				if (!lostItemInput.empty()) {
					(*trips)[userChoice - 1].addLostItem(lostItemInput);
					tripManager.save();
				}
				while (GetKeyState(VK_RETURN) & 0x8000) {}
				break;

			case 2: //go back
				CommonFunctions::waitTime(500);
				break;

			}

		}

	}


}
