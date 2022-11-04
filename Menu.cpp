#include "Menu.h"


void Menu::displayMenu(std::vector<std::string> menuItems) {

	std::cout << "\n\n";
	for (int i = 0; i < size(menuItems); i++) {
		std::cout << "[" << i + 1 << "] " << menuItems[i] << "\n";
	}
}

