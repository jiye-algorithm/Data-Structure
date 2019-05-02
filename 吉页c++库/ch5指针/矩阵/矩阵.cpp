/*
	2014��4��19�� 10:43:23
	��ҳ
	���ܣ� ��������һ������intMat�� һ��time24����timeMat�� �����ļ�mat.dat��ΪԪ�ض�ȡ���ݣ� ����ĵ�һ����intMat�ĺ���������
	������resize���������ֵȷ������ά���� �������matSum����������ÿ�������е�ֵ�ĺ�
*/

#include <iostream>
#include <fstream>

#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_matrix.h"
#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_time24.h"

using namespace std;

// ����mat��Ԫ�صĺ�
template <typename T>
T matSum(const matrix<T>& mat);

int main()
{
	matrix<int> intMat;
	matrix<time24> timeMat;

	int numRows, numCols;
	ifstream fin("mat.dat");
	if (!fin)
	{
		cerr << "Cannot open mat.dat";
		exit(1);
	}

	fin >> numRows >> numCols;
	intMat.resize(numRows, numCols);
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
			fin >> intMat[i][j];
	}
	cout << "the sum of intMat: " << matSum(intMat) << endl;

	fin >> numRows >> numCols;
	timeMat.resize(numRows, numCols);
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
			fin >> timeMat[i][j];
	}
	cout << "the sum of timeMat: " << matSum(timeMat) << endl;

	system("pause");

	return 0;
}

// ����mat��Ԫ�صĺ�
template <typename T>
T matSum(const matrix<T>& mat)
{
	int rows = mat.rows();
	int cols = mat.cols();

	T sum = T();

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			sum += mat[i][j];
		}
	}

	return sum;
}