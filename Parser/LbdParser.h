
#pragma once

#include <string>

namespace LambdaLib
{
	class Parser
	{
	public:
		int parse(const std::string& command);

		static Parser* instance();

	private:
		Parser() {}

		Parser(const Parser& parser) {}

	private:
		static Parser* inst;
	};
}


