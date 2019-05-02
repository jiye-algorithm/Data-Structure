/*
	2014��5��18�� 21:05:57
	��ҳ
	���ܣ� Դ�ļ��ĵ���ͳ�ƣ� 
	ʹ�õ����ݽṹ�� map<string, set<int> >�� kay������¼���ʣ� valueֵ��¼�˵��ʳ��ֵ������к�
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

	// �����ļ����н����� �õ�map�Ľ��ӳ��
void concordance(const string& filename);

	// ���map
	// ��ʽ �� word        ���ֵĴ���:  �к�1     �к�2     ������
	//    �磺		 a						  2 :     12			17
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
		// Ҫ��¼���ļ�����
	string filename;
	cout << "������Ҫ����¼���ļ�������"; 
	cin >> filename;
	
	concordance(filename);

	system("pause");
}



// �����ļ����н����� �õ�map�Ľ��ӳ��
void concordance(const string& filename)
{
		// ��¼���ӳ��
	map<string, set<int> >concordanceMap;

		// ���ļ�
	ifstream fin(filename);
	if (!fin)
	{
		cerr << "file " << filename << " open failed" << endl;
		exit(1);
	}

		// ���ļ��ж�ȡ���ݽ��н���
	char ch;
	int linenumber = 1;
	string identifier = "";
	bool beginIdentifier = true;
	while (fin)
	{
		fin.get(ch);	// ���ļ��ж���һ���ַ�

			// �жϴ����һ�ζ�ȡ, ���ַ�����iden
		if (isalpha(ch) && beginIdentifier == true)
		{
			beginIdentifier = false;
			identifier += ch;
		}
			// ���chΪ���ֻ���ĸ�� �ҵ�ǰ�ַ���Ϊ���ʵ�һ����ȡ�ַ�ʱ, �� �ַ����� identifier
		else if ((isalpha(ch) || isdigit(ch)) && beginIdentifier == false)
			identifier += ch;
			// ��ǰ��ȡ�ַ����ǵ����ַ�ʱ
		else
		{
				// ��ǰ�����Ѷ�ȡ���
			concordanceMap[identifier].insert( linenumber);

			if (ch == '\n')
				linenumber++;
				//���ö����ֵ�� Ϊ��һ�δ�������׼��
			identifier = "";
			beginIdentifier = true;
		}
	}

	writeConcordance(concordanceMap);
}

// ���map
// ��ʽ �� word        ���ֵĴ���:  �к�1     �к�2     ������
//    �磺		 a						  2 :     12			17
void writeConcordance(map<string, set<int> >& concordance)
{
	map < string, set<int> >::iterator iter = concordance.begin();

	while (iter != concordance.end())
	{		// ��֤ÿ������12 �ַ��� �����
		cin.setf(ios::left, ios::adjustfield);
		cout <<setw(12) <<  iter->first;
		cin.setf(ios::right, ios::adjustfield);

		cout << setw(4) <<  (iter->second).size() << ":   ";
		writeContainer((iter->second).begin(), (iter->second).end());

		++iter;
	}
}

