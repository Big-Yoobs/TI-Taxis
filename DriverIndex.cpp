#include "DriverIndex.h"

#include <vector>

const std::vector<std::string> names{
	"Giogi",
	"David",
	"Irakli",
	"Mamuka",
	"Levan",
	"Zaza",
	"Zurab",
	"Lasha",
	"Gocha",
	"Gela"
};

char randomLetter() {
	char list[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'X'};
	return list[rand() % std::size(list)];
}

Driver DriverIndex::getFreeDriver() {
	std::string plate;
	for (int i = 0; i < 3; i++) plate += randomLetter(); // add 3 random letters to number plate
	for (int i = 0; i < 3; i++) plate += std::to_string(rand() % 10); // add 3 random digits to number plate
	return Driver(names[rand() % names.size()], plate);
}