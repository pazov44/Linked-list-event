#include "pch.h"
#include "options.h"
#include "utils.h"
namespace Options
{
	void ShowAllEvents()
	{
		auto events = Global::GetEvents();

		if (events->IsEmpty())
		{
			std::cout << "List is empty\n";
		}
		else
		events->PrintEvent(); // print all events if list is not empty

		_getch(); // wait for user to press to continue
	}
	void InsertEvent()
	{
		auto events = Global::GetEvents();
		EventData event; // entered event data

		Utils::EnterEventData(event);

		Utils::Clear();
		events->InsertDate(event); // insert event sorted by year
	}
	void ReplaceEvent()
	{
		auto events = Global::GetEvents();

		std::cout << "Enter number of event to replace:\n";

		std::string num = "";
		Utils::EnterNumber(num);
		
		if (std::stoi(num) > events->Size()) // if position is bigger than size of list
		{
			Utils::ErrMsg("Wrong position");
			return;
		}

		EventData data;
		std::cout << "Enter new event's data:\n";
		Utils::EnterEventData(data);

		events->Replace(std::stoi(num), data); // replace event after inserting its data
		if (!events->IsSorted())
		{
			events->Sort(); // if events are not sorted after replacement, sort
		}
	}
	void DeleteEvent()
	{
		auto events = Global::GetEvents();

		std::cout << "Enter which event to remove:\n";
		std::cout << "1. First\n";
		std::cout << "2. Last\n";
		std::cout << "3. By number\n";
		std::string choice;
		Utils::EnterNumber(choice);
		
		if (events->IsEmpty())
		{
			Utils::ErrMsg("List is empty");
			return;
		}

		switch (std::stoi(choice))
		{
		case 1: events->DelFront(); break;
		case 2: events->DelBack(); break;
		case 3:
		{
			std::cout << "Enter number of event\n";
			std::string num;
			Utils::EnterNumber(num);
			if (!events->DelPos(std::stoi(num))) // try to delete event at wanted position
			{
				Utils::ErrMsg("Wrong position");
			}
			break;
		}
		default:
		{
			Utils::ErrMsg("Unexpected error");
			break;
		}
		}
	}
	void ShowNames()
	{
		auto events = Global::GetEvents();
		if (events->IsEmpty())
		{
			std::cout << "List is empty\n";
		}
		else
		{
			auto names = events->NameList();
			for (int i = 0; i < names->Size(); i++)
				std::cout << names->Get(i+1) << std::endl; // print all event names
		}
		_getch();
	}
	void ShowTopicEvents()
	{
		auto events = Global::GetEvents();
		if (events->IsEmpty())
		{
			std::cout << "List is empty\n";
		}
		else
		{
			std::string topic;
			
			std::cout << "Enter topic:\n:";
			std::cin >> topic;
			auto eventsTopic = events->EventList(topic);
			if(eventsTopic->IsEmpty())
				std::cout << "No events with this topic\n";
			else
				eventsTopic->PrintEvent(); // print all events with the same topic
		}
		_getch();
	}
	void SearchEvent()
	{
		auto events = Global::GetEvents();
		if (events->IsEmpty())
		{
			std::cout << "List is empty\n";
		}
		else
		{
			std::string year, topic;

			std::cout << "Enter event's year:\n";
			Utils::EnterNumber(year);
			std::cout << "Enter event's topic:\n:";
			std::cin >> topic;

			Utils::Clear();
			std::cout << (events->SearchEvent(std::stoi(year), topic) ? "\nEvent is found" : "\nEvent is not found");
		}
		_getch();
	}
}