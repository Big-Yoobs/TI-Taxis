#pragma once
#include "libs/nlohmann/json.hpp"
#include <string>
using json = nlohmann::json;

class ConfigFile { // wrapper for nlohmann/json, allows us to quickly read and write to/from json files
	private:
		std::string filename;
		json data;
	public:
		ConfigFile read(); // check file for updates
		ConfigFile save(bool minify); // save data to file
		ConfigFile save(); // save data to file (default without minification)
		bool fileExists(); // check if file exists and isn't empty
		json& get(); // get reference to the json object
		ConfigFile(std::string filename); // constructor
};