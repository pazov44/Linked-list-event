#include "pch.h"
#include "menu.h"
#include "caption.h"
#include "process.h"
#include "presentation.h"
#include "options.h"
namespace Menu
{
	void Main()
	{
		if (!Presentation::Init()) // init other logic layers
		{
			Utils::Exit(); // exit if init fails
		}

		InitialMenu(); //call initial menu
		MainMenu(); // call main program menu

		if (!Presentation::Release()) // release other logic layers
		{
		}
		Utils::Exit();
	}
	void InitialMenu()
	{
		Caption::PrintCaption(); // print art text caption

		initial: // inital options ticket

		std::cout << std::endl;
		std::cout << "Options:\n";
		std::cout << "1. Log In\n";
		std::cout << "2. Sign Up\n";
	
		std::string choice = ""; //get user's choice
		do
		{
			std::cout << ":";		
			std::cin >> choice; //get user's choice

		} while ((choice != "1" && choice != "2"));

		Utils::Clear();

		int res = Process::InputLogSign(std::stoi(choice));
		if (res != Error::SUCCESSFUL)
		{
			switch (res)
			{
			case Error::ERROR_INPUT:Utils::ErrMsg("User name and password need to contain:\none small letter\none big letter\none number\npassword needs to be atleast 8 chars long",2.5); break;
			case Error::ERROR_STREAM:Utils::ErrMsg("Internal error. Please try again later"); break;
			case Error::ERROR_EXISTS: Utils::ErrMsg("User already exists"); break;
			case Error::ERROR_FAILED: Utils::ErrMsg((choice == "1" ? "Failed to log in" : "Failed to sign up")); break;
			default: Utils::ErrMsg("Unexpected error. Please try again later"); break;
			}
			goto initial;
		}
		Utils::Clear();
	}
	void MainMenu()
	{
		std::string choice = ""; // user choice;
		while (true)
		{
			std::cout << "Options:\n";
			std::cout << "\n1. exit\n";
			std::cout << "\n2. show all events\n";
			std::cout << "\n3. insert a new event\n";
			std::cout << "\n4. replace an existing event\n";
			std::cout << "\n5. delete an existing event\n";
			std::cout << "\n6. show all event names\n";
			std::cout << "\n7. show events by topic\n";
			std::cout << "\n8. search for an event\n";

			std::cout << "\nEnter choice:\n";
			Utils::EnterNumber(choice);

			Utils::Clear();
			switch (std::stoi(choice))
			{
			case 1: return; break;
			case 2: Options::ShowAllEvents(); break;
			case 3: Options::InsertEvent(); break;
			case 4: Options::ReplaceEvent(); break;
			case 5: Options::DeleteEvent(); break;
			case 6: Options::ShowNames(); break;
			case 7:	Options::ShowTopicEvents(); break;
			case 8: Options::SearchEvent(); break;
			}
			Utils::Clear();
		}
	}

}