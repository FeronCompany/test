
#include <iostream>

#include "TimerEvent.h"

TimerEvent::TimerEvent(int duration, bool singleTrigger) :
	mDuration(duration),
	mIsSiggle(singleTrigger),
	mRecord(time(nullptr))
{
}

int TimerEvent::exec()
{
	std::cout << "Timer Event Triggered!\n";
	if (mIsSiggle)
		return 0;
	else
		return 1;
}

bool TimerEvent::isActive()
{
	return mRecord + mDuration < time(nullptr);
}

void TimerEvent::reset()
{
	mRecord = time(nullptr);
}
