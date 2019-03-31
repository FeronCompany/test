

#ifndef __EVENT_FACTORY_H__
#define __EVENT_FACTORY_H__

#include "EventBase.h"
#include "EventRegister.h"

#include <string>

typedef size_t EventHandler;

class EventFactory
{
public:
	static EventFactory* instance();

	EventHandler createEvent(const std::string& typeName);

	bool removeEvent(EventHandler eventHandle);

private:
	EventFactory() {}

private:
	static EventFactory* mInstance;
	EventRegister mEventRegister;

};

#endif // !__EVENT_FACTORY_H__


