

#include <string>
#include <iostream>
#include <map>
#include "Delta.h"

using namespace std;

/*
���ۣ�
1. ȫ�ֱ���/��̬��Ա���� ��ʼ��˳����ļ����йأ��ļ���asciiֵԽС��ʼ��Խ��
2. ����Ϊָ��������Ӱ�����Ͻ���
3. ���������ں�������static���Խ����������
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
