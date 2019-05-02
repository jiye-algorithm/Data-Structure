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
	// 初始化私有成员， 参数为员工号和员工打卡的时间
	timeCard(const string& ssno, const double rate, 
		const int punchInHour, const int punchInMinute) :

		punchInTime(punchInHour, punchInMinute),
		workId(ssno), hasPunched(false), payrate(rate)
	{}

	// 员工下班后的打卡
	void PunchOut(const time24& out)
	{
		punchOutTime = out;
		hasPunched = true;
	}

	// 输出员工的薪水信息
	//格式:		每小时的薪水：		员工号
	//			上班时间：			下班时间：
	//			总的工作时间:		总的工资：	
	// 前置条件： 如果员工没有打下班卡(hasPunch=false)， 抛出rangeError
	void writeSalaryInfo();

private:
	time24 punchInTime, punchOutTime;
	double payrate;
	string workId;
	bool hasPunched;
};

// 输出员工的薪水信息
//格式:		员工号：			每小时的薪水:
//			上班时间：			下班时间：
//			总的工作时间:		总的工资：			
void timeCard::writeSalaryInfo()
{
	if (hasPunched == false)
		throw rangeError("writeSalaryInfo 参数不是有效的");

	// 总的工作时间，以 h 为单位
	time24 workTime = punchInTime - punchOutTime;
	double workHours = workTime.getHour() + workTime.getMinute() / 60;

	cout << "员工号：  " << workId 
		<< "\t每小时薪水：  " << setreal(10,2) << payrate << endl
		<< "上班时间  " << punchInTime 
		<< "下班时间：   " << punchOutTime << endl
		<< "总的工作时间:  " << workHours
		<< "总的薪水   " << setreal(10, 2) << payrate * workHours << endl;

}

#endif // !TIMECARD_CLASS
