/*
	2014年5月18日 21:05:57
	吉页
	功能： 源文件的单词统计， 
	使用的数据结构： map<string, set<int> >， kay用来记录单词， value值记录了单词出现的所有行号
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <cstdlib>
#include <ctype.h>

using namespace std;

	// 参数文件进行解析， 得到map的结果映射
void concordance(const string& filename);

	// 输出map
	// 格式 ： word        出现的次数:  行号1     行号2     。。。
	//    如：		 a						  2 :     12			17
void writeConcordance(map<string, set<int> >& concordance);

template <typename Iterator>
void writeContainer(Iterator first, Iterator last, const string& seperator = "  ")
{
	while (first != last)
	{
		cout << *first << seperator;
		first++;
	}
	cout << endl;
}

int main()
{
		// 要记录的文件名字
	string filename;
	cout << "请输入要做记录的文件的名字"; 
	cin >> filename;
	
	concordance(filename);

	system("pause");
}



// 参数文件进行解析， 得到map的结果映射
void concordance(const string& filename)
{
		// 记录结果映射
	map<string, set<int> >concordanceMap;

		// 打开文件
	ifstream fin(filename);
	if (!fin)
	{
		cerr << "file " << filename << " open failed" << endl;
		exit(1);
	}

		// 从文件中读取数据进行解析
	char ch;
	int linenumber = 1;
	string identifier = "";
	bool beginIdentifier = true;
	while (fin)
	{
		fin.get(ch);	// 从文件中读入一个字符

			// 判断处理第一次读取, 将字符加入iden
		if (isalpha(ch) && beginIdentifier == true)
		{
			beginIdentifier = false;
			identifier += ch;
		}
			// 如果ch为数字或字母， 且当前字符不为单词第一个读取字符时, 将 字符加入 identifier
		else if ((isalpha(ch) || isdigit(ch)) && beginIdentifier == false)
			identifier += ch;
			// 当前读取字符不是单词字符时
		else
		{
				// 当前单词已读取完成
			concordanceMap[identifier].insert( linenumber);

			if (ch == '\n')
				linenumber++;
				//重置对象的值， 为下一次处理单词做准备
			identifier = "";
			beginIdentifier = true;
		}
	}

	writeConcordance(concordanceMap);
}

// 输出map
// 格式 ： word        出现的次数:  行号1     行号2     。。。
//    如：		 a						  2 :     12			17
void writeConcordance(map<string, set<int> >& concordance)
{
	map < string, set<int> >::iterator iter = concordance.begin();

	while (iter != concordance.end())
	{		// 保证每个单词12 字符， 左对齐
		cin.setf(ios::left, ios::adjustfield);
		cout <<setw(12) <<  iter->first;
		cin.setf(ios::right, ios::adjustfield);

		cout << setw(4) <<  (iter->second).size() << ":   ";
		writeContainer((iter->second).begin(), (iter->second).end());

		++iter;
	}
}

