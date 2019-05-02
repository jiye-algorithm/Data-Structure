/*
	2014��4��22�� 21:42:40
	��ҳ
	���ܣ� graduate �����ѧ�������ֺ�ѧλ���ͣ�BA��BS����
	�����ȡ�ļ��ı�ҵ����Ϣ�� gradBS_list �� gradBA_list��ʹ�� insertOrder()��ÿ����
	����ҵ���������������� noattened.dat�м��أ����μӱ�ҵ�����ѧ����ʹ��
	removeGraduate() ����������ѧλ�� gradBS_list�� gradBA_list��ɾ��ѧ����
	splice������ ��diplomalist���н�ǰ���������������� ������BS��ҵ���� 
	�����BA��ҵ���� �����ʾ��Ϣ��
*/

#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include\y_grad.h"
#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include\y_util.h"
#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include\y_search.h"
#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include\y_listl.h"

using namespace std;

//void removeGraduate(list<graduate>& gradList, const graduate& grad);

int main()
{
		// ��ҵ����
	list<graduate> gradBS_list, gradBA_list, diplomalist;

		// ���ļ�����ȡ��ҵ������
	ifstream fin("gradlist.dat");
		// �ļ��򿪵�״̬�� 
	if (!fin)
	{
		cerr << "�ļ� gradList��dat ��ȡʧ�ܣ� " << endl;
		exit(1);
	}

		// ��ȡ�ļ��ı�ҵ����Ϣ�� gradBS_list �� gradBA_list
	graduate tmpGrad;
	while (fin >> tmpGrad)
	{
		if ("BS" == tmpGrad.getDegree())
			insertSort(gradBS_list, tmpGrad);
		else
			insertSort(gradBA_list, tmpGrad);
	}

		// �ر��ļ�
	fin.close();

		// ��ʾ�ܵı�ҵ����Ϣ
	writeList(gradBS_list, "\n");
	writeList(gradBA_list, "\n");

		// �򿪲��μӱ�ҵ�����ѧ���ļ�
	fin.open("noattend.dat");
		// �ж��ļ��Ƿ��ѱ���ȷ��
	if (!fin)
	{
		cerr << "�ļ� noattend.dat δ����ȷ�򿪣� " << endl;
		exit(1);
	}

		// �����б��и��ݲ��μӵ��������ɾ��ѧ��
	while (fin >> tmpGrad)
	{
		if ("BS" == tmpGrad.getDegree())
			gradBS_list.remove(tmpGrad);
		else
			gradBA_list.remove(tmpGrad);
	}

		// ������BS��BA��˳�� �������ӵ�diplomalist
	splice(diplomalist, diplomalist.end(), gradBS_list);
	splice(diplomalist, diplomalist.end(), gradBA_list);

		// �Ƴ��ظ�����Ϣ
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

// ˳����ң�  �������±� [first, last) ��Χ�ڣ�����Ŀ��ֵ
//����ҵ�Ŀ��ֵ���������������е��±꣬ ���򷵻�last
//template <typename FwdIt, typename T> inline
//FwdIt seqSearch(FwdIt first, FwdIt last, const T& target)
//{
//	FwdIt iter = first;
//	for (iter = first; iter != last; ++iter)
//	if (*iter == target)
//		return iter;		// ����ҵ��������±�
//
//	return last;		// ���û���ҵ��� ����last
//}

//template <typename T> inline
//list<T>::iterator seqSearch(list<T>::iterator first, list<T>::iterator last, const T& target)
//{
//	list<T>::iterator iter = first;
//	for (iter = first; iter != last; ++iter)
//	if (*iter == target)
//		return iter;		// ����ҵ��������±�
//
//	return last;		// ���û���ҵ��� ����last
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

