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

		// 记录叶结点的数目
	int leafCount = 0;
	countLeaf(root, leafCount);

		// 记录树的深度
	int d = depth(root);

	cout << "叶结点数目： " << leafCount << " —————— 深度 : " << d << endl << endl;

	system("pause");
}