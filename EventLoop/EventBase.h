
#ifndef __EVENT_BASE_H__
#define __EVENT_BASE_H__

typedef long long Long;

class EventBase
{
public:
	EventBase() {};
	virtual ~EventBase() {};

	// 返回0表示该事件已经无效，可以移出事件列表
	// 返回小于0表示该事件执行错误
	// 返回大于0表示该事件处理完毕后还需要进行其他操作
	virtual int exec() = 0;

	virtual bool isActive() = 0;

	virtual void reset() = 0;
};

#endif // !__EVENT_BASE_H__


