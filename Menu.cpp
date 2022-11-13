#include "Menu.h"
#include "Settings.h"
#include "CommonFunctions.h"
#include "Session.h"

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
				for (int i = 0; i < menuSpacesH; i++) { std::cout << " "; }
			}
			if (!isVerticle && !isMenuCentered) { std::cout << "\t"; }
			if (isVerticle && isMenuCentered) { //verticle

				menuSpacesV = CommonFunctions::getCenterSpacesStr(menuItems[0]);
				for (int i = 0; i < menuSpacesV; i++) { std::cout << " "; }
			}

			for (int i = 0; i < menuItemSize; i++) {
				if (i == selectedMenuItem) {
					if (isVerticle && isMenuCentered) {
						menuSpacesV = CommonFunctions::getCenterSpacesStr(menuItems[i]);
						if (i != 0) {
							for (int i = 0; i < menuSpacesV; i++) { std::cout << " "; }
						}
					}
					if (isVerticle && !isMenuCentered && isAnimate) { std::cout << "\t"; }
					if (isVerticle && !isMenuCentered) { std::cout << "\t"; }
					CommonFunctions::highlightText(menuItems[i]);
				}
				else {
					if (isVerticle && isMenuCentered) {
						menuSpacesV = CommonFunctions::getCenterSpacesStr(menuItems[i]);
						if (i != 0) {
							for (int i = 0; i < menuSpacesV; i++) { std::cout << " "; }
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
					for (int i = 0; i < titleSpaces; i++) {
						std::cout << " ";
					}
					std::cout << menuTitle;
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
				for (int i = 0; i < menuSpacesHD; i++) { std::cout << " "; }
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
						for (int i = 0; i < menuSpacesVD + 1; i++) { std::cout << " "; }
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

	bool iniLoginMenuLoop = true;

	while (iniLoginMenuLoop) {


		switch (displayMenu({ "Login", "Sign Up", "Exit" }, "BALLS TAXIS", Graphics::get("login"), true, true, false, false, true, true, false, 3)) {

		case 1: //login
			loginMenu();
			Settings::setQuit(false);
			iniLoginMenuLoop = false;
			break;

		case 2: //sign up
			signUpMenu();
			Settings::setQuit(false);
			iniLoginMenuLoop = false;
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
}





void Menu::mainMenu() {


	switch (displayMenu({ "Book A Trip", "Address Book", Session::getUser().getFirstName(), "Help", "Exit"}, "MAIN MENU", Graphics::get("main"), false, true, false, false, true, true, false, -1)) {

	case 1: //Book a Trip
		CommonFunctions::acceptSound();
		break;

	case 2: //Address Book
		CommonFunctions::acceptSound();
		break;

	case 3: //{UserName}
		CommonFunctions::acceptSound();
		userMenu();
		break;

	case 4: //Help
		CommonFunctions::acceptSound();
		break;

	case 5: //exit
		Beep(200, 150);
		Beep(150, 200);
		Beep(100, 600);
		Settings::setQuit(true);
		break;
	}

}

void Menu::userMenu() {
	
	bool userMenuOn = true;
	while (userMenuOn) {

		//Graphic->user1 make this dynamic with the actual user's portrait please
		switch (displayMenu({ "Change User Details", "Settings", "Go Back" }, Session::getUser().getFirstName(), Graphics::get("user" + std::to_string(Session::getUser().getPortraitId())), true, false, false, true, false, false, true, 3)) {

		case 1: //Change User Details
			CommonFunctions::acceptSound();
			userDetailsMenu();
			break;

		case 2: //settings
			CommonFunctions::acceptSound();
			settingsMenu();
			break;

		case 3: //Go Back
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

}

