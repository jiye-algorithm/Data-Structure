#ifndef INFIX_SYMBOLS
#define INFIX_SYMBOLS

	// ������ķ�װ���ԣ� ����������з�װ�� �����Ӧ��ջ���������ȼ�
class expressionSymbol
{
public:
		// Ĭ�Ϲ��캯��
	expressionSymbol();

		// ��������Ĺ��캯��
	expressionSymbol(char ch);

		// �õ������
	char getOperator();

		// �Ƚ�left �������ջ���ȼ��Ƿ� >= right ���������ȼ�
		// ����ֵ�� ����true�� left.stackPrecedence >= right.inputPrecedence
	friend bool operator>= (const expressionSymbol& lhs, const expressionSymbol& rhs);

private:
		// �����
	char op;
		// �������ջ���ȼ�
	int stackPrecedence;
		// ��������������ȼ�
	int inputPrecedence;
};


//////////////////////////////////////////////////////////////////////////
/*										��ʵ��															*/	
//////////////////////////////////////////////////////////////////////////


// Ĭ�Ϲ��캯��
expressionSymbol::expressionSymbol()
{}

// ��������Ĺ��캯��
expressionSymbol::expressionSymbol(char ch)
{
	op = ch;

		// �����������ջ���������ȼ�
	switch (op)
	{
		// + �� - �� inputPrecedence and stackPrecedence ��Ϊ1
	case '+':
	case '-': 	inputPrecedence = 1;
					stackPrecedence = 1;
					break;

		// * �� / �� inputPrecedence and stackPrecedence ��Ϊ2
	case '*':
	case '/':
	case '%':	inputPrecedence = 2;
					stackPrecedence = 2;
					break;

		// ^inputPrecedence Ϊ4�� stackPrecedence Ϊ3
	case '^':    inputPrecedence = 4;
					stackPrecedence = 3;
					break;

		// ( �� inputPrecedence Ϊ5�� stackPrecedence Ϊ-1
	case '(':   inputPrecedence = 5;
				  stackPrecedence = -1;
				  break;

 		// ) �� inputPrecedence �� stackPrecedence Ϊ0
	case ')':  inputPrecedence = 0;
				 stackPrecedence = 0;
				 break;
	}
}

// �õ������
char expressionSymbol::getOperator()
{
	return op;
}

// �Ƚ�left �������ջ���ȼ��Ƿ� >= right ���������ȼ�
// ����ֵ�� ����true�� left.stackPrecedence >= right.inputPrecedence
bool operator>= (const expressionSymbol& lhs, const expressionSymbol& rhs)
{
	return lhs.stackPrecedence >= rhs.inputPrecedence;
}

#endif // !INFIX_SYMBOLS
