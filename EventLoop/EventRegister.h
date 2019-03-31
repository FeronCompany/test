

#ifndef __EVENT_REGISTER_H__
#define __EVENT_REGISTER_H__

#include <set>

class EventRegister
{
public:
	EventRegister();

	size_t getNewHandler();

	void removeHandler(size_t handler);

private:

private:
	std::set<size_t> mActiveList;
	std::set<size_t> mFreezeList;
};

#endif // !__EVENT_REGISTER_H__


