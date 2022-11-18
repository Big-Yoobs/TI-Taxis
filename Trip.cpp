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
	std::cout << "\n\nTrip Overview\n";
	std::cout << "Driver: " << driver << "\n";
	std::cout << "Number Plate: " << numberPlate << "\n";
	std::cout << "From: " << origin << "\n";
	std::cout << "To: " << destination << "\n";
	std::cout << "Distance: " << (distance == -1 ? "Unknown" : CommonFunctions::formatDistance(distance)) << "\n";
	std::cout << "Stage: " << getStageString() << "\n";
	if (stage == ENDED) std::cout << "Rating: " << getRatingString() << "\n";
	
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
	this->rating = round(CommonFunctions::clamp(rating * 2, 0.0, 10.0));
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