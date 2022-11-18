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
    Debug::setDebug(true);

    TripManager tripManager2("trips.json", "CoolUser");

    std::vector<Trip>* trips = tripManager2.getTrips(); // get and manage trip vector like this
    tripManager2.save();




    AddressBook::reload(); // should be called at start of program

    //AddressBook::getAddresses("coolUser"); // get addressbook for user
    //
    //AddressBook::addAddress("coolUser", "6 Beach Rd", "Home"); // add address to addressbook (leave third parameter empty if unnamed)

    //AddressBook::renameAddress("coolUser", "6 Beach Rd", "Work"); // rename address in addressbook (set third parameter to "" if unnamed)

    //AddressBook::save(); // save to local file

    srand(time(NULL));
    Session::newSession(); // creates new user instance

    //running the program
    CommonFunctions::resetColors();
    
    Menu::startScreen();

    //Menu::iniLoginMenu();

    //Session::getUser().loadFromFile("isaiah@eyezah.com"); // logs you in as an existing user without verification
    Session::getUser().signIn("isaiah@eyezah.com", "Password1@");

    TripManager tripManager("trips.json", Session::getUser().getStringId());
    
    Settings::setQuit(false);
    CommonFunctions::centerGraphicLineAnim2(Graphics::get("main"), 20); //animation
    while (!Settings::getQuit()) {
        Menu::mainMenu();
    }
}