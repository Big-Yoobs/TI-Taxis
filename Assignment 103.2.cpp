#include <iostream>
#include <vector>
#include <string>
#include "libs/nlohmann/json.hpp"
#include "commonFunctions.h"
#include "Menu.h"
#include "ConfigFile.h"
#include "Debug.h"

int main() {
    Debug::setDebug(true);

    ConfigFile file("./data/data.json");
    if (!file.fileExists()) {
        file.get() = {
            {"field", "value"},
            {"anotherField", "anotherValue"}
        };
        file.save(true);
    }

    //creating class instances
    CommonFunctions commonFuncs;
    Menu menu;

    menu.mainMenu(); 


}