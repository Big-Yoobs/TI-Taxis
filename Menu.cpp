#include "Menu.h"


void Menu::displayMenu(std::vector<std::string> menuItems) {

	std::cout << "\n\n";
	for (int i = 0; i < size(menuItems); i++) {
		std::cout << "\t[" << i + 1 << "] " << menuItems[i] << "\n";
	}
}


void Menu::mainMenu() {
    //displaying main menu
    bool quit = false;
    while (!quit) {
        commonFuncs.returnClearScreen();
        std::cout << "\tMain Menu";
        std::vector<std::string> mainMenu = { "Book a Trip", "Address Book", "{UserName}", "Exit" }; //main menu item vec
        displayMenu(mainMenu); //displaying it

        if (commonFuncs.userInput(true, false, false, 1, 4, 1)) {

            switch (std::stoi(commonFuncs.getUserInput())) {

            case 1: //book a trip

                break;

            case 2: //address book

                break;

            case 3: //{username}
                userMenu();
                break;

            case 4: //exit program
                quit = true;
                commonFuncs.returnClearScreen();
                std::cout << "Exitting Program...\n\n\n";
                commonFuncs.continueInput(1);
                break;

            }

        }
    }
}

void Menu::userMenu() {
    bool userMenuQuit = false;
    while (!userMenuQuit) {
        commonFuncs.returnClearScreen();
        std::cout << "\tUserName";
        std::vector<std::string> userMenu = { "Change User Details", "Trip History", "Report Missing Items", "Go Back" }; 
        displayMenu(userMenu);

        if (commonFuncs.userInput(true, false, false, 1, 4, 1)) {
            
            switch (std::stoi(commonFuncs.getUserInput())) {
            
            case 1: //Change User Details

                break;

            case 2: //Trip History

                break;

            case 3: //Report Missing Items

                break;

            case 4: //Go Back
                userMenuQuit = true;
                break;

            }
        }
    }
}

