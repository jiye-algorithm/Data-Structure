/*
	2014年4月5日 16:44:03
	吉页
	功能： 改程序使用time24对象计算在公共车库停车的费用，
	假定费用是每小时6美元，程序提示用户输入两个时间，分别作为
	对应的进入和离开车库的时间，输出是一张收据
	期中包含到达时间。离开时间、汽车停放时间以及总费用
*/

#include <iostream>
#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_time24.h"

int main()
{
	// 每小时的停车费用
	const double PERHOUR_PARKING = 6.00;

	// 对象指出汽车何时进入车库，何时离开车库，以及停靠的总时间
	time24 enterGarage, exitGarage, parkingTime;

	cout << "汽车进入停车场的时间 ";
	cin >> enterGarage;
	cout << endl << "汽车离开停车场的时间 ";
	cin >> exitGarage;
	cout << endl;

	// 停的总时间
	parkingTime = exitGarage - enterGarage;

	// 总的费用
	double billingHours = parkingTime.getHour() + parkingTime.getMinute() * 60;

	// 输出停车的收据，包括到达时间，离开时间，总停车时间，总的费用
	cout << "汽车到达 " << enterGarage << endl
		<< "汽车离开 " << exitGarage << endl
		<< "共停了 " << parkingTime << endl
		<< "总费用 " << billingHours * PERHOUR_PARKING << endl;

	system("pause");

	return 0;
}