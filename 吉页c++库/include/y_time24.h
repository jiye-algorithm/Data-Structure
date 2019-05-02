#ifndef TIME24_CLASSES
#define TIME24_CLASSES

#include <iostream>
#include <iomanip>

#include "../include/y_except.h"	// �׳�����Խ���쳣

using namespace std;

// _MSC_VER���Ե��ǰ汾��
#ifdef _MSC_VER
class time24;

time24 operator+ (const time24& lhs, const time24& rhs);
time24 operator+ (const time24& lhs, const int min);
time24 operator+ (const int min, const time24& rhs);

time24 operator- (const time24& lhs, const time24& rhs);

bool operator== (const time24& lhs, const time24& rhs);
bool operator< (const time24& lhs, const time24& rhs);

ostream& operator<< (ostream& os, const time24& rhs);
istream& operator>> (istream& is,  time24& rhs);


#endif // _MSC_VER

class time24
{
	// ��Ԫ����
	friend time24 operator+ (const time24& lhs, const time24& rhs);
	friend time24 operator+ (const time24& lhs, const int min);
	friend time24 operator+ (const int min, const time24& rhs);

	friend time24 operator- (const time24& lhs, const time24& rhs);

	friend bool operator== (const time24& lhs, const time24& rhs);
	friend bool operator< (const time24& lhs, const time24& rhs);

	friend ostream& operator<< (ostream& os, const time24& rhs);
	friend istream& operator>> (istream& is,  time24& rhs);


public:
	// ���캯���� ����ʱ���Ĭ��ֵΪ 00��00
	time24(int h = 0, int m = 0);

	// ʱ������ m ���ӣ�
	//ǰ�������� m>0�� �����׳�����Խ���쳣
	void addTime(int m);

	// ���ܣ� ���ص�ǰ����ʱ���������ʱ���
	//ǰ�������� ����ʱ�������ڵ�ǰ����ʱ�䣬�����׳�rangeError
	time24 duration(const time24& t) const;
	
	//���ܣ� ����һ��ʱ����Ϊ��ǰ�����ʱ�䣬 ��ʽΪ  hh:mm
	void readTime();

	// �����ǰ�����ʱ�䣬 ��ʽΪ��  hh:mm
	void writeTime() const;

	// �õ���ǰ�����Сʱֵ
	int getHour() const;

	// �õ���ǰ�������ֵ
	int getMinute()const;

	// ������ʱ�����ӵ���ǰʱ����
	time24& operator+= (const time24& rhs);

	// ��ǰ�����ʱ������minutes����
	// ǰ�������� minute>0 �����׳��쳣
	time24& operator+= (const int minute);

private:
	int hour, minute;

	//���������� �ǵ�ǰʱ�����ϰ��
	//��Сʱ�� 0-23 ֮�䣬 ������0-59 ֮��
	void normalizeTime();
};


/***************************************************************/
//					time24 ���ʵ��
/***************************************************************/

//��׼��ʱ��ı�ʾ��ʹ��Сʱ�� 0-24 ֮�䣬 ������ 0-59 ֮��
void time24::normalizeTime()
{
	int extendHour = 0;
	if (minute > 59) {
		extendHour = minute / 60;
		minute %= 60;
	}
	hour += extendHour;
	if (hour > 23) {
		hour %= 24;
	}
}

// ���캯���� ����ʱ���Ĭ��ֵΪ 00��00
time24::time24(int h , int m) : hour(h), minute(m)
{ normalizeTime(); }

////���ܣ� ����һ��ʱ����Ϊ��ǰ�����ʱ�䣬 ��ʽΪ  hh:mm
void time24::readTime() {
	char colonSeparator;
	cin >> hour >> colonSeparator >> minute;

	// ʹ�������ʱ�䳣�滯
	normalizeTime();
}

// �����ǰ�����ʱ�䣬 ��ʽΪ��  hh:mm
void time24::writeTime() const {
	//  ��¼��ǰ cout ���� flag �� fill ����ֵ
	long currentFlag = cout.flags();
	char currentFill = cout.fill();

	// ������Ҫ��flag �� fill ֵ
	cout.fill(' ');
	cout.setf(ios::right, ios::adjustfield);

	cout << setw(2) << hour << ":";

	cout.fill('0');
	cout << setw(2) << minute << "   ";

	// �����ɣ� �ָ�cout����״̬
	cout.fill(currentFill);
	cout.setf(currentFlag);
	cout << ends;

}

