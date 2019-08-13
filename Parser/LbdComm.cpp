

#include "LbdComm.h"

int LambdaLib::excute(const std::string& command)
{
	return Parser::instance()->parse(command);;
}
