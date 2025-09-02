#pragma once

namespace Global
{
	// assign default values to global vars
	bool Init();
	// release global vars
	bool Release();
	// getter for events ptr
	std::shared_ptr<ListEvent> GetEvents();
}