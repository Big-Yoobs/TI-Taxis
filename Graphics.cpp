#include "Graphics.h"



void Graphics::iniGraphics() {
	std::ifstream file;
	std::stringstream fileData;
	
	//main.ascii
	file.open("data/ASCII/main.ascii");
	if (file.is_open()) {
		fileData << file.rdbuf();
		file.close();
		main = fileData.str();
		fileData.str("");
	}
	else { Debug::out("data/ASCII/main.ascii\nfailed to open"); }

	//login.ascii
	file.open("data/ASCII/main.ascii");
	if (file.is_open()) {
		fileData << file.rdbuf();
		file.close();
		login = fileData.str();
		fileData.str("");
	}
	else { Debug::out("data/ASCII/login.ascii\nfailed to open"); }


	//settings.ascii
	file.open("data/ASCII/settings.ascii");
	if (file.is_open()) {
		fileData << file.rdbuf();
		file.close();
		settings = fileData.str();
		fileData.str("");
	}
	else { Debug::out("data/ASCII/settings.ascii\nfailed to open"); }

	//user1.ascii
	file.open("data/ASCII/user1.ascii");
	if (file.is_open()) {
		fileData << file.rdbuf();
		file.close();
		user1 = fileData.str();
		fileData.str("");
	}
	else { Debug::out("data/ASCII/user1.ascii\nfailed to open"); }

	//user2.ascii
	file.open("data/ASCII/user2.ascii");
	if (file.is_open()) {
		fileData << file.rdbuf();
		file.close();
		user2 = fileData.str();
		fileData.str("");
	}
	else { Debug::out("data/ASCII/user2.ascii\nfailed to open"); }

	//user3.ascii
	file.open("data/ASCII/user3.ascii");
	if (file.is_open()) {
		fileData << file.rdbuf();
		file.close();
		user3 = fileData.str();
		fileData.str("");
	}
	else { Debug::out("data/ASCII/user3.ascii\nfailed to open"); }

}
