#ifndef GRADUATE_CLASS
#define  GRADUATE_CLASS

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class graduate
{
		// ����
public:
		// ���캯����
	graduate();

		// �õ���ҵ��ѧλ
	string getDegree()
	{
		return degree;
	}

		// ���ص� == ��, �Ƚ�������ҵ�������Ƿ���ͬ�� �����ڱ����ظ�����
	friend bool operator== (const graduate& lhs, const graduate& rhs)
	{
		return lhs.name == rhs.name;
	}

		// �Ƚ���������أ� ����Ϊ��ҵ��������ĸ����
	friend bool operator< (const graduate& lhs, const graduate& rhs)
	{
		return lhs.name < rhs.name;
	}

		// ������������أ� ������ļ��ж�ȡ��ҵ������
	friend istream& operator>> (istream& istr, graduate& rhs)
	{
		getline(istr, rhs.name, '\t');
		getline(istr, rhs.degree, '\n');

		return istr;
	}

		// �����������أ� ������ʾ��ҵ������
	friend ostream& operator<< (ostream& ostr, const graduate& rhs)
	{
		ostr.setf(ios::left, ios::adjustfield);

		ostr << setw(20) << rhs.name << rhs.degree;

		ostr.setf(ios::right, ios::adjustfield);
	}
	
	// ����
private:
		// ��ҵ�������ֺ�ѧλ
	string name, degree;
};


#endif // !GRADUATE_CLASS
