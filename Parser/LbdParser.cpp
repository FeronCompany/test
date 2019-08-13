

#include "LbdParser.h"
#include <iostream>

using namespace LambdaLib;

Parser* Parser::inst = nullptr;
const std::string reserveMarks = "+-*/%";

int LambdaLib::Parser::parse(const std::string& command)
{
	int leftNumber = 0;
	int rightNumber = 0;
	bool changeNumber = false;
	char mark = '\0';
	for (auto __c : command)
	{
		if (!changeNumber && reserveMarks.find(__c) != std::string::npos)
		{
			mark = __c;
			changeNumber = true;
			continue;
		}
		if (__c == '\n')
		{
			break;
		}

		if (__c == ' ')
		{
			continue;
		}
		if (!changeNumber)
		{
			leftNumber = leftNumber * 10 + (__c - '0');
		}
		else
		{
			rightNumber = rightNumber * 10 + (__c - '0');
		}
	}
	int result = 0;
	switch (mark)
	{
	case '+':
		result = leftNumber + rightNumber;
		break;
	case '-':
		result = leftNumber - rightNumber;
		break;
	case '*':
		result = leftNumber * rightNumber;
		break;
	case '/':
		result = leftNumber / rightNumber;
		break;
	case '%':
		result = leftNumber % rightNumber;
		break;
	default:
		break;
	}
	return result;
}

Parser* LambdaLib::Parser::instance()
{
	if (!inst)
	{
		inst = new Parser;
	}
	return inst;
}
