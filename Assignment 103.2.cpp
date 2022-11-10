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

int main() {
    Debug::setDebug(true);

    ConfigFile file("data.json");
    if (!file.fileExists()) {
        file.get() = {
            {"field", "value"},
            {"anotherField", "anotherValue"}
        };
        file.save(true);
    }

    TripManager tripManager("trips.json", "CoolUser");


    //running the program
    CommonFunctions::resetColors();

    Settings::setControlMode(true); //this should be aquired through the userSettings json
    Settings::setSound(true); //this should be aquired through the userSettings json
    
    Menu::startScreen();

    Menu::iniLoginMenu();
    
    Settings::setQuit(false);
    CommonFunctions::centerGraphicLineAnim2(Graphics::get("main"), 20); //animation
    while (!Settings::getQuit()) {
        Menu::mainMenu();
    }
}