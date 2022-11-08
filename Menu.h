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

	int displayMenu(std::vector<std::string> menuItems, std::string menuTitle, std::string menuGraphic, bool isVerticle, bool isGraphicCentered, bool isMenuCentered, bool isMenuTitleCentered, bool isAnimate, int back);

	void mainMenu();



};

