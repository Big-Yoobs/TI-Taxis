#pragma once
#include "ConfigFile.h"
#include "Trip.h"
#include <vector>

class TripManager {
	private:
		std::string userId;
		ConfigFile* configFile;
		std::vector<Trip> trips;
	public:
		TripManager(std::string filename, std::string userId); // keeps records of all taxi trips done by user
		std::vector<Trip>* getTrips();
		void save();
};