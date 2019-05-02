#include <iostream>
#include <string>

#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_store.h"

using namespace std;

int main()
{
	store<int> intStore(11);
	store<double> realStore(12.123465);
	store<string> strStore("Template");

	cout << "初始数据为： " << endl
		<< "intStore :" << intStore << endl
		<< "strStore : " << strStore << endl
		<< "realStore: " << realStore << endl;

	// 重新设置 strStore 的值为，Template Class
	strStore.setValue(strStore.getValue() + " Class");
	cout << "新的 strStore : " << strStore.getValue() << endl;

	system("pause");

	return 0;
}