#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "commonFunctions.h"
#include "Menu.h"
#include "ConfigFile.h"


//This class is for the user. It holds user details such as the username and functions to interact with such details.

class User {
private:
	static ConfigFile userConfig;
	bool signedIn = false;

	int userID = -1;
	std::string firstNameStr;
	std::string lastNameStr;

	std::string emailStr;
	std::string passwordStr;
	std::string creditCardNoStr;
	std::string creditCardSecCodeStr;
	std::string creditCardExpMonthStr;
	std::string creditCardExpYearStr;
	int portraitId;

	


public:
	bool loadFromFile(std::string email);
	void saveUserInfo();
	bool isEmailTaken(std::string email);
	bool isSignedIn();
	bool signIn(std::string email, std::string password);

	//settters
	void setFirstName();
	void setLastName();
	void setEmail();
	void setPassword();
	void setPortrait();

	//creditcard
	void setCardNo();
	void setCardSecCode();
	void setCardExpMonth();
	void setCardExpYear();


	std::string getFirstName();
	std::string getLastName();
	std::string getName();
	int getPortraitId();
	int getId();
	std::string getStringId();
};

