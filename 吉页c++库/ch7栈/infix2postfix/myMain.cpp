/*
	2014��4��26�� 09:24:56
	��ҳ
	���ܣ� ����׺���ʽת��Ϊ��׺���ʽ��
	������ʾ�û�����һ����׺���ʽ�� ת��Ϊ��׺���ʽ������ֵ�� 
	���й����κεط��������׳�expreError �� ����������expressError������
*/
#include <iostream>
#include <string>

// if Microsoft VC++, compensate for a getline() bug in <string>
#ifdef _MSC_VER
#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_util.h"
#endif _MSC_VER

#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_inftop.h"		// infix2Postfix class
#include "E:\ѧϰ\���ݽṹ\���ݽṹSTL\��ҳc++��\include/y_rpn.h"			// postfixEval class

using namespace std;

int main()
{
	// use iexp for infix to postfix conversion
	infix2Postfix iexp;
	// infix expression input and postfix expression output
	string infixExp, postfixExp;
	// use pexp to evaluate postfix expressions
	postfixEval pexp;

	// input and evaluate infix expressions until the
	// user enters an empty string

	// get the first expression
	cout << "Enter an infix expression: ";
	getline(cin, infixExp);

	while (infixExp != "")
	{
		// an exception may occur. enclose the conversion
		// to postfix and the output of the expression
		// value in a try block
		try
		{
			// convert to postfix
			iexp.setInfixExp(infixExp);
			postfixExp = iexp.postfix();

			// output the postfix expression
			cout << "The postfix form is " << postfixExp
				<< endl;

			// use pexp to evaluate the postfix expression
			pexp.setPostfix(postfixExp);

			cout << "Value of the expression = "
				<< pexp.evaluate() << endl << endl;
		}

		// catch an exception and output the error
		catch (const expressionError& ee)
		{
			cout << ee.what() << endl << endl;
		}
		// input another expression
		cout << "Enter an infix expression: ";
		getline(cin, infixExp);
	}

	return 0;
}


