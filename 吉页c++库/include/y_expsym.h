#ifndef INFIX_SYMBOLS
#define INFIX_SYMBOLS

	// 利用类的封装特性， 将运算符进行封装， 添加相应的栈和输入优先级
class expressionSymbol
{
public:
		// 默认构造函数
	expressionSymbol();

		// 带运算符的构造函数
	expressionSymbol(char ch);

		// 得到运算符
	char getOperator();

		// 比较left 运算符的栈优先级是否 >= right 的输入优先级
		// 返回值： 返回true， left.stackPrecedence >= right.inputPrecedence
	friend bool operator>= (const expressionSymbol& lhs, const expressionSymbol& rhs);

private:
		// 运算符
	char op;
		// 运算符的栈优先级
	int stackPrecedence;
		// 运算符的输入优先级
	int inputPrecedence;
};


//////////////////////////////////////////////////////////////////////////
/*										类实现															*/	
//////////////////////////////////////////////////////////////////////////


// 默认构造函数
expressionSymbol::expressionSymbol()
{}

// 带运算符的构造函数
expressionSymbol::expressionSymbol(char ch)
{
	op = ch;

		// 设置运算符的栈和输入优先级
	switch (op)
	{
		// + 和 - 的 inputPrecedence and stackPrecedence 都为1
	case '+':
	case '-': 	inputPrecedence = 1;
					stackPrecedence = 1;
					break;

		// * 和 / 的 inputPrecedence and stackPrecedence 都为2
	case '*':
	case '/':
	case '%':	inputPrecedence = 2;
					stackPrecedence = 2;
					break;

		// ^inputPrecedence 为4， stackPrecedence 为3
	case '^':    inputPrecedence = 4;
					stackPrecedence = 3;
					break;

		// ( 的 inputPrecedence 为5， stackPrecedence 为-1
	case '(':   inputPrecedence = 5;
				  stackPrecedence = -1;
				  break;

 		// ) 的 inputPrecedence ， stackPrecedence 为0
	case ')':  inputPrecedence = 0;
				 stackPrecedence = 0;
				 break;
	}
}

// 得到运算符
char expressionSymbol::getOperator()
{
	return op;
}

// 比较left 运算符的栈优先级是否 >= right 的输入优先级
// 返回值： 返回true， left.stackPrecedence >= right.inputPrecedence
bool operator>= (const expressionSymbol& lhs, const expressionSymbol& rhs)
{
	return lhs.stackPrecedence >= rhs.inputPrecedence;
}

#endif // !INFIX_SYMBOLS
