/*
	2014��5��15�� 18:25:55
	��ҳ
	���ܣ� ��ʾ������ֱ�������
*/

#include <iostream>

#include "../../include//y_tnodel.h"
#include "../../include/y_tnode.h"

using namespace std;

int main()
{
	tnode<char> *root = buildTree(1);

	cout << "�������" << endl;
	postorderOutput(root, "  ");
	cout << endl;

	cout << "�������" << endl;
	inorderOutput(root, "  ");
	cout << endl;

	cout << "��α���" << endl;
	levelorderOutput(root, "  ");
	cout << endl << endl;

	system("pause");
}