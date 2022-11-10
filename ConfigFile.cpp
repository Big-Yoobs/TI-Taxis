#pragma once

#include "ConfigFile.h"
#include "Debug.h"

#include <fstream>
#include <iostream>

ConfigFile ConfigFile::read() {
	std::ifstream file(filename);
	if (!file.is_open()) {
		Debug::out("Could not read from file " + filename + "!");
		return *this; // return pointer to self to allow for function chaining
	}
	data = Json::parse(file);
	file.close();
	return *this;
}

ConfigFile ConfigFile::save(bool minify) {
	std::ofstream file(filename);
	if (!file.is_open()) {
		Debug::out("Could not write to file " + filename + "!");
		return *this;
	}
	if (!minify) file << std::setw(4);
	file << data << "\n";
	file.close();
	return *this;
}

ConfigFile ConfigFile::save() {
	return save(false);
}

Json& ConfigFile::get() {
	return data;
}

bool ConfigFile::fileExists() {
	std::ifstream file(filename);
	if (!file.is_open()) return false;
	std::string line;
	bool foundData = false;
	while (std::getline(file, line)) {
		if (line != "") {
			foundData = true;
			break;
		}
	}
	file.close();
	if (!foundData) Debug::out("File " + filename + " exists but was empty!");
	return foundData;
}

ConfigFile::ConfigFile(std::string filename) {
	this->filename = "./data/" + filename;
	read();
}