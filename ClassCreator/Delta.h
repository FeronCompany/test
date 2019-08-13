#pragma once

#include "SingletonFormat.h"

class Delta
{
public:
	Delta() {}
	virtual ~Delta() {}
	virtual void speak() = 0;
};

typedef Delta* (*__cbDelta)();
typedef FormatFactory<__cbDelta, Delta> DeltaFactory;

class DeltaModel
{
public:
	DeltaModel(__cbDelta __cb, const std::string& className)
	{
		DeltaFactory::instance().join(className, __cb);
	}
};

#define REGIST_DELTA_CLASS(class_name) \
Delta* class_name##_cb(); \
DeltaModel class_name##model = DeltaModel(class_name##_cb, #class_name); \
Delta* class_name##_cb()

