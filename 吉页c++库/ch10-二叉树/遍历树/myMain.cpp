/*
	2014年5月15日 18:25:55
	吉页
	功能： 演示输的三种遍历方法
*/

#include <iostream>

#include "../../include//y_tnodel.h"
#include "../../include/y_tnode.h"

using namespace std;

int main()
{
	tnode<char> *root = buildTree(1);

	cout << "后序遍历" << endl;
	postorderOutput(root, "  ");
	cout << endl;

	cout << "中序遍历" << endl;
	inorderOutput(root, "  ");
	cout << endl;

	cout << "层次遍历" << endl;
	levelorderOutput(root, "  ");
	cout << endl << endl;

	system("pause");
}