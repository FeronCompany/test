
#include <iostream>
#include <string>

#include "EventBase.h"
#include "EventRegister.h"
#include "MyApplication.h"

void testReg()
{
	EventRegister reg;
	while (true)
	{
		std::cout << "Please input COMMAND:";
		std::cout.flush();
		std::string command;
		size_t content;
		std::cin >> command;
		if (command == "add")
		{
			std::cout << "New id added [" << reg.getNewHandler() << "]\n";
		}
		else if(command == "remove")
		{
			std::cin >> content;
			reg.removeHandler(content);
		}
		else if (command == "quit")
		{
			std::cout << "GOOD BYE\n";
			break;
		}
		else
		{
			std::cout << "UNKNOWN COMMAND[" << command << "]\n";
		}
	}
}

int testApp()
{
	MyApplication app;

	return app.exec();
}

int main(int argc, char* argv[])
{
	//testReg();

	testApp();

	system("pause");
	return 0;
}
