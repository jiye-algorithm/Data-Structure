/*
	2014��7��7�� 19:34:55
	��ҳ
	���ܣ�
		���Ե��ļ������ڴ���һ���µ��ļ��� Ȼ�����һЩ����
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

int main()
{
	ifstream fin;
	string filename = "��¥.txt";
	fin.open(filename.c_str(), ios::in | ios::app);
	assert(fin);

	string message;
	
	getline(fin, message);

	fin.close();
	return 0;
}