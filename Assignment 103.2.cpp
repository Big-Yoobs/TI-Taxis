#include <iostream>
#include <vector>
#include <string>
#include "commonFunctions.h"
#include "Menu.h"

int main() {
    //creating class instances
    CommonFunctions commonFuncs;
    Menu menu;

    //displaying main menu
    std::vector<std::string> mainMenu = { "Book a Trip", "Address Book", "{UserName}", "Exit" }; //main menu item vec
    menu.displayMenu(mainMenu); //displaying it

    if (commonFuncs.userInput(true, false, false, 1, 4, 1)) {

        switch (std::stoi(commonFuncs.getUserInput())) {

        case 1: //book a trip

            break;

        case 2: //address book

            break;

        case 3: //{username}

            break;

        case 4:
            goto ExitProgram;
            break;

        }

    }


ExitProgram:
    commonFuncs.returnClearScreen();
    std::cout << "Exitting Program...\n\n\n";
    commonFuncs.continueInput(1);


}