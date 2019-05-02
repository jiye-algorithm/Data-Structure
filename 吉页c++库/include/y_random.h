#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

#include <time.h>

using namespace std;

// 产生随机数
class randomNumber
{
public:
	// 用 s 作为随机数的种子
	randomNumber(long s = 0);

	// 产生 0-1 之间的实数
	double frandom();

	// 默认产生0到2^31 - 2之间的数
	long random();

	// 产生 0 到 n 之间的随机数
	long random(int n);
	
	// 产生low， high之间的随机数
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

// 用 s 作为随机数的种子
randomNumber::randomNumber(long s)
{
	if (s < 0) s = 0;

	if (s == 0)
	{
		// 产生一个 从 1970年1月1日到当前时间秒数
		long tTime = time(NULL);

		//加大时间，使得随机性更高
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

// 产生 0-1 之间的实数
double randomNumber::frandom()
{
	return double(random()) / double(M);


}

// 默认产生0到2^31 - 2之间的数
long randomNumber::random()
{
	long tmpSeed = A * (seed % Q) - R * (seed / Q);

	if (tmpSeed >= 0)
		seed = tmpSeed;
	else
		seed = tmpSeed + M;

	return seed;
}

// 产生 0 到 n 之间的随机数
long randomNumber::random(int n)
{
	return n * frandom();
}

	// 产生low， high之间的随机数
long randomNumber::random(int low, int high)
{
	long temp = high * frandom();
	return temp > low ? temp : (temp + low);
}

#endif	// RANDOMNUMBER_H