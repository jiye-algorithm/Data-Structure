#include <iostream>
#include <string>

#include "miniList.h"

int mian()
{
	miniList<string> ls;

	ls.insert("�Ǻ�");
	ls.insert("����");
	ls.insert("oo");

	ls.travel();
}