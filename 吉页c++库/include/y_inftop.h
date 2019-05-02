#ifdef __BORLANDC__
// suppress the warning message about comparing signed and unsigned values
#pragma warn -8012
#endif	// __BORLANDC__

#ifndef INFIX_TO_POSTFIX
#define INFIX_TO_POSTFIX

#include <iostream>
#include <string>
#include <stack>
#include <ctype.h>

#include "y_expsym.h"
#include "y_except.h"

using namespace std;

class infix2Postfix
{
public:
		// 默认构造函数
	infix2Postfix();
		
		// 构造函数， 初始化	   infix expression
	infix2Postfix(const string& infixExp);

		// 重置前缀表达式
	void setInfixExp(const string& infixExp);

		// 得到后缀表达式
	string postfix();

private:
		// 前缀和后缀表达式
	string infixExpression, postfixExpression;

		// 保存运算符的栈
	stack<expressionSymbol> operatorStack;

		// 如果运算符的栈优先级 >= 参数的输入优先级， 弹出运算符到后缀表达式中
	void outputHigherOrEqual(const expressionSymbol& op);

		// 判断是否为运算符
	bool isOperator(const char ch) const;
};


/////////////////////////////////////////////////////////////
//					 类实现
/////////////////////////////////////////////////////////////


// 如果运算符的栈优先级 >= 参数的输入优先级， 弹出运算符到后缀表达式中
void infix2Postfix::outputHigherOrEqual(const expressionSymbol& op)
{
	expressionSymbol tmpOp;

	while (!operatorStack.empty() &&
			(tmpOp = operatorStack.top()) >= op)
	{
		operatorStack.pop();
		postfixExpression += tmpOp.getOperator();
		postfixExpression += ' ';
	}
}

// 判断是否为运算符
bool infix2Postfix::isOperator(const char ch) const
{
	return ch == '+' || ch == '-' ||	ch == '*' || 
	   		  ch == '/' || ch == '%' || ch == '^';
}

// 默认构造函数
infix2Postfix::infix2Postfix()
{}

// 构造函数， 初始化	   infix expression
infix2Postfix::infix2Postfix(const string& infixExp)
{
	infixExpression = infixExp;
}

// 重置前缀表达式
void infix2Postfix::setInfixExp(const string& infixExp)
{
	infixExpression = infixExp;
}

// 得到后缀表达式
string infix2Postfix::postfix()
{	
		// 保存扫描到的元素
	char ch;
		// 判断表达式的等级，  0 <= rank <=1, 否则 throw expressionError
	int rank = 0;

	/*从头开始一次扫描前缀表达式， 转化为后缀表达式
	*/
	for (int i = 0; i < infixExpression.length(); ++i)
	{
			// 保存当前扫描的元素
		ch = infixExpression[i];

			// 如果为运算数，就将其压入后缀表达式中
		if (isdigit(ch))
		{
			postfixExpression + ch;
			postfixExpression += ' ';

			rank++;

			if (rank > 1) throw expressionError("太多操作数");
		}
			// 如果是运算符， 判断入栈或是如后缀表达式
		else if (isOperator(ch) || ch == '(')
		{
				// 如果为运算符， rank - 1;
			if (ch != '(') rank--;
				// 从栈中弹出栈优先级大于 ch 的输入优先级的运算符
			outputHigherOrEqual(ch);

			if (rank < 0) throw expressionError("太多运算符");
		}
		else if (ch == ')')
		{
			outputHigherOrEqual(ch);

			if (operatorStack.empty())
				throw expressionError("缺少（运算符");
			else
				operatorStack.pop();		// 弹出（
		}
		else (!isspace(ch))		// 如果不是空格， 表示非法输入
			throw expressionError("非法输入字符");
	}

	if (rank != 1)
		throw expressionError("操作数太少");
		// 弹出运算符栈中剩下的运算符到后缀表达式中
	else
	{
		while (!operatorStack.empty())
		{
			ch = operatorStack.top().getOperator();
			operatorStack.pop();

			// 如果栈中还有（ 运算符， 表示缺少） 运算符
			if (ch == '(')
				throw expressionError("缺少）运算符");
			else
			{
				postfixExpression += ch;
				postfixExpression += ' ';
			}
		}
	}

	return postfixExpression;
}

#endif // !INFIX_TO_POSTFIX
