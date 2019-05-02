/*
	2014年4月22日 21:42:40
	吉页
	功能： graduate 类存数学生的名字和学位类型（BA或BS），
	程序读取文件的毕业生信息到 gradBS_list 或 gradBA_list。使用 insertOrder()是每个表
	按毕业生的名字排序，随后从 noattened.dat中加载，不参加毕业典礼的学生，使用
	removeGraduate() 函数，根据学位在 gradBS_list、 gradBA_list中删除学生，
	splice（）， 在diplomalist表中将前两个表连接起来， 首先是BS毕业生， 
	随后是BA毕业生， 最后显示信息。
*/

#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include "E:\学习\数据结构\数据结构STL\吉页c++库\include\y_grad.h"
#include "E:\学习\数据结构\数据结构STL\吉页c++库\include\y_util.h"
#include "E:\学习\数据结构\数据结构STL\吉页c++库\include\y_search.h"
#include "E:\学习\数据结构\数据结构STL\吉页c++库\include\y_listl.h"

using namespace std;

//void removeGraduate(list<graduate>& gradList, const graduate& grad);

int main()
{
		// 毕业生表
	list<graduate> gradBS_list, gradBA_list, diplomalist;

		// 打开文件，读取毕业生数据
	ifstream fin("gradlist.dat");
		// 文件打开的状态， 
	if (!fin)
	{
		cerr << "文件 gradList。dat 读取失败！ " << endl;
		exit(1);
	}

		// 读取文件的毕业生信息到 gradBS_list 或 gradBA_list
	graduate tmpGrad;
	while (fin >> tmpGrad)
	{
		if ("BS" == tmpGrad.getDegree())
			insertSort(gradBS_list, tmpGrad);
		else
			insertSort(gradBA_list, tmpGrad);
	}

		// 关闭文件
	fin.close();

		// 显示总的毕业生信息
	writeList(gradBS_list, "\n");
	writeList(gradBA_list, "\n");

		// 打开不参加毕业典礼的学生文件
	fin.open("noattend.dat");
		// 判断文件是否已被正确打开
	if (!fin)
	{
		cerr << "文件 noattend.dat 未能正确打开！ " << endl;
		exit(1);
	}

		// 从已有表中根据不参加典礼的名单删除学生
	while (fin >> tmpGrad)
	{
		if ("BS" == tmpGrad.getDegree())
			gradBS_list.remove(tmpGrad);
		else
			gradBA_list.remove(tmpGrad);
	}

		// 按照先BS后BA的顺序， 将表连接到diplomalist
	splice(diplomalist, diplomalist.end(), gradBS_list);
	splice(diplomalist, diplomalist.end(), gradBA_list);

		// 移除重复的信息
	removeDuplicates(diplomalist);

	writeList(diplomalist, "\n");

	system("pause");
	return 0;


}

//#include <iostream>
//#include <list>
//
//using namespace std;
//
//int main()
//{
//	list<int> intList;
//	intList.push_back(1);
//	intList.push_back(2);
//	intList.push_back(3);
//	intList.push_back(4);
//	intList.push_back(5);
//
//	list<int>::iterator iter = intList.begin();
//	while (iter != intList.end())
//	{
//		intList.push_front(*iter);
//		intList.erase(iter++);
//	}
//
//	for (iter = intList.begin(); iter != intList.end(); ++iter)
//	{
//		cout << *iter;
//	}
//
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <list>

using namespace std;

// 顺序查找，  在链表下标 [first, last) 范围内，查找目标值
//如果找到目标值，返回其在数组中的下标， 否则返回last
//template <typename FwdIt, typename T> inline
//FwdIt seqSearch(FwdIt first, FwdIt last, const T& target)
//{
//	FwdIt iter = first;
//	for (iter = first; iter != last; ++iter)
//	if (*iter == target)
//		return iter;		// 如果找到，返回下标
//
//	return last;		// 如果没有找到， 返回last
//}

//template <typename T> inline
//list<T>::iterator seqSearch(list<T>::iterator first, list<T>::iterator last, const T& target)
//{
//	list<T>::iterator iter = first;
//	for (iter = first; iter != last; ++iter)
//	if (*iter == target)
//		return iter;		// 如果找到，返回下标
//
//	return last;		// 如果没有找到， 返回last
//}

//int main()
//{
//	list<int> intList;
//	intList.push_back(1);
//	intList.push_back(2);
//	intList.push_back(3);
//	intList.push_back(4);
//	intList.push_back(5);
//
//	list<int>::iterator iter = seqSearch(intList.begin(), intList.end(), 4);
//
//	cout << *iter;
//
//	system("pause");
//	return 0;
//}

