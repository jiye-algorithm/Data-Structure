#ifndef WFREQ_CLASS
#define WFREQ_CLASS

#include <iostream>
#include <string>

using namespace std;

	/*
		该类用于记录单词出现的次数,
		应为是以数据类，所以利用属性优先设计类
	*/
class wordFreq
{
public:
		// 构造函数， 默认下单词初始次数为1
	wordFreq(const string& str) : word(str), freq(1)
	{}

		// 比较两个单词
	friend bool operator== (const wordFreq& lhs, const wordFreq& rhs)
	{
		return lhs.word == rhs.word;
	}
		// 比较两个单词
	friend bool operator< (const wordFreq& lhs, const wordFreq& rhs)
	{
		return lhs.word < rhs.word;
	}

		// 是该单词的次数增加 1
	void increase()
	{
		freq++;
	}

		// 输出类对象， 格式为： word(freq),
	friend ostream& operator<< (const ostream& ostr, const wordFreq& rhs)
	{
		ostr << rhs.word << "(" << rhs.freq << ")";
	}

private:
		// 单词及其出现的次数
	string word;
	int freq;
};


#endif // !WFREQ_CLASS
