


#include "EventFactory.h"

EventFactory* EventFactory::mInstance = new EventFactory;

EventFactory* EventFactory::instance()
{
	return mInstance;
}

EventHandler EventFactory::createEvent(const std::string& typeName)
{
	return mEventRegister.getNewHandler();
}

bool EventFactory::removeEvent(EventHandler eventHandle)
{
	return false;
}
