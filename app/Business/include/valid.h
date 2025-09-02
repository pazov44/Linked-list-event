#pragma once

namespace Validation
{
	// returns whether username and pass are valid
	// A-Z,a-z,0-9 are a must and any other are allowed
	bool IsValidUser(const User& acc);
}