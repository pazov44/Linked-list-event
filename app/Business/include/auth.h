#pragma once

namespace Auth
{
	// register a new user: name,pass
	int RegisterUser(const User& data);
	// log in an existing user
	int LogUser(const User& data);
	//user folder dir
	const std::string createUserDir = R"(..\Access\Data\Users\)";
}