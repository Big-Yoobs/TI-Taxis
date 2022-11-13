#include "Session.h"

User user;

void Session::newSession() {
	user = User();
}

User& Session::getUser() {
	return user;
}