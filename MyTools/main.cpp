
#include <iostream>
#include <string>
#include "./comm/LbdParams.h"
#include "./comm/LbdEvent.h"
using namespace std;


void toolTest()
{
	LambdaLib::Param param;
	param.setValue("haha", 12);
	param.setString("hheheh", "KKKK");
	param.setValue("yeyye", 0.233);
	cout << param.toQueryString("&", "=") << "\n";

	param.clear();
	string parse = "aaa=100&bbb=200&ccc=300";
	param.parseQueryString(parse, "&", "=");
	cout << param.toQueryString("&", "=") << "\n";
}

void eventTest()
{
	LambdaLib::EService service;
	service.init();
	//service.wait(evCallback);
	service.wait([](const char* params) {
		// 处理传入的param字符串
		cout << "deal params[" << params << "]\n";
	});
}

int main(void)
{
	eventTest();

	//system("pause");
	return 0;
}


