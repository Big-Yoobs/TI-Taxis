#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "commonFunctions.h"
#include "Menu.h"


//This class is for the user. It holds user details such as the username and functions to interact with such details.

class User {
private:

	int userID;
	std::string firstNameStr;
	std::string lastNameStr;

	std::string emailStr;
	std::string passwordStr;
	std::string userPortraitStr;
	std::string creditCardNoStr;
	std::string creditCardSecCodeStr;
	std::string creditCardExpMonthStr;
	std::string creditCardExpYearStr;

	


public:
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






};

