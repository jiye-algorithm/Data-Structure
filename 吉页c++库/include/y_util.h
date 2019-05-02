#ifndef UTILITY_FUNCTIONS
#define UTILITY_FUNCTIONS

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>

//#include "E:\学习\data stucture\data STL\DataStruct_CppSTL\include/d_stree.h"		// for the stree class

using namespace std;

#ifdef _MSC_VER
// temporary fix for Microsoft VC++ 6.0 bug, 
istream& getline(istream& is, string& sbuf, char term_char = '\n');
#endif //_MSC_VER

// output an array
template <typename T>
void writeArray(const T arr[], int n);

// output a vector
template <typename T>
void writeVector(const vector<T>& v);

// output a list 
// default sperator = " "
template <typename T>
void writeList(const list<T>& alist, const string& separator = " ");

// output a tree 
// default sperator = " "
//template <typename T>
//void writeList(const stree<T>& t, const string& separator = " ");

// output the elements of a container in the itrator range [first, last)
// default separator = " "
template <typename Iterator>
void writeContainer(Iterator first, Iterator last, const string& separator = " ");

// display the key-value pair in map
// default separator = " "
template <typename Key, typename T>
void writeMap(const map<Key, T>& m, const string& separator = " ");

// return the max value of a container in range [first, last)
template <typename Iterator>
Iterator maxElement(Iterator first, Iterator last);

// class used for one-arguement I/O manipulators
template <typename T>
class omanip1
{
public:
	// constructor , initial the private members
	omanip1(ostream& (*f)(ostream& ostr, const T& x), const T& w) :
		func(f), parm(w)
	{}

	friend ostream& operator<< (ostream& ostr, const omanip1<T>& f)
	{
		return (*f.func)(ostr, f.parm);
	}

private:
	// point a function to do the word
	ostream& (&func)(ostream& ostr, const T& x);

	// the two miniplator parameter in the class
	T parm;
};

// class used for two-agruement I/O manipulator
template <typename T>
class omanip2
{
public:
	// constructor initial the private members
	omanip2(ostream& (*f)(ostream& ostr, const T& x, const T& y),
		const T& w, const T& p) :
		func(f), parm1(w), parm2(p)
	{}

	friend ostream& operator<< (ostream& ostr, const omanip2<T>& f)
	{
		(*f.func)(ostr, f.parm1, f.parm2);
		return ostr;
	}

private:
	// the function to do the work
	ostream& (*func)(ostream& ostr, const T& x, const T& y);

	T parm1, parm2;
};

// change ostr to fixed mode precision with p decimal places.
// output the next stream data item in a field of w positions
ostream& sr(ostream& ostr, const int& w, const int& p);

// 设置显示总的位数为w， 小数点后有p位
omanip2<int> setreal(int w, int p);

#ifdef _MSC_VER

// temporary fix for Microsoft VC++ 6.0 bug, 
istream& getline(istream& is, string& sbuf, char term_char)
{
	char tc, eof = char_traits<char>::eof();
	int numchars = 0;

	sbuf.erase();

	while (true)
	{
		is.get(tc);
		// 如果读到流的末尾， 结束读取并设置流状态为失败字节读取
		if (tc == eof)
		{
			is.setstate(ios::failbit);
			break;
		}
		// 如果读到终止字符， 结束读取
		if (tc == term_char)
			break;

		sbuf.append(1, tc);
		numchars++;

		if (numchars == sbuf.max_size())
			break;
	}

	return is;
}

#endif // _MSC_VER

//////////////////////////////////////////////////////////////
//					实现部分
/////////////////////////////////////////////////////////////

// output an array
template <typename T>
void writeArray(const T arr[], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

// output a vector
template <typename T>
void writeVector(const vector<T>& v)
{
	int length = v.size();

	for (size_t i = 0; i < length; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

// output a list 
// default sperator = " "
template <typename T>
void writeList(const list<T>& alist, const string& separator)
{
	list<T>::const_iterator iter;

	for (iter = alist.begin(); iter != alist.end(); ++iter)
	{
		cout << *iter << separator;
	}
	cout << endl;
}

// output a tree 
// default sperator = " "
//template <typename T>
//void writeList(const stree<T>& t, const string& separator = " ")
//{
//	stree<T>::const_itertor iter = t.begin();
//
//	while (iter != t.end())
//	{
//		cout << *iter << separator;
//	}
//
//	cout << endl;
//}

// output the elements of a container in the itrator range [first, last)
// default separator = " "
template <typename Iterator>
void writeContainer(Iterator first, Iterator last, const string& separator)
{
	while (first != last)
	{
		cout << *first++ << separator;
	}

	cout << endl;
}

// display the key-value pair in map
// default separator = " "
template <typename Key, typename T>
void writeMap(const map<Key, T>& m, const string& separator)
{
	map<T>::const_itertor iter = m.begin();

	while (iter != m.end())
	{
		cout << iter->first << " " << iter->second << separator;
		iter++;
	}

	cout << endl;
}                                      

// return the max value of a container in range [first, last)
template <typename Iterator>
Iterator maxElement(Iterator first, Iterator last)
{
	//记录做大值的位置
	Iterator maxIter = first;

	while (first != last)
	{
		if (*maxIter < *first)
			maxIter = first;
		++first;
	}

	return maxIter;
}

ostream& sr(ostream& os, const int& w, const int& p)
{
	os.setf(ios::fixed || ios::floatfield);
	os.precision(p);
	os.width(w);

	return os;
}

// 使用sr 函数， 设置实数的输出
omanip2<int> setreal(ostream& os, int w, int p)
{
	return omanip2<int>(sr, w, p);
}

#endif // !UTILITY_FUNCTIONS
