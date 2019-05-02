/*
	2014��5��14�� 16:18:13
	 ��ҳ
	 ���ܣ� ���ļ� "accounts.dat" �ж�ȡ�˻���¼�� ��ʼ������˻��� Ȼ�������˻������޸ģ� ���û������˻� -1 ������� ����ʾ��ǰ�˻���Ϣ
*/

#include <iostream>
#include <fstream>

#include "../include/y_acc.h"

void outputAccounts(fstream& f);

int main()
{
		// ���ļ�
	fstream accFile;
	accFile.open("accounts.txt", ios::in | ios::out | ios::trunc );

	if (!accFile)
	{
		cerr << "file accounts.dat open fialed";
		exit(1);
	}

		// ��ʼ������˻�д���ļ�
	account acct;
	for (int i = 0; i < 5; ++i)
	{
		acct = account(i);
		accFile.write((char*)&acct, sizeof(account));
	}

		// ����ָ���˻�����
	int n;
	char type;
	double accmt;

	while (true)
	{
		cout << "Enter acct#, type(D or W), and amount: ";

		cin >> n;
		if (n == -1)		break;

		cin >> type >> accmt;
			// ���ļ����ҵ�ָ���˻���¼
		accFile.seekg(n * sizeof(account), ios::beg);
		accFile.read((char*)&acct, sizeof(account));
			// ��������
		acct.update(type, accmt);

			// �����º����Ϣд��Դ�ļ�
		accFile.seekg(-int(sizeof(account)), ios::cur);
		accFile.write((char*)&acct, sizeof(account));
	}

	cout << endl << endl << "Final state of the accounts" << endl;
	outputAccounts(accFile);

	system("pause");
}

void outputAccounts(fstream& f)
{
	account acct;
	f.seekg(0, ios::end);
	int n = f.tellg() / sizeof(account);

	f.seekg(0, ios::beg);
		// ����������ʾ
	for (int i = 0; i < n; i++)
	{
		f.read((char*)&acct, sizeof(account));
		cout << acct  << endl;
	}
}