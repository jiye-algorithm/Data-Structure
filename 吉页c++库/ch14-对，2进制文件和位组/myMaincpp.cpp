/*
	2014年5月14日 16:18:13
	 吉页
	 功能： 从文件 "accounts.dat" 中读取账户记录， 初始化五个账户， 然后对五个账户进行修改， 当用户输入账户 -1 后结束， 并显示当前账户信息
*/

#include <iostream>
#include <fstream>

#include "../include/y_acc.h"

void outputAccounts(fstream& f);

int main()
{
		// 打开文件
	fstream accFile;
	accFile.open("accounts.txt", ios::in | ios::out | ios::trunc );

	if (!accFile)
	{
		cerr << "file accounts.dat open fialed";
		exit(1);
	}

		// 初始化五个账户写入文件
	account acct;
	for (int i = 0; i < 5; ++i)
	{
		acct = account(i);
		accFile.write((char*)&acct, sizeof(account));
	}

		// 更新指定账户数据
	int n;
	char type;
	double accmt;

	while (true)
	{
		cout << "Enter acct#, type(D or W), and amount: ";

		cin >> n;
		if (n == -1)		break;

		cin >> type >> accmt;
			// 在文件中找到指定账户记录
		accFile.seekg(n * sizeof(account), ios::beg);
		accFile.read((char*)&acct, sizeof(account));
			// 更新数据
		acct.update(type, accmt);

			// 将更新后的信息写入源文件
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
		// 读出数据显示
	for (int i = 0; i < n; i++)
	{
		f.read((char*)&acct, sizeof(account));
		cout << acct  << endl;
	}
}