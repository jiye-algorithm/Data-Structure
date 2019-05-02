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
		// Ĭ�Ϲ��캯��
	infix2Postfix();
		
		// ���캯���� ��ʼ��	   infix expression
	infix2Postfix(const string& infixExp);

		// ����ǰ׺���ʽ
	void setInfixExp(const string& infixExp);

		// �õ���׺���ʽ
	string postfix();

private:
		// ǰ׺�ͺ�׺���ʽ
	string infixExpression, postfixExpression;

		// �����������ջ
	stack<expressionSymbol> operatorStack;

		// ����������ջ���ȼ� >= �������������ȼ��� �������������׺���ʽ��
	void outputHigherOrEqual(const expressionSymbol& op);

		// �ж��Ƿ�Ϊ�����
	bool isOperator(const char ch) const;
};


/////////////////////////////////////////////////////////////
//					 ��ʵ��
/////////////////////////////////////////////////////////////


// ����������ջ���ȼ� >= �������������ȼ��� �������������׺���ʽ��
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

// �ж��Ƿ�Ϊ�����
bool infix2Postfix::isOperator(const char ch) const
{
	return ch == '+' || ch == '-' ||	ch == '*' || 
	   		  ch == '/' || ch == '%' || ch == '^';
}

// Ĭ�Ϲ��캯��
infix2Postfix::infix2Postfix()
{}

// ���캯���� ��ʼ��	   infix expression
infix2Postfix::infix2Postfix(const string& infixExp)
{
	infixExpression = infixExp;
}

// ����ǰ׺���ʽ
void infix2Postfix::setInfixExp(const string& infixExp)
{
	infixExpression = infixExp;
}

// �õ���׺���ʽ
string infix2Postfix::postfix()
{	
		// ����ɨ�赽��Ԫ��
	char ch;
		// �жϱ��ʽ�ĵȼ���  0 <= rank <=1, ���� throw expressionError
	int rank = 0;

	/*��ͷ��ʼһ��ɨ��ǰ׺���ʽ�� ת��Ϊ��׺���ʽ
	*/
	for (int i = 0; i < infixExpression.length(); ++i)
	{
			// ���浱ǰɨ���Ԫ��
		ch = infixExpression[i];

			// ���Ϊ���������ͽ���ѹ���׺���ʽ��
		if (isdigit(ch))
		{
			postfixExpression + ch;
			postfixExpression += ' ';

			rank++;

			if (rank > 1) throw expressionError("̫�������");
		}
			// ������������ �ж���ջ�������׺���ʽ
		else if (isOperator(ch) || ch == '(')
		{
				// ���Ϊ������� rank - 1;
			if (ch != '(') rank--;
				// ��ջ�е���ջ���ȼ����� ch ���������ȼ��������
			outputHigherOrEqual(ch);

			if (rank < 0) throw expressionError("̫�������");
		}
		else if (ch == ')')
		{
			outputHigherOrEqual(ch);

			if (operatorStack.empty())
				throw expressionError("ȱ�٣������");
			else
				operatorStack.pop();		// ������
		}
		else (!isspace(ch))		// ������ǿո� ��ʾ�Ƿ�����
			throw expressionError("�Ƿ������ַ�");
	}

	if (rank != 1)
		throw expressionError("������̫��");
		// ���������ջ��ʣ�µ����������׺���ʽ��
	else
	{
		while (!operatorStack.empty())
		{
			ch = operatorStack.top().getOperator();
			operatorStack.pop();

			// ���ջ�л��У� ������� ��ʾȱ�٣� �����
			if (ch == '(')
				throw expressionError("ȱ�٣������");
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
