#pragma once
#include "commonFunctions.h"
#include <vector>
class Menu
{
private:


public:


	CommonFunctions commonFuncs;

	void displayMenu(std::vector<std::string> menuItems);

	void mainMenu();

	void userMenu();


};

