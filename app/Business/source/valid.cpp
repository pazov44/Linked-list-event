#include "pch.h"
#include "valid.h"
namespace Validation
{
	bool IsValidUser(const User& acc)
	{
		std::regex pattern(R"(^[a-zA-Z0-9]+$)");

		return std::regex_search(acc.username, pattern) && std::regex_search(acc.password, pattern) && acc.password.size() >= 8;
	}
}