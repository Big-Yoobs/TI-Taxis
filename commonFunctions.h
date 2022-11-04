#pragma once
#include <iostream>
#include <string>

class CommonFunctions
{
    private:
    std::string userInputStr; //what the userInput() function writes to
    bool correctInput; //the bool userInput() writes and decides whether to call wrongInput() function
    int wrongInputCode; //the parameter wrongInput() takes to select a message

    public:

    const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; //string of all characters in the alphabet, first lowercase then uppercase
    const std::string symbol = "`~!@#$%^&*()_-+={}[]|\\:;'\",<.>/?"; //string of all symbols on a normal keyboard
    const std::string numbers = "0123456789"; //string of all numbers 0123456789

    //funcs

    void returnClearScreen(); //adds enough return lines to clear the screen
    void returnLine(int amount); //\n per amount
    void createLine(char symbol, int amount); //creates an ascii line, input symbol (example: '-'), and input the amount of dahses.
    bool userInput(bool isInt, bool isStr, bool isSymbol, int isIntMin, int isIntMax, int lengthAllowed); //takes in a number of variables and returns whether it is acceptable or not
    void wrongInput(int errorCode); //tells the user why their input was wrong
    void continueInput(int selector); //gives a prompt to the user to enter any character to continue or go back 1 = continue 2 = go back


    //getters
    std::string getUserInput();
    std::string getAlphabet();
    std::string getSymbol();
    std::string getNumbers();



};
