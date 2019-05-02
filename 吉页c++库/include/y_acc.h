#ifndef ACCOUNT_CLASS
#define ACCOUNT_CLASS

#include <iostream>

using namespace std;

class account
{
public :
		// 构造函数，初始化账户信息， 默认账户号和余额均为0
	account(int n = 0, double bal = 0.0) :
		accNo(n), balance(bal)
	{}

		// 更新账户余额信息， 
		//	 类型 deposit(D) , withdrawal(W), 
	void update(char type, double amt)
	{
		if (toupper(type) == 'D')
			balance += amt;
		else
			balance -= amt;
	}

		// << 运算符重载， 方便输出信息
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
