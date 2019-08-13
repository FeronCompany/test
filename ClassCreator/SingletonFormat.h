#pragma once

#include <string>
#include <map>


template<class CbFunc, class BaseClass>
class FormatFactory
{
public:
	static FormatFactory& instance()
	{
		static FormatFactory inst;
		return inst;
	}

	BaseClass* create(const std::string& className)
	{
		auto iter = cbFuncMap.find(className);
		if (iter != cbFuncMap.end())
		{
			return (iter->second)();
		}
		else
		{
			return nullptr;
		}
	}

	void join(const std::string className, CbFunc __cb)
	{
		cbFuncMap.insert(std::make_pair(className, __cb));
	}

private:
	FormatFactory() {}
	FormatFactory(FormatFactory& alFac) {}

	std::map<std::string, CbFunc> cbFuncMap;
};

