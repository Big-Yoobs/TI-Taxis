#include "TripManager.h"
#include "Debug.h"
#include <vector>

TripManager::TripManager(std::string filename, std::string userId) {
	configFile = new ConfigFile(filename);
	if (!configFile->fileExists()) {
		Debug::out("TripManager file did not exist!");
		configFile->save();
	}
	if (!configFile->get().contains(userId)) {
		Debug::out("Trips file didn't have entry for user " + userId + "!");
		configFile->get()[userId] = *(new std::vector<int>());
		configFile->save();
	} else { // user data was found in file
		Debug::out("Trips file had entry for user " + userId + "!");

		for (Json tripData : configFile->get()[userId]) { // iterate through all stored trips and load them into memory as instances of "Trip"
			Debug::out(tripData.dump());
			try {
				Trip trip;
				if (tripData.contains("numberPlate")) trip.setNumberPlate(tripData["numberPlate"]);
				if (tripData.contains("driver")) trip.setDriver(tripData["driver"]);
				if (tripData.contains("origin")) trip.setOrigin(tripData["origin"]);
				if (tripData.contains("destination")) trip.setDestination(tripData["destination"]);
				if (tripData.contains("distance")) trip.setDistance(tripData["distance"]);
				if (tripData.contains("stage")) trip.setStage(static_cast<std::string>(tripData["stage"]));
				if (tripData.contains("rating")) trip.setRating(tripData["rating"]);
				if (tripData.contains("lostItems")) {
					
					for (Json item : tripData["lostItems"]) {
						trip.addLostItem(item.get<std::string>());
					}
				}
				if (Debug::isOn()) trip.printOverview();
				trips.push_back(&trip);
			} catch (int e) {
				Debug::out("Could not create trip object from JSON! " + tripData.dump());
			}
		}
	}
	Debug::out("Finished loading TripManager!");
}

void TripManager::save() {
	configFile->save();
}