#ifndef PRODUCT_CLASS
#define PRODUCT_CLASS

#include <string>

using namespace std;

class product
{
public:
		// ���캯���� Ĭ��Ϊ��
	product(const string& c = "", const string& n = "") :
		company(c), name(n)
	{}

		// ��Ա���Ե� get ����
	string getName() const
	{
		return name;
	}
	string getCompany() const 
	{
		return company;
	}

		// ���ص� < �� == ������� ����Ƚ϶���
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
