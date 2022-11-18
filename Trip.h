#pragma once
#include <string>
#include "ConfigFile.h";

enum TripStage {
	PENDING,
	IN_PROGRESS,
	ENDED,
	UNKNOWN
};

class Trip {
	private:
		std::string numberPlate = "Unknown";
		std::string driver = "Unknown";
		std::string origin = "Unknown";
		std::string destination = "Unknown";
		long distance = -1;
		TripStage stage = UNKNOWN;
		int rating = -1;
		std::vector<std::string> lostItems;

	public:
		
			
		Trip printOverview();

		Trip();

		//getters
		std::vector<std::string> getLostItems();
		std::string getStageString();
		std::string getRatingString();
		std::string getNumberPlate();

		Json getAsJson();

		//setters
		Trip setNumberPlate(std::string numberPlate);
		Trip setDriver(std::string driver);
		Trip setOrigin(std::string origin);
		Trip setDestination(std::string destination);
		Trip setDistance(long distance);
		Trip setStage(TripStage stage);
		Trip setStage(std::string stage);
		Trip setRating(float rating);
		Trip addLostItem(std::string lostItem);


};