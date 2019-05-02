#ifndef TIMECARD_CLASS
#define TIMECARD_CLASS

#include <iostream>

#include "y_time24.h"
#include "y_except.h"
#include "y_util.h"

using namespace std;

class timeCard
{
public:
	// ��ʼ��˽�г�Ա�� ����ΪԱ���ź�Ա���򿨵�ʱ��
	timeCard(const string& ssno, const double rate, 
		const int punchInHour, const int punchInMinute) :

		punchInTime(punchInHour, punchInMinute),
		workId(ssno), hasPunched(false), payrate(rate)
	{}

	// Ա���°��Ĵ�
	void PunchOut(const time24& out)
	{
		punchOutTime = out;
		hasPunched = true;
	}

	// ���Ա����нˮ��Ϣ
	//��ʽ:		ÿСʱ��нˮ��		Ա����
	//			�ϰ�ʱ�䣺			�°�ʱ�䣺
	//			�ܵĹ���ʱ��:		�ܵĹ��ʣ�	
	// ǰ�������� ���Ա��û�д��°࿨(hasPunch=false)�� �׳�rangeError
	void writeSalaryInfo();

private:
	time24 punchInTime, punchOutTime;
	double payrate;
	string workId;
	bool hasPunched;
};

// ���Ա����нˮ��Ϣ
//��ʽ:		Ա���ţ�			ÿСʱ��нˮ:
//			�ϰ�ʱ�䣺			�°�ʱ�䣺
//			�ܵĹ���ʱ��:		�ܵĹ��ʣ�			
void timeCard::writeSalaryInfo()
{
	if (hasPunched == false)
		throw rangeError("writeSalaryInfo ����������Ч��");

	// �ܵĹ���ʱ�䣬�� h Ϊ��λ
	time24 workTime = punchInTime - punchOutTime;
	double workHours = workTime.getHour() + workTime.getMinute() / 60;

	cout << "Ա���ţ�  " << workId 
		<< "\tÿСʱнˮ��  " << setreal(10,2) << payrate << endl
		<< "�ϰ�ʱ��  " << punchInTime 
		<< "�°�ʱ�䣺   " << punchOutTime << endl
		<< "�ܵĹ���ʱ��:  " << workHours
		<< "�ܵ�нˮ   " << setreal(10, 2) << payrate * workHours << endl;

}

#endif // !TIMECARD_CLASS
