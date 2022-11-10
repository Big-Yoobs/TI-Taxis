#include "Graphics.h"
#include <map>

std::map<std::string, std::string> cachedGraphics;

std::string Graphics::get(std::string id) {
	if (cachedGraphics.count(id)) { // ASCII art is in the cache
		std::map<std::string, std::string>::iterator iterator = cachedGraphics.find(id); // find ASCII art in cache
		return iterator->second; // return value of pair (key is filename, value is art)
	}
	std::ifstream file;
	std::stringstream fileData;
	file.open("./data/ASCII/" + id + ".ascii");
	if (!file.is_open()) { // ASCII art file does not exist
		Debug::out("Couldn't open ASCII file \"data/ASCII/" + id + ".ascii\"");
		return "";
	}
	fileData << file.rdbuf(); // pipe file buffer to stringStream to close file quickly
	file.close();
	std::string out = fileData.str(); // convert stringStream to string
	cachedGraphics.insert(std::pair<std::string, std::string>(id, out)); // add located ASCII art to cache
	fileData.str(""); // idfk. -I
	return out;
}