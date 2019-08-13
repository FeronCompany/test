

#include "Beta.h"
#include <iostream>
#include <string>

using namespace std;
Beta::Beta()
{
}

Beta::~Beta()
{
}

void Beta::speak()
{
	cout << "Beta speak\n";
}

REGIST_DELTA_CLASS(beta)
{
	return new Beta;
}
