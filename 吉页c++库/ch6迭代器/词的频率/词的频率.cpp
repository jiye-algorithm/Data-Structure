/*
	2014年4月20日 18:41:36
	吉页
	功能： 此程序提示用户输入包含单词的文件名，打开文件，并检查错误后，用一个循环输入词，直到遇到文件结束符，
	并把频率信息存储到wordFreq中对象的表wf中，如果对seqSearch（） 调用确定某次没有在表中，则按频率 1 插入单词， 
	如果这个词已经在表中，则用seqSearch（）返回的迭代器来执行成员函数increase（）， 它将词频率增加1， 
	处理完所有词后，用list类的成员函数 sort（） 按字母排序单词， 用separate = “\n” 的writeList（）在单独的行中输出每个词及其频率
*/

#include <iostream>
#include <list>
#include <string>
#include <fstream>

#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_search.h"
#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_wfreq.h"
#include "E:\学习\数据结构\数据结构STL\吉页c++库\include/y_util.h"

using namespace std;

int main()
{
		// 保存从文件中读出的单词
	list<wordFreq> wf;

	string filename;
	cout << "请输入要打开的文件名：";
	cin >> filename;

		// 打开文件
	ifstream fin(filename.c_str());
	if (!fin)
	{
		cerr << "打开文件wf。dat失败！" << endl;
		exit(1);
	}

		// 从文件中读出单词， 并计算每个单词出现的次数
	string word;
	list<wordFreq>::iterator iter;
	while (fin >> word)
	{
			// 在已有的表中查找元素
		iter = seqSearch<wordFreq>(wf.begin(), wf.end(), word);
			// 如果元素不再表中，向表中增加元素
		if (iter == wf.end())
			wf.push_back(word);
		else
			iter->increase();	// 单词在表中，计数器加 1
	}

		// 对已有表进行字典排序
	wf.sort();

		// 输出表元素， separtor = "\n"
	writeList(wf, "\n");

	system("pause");

	return 0;
}