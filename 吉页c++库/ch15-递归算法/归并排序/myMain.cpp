/*
	2014年5月21日 21:25:27
	吉页
	功能： 测试归并排序
*/

#include <string>
#include <iostream>
#include <vector>

#include "../../include/y_sort.h"
#include "../../include/y_util.h"

int main()
{
	// create an array of integers and of strings for the sort
	int intList[] = { 25, 10, 7, 19, 3, 48, 12, 17, 56, 30, 21 };

	string strList[] = { "Dallas", "Akron", "Wausau", "Phoenix",
		"Fairbanks", "Miami" };

		// 构建两个向量用于排序
	vector<string> vs(strList, strList + 6);
	vector<int> vi(intList, intList + 11);

	cout << "排序前的向量： " << endl;
	writeContainer(vs.begin(), vs.end());
	writeContainer(vi.begin(), vi.end());

	cout << endl << endl;
	mergeSort(vi, 0, vi.size());
	mergeSort(vs, 0, vs.size());
	cout << "排序后的向量： " << endl;
	writeContainer(vs.begin(), vs.end());
	writeContainer(vi.begin(), vi.end());

	system("pause");
}
