#include "pch.h"
#include "find.h"
namespace Find
{
	bool FindUser(const User& data, const std::string& dir)
	{
		std::string dirUser = dir + "user" + data.username + ".txt";
		return std::filesystem::exists(dirUser); // return if user's data file is found
	}
}