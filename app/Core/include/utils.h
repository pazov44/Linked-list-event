#pragma once

namespace Utils
{
	// clear screen cmd command
	void Clear();
	// enter passed event's data
	void EnterEventData(EventData& event);
	// loop while non-negative number is entered
	void EnterNumber(std::string& num);
	// exit with err msg as quiting
	void Exit();
	// show err msg for wait seconds
	void ErrMsg(const std::string& msg, float wait = 0.5);
}