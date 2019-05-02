#ifndef MATRIX_CLASS
#define MATRIX_CLASS

#include <vector>

#include "y_except.h"

using namespace std;

template <typename T>
class matrix
{
public:
		// 构造函数， 构造一个numRow行，numCol列的矩阵，以initValue为初始值
	matrix(int numRow = 1, int numCol = 1, const T& initValue = T());
		
		//读取矩阵i行某个元素
		// 前置条件： 0 < i < rows, 否则throw indexRangeError
	vector<T>& operator[] (int i);
	const vector<T>& operator[] (int i) const;

		// 返回矩阵的行数
	int rows() const;

		// 返回矩阵的列数
	int cols() const;

		// 将矩阵重置为 numRows * numCols; 任意新元素T的默认值填充
	void resize(int numRows, int numCols);

private:
		// 行数和列数
	int nRows, nCols;

		// 保存矩阵元素的二维向量
	vector<vector<T> > mat;
};


///////////////////////////////////////////////////////////////////
//			矩阵类的实现
///////////////////////////////////////////////////////////////////



// 构造函数， 构造一个numRow行，numCol列的矩阵，以initValue为初始值
template <typename T>
matrix<T>::matrix(int numRow, int numCol, const T& initValue) :
nRows(numRow), nCols(numCol),
mat(nRows, vector<T>(nCols, initValue))
{}

//读取矩阵i行某个元素
// 前置条件： 0 < i < rows, 否则throw indexRangeError
template <typename T>
vector<T>& matrix<T>::operator[] (int i)
{
		// 0 < i < rows, 否则throw indexRangeError
	if (i < 0 || i > nRows - 1)
		throw indexRangeError("operator[]参数不是有效的： ", i, nRows);

	return mat[i];
}

template <typename T>
const vector<T>& matrix<T>::operator[] (int i) const
{
		// 0 < i < rows, 否则throw indexRangeError
	if (i < 0 || i > nRows - 1)
		throw indexRangeError("operator[]参数不是有效的： ", i, nRows);

	return mat[i];
}

// 返回矩阵的行数
template <typename T>
int matrix<T>::rows() const
{
	return nRows;
}

// 返回矩阵的列数
template <typename T>
int matrix<T>::cols() const
{
	return nCols;
}

// 将矩阵重置为 numRows * numCols; 任意新元素T的默认值填充
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
