#pragma once

//other event data
struct Other
{
	std::string leader;
	std::vector<std::string> participants;
	std::string result;
};
// event data
struct EventData
{
	int year;
	std::string topic;
	std::string name;
	Other otherData;
	EventData() : year(-1) {}
};