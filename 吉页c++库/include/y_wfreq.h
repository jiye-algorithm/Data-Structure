#ifndef WFREQ_CLASS
#define WFREQ_CLASS

#include <iostream>
#include <string>

using namespace std;

	/*
		�������ڼ�¼���ʳ��ֵĴ���,
		ӦΪ���������࣬���������������������
	*/
class wordFreq
{
public:
		// ���캯���� Ĭ���µ��ʳ�ʼ����Ϊ1
	wordFreq(const string& str) : word(str), freq(1)
	{}

		// �Ƚ���������
	friend bool operator== (const wordFreq& lhs, const wordFreq& rhs)
	{
		return lhs.word == rhs.word;
	}
		// �Ƚ���������
	friend bool operator< (const wordFreq& lhs, const wordFreq& rhs)
	{
		return lhs.word < rhs.word;
	}

		// �Ǹõ��ʵĴ������� 1
	void increase()
	{
		freq++;
	}

		// �������� ��ʽΪ�� word(freq),
	friend ostream& operator<< (const ostream& ostr, const wordFreq& rhs)
	{
		ostr << rhs.word << "(" << rhs.freq << ")";
	}

private:
		// ���ʼ�����ֵĴ���
	string word;
	int freq;
};


#endif // !WFREQ_CLASS
