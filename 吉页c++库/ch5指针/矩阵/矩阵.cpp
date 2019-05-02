/*
	2014年4月19日 10:43:23
	吉页
	功能： 程序声明一个矩阵intMat， 一个time24矩阵timeMat， 并存文件mat.dat中为元素读取数据， 输入的第一行是intMat的函数和列数
	，函数resize（）用这个值确定矩阵维数， 程序调用matSum（）来计算每个矩阵中的值的和
*/

#include <iostream>
#include <fstream>

#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_matrix.h"
#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_time24.h"

using namespace std;

// 返回mat中元素的和
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

// 返回mat中元素的和
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