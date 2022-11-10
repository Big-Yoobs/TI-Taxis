#include "Menu.h"

//Constructor
Menu::Menu(CommonFunctions& CommonFuncs, Graphics& Graphic) {
	this->CommonFuncs = &CommonFuncs;
	this->Graphic = &Graphic;
}

//functions

int Menu::displayMenu(std::vector<std::string> menuItems, std::string menuTitle, std::string menuGraphic, bool isVerticle, bool isGraphicCentered, bool isGraphicCenteredR, bool isDisplayGraphicRU, bool isMenuCentered, bool isMenuTitleCentered, bool isAnimate, int back) {

	int menuItemSize = size(menuItems);

	int selectedMenuItem = 0;
	std::string selectedMenuItemStr;
	if (CommonFuncs->getControlMode()) {
		bool inMenu = true;
		while (inMenu) {

			CommonFuncs->returnClearScreen(); //clearing the screen

			if (menuGraphic != "") { //menu graphic
				if (isGraphicCentered) { //centered 
					CommonFuncs->centerGraphic(menuGraphic);
				}
				if (isGraphicCenteredR) { //centered vertically but right aligned (pick one!)
					CommonFuncs->centerGraphicR(menuGraphic);
				}
				if (isDisplayGraphicRU) { //display the graphic in the top right corner (pick one!)
					CommonFuncs->displayGraphicRU(menuGraphic);
				}
				if (!isGraphicCentered && !isGraphicCenteredR && !isDisplayGraphicRU) { std::cout << menuGraphic; } //not centered
			}


			if (menuTitle != "") { //menu title
				std::cout << "\n\n\n";
				if (isMenuTitleCentered) { //centered horizontally
					int titleSpaces = CommonFuncs->getCenterSpacesStr(menuTitle);
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
				int menuSpacesH = CommonFuncs->getCenterSpacesVec(menuItems);
				for (int i = 0; i < menuSpacesH; i++) { std::cout << " "; }
			}
			if (!isVerticle && !isMenuCentered) { std::cout << "\t"; }
			if (isVerticle && isMenuCentered) { //verticle

				menuSpacesV = CommonFuncs->getCenterSpacesStr(menuItems[0]);
				for (int i = 0; i < menuSpacesV; i++) { std::cout << " "; }
			}

			for (int i = 0; i < menuItemSize; i++) {
				if (i == selectedMenuItem) {
					if (isVerticle && isMenuCentered) {
						menuSpacesV = CommonFuncs->getCenterSpacesStr(menuItems[i]);
						if (i != 0) {
							for (int i = 0; i < menuSpacesV; i++) { std::cout << " "; }
						}
					}
					if (isVerticle && !isMenuCentered && isAnimate) { std::cout << "\t"; }
					if (isVerticle && !isMenuCentered) { std::cout << "\t"; }
					CommonFuncs->highlightText(menuItems[i]);
				}
				else {
					if (isVerticle && isMenuCentered) {
						menuSpacesV = CommonFuncs->getCenterSpacesStr(menuItems[i]);
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




			//CommonFuncs->waitTime(200);
			while (1) {
				if (isVerticle) {
					if (GetKeyState('W') & 0x8000) {
						while (GetKeyState('W') & 0x8000) {}
						if (selectedMenuItem > 0) {
							selectedMenuItem--;
							CommonFuncs->movementSound();
							break;
						}
						else if (selectedMenuItem == 0) {
							selectedMenuItem = menuItemSize - 1;
							CommonFuncs->movementSound();
							break;
						}
						
					}
					else if (GetKeyState('S') & 0x8000) {
						while (GetKeyState('S') & 0x8000) {}
						if (selectedMenuItem < menuItemSize - 1) {
							selectedMenuItem++;
							CommonFuncs->movementSound();
							break;
						}
						else if (selectedMenuItem == menuItemSize - 1) {
							selectedMenuItem = 0;
							CommonFuncs->movementSound();
							break;
						}
						
					}
				}
				else {
					if (GetKeyState('A') & 0x8000) {
						while (GetKeyState('A') & 0x8000) {}
						if (selectedMenuItem > 0) {
							selectedMenuItem--;
							CommonFuncs->movementSound();
							break;
						}
						else if (selectedMenuItem == 0) {
							selectedMenuItem = menuItemSize - 1;
							CommonFuncs->movementSound();
							break;
						}
						
					}
					else if (GetKeyState('D') & 0x8000) {
						while (GetKeyState('D') & 0x8000) {}
						if (selectedMenuItem < menuItemSize - 1) {
							selectedMenuItem++;
							CommonFuncs->movementSound();
							break;
						}
						else if (selectedMenuItem == menuItemSize - 1) {
							selectedMenuItem = 0;
							CommonFuncs->movementSound();
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

			CommonFuncs->returnClearScreen();

			if (menuGraphic != "") { //menu graphic
				if (isGraphicCentered) { //centered
					CommonFuncs->centerGraphic(menuGraphic);
				}
				else { std::cout << menuGraphic; } //not centered
			}

			if (menuTitle != "") { //menu title
				std::cout << "\n\n\n";
				if (isMenuTitleCentered) { //centered horizontally
					int titleSpaces = CommonFuncs->getCenterSpacesStr(menuTitle);
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
				menuSpacesHD = (CommonFuncs->getCenterSpacesVec(menuItems) - size(menuItems) - size(menuItems));
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
							if (CommonFuncs->getCenterSpacesStr(menuItems[i]) > menuSpacesVD) { menuSpacesVD = CommonFuncs->getCenterSpacesStr(menuItems[i]); }
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

			if (CommonFuncs->strHasAlphabet(selectedMenuItemStr) || CommonFuncs->strHasSymbol(selectedMenuItemStr)) {
				CommonFuncs->wrongInput(2);
			}
			else {
				if (std::stoi(selectedMenuItemStr) < 1 || std::stoi(selectedMenuItemStr) > size(menuItems)) { //wrongInput
					CommonFuncs->wrongInput(2);

				}
				else {
					selectedMenuItem = std::stoi(selectedMenuItemStr);
					return selectedMenuItem;
				}
			}

		}
	}
}

void Menu::mainMenu() {


	switch (displayMenu({ "Book A Trip", "Address Book", "{UserName}", "Help", "Exit" }, "MAIN MENU", Graphic->main, false, true, false, false, true, true, false, -1)) {

	case 1: //Book a Trip
		CommonFuncs->acceptSound();
		break;

	case 2: //Address Book
		CommonFuncs->acceptSound();
		break;

	case 3: //{UserName}
		CommonFuncs->acceptSound();
		userMenu();
		break;

	case 4: //Help
		CommonFuncs->acceptSound();
		break;

	case 5: //exit
		Beep(200, 150);
		Beep(150, 200);
		Beep(100, 600);
		CommonFuncs->setQuit(true);
		break;
	}

}

void Menu::userMenu() {
	
	bool userMenuOn = true;
	while (userMenuOn) {

		//Graphic->user1 make this dynamic with the actual user's portrait please
		switch (displayMenu({ "Change User Details", "Settings", "Go Back" }, "{UserName}", Graphic->user1, true, false, false, true, false, false, true, 3)) {

		case 1: //Change User Details
			CommonFuncs->acceptSound();
			userDetailsMenu();
			break;

		case 2: //settings
			CommonFuncs->acceptSound();
			settingsMenu();
			break;

		case 3: //Go Back
			CommonFuncs->returnClearScreen();
			CommonFuncs->negativeSound();
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
		if (CommonFuncs->getControlMode()) { controlModeStatus = "Control"; }
		else { controlModeStatus = "Cin"; }
		if (CommonFuncs->getSound()) { soundStatus = "On"; }
		else { soundStatus = "Off"; }

		switch (displayMenu({ "Change Control Mode (Currently: " + controlModeStatus + ")", "Sound (Currently: " + soundStatus + ")", "Go Back" }, "SETTINGS", Graphic->settings, true, false, false, true, false, false, false, 3)) {

		case 1: //Change Control Mode
			CommonFuncs->acceptSound();
			CommonFuncs->toggleControlMode();
			break;

		case 2: //toggle sound
			CommonFuncs->toggleSound();
			CommonFuncs->acceptSound();
			break;

		case 3: //Go Back
			CommonFuncs->negativeSound();
			settingsMenuOn = false;
			break;

		}
	}

}

void Menu::userDetailsMenu() {

}

