

#include "Catty.h"
#include <iostream>
#include <string>

using namespace std;
Catty::Catty()
{
}


Catty::~Catty()
{
}

void Catty::speak()
{
	cout << "Catty speak\n";
}

REGIST_DELTA_CLASS(catty)
{
	return new Catty;
}

