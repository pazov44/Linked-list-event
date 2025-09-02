#include "pch.h"
#include "caption.h"
namespace Caption
{
	void PrintCaption()
	{
		std::ifstream handle(R"(../Presentation/assets/timelist.txt)");
        if (!handle.is_open())
        {
            handle.clear();
            handle.open("timelist.txt");

            if (!handle.is_open())
            {
                std::cout << "----------TimeList----------\n";
                return;
            }
        }

		std::string line;
		while (std::getline(handle, line))
		{
            std::cout << line << std::endl;
        }
        handle.close();
    }
}