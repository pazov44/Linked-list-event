#pragma once

namespace Options
{
	// print all events' data
	void ShowAllEvents();
	// insert an event to global events list
	void InsertEvent();
	// replace an event from the global event list
	void ReplaceEvent();
	// delete an event from the global event list
	void DeleteEvent();
	// shows names of all events
	void ShowNames();
	// show events with the same topic
	void ShowTopicEvents();
	// search for an event
	void SearchEvent();
}