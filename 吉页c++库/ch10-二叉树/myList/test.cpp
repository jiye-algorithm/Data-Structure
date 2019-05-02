#include <iostream>
#include <string>

#include "miniList.h"

int mian()
{
	miniList<string> ls;

	ls.insert("最最");
	ls.insert("込込");
	ls.insert("oo");

	ls.travel();
}