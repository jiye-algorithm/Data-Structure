#ifndef TREE_FUNCTIONS
#define TREE_FUNCTIONS


#include <iostream>
#include <string>
#include <queue>

#include "y_tnode.h"

#ifndef NULL
#include <cstddef>
#endif

using namespace std;

// create one of three binary trees with character data.
// the argument n selects from tree 0 - tree 2
tnode<char> *buildTree(int n)
{
	// 9 tnode pointers; points to the 9 items in the tree
	tnode<char> *root = NULL, *b, *c, *d, *e, *f, *g, *h, *i;

	// parameter n specifies a tree in the range 0 - 2
	switch (n)
	{
		// nodes d and e are leaf nodes
	case 0:
		d = new tnode<char>('D');
		e = new tnode<char>('E');
		b = new tnode<char>('B', (tnode<char> *)NULL, d);
		c = new tnode<char>('C', e, (tnode<char> *)NULL);
		root = new tnode<char>('A', b, c);
		break;

		// nodes g, h, i, and d are leaf nodes
	case 1:
		g = new tnode<char>('G');
		h = new tnode<char>('H');
		i = new tnode<char>('I');
		d = new tnode<char>('D');
		e = new tnode<char>('E', g, (tnode<char> *)NULL);
		f = new tnode<char>('F', h, i);
		b = new tnode<char>('B', d, e);
		c = new tnode<char>('C', (tnode<char> *)NULL, f);
		root = new tnode<char>('A', b, c);
		break;

		// nodes g, h, i and f are leaf nodes
	case 2:
		g = new tnode<char>('G');
		h = new tnode<char>('H');
		i = new tnode<char>('I');
		d = new tnode<char>('D', (tnode<char> *)NULL, g);
		e = new tnode<char>('E', h, i);
		f = new tnode<char>('F');
		b = new tnode<char>('B', d, (tnode<char> *)NULL);
		c = new tnode<char>('C', e, f);
		root = new tnode<char>('A', b, c);
		break;
	}

	return root;
}

	// 中序遍历
// of separator is "  "
template <typename T>
void inorderOutput(tnode<T> *t, const string& separator)
{
	if (t != NULL)
	{
			// 遍历子节点
		inorderOutput(t->left, separator);
			// 输出当前结点
		cout << t->data << separator;
			// 遍历右结点
		inorderOutput(t->right, separator);
	}
}

// postorder recursive output of the nodes in a binary tree.
// output separator after each node value. default value
// of separator is "  "
template <typename T>
void postorderOutput(tnode<T> *t, const string& separator)
{
	if (t != NULL)
	{
			// 遍历左结点
		postorderOutput(t->left, separator);
			// 遍历右结点
		postorderOutput(t->right, separator);
			// 显示当前结点
		cout << t->data << separator;
	}
}

// traverse the tree level by level and output each node in a
// binary tree. output separator after each node value. default value
// of separator is "  "
template <typename T>
void levelorderOutput(tnode<T> *t, const string& separator)
{
	queue<tnode<T> *> q;
	tnode<T>* p;

	q.push(t);

	while (!q.empty())
	{
			// 取出队列的头结点， 访问
		p = q.front();
		q.pop();

			// 将当访问结点的左右子点， 压入队列中
		if (p->left != NULL)  q.push(p->left);
		if (p->right != NULL) q.push(p->right);

		cout << p->data << separator;

	}
}

// accumulate the number of leaf nodes in count
template <typename T>
void countLeaf(tnode<T> *t, int& count)
{
	if (t != NULL)
	{
		if (t->left == NULL && t->right == NULL)
			count++;
		countLeaf(t->left, count);
		countLeaf(t->right, count);
	}

}

// return the depth of the binary tree
template <typename T>
int depth(tnode<T> *t)
{
	if (t == NULL) return -1;

	int leftCount = depth(t->left);
	int rightCount = depth(t->right);

	return leftCount > rightCount ? (leftCount + 1)
		: (rightCount + 1);
}

// create copy of tree t and return a pointer to the new root
template <typename T>
tnode<T> *copyTree(tnode<T> *t)
{
	
		// 复制空树
	if (t == NULL) return  NULL;
		// 确定当前结点
	tnode rootPtr = new tnode<T>(t->data);
		// 确定当前结点的左右子节点
	rootPtr->left = copyTree(t->left);
	rootPtr->right = copyTree(t->right);

	return rootPtr;
}

// traverse the nodes in the binary tree and delete each node
template <typename T>
void deleteTree(tnode<T> *t)
{
		// 空树直接返回
	if (t != NULL)
	{
			// 删除当前结点右子树
		deleteTree(t->right);
		// 删除当前结点的左子树
		deleteTree(t->left);
			// 释放当前结点
		delete(t);
		t = NULL;
	}
}

// delete all tree nodes using deleteTree() and then assign
// t to be NULL
template <typename T>
void clearTree(tnode<T> * & t)
{
	deleteTree(t);
}

#endif // !TREE_FUNCTIONS
