/*
	2014��5��13�� 18:34:13
	��ҳ
	���ܣ� ʹ�öѵ�pushHeap��popHeap����
*/

#include <iostream>
#include <vector>

#include "../../include/y_heap.h"

using namespace std;

int main()
{
	int arr[] = { 5, 9, 2, 7, 1, 3, 8 };
	vector<int>va, vb;
	int arrSize = sizeof(arr) / sizeof(int);

		// ���һ�����Ѻ���С��
	for (int i = 0; i < arrSize; ++i)
	{
		va.push_back(arr[i]);
		pushHeap(va, va.size(), greater<int>());
		vb.push_back(arr[i]);
		pushHeap(vb, vb.size(), less<int>());
	}

	cout << "Maximum heap: ";
	while (!va.empty())
	{
		popHeap(va, va.size(), greater<int>());
		cout << va.back() << "  ";
		va.pop_back();
	}
	cout << endl;

	cout << "Minum heap:";
	while (!vb.empty())
	{
		popHeap(vb, vb.size(), less<int>());
		cout << vb.back() << "  ";
		vb.pop_back();
	}

	system("pause");
	return 0;
}