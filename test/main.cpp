
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Test
{
public:
	Test()
	{
		cout << "construct" << endl;
	}
	~Test()
	{
		cout << "destruct" << endl;
	}
	Test(Test& t)
	{
		cout << "refer" << endl;
	}
	Test(Test&& t)
	{
		cout << "copy" << endl;
	}
private:
	int num = 1;
	int haha = 2;
	int mem = 4;
};

void test01()
{
	time_t curTime = time(nullptr);
	tm localTime;
	localtime_s(&localTime, &curTime);
	char buf[64] = { 0 };
	sprintf_s(buf, sizeof(buf), "[%04d-%02d-%02d %02d:%02d:%02d]", localTime.tm_year + 1900,
		localTime.tm_mon + 1, localTime.tm_mday, localTime.tm_hour, localTime.tm_min, localTime.tm_sec);
	cout << buf << endl;
}

int FibonacciNumber(int index)
{
	int initNum = 1;
	int secNum = 1;
	int fibNum = secNum;
	for (int i = 2; i < index; ++i)
	{
		fibNum = initNum + secNum;
		initNum = secNum;
		secNum = fibNum;
	}
	return fibNum;
}

void test02()
{
	// 斐波拉契数列第N个数
	int number = 10;
	for (int i = 1; i <= 20; ++i)
	{
		printf("[%d]nd FibonacciNumber[%d]\n", i, FibonacciNumber(i));
	}
}

int main(void)
{
	/*Test&& ta = Test();
	vector<Test> henhen;
	henhen.push_back(ta);*/
	test02();
	system("pause");
	return 0;
}
