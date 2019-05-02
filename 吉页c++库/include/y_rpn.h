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
		// Ĭ�Ϲ��캯��
	postfixEval();
		
		// ���캯���� ���� m_postfix = postfix
	postfixEval(const string& postfix);

		// ����m_postfix 
	void setPostfix(const string& postfix);

		// �õ���׺���ʽ
	string getPostfix() const;

		// �����׺���ʽ��ֵ
	int evaluate();

private:
		// ��׺���ʽ
	string m_postfix;

		// �洢��������ջ
	stack<int> intStack;

		// �ж��ַ��Ƿ�Ϊ�����
	bool isOperator(char ch) const;

		// ������ʽ
	int compute(int left, int right, char op);

		// �õ�����������Ҳ�����
	bool getOperands(int& left, int& right);
};


///////////////////////////////////////////////////////////////////////////////
//											��ʵ��
///////////////////////////////////////////////////////////////////////////////


// �ж��ַ��Ƿ�Ϊ�����
bool postfixEval::isOperator(char ch) const
{
	return ch == '+' || ch == '-' || ch == '*' ||
		ch == '/' || ch == '%' || ch == '^';
}


// ������ʽ
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
							expressionError("/�в�����0����");
					result = left / right;
					break;	

	case '%':	if (right == 0 )
						throw
							expressionError("%�в�����0����");
					result = left % right;
					break;

	case '^':  	if (right == 0 && left == 0)
						throw
							expressionError("^���Ҳ�����Ϊ0");

					result = left;

						// �� right Ϊ�������� left �Գ� right ��
					while (right-- != 1)
					{
						result *= left;
					}
					break;
	}

	return result;
}

// �õ�����������Ҳ�����
bool postfixEval::getOperands(int& left, int& right)
{
	bool success = true;

		// �õ��������
	if (!intStack.empty())
	{
		left = intStack.top();
		intStack.pop();
	}
	else
		throw expressionError("��̫��������");
		
		// �õ��Ҳ�����
	if (!intStack.empty())
	{
		right = intStack.top();
		intStack.pop();
	}
	else
		throw expressionError("��̫��������");

	return success;
}

// Ĭ�Ϲ��캯��
postfixEval::postfixEval()
{
	m_postfix = "";
}

// ���캯���� ���� m_postfix = postfix
postfixEval::postfixEval(const string& postfix)
{
	m_postfix = postfix;
}

// ����m_postfix 
void postfixEval::setPostfix(const string& postfix)
{
	m_postfix = postfix;
}

// �����׺���ʽ��ֵ
int postfixEval::evaluate()
{
	char ch;
	int left, right, result, value;

	for (int i = 0; i < m_postfix.length(); ++i)
	{
		ch = m_postfix[i];

		if (isdigit(ch))
			intStack.push(ch - '0');

			// �ж��Ƿ�Ϊ�����
		else if (isOperator(ch))
		{
			// �õ����Ҳ�����
			getOperands(left, right);
			// ���㲢�����ѹջ
			value = compute(left, right, ch);
			intStack.push(value);
		}
			// ���ʽ��ֻ�ܰ������֣� ������Ϳո�
		else if (!isspace(ch))
			throw expressionError("�Ƿ��ĺ�׺���ʽ");
	}

		// �õ���׺���ʽ�ļ�����
	result = intStack.top();
	intStack.pop();

		// ���������ջӦ��Ϊ��
	if (!intStack.empty())
		throw expressionError("��̫��Ĳ�����");

	return  result;
}


#endif // !POSTFIX_EVALUATION
