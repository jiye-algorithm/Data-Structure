#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

#include <time.h>

using namespace std;

// ���������
class randomNumber
{
public:
	// �� s ��Ϊ�����������
	randomNumber(long s = 0);

	// ���� 0-1 ֮���ʵ��
	double frandom();

	// Ĭ�ϲ���0��2^31 - 2֮�����
	long random();

	// ���� 0 �� n ֮��������
	long random(int n);
	
	// ����low�� high֮��������
	long random(int low, int high);

private:
	static const long A;
	static const long M;
	static const long Q;
	static const long R;

	long seed;
};

const long randomNumber::A = 48271;
const long randomNumber::M = 2147483647;
const long randomNumber::Q = M / A;
const long randomNumber::R = M % A;

// �� s ��Ϊ�����������
randomNumber::randomNumber(long s)
{
	if (s < 0) s = 0;

	if (s == 0)
	{
		// ����һ�� �� 1970��1��1�յ���ǰʱ������
		long tTime = time(NULL);

		//�Ӵ�ʱ�䣬ʹ������Ը���
		tTime *= tTime;

		if (tTime > 0)
			s = tTime ^ 0x5EECE66DL;

		else if (tTime < 0)
			s = (tTime & 0x7fffffff) ^ 0x5EECE66DL;

		else
			s = 0x5EECE66DL;
	}
	
	seed = s;
}

// ���� 0-1 ֮���ʵ��
double randomNumber::frandom()
{
	return double(random()) / double(M);


}

// Ĭ�ϲ���0��2^31 - 2֮�����
long randomNumber::random()
{
	long tmpSeed = A * (seed % Q) - R * (seed / Q);

	if (tmpSeed >= 0)
		seed = tmpSeed;
	else
		seed = tmpSeed + M;

	return seed;
}

// ���� 0 �� n ֮��������
long randomNumber::random(int n)
{
	return n * frandom();
}

	// ����low�� high֮��������
long randomNumber::random(int low, int high)
{
	long temp = high * frandom();
	return temp > low ? temp : (temp + low);
}

#endif	// RANDOMNUMBER_H