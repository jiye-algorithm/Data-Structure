#include <iostream>
#include <string>

#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_store.h"

using namespace std;

int main()
{
	store<int> intStore(11);
	store<double> realStore(12.123465);
	store<string> strStore("Template");

	cout << "��ʼ����Ϊ�� " << endl
		<< "intStore :" << intStore << endl
		<< "strStore : " << strStore << endl
		<< "realStore: " << realStore << endl;

	// �������� strStore ��ֵΪ��Template Class
	strStore.setValue(strStore.getValue() + " Class");
	cout << "�µ� strStore : " << strStore.getValue() << endl;

	system("pause");

	return 0;
}