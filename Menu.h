#pragma once
#include "commonFunctions.h"
#include "Graphics.h"
#include <vector>
class Menu
{
private:

public:

	//constructor
	CommonFunctions* CommonFuncs;
	Graphics* Graphic;
	Menu(CommonFunctions& CommonFuncs, Graphics& Graphic);


	//functions

	int displayMenu(std::vector<std::string> menuItems, std::string menuTitle, std::string menuGraphic, bool isVerticle, bool isGraphicCentered, bool isGraphicCenteredR, bool isDisplayGraphicRU, bool isMenuCentered, bool isMenuTitleCentered, bool isAnimate, int back);

	//display the main menu
	void mainMenu();

	//display the user menu
	void userMenu();

	//display the user details menu
	void userDetailsMenu();

	//display the settings menu
	void settingsMenu();



};

