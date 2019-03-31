
#include "./LbdParams.h"
#include <sstream>
#include <iostream>

void LambdaLib::Param::setString(const std::string& key, const std::string& value)
{
	mKvMap[key] = value;
}

void LambdaLib::Param::setValue(const std::string& key, int32_t value)
{
	mKvMap[key] = std::to_string(value);
}

void LambdaLib::Param::setValue(const std::string& key, int64_t value)
{
	mKvMap[key] = std::to_string(value);
}

void LambdaLib::Param::setValue(const std::string& key, double value)
{
	mKvMap[key] = std::to_string(value);
}

int32_t LambdaLib::Param::getInt(const std::string& key)
{
	std::map<std::string, std::string>::iterator itor = mKvMap.find(key);
	if (itor != mKvMap.end())
	{
		return atoi(itor->second.c_str());
	}
	else
	{
		return 0;
	}
}

int64_t LambdaLib::Param::getLong(const std::string& key)
{
	std::map<std::string, std::string>::iterator itor = mKvMap.find(key);
	if (itor != mKvMap.end())
	{
		return atoll(itor->second.c_str());
	}
	else
	{
		return 0ll;
	}
}

double LambdaLib::Param::getDouble(const std::string& key)
{
	std::map<std::string, std::string>::iterator itor = mKvMap.find(key);
	if (itor != mKvMap.end())
	{
		return atof(itor->second.c_str());
	}
	else
	{
		return 0.0;
	}
}

std::string LambdaLib::Param::getString(const std::string& key)
{
	std::map<std::string, std::string>::iterator itor = mKvMap.find(key);
	if (itor != mKvMap.end())
	{
		return itor->second;
	}
	else
	{
		return "";
	}
}

std::string LambdaLib::Param::toQueryString(const std::string& bigSep, const std::string& smallSep)
{
	std::stringstream qsStream;
	for (auto& pair : mKvMap)
	{
		qsStream << pair.first << smallSep << pair.second << bigSep;
	}
	const std::string& output = qsStream.str();
	if (output.length() != 0)
	{
		return output.substr(0, output.length() - 1);
	}
	else
	{
		return output;
	}
}

void LambdaLib::Param::parseQueryString(const std::string& rawString,
	const std::string& bigSep, const std::string& smallSep)
{
	size_t pos = 0;
	size_t off = 0;
	while (true)
	{
		pos = rawString.find(bigSep, off);
		if (pos == std::string::npos)
		{
			std::string kvPair = rawString.substr(off);
			size_t sPos = kvPair.find(smallSep);
			if (sPos != std::string::npos)
			{
				mKvMap[kvPair.substr(0, sPos)] = kvPair.substr(sPos + 1);
			}
			break;
		}
		else
		{
			std::string kvPair = rawString.substr(off, pos - off);
			size_t sPos = kvPair.find(smallSep);
			if (sPos != std::string::npos)
			{
				mKvMap[kvPair.substr(0, sPos)] = kvPair.substr(sPos + 1);
			}
			off = pos + 1;
		}
	}
}

void LambdaLib::Param::clear()
{
	std::map<std::string, std::string>().swap(mKvMap);
}

