/*
	2014��4��13�� 18:50:09
	��ҳ
	���ܣ� �������12�������������Χ��100��999���� �趨���������洢һ����Χ��ֵ
	vSmall [100, 400)
	vMedium [400, 700)
	vLarge  [700, 1000)
	���ò�������ÿ�������� Ȼ������join()�� vSmall + vMedium + vLarge��������� 
	����writeVector�������ÿ������
*/

#include <iostream>
#include <vector>

#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_util.h"
#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_random.h"
#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\DataStruct_CppSTL\include/d_sort.h"

using namespace std;

// ������ cSrc ���뵽vDest��β��
template <typename T>
void join(vector<T>& vDest, const vector<T>& vSrc);

int main()
{
	// ���������
	randomNumber rnd;
	vector<int> vSmall, vMedium, vLarge;

	int value;

	for (size_t i = 0; i < 12; i++)
	{
		value = rnd.random(900) + 100;
		
		if (value < 400)
			vSmall.push_back(value);
		else if (value < 700)
			vMedium.push_back(value);
		else
			vLarge.push_back(value);

	}

	// ���ò������򷨣�������������������
	insertionSort(vSmall);
	insertionSort(vMedium);
	insertionSort(vLarge);


	// ���û�кϲ�ʱ������
	cout << endl <<  "�ϲ�ǰ vSmall: ";
	writeVector(vSmall);
	cout << endl <<  "�ϲ�ǰ vMedium: ";
	writeVector(vMedium);
	cout << endl << "�ϲ�ǰ vLarge: ";
	writeVector(vLarge);

	// �ϲ������� vSmall
	join(vSmall, vMedium);
	join(vSmall, vLarge);

	// ����ϲ������������
	cout << endl << "�ϲ�ǰ vSmall: ";
	writeVector(vSmall);

	system("pause");

	return 0;

}

// ������ cSrc ���뵽vDest��β��
template <typename T>
void join(vector<T>& vDest, const vector<T>& vSrc)
{
	vector<T>::size_t size = vSrc.size();

	for (size_t i = 0; i < size; i++)
	{
		vDest.push_back(vSrc[i]);
	}
}