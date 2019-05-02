#ifndef TIMER_CLASS
#define	TIMER_CLASS

#include <time.h>

class timer
{
public:
	// 初始化起始时间和终止时间，
	// 后置条件： 起始时间和终止时间均被置为 0：0
	timer();

	// 功能： 更新起始时间
	// 后置条件， 起始时间跟新为系统的当前时间
	void start();

	// 功能： 跟新终止时间
	// 后置条件： 终止时间被置为系统的当前时间
	void stop();

	// 功能： 得到终止时间与起始时间的时间差
	double time() const;

private:
	// 定义起始时间和终止时间
	clock_t startTime, endTime;
};

/*--------------------------------------------------------------
			timer	类的实现
----------------------------------------------------------------*/

// 初始化起始时间和终止时间，
// 后置条件： 起始时间和终止时间均被置为 0：0
timer::timer() :
startTime(0), endTime(0)
{}

// 功能： 更新起始时间
// 后置条件， 起始时间跟新为系统的当前时间
void timer::start()
{
	startTime = clock();
}

// 功能： 跟新终止时间
// 后置条件： 终止时间被置为系统的当前时间
void timer::stop()
{
	endTime = clock();
}

// 功能： 得到终止时间与起始时间的时间差
double timer::time() const
{
	return (endTime - startTime) / (double)CLOCKS_PER_SEC;
}

#endif // !TIMER_CLASS
