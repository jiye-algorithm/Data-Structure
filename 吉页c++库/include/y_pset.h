#ifndef POWERSET_FUNCTIONS
#define  POWERSET_FUNCTIONS

#include <set>

#include "y_setops.h"	// ���� +

// return the power set of s
template <typename T>
set<set<T> > powerSet(set<T>& s);

// output the power set of a set with n elements
template <typename T>
void writePowerSet(set<set<T> >& pSet);


/************************************************************************/
/*									ʵ��	                                                              */
/************************************************************************/


// return the power set of s
template <typename T>
set<set<T> > powerSet(set<T>& s)
{
		// ����Ԫ���ϵ��Ӽ����޳���Ԫ�ص��Ӽ�
	set<set<T> > sPrime, sPrimePlus;
		// �����ݼ�
	set<set<T> >pSet;
	set<T> empty;

		// ����ռ�
	if (0 == s.size())
		pSet.insert(empty);
	else
	{
		T temp = *(s.begin());

		s.erase(temp);
			// �õ�ȥ��Ԫ�غ�ļ����Ӽ�
		 sPrime = powerSet(s);
			// ��Ԫ�ؼ����������Ӽ�
		 set<set<T> >::iterator iter;
		 set<T> tempSet;
		 for (iter = sPrime.begin(); iter != sPrime.end(); ++iter)
		 {
			 tempSet = *iter;
			 tempSet.insert(temp);
			 sPrimePlus.insert(tempSet);
		 }
			// s���ݼ��� sPrime�� sPrimePlus�Ĳ���
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
			// ׼�������ļ��Ϻ͵�����
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








