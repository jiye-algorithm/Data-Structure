#ifndef ACCOUNT_CLASS
#define ACCOUNT_CLASS

#include <iostream>

using namespace std;

class account
{
public :
		// ���캯������ʼ���˻���Ϣ�� Ĭ���˻��ź�����Ϊ0
	account(int n = 0, double bal = 0.0) :
		accNo(n), balance(bal)
	{}

		// �����˻������Ϣ�� 
		//	 ���� deposit(D) , withdrawal(W), 
	void update(char type, double amt)
	{
		if (toupper(type) == 'D')
			balance += amt;
		else
			balance -= amt;
	}

		// << ��������أ� ���������Ϣ
	friend ostream& operator<< (ostream& ostr, const account& acct)
	{
		ostr << acct.accNo << ": " << acct.balance;
		return ostr;
	}

private:
	int accNo;
	double balance;
};

#endif // !ACCOUNT_CLASS
