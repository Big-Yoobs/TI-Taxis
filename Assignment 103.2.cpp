#include <iostream>
#include <vector>
#include <string>

//third party libs
#include "libs/nlohmann/json.hpp"
#include "libs/cscrutil/scrutil.h" //DO NOT INCLUDE THESE OUTSIDE OF THIS CPP & the commonFunctions.h (unless you know what you are doing)
#include "libs/cscrutil/scrutil.c" //call scr funcs from the commonFuncs instance and write your own in the scr section of commonFunctions
//

#include "commonFunctions.h"
#include "Graphics.h"
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
    CommonFunctions * CommonFuncs = new CommonFunctions;
    Graphics* Graphic = new Graphics;
    Graphic->iniGraphics();
    Menu menu(* CommonFuncs, * Graphic);


    //running the program
    CommonFuncs->resetColors();
    CommonFuncs->setControlMode(true);
    CommonFuncs->setQuit(false);
    CommonFuncs->startScreen();
    CommonFuncs->showCursor(false);
    CommonFuncs->centerGraphicLineAnim2(Graphic->main, 100);
    while (!CommonFuncs->getQuit()) {
        
        
        menu.mainMenu();

    }

   



     


}