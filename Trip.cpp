#include "Trip.h"
#include "CommonFunctions.h"
#include "Debug.h"
#include <iostream>

Trip::Trip() {}

Trip Trip::setNumberPlate(std::string numberPlate) {
	this->numberPlate = numberPlate;
	return *this;
}

Trip Trip::setDriver(std::string driver) {
	this->driver = driver;
	return *this;
}

Trip Trip::printOverview() {
	std::cout << "\n\n\tTrip Overview\n";
	std::cout << "\tDriver: " << driver << "\n";
	std::cout << "\tNumber Plate: " << numberPlate << "\n";
	std::cout << "\tFrom: " << origin << "\n";
	std::cout << "\tTo: " << destination << "\n";
	std::cout << "\tDistance: " << (distance == -1 ? "Unknown" : CommonFunctions::formatDistance(distance)) << "\n";
	std::cout << "\tStage: " << getStageString() << "\n";
	if (stage == ENDED) {
		std::cout << "Rating: " << getRatingString() << "\n";
		if (lostItems.size()) {
			std::cout << "Lost items:\n";
			for (std::string item : lostItems) {
				std::cout << "\t" << item << "\n";
			}
		}
	}
	
	return *this;
}

Trip Trip::setOrigin(std::string origin) {
	this->origin = origin;
	return *this;
}

Trip Trip::setDestination(std::string destination) {
	this->destination = destination;
	return *this;
}

Trip Trip::setDistance(long distance) {
	this->distance = distance;
	return *this;
}

Trip Trip::setStage(TripStage stage) {
	this->stage = stage;
	return *this;
}

Trip Trip::setStage(std::string stage) {
	stage = CommonFunctions::lowerCase(stage);
	if (stage == "pending") {
		this->stage = PENDING;
	} else if (stage == "in_progress") {
		this->stage = IN_PROGRESS;
	} else if (stage == "ended") {
		this->stage = ENDED;
	} else {
		Debug::out("Tried to set stage of trip to invalid value \"" + stage + "\"!");
	}
	return *this;
}

Trip Trip::setRating(float rating) {
	this->rating = rating == -1 ? -1 : round(CommonFunctions::clamp(rating * 2, 0.0, 10.0));
	return *this;
}

Trip Trip::setCost(float cost) {
	this->cost = cost;
	return *this;
}



std::string Trip::getStageString() {
	switch (stage) {
		case PENDING:
			return "Awaiting taxi";
		case IN_PROGRESS:
			return "In Progress";
		case ENDED:
			return "Ended";
	}
	return "Unknown";
}

std::string Trip::getRatingString() {
	if (rating == -1) return "Unrated";
	std::string out = std::to_string(rating / 2);
	if (!!(rating % 2)) out += ".5";
	out += " star";
	if (rating != 2) out += "s";
	return out;
}


std::vector<std::string> Trip::getLostItems() {
	return lostItems;
}

Trip Trip::addLostItem(std::string lostItem) {
	lostItems.push_back(lostItem);
	return *this;
}

Json Trip::getAsJson() {
	Json out;
	out["numberPlate"] = numberPlate;
	out["driver"] = driver;
	out["origin"] = origin;
	out["destination"] = destination;
	out["distance"] = distance;
	out["stage"] = std::vector<std::string>{"pending", "in_progress", "ended", "unknown"}[stage];
	out["rating"] = rating < 0 ? -1 : (rating / 2);
	out["lostItems"] = lostItems;
	out["cost"] = cost;
	return out;
}

std::string Trip::getNumberPlate() {
	return numberPlate;
}

float Trip::getCost() {
	return cost;
}

std::string Trip::getDriver() {
	return driver;
}

std::string Trip::getOrigin() {
	return origin;
}

std::string Trip::getDestination() {
	return destination;
}

std::string Trip::getDistanceStr() {
	return std::to_string(distance);
}

std::string Trip::getCostStr() {
	return std::to_string(cost);
}