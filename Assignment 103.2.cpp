#include <iostream>
#include <vector>
#include <string>

//third party libs
#include "libs/nlohmann/json.hpp" // https://github.com/nlohmann/json
#include "libs/cscrutil/scrutil.h" //DO NOT INCLUDE THESE OUTSIDE OF THIS CPP & the commonFunctions.h (unless you know what you are doing)
#include "libs/cscrutil/scrutil.c" //call scr funcs from the commonFuncs instance and write your own in the scr section of commonFunctions


#include "CommonFunctions.h"
#include "Menu.h"

#include "TripManager.h"
#include "ConfigFile.h"
#include "Debug.h"
#include "Session.h"
#include "AddressBook.h"

int main() {
    Debug::setDebug(false);

    AddressBook::reload(); // should be called at start of program
    srand(time(NULL));
    Session::newSession(); // creates new user instance
    CommonFunctions::resetColors(); // add colours to the terminal
    Menu::startScreen(); // fullscreen prompt

    //Session::getUser().signIn("isaiah@eyezah.com", "Password1@"); // temporary login bypass
    Menu::iniLoginMenu(); // wait for user login
    
    Settings::setQuit(false); // starts lifespan of program
    CommonFunctions::centerGraphicLineAnim(Graphics::get("main"), 20); //animation
    while (!Settings::getQuit()) { // program loop
        Menu::mainMenu(); // main menu
    }
    // program ends when previous loop ends
}