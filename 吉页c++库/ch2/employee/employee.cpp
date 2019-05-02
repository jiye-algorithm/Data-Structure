/*
	2014年4月9日 15:04:51
	吉页
	功能： 此程序模拟临时员工上班和5：00PM 下班是离开工厂，
	程序提示用户输入上班的小时和分钟数，以及社会保障号，
	他使用timeCard类确定员工一天的工资，
	程序使用随机数模拟四分之三的人员自己打卡
	在这种情况下， 程序处理没有打卡时 timeCard 类抛出的rangeError异常
	catch 块模拟管理人员为员工打卡
*/

#include <iostream>

#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_random.h"
#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_tcard.h"

using namespace std;

int main()
{
	// 每小时的薪水
	const double PAYRATE = 12.5;

	// 5:00PM 下班
	const time24 CHECKOUT(17, 0);

	// 随机类对象模拟员工的下班是打卡情况， 参数的随机数 < 0.25 说明员工没有下班打卡
	// 这是由管理员替员工打卡
	randomNumber rnd;

	// 员工的员工号和上班时间
	string id;
	int hour, minute;

	cout << "请输入员工号： ";
	cin >> id;
	cout << endl;
	cout << "请输入员工上班的小时和分钟数： ";
	cin >> hour >> minute;
	cout << endl;

	timeCard employee(id, PAYRATE, hour, minute);

	if (rnd.frandom() > 0.25)
		employee.PunchOut(CHECKOUT);

	// 如果员工没有打卡， 管理替员工打卡
	try
	{
		employee.writeSalaryInfo();
	}
	catch (const rangeError& e)
	{
		// 输出错误信息
		cerr << e.what() << endl;

		employee.PunchOut(CHECKOUT);
		employee.writeSalaryInfo();
	}

	return 0;

}