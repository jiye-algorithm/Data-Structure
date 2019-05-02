#ifndef TIME24_CLASSES
#define TIME24_CLASSES

#include <iostream>
#include <iomanip>

#include "../include/y_except.h"	// 抛出参数越界异常

using namespace std;

// _MSC_VER定以的是版本号
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
	// 友元函数
	friend time24 operator+ (const time24& lhs, const time24& rhs);
	friend time24 operator+ (const time24& lhs, const int min);
	friend time24 operator+ (const int min, const time24& rhs);

	friend time24 operator- (const time24& lhs, const time24& rhs);

	friend bool operator== (const time24& lhs, const time24& rhs);
	friend bool operator< (const time24& lhs, const time24& rhs);

	friend ostream& operator<< (ostream& os, const time24& rhs);
	friend istream& operator>> (istream& is,  time24& rhs);


public:
	// 构造函数， 设置时间的默认值为 00：00
	time24(int h = 0, int m = 0);

	// 时间增加 m 分钟，
	//前置条件： m>0， 否则抛出参数越界异常
	void addTime(int m);

	// 功能： 返回当前对象时间与参数的时间差
	//前置条件： 参数时间必须大于当前对象时间，否则抛出rangeError
	time24 duration(const time24& t) const;
	
	//功能： 读入一个时间作为当前对象的时间， 格式为  hh:mm
	void readTime();

	// 输出当前对象的时间， 格式为：  hh:mm
	void writeTime() const;

	// 得到当前对象的小时值
	int getHour() const;

	// 得到当前对象分钟值
	int getMinute()const;

	// 将参数时间增加到当前时间上
	time24& operator+= (const time24& rhs);

	// 当前对象的时间增加minutes分钟
	// 前置条件： minute>0 否则抛出异常
	time24& operator+= (const int minute);

private:
	int hour, minute;

	//辅助函数， 是当前时间符合习惯
	//即小时在 0-23 之间， 分钟在0-59 之间
	void normalizeTime();
};


/***************************************************************/
//					time24 类的实现
/***************************************************************/

//标准化时间的表示，使得小时在 0-24 之间， 分钟在 0-59 之间
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

// 构造函数， 设置时间的默认值为 00：00
time24::time24(int h , int m) : hour(h), minute(m)
{ normalizeTime(); }

////功能： 读入一个时间作为当前对象的时间， 格式为  hh:mm
void time24::readTime() {
	char colonSeparator;
	cin >> hour >> colonSeparator >> minute;

	// 使得输入的时间常规化
	normalizeTime();
}

// 输出当前对象的时间， 格式为：  hh:mm
void time24::writeTime() const {
	//  记录当前 cout 流的 flag 和 fill 属性值
	long currentFlag = cout.flags();
	char currentFill = cout.fill();

	// 设置需要的flag 和 fill 值
	cout.fill(' ');
	cout.setf(ios::right, ios::adjustfield);

	cout << setw(2) << hour << ":";

	cout.fill('0');
	cout << setw(2) << minute << "   ";

	// 输出完成， 恢复cout流的状态
	cout.fill(currentFill);
	cout.setf(currentFlag);
	cout << ends;

}

// 得到当前对象的小时值
int time24::getHour() const
{
	return hour;
}

// 得到当前对象分钟值
int time24::getMinute() const
{
	return minute;
}

// 时间增加 m 分钟，
//前置条件： m>0， 否则抛出参数越界异常
void time24::addTime(int m) 
{
	minute += m;

	// 使得输入的时间常规化
	normalizeTime();
}

// 功能： 返回当前对象时间与参数的时间差
//前置条件： 参数时间必须大于当前对象时间，否则抛出rangeError
time24 time24::duration(const time24& t) const 
{
	int currentTime = hour * 60 + minute;
	int tTime = t.hour * 60 + minute;

	// 参数时间不能在当前时间之前
	if (currentTime < tTime)	
		throw rangeError(
				"参数时间不能在当前时间之前");	
	else 
		// 返回参数时间与当前时间的相差时间
		return time24(0, tTime - currentTime);
	
}



// 将参数时间增加到当前时间上
time24& time24::operator+= (const time24& rhs)
{
	// 利用重载的+ 运算符将参数时间加到当前时间上
	*this = *this + rhs;

	//返回新的当前时间
	return *this;
}

// 当前对象的时间增加minutes分钟
// 前置条件： minute>0 否则抛出异常
time24& time24::operator+= (const int minute)
{
	// 利用重载的+运算符将参数的分钟数加入到当前时间
	*this = *this + minute;

	// 返回新的当前时间
	return *this;
}

// 两个time24对象相加
//返回值： 对象相加后的值
time24 operator+ (const time24& lhs, const time24& rhs)
{
	//返回对象的小时和分钟
	time24 returnTime;
	returnTime.hour = lhs.hour + rhs.hour;
	returnTime.minute = lhs.minute + rhs.minute;

	returnTime.normalizeTime();

	return returnTime;
}

// 两个time24对象相加
//返回值： 对象相加后的值
time24 operator+ (const time24& lhs, const int min) 
{
	return min + lhs;
}

time24 operator+ (const int min,  const time24& rhs)
{

	// 返回右参数的时间与左参数的时间和
	return time24(rhs.hour, rhs.minute + min);
}

time24 operator- (const time24& lhs, const time24& rhs)
{
	if (lhs < rhs)
	{
		//左参数时间必须大于右参数时间
		throw rangeError("左参数时间必须大于右参数时间");
	}
	
// 返回右参数与右参数的差值
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
	//  记录当前 os 流的 flag 和 fill 属性值
	long currentFlag = os.flags();
	char currentFill = os.fill();

	// 设置需要的flag 和 fill 值
	os.fill(' ');
	os.setf(ios::right, ios::adjustfield);

	os << setw(2) << rhs.hour << ":";

	os.fill('0');
	os << setw(2) << rhs.minute << "   ";

	// 输出完成， 恢复os流的状态
	os.fill(currentFill);
	os.setf(currentFlag);
	os << ends;

	return os;
}

istream& operator>> (istream& is, time24& rhs)
{
	char colonSeparator;
	is >> rhs.hour >> colonSeparator >> rhs.minute;

	// 使得输入的时间常规化
	rhs.normalizeTime();

	return is;
}

#endif // !TIME24_CLASS
