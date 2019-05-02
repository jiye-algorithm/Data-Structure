/*
	2014��4��20�� 18:41:36
	��ҳ
	���ܣ� �˳�����ʾ�û�����������ʵ��ļ��������ļ��������������һ��ѭ������ʣ�ֱ�������ļ���������
	����Ƶ����Ϣ�洢��wordFreq�ж���ı�wf�У������seqSearch���� ����ȷ��ĳ��û���ڱ��У���Ƶ�� 1 ���뵥�ʣ� 
	���������Ѿ��ڱ��У�����seqSearch�������صĵ�������ִ�г�Ա����increase������ ������Ƶ������1�� 
	���������дʺ���list��ĳ�Ա���� sort���� ����ĸ���򵥴ʣ� ��separate = ��\n�� ��writeList�����ڵ������������ÿ���ʼ���Ƶ��
*/

#include <iostream>
#include <list>
#include <string>
#include <fstream>

#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_search.h"
#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_wfreq.h"
#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_util.h"

using namespace std;

int main()
{
		// ������ļ��ж����ĵ���
	list<wordFreq> wf;

	string filename;
	cout << "������Ҫ�򿪵��ļ�����";
	cin >> filename;

		// ���ļ�
	ifstream fin(filename.c_str());
	if (!fin)
	{
		cerr << "���ļ�wf��datʧ�ܣ�" << endl;
		exit(1);
	}

		// ���ļ��ж������ʣ� ������ÿ�����ʳ��ֵĴ���
	string word;
	list<wordFreq>::iterator iter;
	while (fin >> word)
	{
			// �����еı��в���Ԫ��
		iter = seqSearch<wordFreq>(wf.begin(), wf.end(), word);
			// ���Ԫ�ز��ٱ��У����������Ԫ��
		if (iter == wf.end())
			wf.push_back(word);
		else
			iter->increase();	// �����ڱ��У��������� 1
	}

		// �����б�����ֵ�����
	wf.sort();

		// �����Ԫ�أ� separtor = "\n"
	writeList(wf, "\n");

	system("pause");

	return 0;
}