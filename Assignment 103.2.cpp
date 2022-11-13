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

int main() {
    Debug::setDebug(true);

    srand(time(NULL));
    Session::newSession(); // creates new user instance

    //running the program
    CommonFunctions::resetColors();
    
    Menu::startScreen();

    //Menu::iniLoginMenu();

    // Session::getUser().loadFromFile("isaiah@eyezah.com"); // logs you in as an existing user without verification
    Session::getUser().signIn("isaiah@eyezah.com", "Password1@");

    TripManager tripManager("trips.json", Session::getUser().getStringId());
    
    Settings::setQuit(false);
    CommonFunctions::centerGraphicLineAnim2(Graphics::get("main"), 20); //animation
    while (!Settings::getQuit()) {
        Menu::mainMenu();
    }
}