
#ifndef __TIMER_EVENT_H__
#define __TIMER_EVENT_H__

#include "EventBase.h"
#include <ctime>

class TimerEvent : public EventBase
{
public:
	TimerEvent(int duration, bool singleTrigger);

	virtual int exec();

	virtual bool isActive();

	virtual void reset();

private:
	Long mDuration;
	bool mIsSiggle;
	time_t mRecord;
};

#endif // !__TIMER_EVENT_H__


