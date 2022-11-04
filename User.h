#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

//DO NOT USE UNTIL WE HAVE FILE HANDLING FRAMEWORK
//This class is for the user. It holds user details such as the username and functions to interact with such details.

class User
{
private:

	std::string firstName; //user's first name
	std::string lastName; //user's last name



public:

	//TEMPORARY: I am storing these publically for now as I need to learn more about handling getters and setters stream vars
	std::fstream userFile; //stream for user file
	std::stringstream userFileData; //stringstream that is assigned the contents of our fstream


	void loadUserFile();






};