// �õ���ǰ�����Сʱֵ
int time24::getHour() const
{
	return hour;
}

// �õ���ǰ�������ֵ
int time24::getMinute() const
{
	return minute;
}

// ʱ������ m ���ӣ�
//ǰ�������� m>0�� �����׳�����Խ���쳣
void time24::addTime(int m) 
{
	minute += m;

	// ʹ�������ʱ�䳣�滯
	normalizeTime();
}

// ���ܣ� ���ص�ǰ����ʱ���������ʱ���
//ǰ�������� ����ʱ�������ڵ�ǰ����ʱ�䣬�����׳�rangeError
time24 time24::duration(const time24& t) const 
{
	int currentTime = hour * 60 + minute;
	int tTime = t.hour * 60 + minute;

	// ����ʱ�䲻���ڵ�ǰʱ��֮ǰ
	if (currentTime < tTime)	
		throw rangeError(
				"����ʱ�䲻���ڵ�ǰʱ��֮ǰ");	
	else 
		// ���ز���ʱ���뵱ǰʱ������ʱ��
		return time24(0, tTime - currentTime);
	
}



// ������ʱ�����ӵ���ǰʱ����
time24& time24::operator+= (const time24& rhs)
{
	// �������ص�+ �����������ʱ��ӵ���ǰʱ����
	*this = *this + rhs;

	//�����µĵ�ǰʱ��
	return *this;
}

// ��ǰ�����ʱ������minutes����
// ǰ�������� minute>0 �����׳��쳣
time24& time24::operator+= (const int minute)
{
	// �������ص�+������������ķ��������뵽��ǰʱ��
	*this = *this + minute;

	// �����µĵ�ǰʱ��
	return *this;
}

// ����time24�������
//����ֵ�� ������Ӻ��ֵ
time24 operator+ (const time24& lhs, const time24& rhs)
{
	//���ض����Сʱ�ͷ���
	time24 returnTime;
	returnTime.hour = lhs.hour + rhs.hour;
	returnTime.minute = lhs.minute + rhs.minute;

	returnTime.normalizeTime();

	return returnTime;
}

// ����time24�������
//����ֵ�� ������Ӻ��ֵ
time24 operator+ (const time24& lhs, const int min) 
{
	return min + lhs;
}

time24 operator+ (const int min,  const time24& rhs)
{

	// �����Ҳ�����ʱ�����������ʱ���
	return time24(rhs.hour, rhs.minute + min);
}

time24 operator- (const time24& lhs, const time24& rhs)
{
	if (lhs < rhs)
	{
		//�����ʱ���������Ҳ���ʱ��
		throw rangeError("�����ʱ���������Ҳ���ʱ��");
	}
	
// �����Ҳ������Ҳ����Ĳ�ֵ
	return time24(0, (lhs.hour * 60 + lhs.minute) -
					(rhs.hour * 60 + rhs.minute));
}

bool operator== (const time24& lhs, const time24& rhs)
{
	return lhs.hour == rhs.hour &&
		rhs.minute == rhs.minute;
}

bool operator< (const time24& lhs, const time24& rhs)
{
	return (lhs.hour * 60 + lhs.minute) <
		(rhs.hour * 60 + rhs.minute);

}

ostream& operator<< (ostream& os, const time24& rhs)
{
	//  ��¼��ǰ os ���� flag �� fill ����ֵ
	long currentFlag = os.flags();
	char currentFill = os.fill();

	// ������Ҫ��flag �� fill ֵ
	os.fill(' ');
	os.setf(ios::right, ios::adjustfield);

	os << setw(2) << rhs.hour << ":";

	os.fill('0');
	os << setw(2) << rhs.minute << "   ";

	// �����ɣ� �ָ�os����״̬
	os.fill(currentFill);
	os.setf(currentFlag);
	os << ends;

	return os;
}

istream& operator>> (istream& is, time24& rhs)
{
	char colonSeparator;
	is >> rhs.hour >> colonSeparator >> rhs.minute;

	// ʹ�������ʱ�䳣�滯
	rhs.normalizeTime();

	return is;
}

#endif // !TIME24_CLASS
