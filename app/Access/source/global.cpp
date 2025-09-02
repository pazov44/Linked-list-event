#include "pch.h"
#include "global.h"

namespace Global
{
	// global events list
	static std::shared_ptr<ListEvent> events;

	bool Init()
	{
		if (!events)
		{
			events = std::make_shared<ListEvent>();
			return true;
		}
		return false;
	}
	bool Release() 
	{
		events.reset();
		return true;
	}
	std::shared_ptr<ListEvent> GetEvents()
	{
		return events;
	}
}