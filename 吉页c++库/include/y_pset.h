#ifndef POWERSET_FUNCTIONS
#define  POWERSET_FUNCTIONS

#include <set>

#include "y_setops.h"	// 集合 +

// return the power set of s
template <typename T>
set<set<T> > powerSet(set<T>& s);

// output the power set of a set with n elements
template <typename T>
void writePowerSet(set<set<T> >& pSet);


/************************************************************************/
/*									实现	                                                              */
/************************************************************************/


// return the power set of s
template <typename T>
set<set<T> > powerSet(set<T>& s)
{
		// 保存元集合的子集和剔除首元素的子集
	set<set<T> > sPrime, sPrimePlus;
		// 将是幂集
	set<set<T> >pSet;
	set<T> empty;

		// 处理空集
	if (0 == s.size())
		pSet.insert(empty);
	else
	{
		T temp = *(s.begin());

		s.erase(temp);
			// 得到去掉元素后的集合子集
		 sPrime = powerSet(s);
			// 将元素加入后的所有子集
		 set<set<T> >::iterator iter;
		 set<T> tempSet;
		 for (iter = sPrime.begin(); iter != sPrime.end(); ++iter)
		 {
			 tempSet = *iter;
			 tempSet.insert(temp);
			 sPrimePlus.insert(tempSet);
		 }
			// s的幂集是 sPrime和 sPrimePlus的并集
		 pSet = sPrime + sPrimePlus;
	}

	return pSet;

}

// output the power set of a set with n elements
template <typename T>
void writePowerSet(set<set<T> >& pSet)
{
	set<T> temp;
	set<set<T> >::iterator ssIter = pSet.begin();
	set<T>::iterator sIter;
	int count = 0;

	while (ssIter != pSet.end())
	{
		if (count++ % 4 == 0)
			cout << endl;
			// 准备遍历的集合和迭代器
		temp = *ssIter;

		cout << "{  ";
		for (sIter = temp.begin(); sIter != temp.end(); ++sIter)
		{
			cout << *sIter << " ";
		}
		cout << "}, ";

		++ssIter;
	}
	cout << endl;
}

#endif // !POWERSET_FUNCTIONS








