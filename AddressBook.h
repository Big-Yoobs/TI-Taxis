#pragma once

#include "Address.h"
#include <vector>

namespace AddressBook {
	std::vector<Address>* getAddresses(std::string userId); // get addressbook for user
	void removeAddress(std::string userId, std::string address); // remove address from addressbook
	void addAddress(std::string userId, std::string address, std::string name); // add address to addressbook with personal alias
	void addAddress(std::string userId, std::string address); // add address to addressbook without personal alias
	void renameAddress(std::string userId, std::string address, std::string name); // change alias of address
	void save(); // save to file
	void reload(); // load from file, call on program start
}