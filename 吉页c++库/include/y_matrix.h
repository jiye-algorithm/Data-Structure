#ifndef MATRIX_CLASS
#define MATRIX_CLASS

#include <vector>

#include "y_except.h"

using namespace std;

template <typename T>
class matrix
{
public:
		// ���캯���� ����һ��numRow�У�numCol�еľ�����initValueΪ��ʼֵ
	matrix(int numRow = 1, int numCol = 1, const T& initValue = T());
		
		//��ȡ����i��ĳ��Ԫ��
		// ǰ�������� 0 < i < rows, ����throw indexRangeError
	vector<T>& operator[] (int i);
	const vector<T>& operator[] (int i) const;

		// ���ؾ��������
	int rows() const;

		// ���ؾ��������
	int cols() const;

		// ����������Ϊ numRows * numCols; ������Ԫ��T��Ĭ��ֵ���
	void resize(int numRows, int numCols);

private:
		// ����������
	int nRows, nCols;

		// �������Ԫ�صĶ�ά����
	vector<vector<T> > mat;
};


///////////////////////////////////////////////////////////////////
//			�������ʵ��
///////////////////////////////////////////////////////////////////



// ���캯���� ����һ��numRow�У�numCol�еľ�����initValueΪ��ʼֵ
template <typename T>
matrix<T>::matrix(int numRow, int numCol, const T& initValue) :
nRows(numRow), nCols(numCol),
mat(nRows, vector<T>(nCols, initValue))
{}

//��ȡ����i��ĳ��Ԫ��
// ǰ�������� 0 < i < rows, ����throw indexRangeError
template <typename T>
vector<T>& matrix<T>::operator[] (int i)
{
		// 0 < i < rows, ����throw indexRangeError
	if (i < 0 || i > nRows - 1)
		throw indexRangeError("operator[]����������Ч�ģ� ", i, nRows);

	return mat[i];
}

template <typename T>
const vector<T>& matrix<T>::operator[] (int i) const
{
		// 0 < i < rows, ����throw indexRangeError
	if (i < 0 || i > nRows - 1)
		throw indexRangeError("operator[]����������Ч�ģ� ", i, nRows);

	return mat[i];
}

// ���ؾ��������
template <typename T>
int matrix<T>::rows() const
{
	return nRows;
}

// ���ؾ��������
template <typename T>
int matrix<T>::cols() const
{
	return nCols;
}

// ����������Ϊ numRows * numCols; ������Ԫ��T��Ĭ��ֵ���
template <typename T>
void matrix<T>::resize(int numRows, int numCols)
{
	if (nRows == numRows && nCols == numCols) return;

	nRows = numRows;
	nCols = numCols;

	mat.resize(nRows);

	for (int i = 0; i < nRows; ++i)
		mat[i].resize(numCols);
}

#endif // !MATRIX_CLASS
