#ifndef PRODUCT_CLASS
#define PRODUCT_CLASS

#include <string>

using namespace std;

class product
{
public:
		// 构造函数， 默认为空
	product(const string& c = "", const string& n = "") :
		company(c), name(n)
	{}

		// 成员属性的 get 方法
	string getName() const
	{
		return name;
	}
	string getCompany() const 
	{
		return company;
	}

		// 重载的 < 和 == 运算符， 方便比较对象
	friend bool operator< (const product& lhs, const product& rhs)
	{
		return lhs.company < rhs.company;
	}
	friend bool operator== (const product& lhs, const product& rhs)
	{
		return lhs.company == rhs.company;
	}
private:
	string company, name;
};

#endif // !PRODUCT_CLASS
