

#ifndef __MY_APPLICATION_H__
#define __MY_APPLICATION_H__

#include "EventBase.h"

#include <list>

class MyApplication
{
public:
	MyApplication();

	virtual ~MyApplication();

	int exec();

private:
	int checkFreezeEvent();

	int dealActiveEvents();

private:
	std::list<EventBase*> mActiveEventList;
	std::list<EventBase*> mFreezeEventList;
	Long mSleepTime;
};

#endif // !__MY_APPLICATION_H__


