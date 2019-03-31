
#ifndef __LBD_EVENT_H__
#define __LBD_EVENT_H__

#include <string>

typedef void __svcCallback(const char*);

namespace LambdaLib
{
	class EService
	{
	public:
		EService();

		~EService();

		int32_t init();

		int32_t wait(__svcCallback cbFunc);

	private:

		void setNonblocking(int32_t sock);

		int32_t readAll(int32_t sock, char* buf, size_t size);

		int32_t writeAll(int32_t sock, char* buf, size_t size);

	private:
		int epfd;		// epoll¾ä±ú
		int listenFd;	// ¼àÌýsocketÎÄ¼þÃèÊö·û
	};
}

#endif // !__LBD_EVENT_H__



