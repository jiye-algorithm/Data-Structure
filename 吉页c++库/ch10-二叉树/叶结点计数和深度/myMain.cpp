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

		// ��¼Ҷ������Ŀ
	int leafCount = 0;
	countLeaf(root, leafCount);

		// ��¼�������
	int d = depth(root);

	cout << "Ҷ�����Ŀ�� " << leafCount << " ������������ ��� : " << d << endl << endl;

	system("pause");
}