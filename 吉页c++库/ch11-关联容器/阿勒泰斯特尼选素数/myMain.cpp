/*
		2014年5月18日 17:15:15
		吉页
		功能:   提示用户输入数字的上界 n， 选出从 2 ~n 之间的所有素数， 保存在集合中
		sieve（）函数进行删选素数，从 2~sqrt（n） 的数字筛选， 所有的合数， 如果数字存在， 那么筛除它所有的倍数
		如遍历到 2 的筛选， 剔除 2 的（２，　３，　４，　５，　。。。）等等倍数，　
		遍历到　３　的筛选，　剔除３的（２，　３，　４，　５，　。。）等等倍数
		遍历到　４　的筛选，　由于４已被剔除，　所有不做任何操作，　继续下一个　５，
		直到到达　根号ｎ　为止
*/

#include <iostream>
#include <set>
#include <iomanip>

using namespace std;

void sieve(set<int>& s, int n);

int main()
{
		// 建立筛选集
	set<int> s;
		// 获得筛选集上界
	int n;
	cout << "please enter the upper_range of the set: ";
	cin >> n;

		// 进行筛选， 得到所有素数集
	sieve(s, n);

		// 输出素数集，每行10个数字
	set<int>::iterator iter = s.begin();
	int count = 0;
	while (iter != s.end())
	{
		count++;
		cout << setw(5) << *iter;
		if (count % 10 == 0)
			cout << endl;

		++iter;
	}
	cout << endl;

	system("pause");
}

void sieve(set<int>& s, int n)
{
	s.erase(s.begin(), s.end());
		// 建立待筛选集
	for (int i = 2; i < n; i++)
		s.insert(i);
		// 从 2 ~ sqrt（n）开始筛选素数
	for (int m = 2; m * m <= n; ++m)
	{	
			// 如果数字在集合中， 就进行筛选
		if (s.find(m) != s.end())
		{
			int i = 2 * m;
			while (i <= n)
			{
				s.erase(i);
				i += m;
			}
		}
	}
}

/************************************************************************/
/*  总结                 
		算法利用筛选步骤， 确定各个阶段的步长， 然后进行筛选
		这样的筛选可以当元素剔除是跳过此操作来节省遍历的时间。
*/
/************************************************************************/