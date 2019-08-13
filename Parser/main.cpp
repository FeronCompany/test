

#include <iostream>
#include "LbdComm.h"

int main()
{
	std::string command;
	std::cin >> command;
	std::cout << LambdaLib::excute(command);
	system("pause");
	return 0;
}







