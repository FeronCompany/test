
#ifndef __EVENT_BASE_H__
#define __EVENT_BASE_H__

typedef long long Long;

class EventBase
{
public:
	EventBase() {};
	virtual ~EventBase() {};

	// ����0��ʾ���¼��Ѿ���Ч�������Ƴ��¼��б�
	// ����С��0��ʾ���¼�ִ�д���
	// ���ش���0��ʾ���¼�������Ϻ���Ҫ������������
	virtual int exec() = 0;

	virtual bool isActive() = 0;

	virtual void reset() = 0;
};

#endif // !__EVENT_BASE_H__


