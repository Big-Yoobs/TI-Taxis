#pragma once
#include "CommonFunctions.h"
#include "User.h"
#include "Graphics.h"
#include <vector>



namespace Menu {



	int displayMenu(std::vector<std::string> menuItems, std::string menuTitle, std::string menuGraphic, bool isVerticle, bool isGraphicCentered, bool isGraphicCenteredR, bool isDisplayGraphicRU, bool isMenuCentered, bool isMenuTitleCentered, bool isAnimate, int back);

	//initial login and sign up menu 
	void iniLoginMenu();

	void signUpMenu();

	void loginMenu();

	//display the main menu
	void mainMenu();

	//display the user menu
	void userMenu();

	//display the user details menu
	void userDetailsMenu();

	//display the settings menu
	void settingsMenu();

	void startScreen();

	void bookATrip();

	void openAddressBook();

};