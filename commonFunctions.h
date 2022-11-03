#pragma once
#include <iostream>
#include <string>

class CommonFunctions
{
    private:
    std::string userInputStr;
    bool correctInput;
    int wrongInputCode;

    public:

    const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCEDFGHIJKLMNOPQRSTUVWXYZ";
    const std::string symbol = "`~!@#$%^&*()_-+={}[]|\\:;'\",<.>/?";
    const std::string numbers = "1234567890";

    void returnClearScreen(); //adds enough return lines to clear the screen

    bool userInput(bool isInt, bool isStr, bool isSymbol, int isIntMin, int isIntMax, int lengthAllowed); //takes in a number of variables and returns whether it is acceptable or not
    void wrongInput(int errorCode); //tells the user why their input was wrong
    void continueInput(int selector); //gives a prompt to the user to enter any character to continue or go back 1 = continue 2 = go back




};
