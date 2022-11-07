#include <iostream>
#include <vector>
#include <string>
#include "libs/nlohmann/json.hpp"
#include "commonFunctions.h"
#include "Menu.h"

using json = nlohmann::json;

int main() {
    //creating class instances
    CommonFunctions commonFuncs;
    Menu menu;

    menu.mainMenu(); 


}