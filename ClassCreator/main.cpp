

#include <string>
#include <iostream>
#include <map>
#include "Delta.h"

using namespace std;

/*
结论：
1. 全局变量/静态成员变量 初始化顺序和文件名有关，文件名ascii值越小初始化越早
2. 单例为指针或变量不影响以上结论
3. 将单例放在函数域内static可以解决以上问题
*/

int main()
{
	//Alpha* obj = AlphaFactory::instance()->create("catty");
	Delta* obj = DeltaFactory::instance().create("catty");
	if (obj != nullptr)
	{
		obj->speak();
	}
	else
	{
		cout << "FUCK!\n";
	}
	system("pause");
	return 0;
}
