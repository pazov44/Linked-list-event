#include "pch.h"
#include "process.h"
namespace Process
{
	int InputLogSign(const int& mode)
	{
		User userNew; // user data struct

		std::cout << "\nEnter username\n:";
		std::cin >> userNew.username;

		std::cout << "\nEnter password\n:";
		std::cin >> userNew.password;

		if (mode == 1)
		{
			return Auth::LogUser(userNew); // return log in result
		}
		else
		{
			return Auth::RegisterUser(userNew); // return sign up result
		}

		return Error::ERROR_FAILED; // prevent non-control void error
	}
}
