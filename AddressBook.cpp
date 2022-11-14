#include "AddressBook.h"

#include "ConfigFile.h"
#include "Debug.h"
#include <map>

ConfigFile* config;

std::map<std::string, std::vector<Address>> list;

void AddressBook::reload() {
	config = new ConfigFile("addressBook.json");
	list.clear();
	if (!config->fileExists()) config->get() = Json::parse("{}"); // file doesn't exist, create now
	std::map<std::string, Json> users = config->get().get<std::map<std::string, Json>>();
	for (std::map<std::string, Json>::iterator iterator = users.begin(); iterator != users.end(); iterator++) { // iterate through users in file
		std::vector<Address> out;
		std::string userId = iterator->first;
		for (Json entry : iterator->second) { // iterate through addressbook of user
			try {
				std::string address = entry["address"];
				std::string name = entry["name"];
				Address addressObject(address, name);
				out.push_back(addressObject);
			} catch (...) {}
		}
		list.insert(std::pair<std::string, std::vector<Address>>(userId, out)); // add parsed addressbook to list
	}
}

std::vector<Address>* AddressBook::getAddresses(std::string userId) {
	for (std::map<std::string, std::vector<Address>>::iterator iterator = list.begin(); iterator != list.end(); iterator++) { // iterate through users in list
		if (iterator->first == userId) return &(iterator->second); // found user, return
	}
	std::vector<Address> out; // user wasn't in file, create empty addressbook
	list.insert(std::pair<std::string, std::vector<Address>>(userId, out)); // add addressbook to list
	return &out;
}

void AddressBook::addAddress(std::string userId, std::string address, std::string name) {
	removeAddress(userId, address); // avoids duplicates
	for (std::map<std::string, std::vector<Address>>::iterator iterator = list.begin(); iterator != list.end(); iterator++) { // iterate through users in list
		if (iterator->first == userId) { // found user
			iterator->second.push_back(Address(address, name)); // add to addressbook
			return;
		}
	}
	std::vector<Address> out; // user wasn't in file, create empty addressbook
	out.push_back(Address(address, name)); // add to addressbook
	list.insert(std::pair<std::string, std::vector<Address>>(userId, out)); // add addressbook to list
}

void AddressBook::addAddress(std::string userId, std::string address) {
	addAddress(userId, address, "");
}

void AddressBook::removeAddress(std::string userId, std::string address) {
	std::vector<Address>* addresses = AddressBook::getAddresses(userId); // get addressbook for user
	for (int i = 0; i < addresses->size(); i++) { // iterate through addressbook
		if ((*addresses)[i].address == address) { // found address
			addresses->erase(addresses->begin() + i); // remove
			i--; // compensate for removal of address
		}
	}
}

void AddressBook::save() {
	config->get() = Json::parse("{}"); // clear old JSON
	for (std::map<std::string, std::vector<Address>>::iterator iterator = list.begin(); iterator != list.end(); iterator++) { // iterate through users in list
		std::string userId = iterator->first;
		std::vector<Address> addressList = iterator->second;
		std::vector<Json> out;
		for (Address address : addressList) { // iterate through addressbook for user
			Json instance = { // convert address to JSON
				{"address", address.address},
				{"name", address.name}
			};
			out.push_back(instance); // add JSON address to JSON new list
		}
		config->get()[userId] = out; // add new list to JSON
	}
	config->save(); // save file
}

void AddressBook::renameAddress(std::string userId, std::string address, std::string name) {
	for (Address& instance : *AddressBook::getAddresses(userId)) { // iterate through addressbook for user
		if (instance.address == address) instance.name = name; // found address, rename
	}
}