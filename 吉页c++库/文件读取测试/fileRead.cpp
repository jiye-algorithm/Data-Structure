/*
	2014年7月7日 19:34:55
	吉页
	功能：
		测试当文件不存在创建一个新的文件， 然后读入一些内容
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

int main()
{
	ifstream fin;
	string filename = "红楼.txt";
	fin.open(filename.c_str(), ios::in | ios::app);
	assert(fin);

	string message;
	
	getline(fin, message);

	fin.close();
	return 0;
}