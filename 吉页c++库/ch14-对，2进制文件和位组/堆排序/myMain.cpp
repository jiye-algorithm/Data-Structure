/*
	2014年5月13日 19:58:33
	吉页
	功能： 测试堆排序
*/
#include <iostream>
#include <vector>
#include <functional>

#include "../../include/y_sort.h"
//#include "../../include/y_util.h"

using namespace std;

int main()
{
	int arr[7] = { 1, 4, 7, 8, 0, 2, 3 };
	vector<int> v(arr, arr + 7);

	heapSort(v, greater<int>());

	for (int i = 0; i < 7; ++i)
		cout << v[i] << "   ";
	cout << endl;

	system("pause");
}