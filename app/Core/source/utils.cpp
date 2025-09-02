#include "pch.h"
#include "utils.h"
namespace Utils
{
	void Clear()
	{
		system("cls");
	}
	void Exit()
	{
		ErrMsg("Quiting");
		exit(0);
	}
	void ErrMsg(const std::string& msg, float wait)
	{
		if (wait < 0.5) wait = 0.5;
		wait *= 1000;

		Utils::Clear();
		std::cout << std::endl << msg;
		Sleep((int)wait);
		Utils::Clear();
	}
	void EnterEventData(EventData& event)
	{
		std::cout << std::endl;
		std::cout << "Enter event's name\n:";
		std::cin >> event.name;

		std::cout << "Enter event's year\n";
		std::string strYear;
		EnterNumber(strYear);

		event.year = std::stoi(strYear);

		std::cout << "Enter event's topic\n:";
		std::cin >> event.topic;

		std::cout << "Enter event's leader\n:";
		std::cin >> event.otherData.leader;

		std::cout << "Enter event's result\n:";
		std::cin >> event.otherData.result;

		std::cout << "Enter number of participants:\n";
		std::string count; // participants count

		EnterNumber(count); // enter count
		std::cout << "\nEnter participants:\n";

		for (int i = 0; i < std::stoi(count); i++)
		{
			std::string participant;
			std::cout << ":";
			std::cin >> participant;
			event.otherData.participants.push_back(participant);
		}
	}
	void EnterNumber(std::string& num)
	{
		while (true)
		{
			std::cout << ":";
			std::cin >> num;
			if (std::all_of(num.begin(), num.end(), isdigit))
			{
				if (std::stoi(num) > 0)
					break; // break if num is a non-negative number
			}
		}
	}
}