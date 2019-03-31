

#include <iostream>
#include <chrono>
#include <thread> 

#include "MyApplication.h"
#include "TimerEvent.h"

MyApplication::MyApplication()
{
	mSleepTime = 100;

	TimerEvent* timer = new TimerEvent(2, false);
	mFreezeEventList.push_back(timer);
}

MyApplication::~MyApplication()
{
	for (std::list<EventBase*>::iterator itor = mActiveEventList.begin();
		itor != mActiveEventList.end(); ++itor)
	{
		if (*itor != nullptr)
			delete *itor;
		itor = mActiveEventList.erase(itor);
	}
	for (std::list<EventBase*>::iterator itor = mFreezeEventList.begin();
		itor != mFreezeEventList.end(); ++itor)
	{
		if (*itor != nullptr)
			delete *itor;
		itor = mFreezeEventList.erase(itor);
	}
}

int MyApplication::exec()
{
	while (true)
	{
		//std::cout << "New Round\n";
		// 检查是否有待处理的事件
		checkFreezeEvent();
		if (mActiveEventList.empty())
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(mSleepTime));
		}
		else
		{
			// 处理激活事件队列中的事件
			dealActiveEvents();
		}
	}
	return 0;
}

int MyApplication::checkFreezeEvent()
{
	for (std::list<EventBase*>::iterator itor = mFreezeEventList.begin();
		itor != mFreezeEventList.end(); )
	{
		if ((*itor)->isActive())
		{
			std::cout << "Active Now\n";
			EventBase* tempPtr = *itor;
			itor = mFreezeEventList.erase(itor);
			mActiveEventList.push_back(tempPtr);
		}
		else
		{
			++itor;
		}
	}
	return 0;
}

int MyApplication::dealActiveEvents()
{
	for (std::list<EventBase*>::iterator itor = mActiveEventList.begin();
		itor != mActiveEventList.end(); )
	{
		int ret = (*itor)->exec();
		if (ret == 0)
		{
			std::cout << "[NORMAL]Delete Event!\n";
			delete (*itor);
			itor = mActiveEventList.erase(itor);
		}
		else if (ret > 0)
		{
			if (ret == 1)
			{
				std::cout << "Reset Event\n";
				EventBase* tempPtr = *itor;
				tempPtr->reset();
				itor = mActiveEventList.erase(itor);
				mFreezeEventList.push_back(tempPtr);
			}
			else
			{
				std::cout << "[NORMAL]Delete Event!\n";
				delete (*itor);
				itor = mActiveEventList.erase(itor);
			}
		}
		else
		{
			std::cout << "Somthing wrong[" << ret << "]\n";
			delete (*itor);
			itor = mActiveEventList.erase(itor);
		}
	}
	return 0;
}
