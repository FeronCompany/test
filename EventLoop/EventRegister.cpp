
#include <iostream>

#include "EventRegister.h"

EventRegister::EventRegister()
{
	mActiveList.insert(0);
}

size_t EventRegister::getNewHandler()
{
	size_t retValue;
	if (mFreezeList.size() != 0)
	{
		auto itor = mFreezeList.begin();
		retValue = *itor;
		mFreezeList.erase(itor);
	}
	else
	{
		auto itor = mActiveList.rbegin();
		retValue = *itor + 1;
	}
	mActiveList.insert(retValue);
	return retValue;
}

void EventRegister::removeHandler(size_t handler)
{
	if (handler == 0)
	{
		std::cout << "0 cannot be removed!\n";
		return;
	}
	mActiveList.erase(handler);
	mFreezeList.insert(handler);
}
