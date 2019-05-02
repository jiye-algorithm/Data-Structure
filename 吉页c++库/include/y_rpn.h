#ifdef __BORLANDC__
// turn off Borland warning message about comparison of signed and
// unsigned values
#pragma warn -8012
#endif	// __BORLANDC__

#ifndef POSTFIX_EVALUATION
#define POSTFIX_EVALUATION

#include <iostream>
#include <stack>

#include "y_except.h"

using namespace std;

class postfixEval
{
public:
		// 默认构造函数
	postfixEval();
		
		// 构造函数， 设置 m_postfix = postfix
	postfixEval(const string& postfix);

		// 重置m_postfix 
	void setPostfix(const string& postfix);

		// 得到后缀表达式
	string getPostfix() const;

		// 计算后缀表达式的值
	int evaluate();

private:
		// 后缀表达式
	string m_postfix;

		// 存储操作数的栈
	stack<int> intStack;

		// 判断字符是否为运算符
	bool isOperator(char ch) const;

		// 计算表达式
	int compute(int left, int right, char op);

		// 得到运算符的左右操作数
	bool getOperands(int& left, int& right);
};


///////////////////////////////////////////////////////////////////////////////
//											类实现
///////////////////////////////////////////////////////////////////////////////


// 判断字符是否为运算符
bool postfixEval::isOperator(char ch) const
{
	return ch == '+' || ch == '-' || ch == '*' ||
		ch == '/' || ch == '%' || ch == '^';
}


// 计算表达式
int postfixEval::compute(int left, int right, char op)
{
	int result;

	switch (op)
	{
	case '+':	result = left + right;
				    break;

	case '-':		result = left - right;
					break;

	case '*':		result = left * right;
			    	break;

	case '/':		if (right == 0)
						throw
							expressionError("/有参数有0出现");
					result = left / right;
					break;	

	case '%':	if (right == 0 )
						throw
							expressionError("%有参数有0出现");
					result = left % right;
					break;

	case '^':  	if (right == 0 && left == 0)
						throw
							expressionError("^左右参数均为0");

					result = left;

						// 以 right 为计数机， left 自乘 right 次
					while (right-- != 1)
					{
						result *= left;
					}
					break;
	}

	return result;
}

// 得到运算符的左右操作数
bool postfixEval::getOperands(int& left, int& right)
{
	bool success = true;

		// 得到左操作数
	if (!intStack.empty())
	{
		left = intStack.top();
		intStack.pop();
	}
	else
		throw expressionError("有太多的运算符");
		
		// 得到右操作数
	if (!intStack.empty())
	{
		right = intStack.top();
		intStack.pop();
	}
	else
		throw expressionError("有太多的运算符");

	return success;
}

// 默认构造函数
postfixEval::postfixEval()
{
	m_postfix = "";
}

// 构造函数， 设置 m_postfix = postfix
postfixEval::postfixEval(const string& postfix)
{
	m_postfix = postfix;
}

// 重置m_postfix 
void postfixEval::setPostfix(const string& postfix)
{
	m_postfix = postfix;
}

// 计算后缀表达式的值
int postfixEval::evaluate()
{
	char ch;
	int left, right, result, value;

	for (int i = 0; i < m_postfix.length(); ++i)
	{
		ch = m_postfix[i];

		if (isdigit(ch))
			intStack.push(ch - '0');

			// 判断是否为运算符
		else if (isOperator(ch))
		{
			// 得到左右操作数
			getOperands(left, right);
			// 计算并将结果压栈
			value = compute(left, right, ch);
			intStack.push(value);
		}
			// 表达式中只能包含数字， 运算符和空格
		else if (!isspace(ch))
			throw expressionError("非法的后缀表达式");
	}

		// 得到后缀表达式的计算结果
	result = intStack.top();
	intStack.pop();

		// 弹出结果后栈应该为空
	if (!intStack.empty())
		throw expressionError("有太多的操作数");

	return  result;
}


#endif // !POSTFIX_EVALUATION
