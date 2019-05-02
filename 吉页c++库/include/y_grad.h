#ifndef GRADUATE_CLASS
#define  GRADUATE_CLASS

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class graduate
{
		// 方法
public:
		// 构造函数，
	graduate();

		// 得到毕业生学位
	string getDegree()
	{
		return degree;
	}

		// 重载的 == 符, 比较两个毕业生名字是否相同， 放置在表中重复对象
	friend bool operator== (const graduate& lhs, const graduate& rhs)
	{
		return lhs.name == rhs.name;
	}

		// 比较运算符重载， 方便为毕业生进行字母排序
	friend bool operator< (const graduate& lhs, const graduate& rhs)
	{
		return lhs.name < rhs.name;
	}

		// 输入运算符重载， 方便从文件中读取毕业生数据
	friend istream& operator>> (istream& istr, graduate& rhs)
	{
		getline(istr, rhs.name, '\t');
		getline(istr, rhs.degree, '\n');

		return istr;
	}

		// 输出运算符重载， 方便显示毕业生数据
	friend ostream& operator<< (ostream& ostr, const graduate& rhs)
	{
		ostr.setf(ios::left, ios::adjustfield);

		ostr << setw(20) << rhs.name << rhs.degree;

		ostr.setf(ios::right, ios::adjustfield);
	}
	
	// 属性
private:
		// 毕业生的名字和学位
	string name, degree;
};


#endif // !GRADUATE_CLASS
