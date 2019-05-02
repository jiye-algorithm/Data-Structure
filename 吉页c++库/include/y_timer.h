#ifndef TIMER_CLASS
#define	TIMER_CLASS

#include <time.h>

class timer
{
public:
	// ��ʼ����ʼʱ�����ֹʱ�䣬
	// ���������� ��ʼʱ�����ֹʱ�������Ϊ 0��0
	timer();

	// ���ܣ� ������ʼʱ��
	// ���������� ��ʼʱ�����Ϊϵͳ�ĵ�ǰʱ��
	void start();

	// ���ܣ� ������ֹʱ��
	// ���������� ��ֹʱ�䱻��Ϊϵͳ�ĵ�ǰʱ��
	void stop();

	// ���ܣ� �õ���ֹʱ������ʼʱ���ʱ���
	double time() const;

private:
	// ������ʼʱ�����ֹʱ��
	clock_t startTime, endTime;
};

/*--------------------------------------------------------------
			timer	���ʵ��
----------------------------------------------------------------*/

// ��ʼ����ʼʱ�����ֹʱ�䣬
// ���������� ��ʼʱ�����ֹʱ�������Ϊ 0��0
timer::timer() :
startTime(0), endTime(0)
{}

// ���ܣ� ������ʼʱ��
// ���������� ��ʼʱ�����Ϊϵͳ�ĵ�ǰʱ��
void timer::start()
{
	startTime = clock();
}

// ���ܣ� ������ֹʱ��
// ���������� ��ֹʱ�䱻��Ϊϵͳ�ĵ�ǰʱ��
void timer::stop()
{
	endTime = clock();
}

// ���ܣ� �õ���ֹʱ������ʼʱ���ʱ���
double timer::time() const
{
	return (endTime - startTime) / (double)CLOCKS_PER_SEC;
}

#endif // !TIMER_CLASS
