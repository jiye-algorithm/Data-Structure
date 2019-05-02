#ifndef TREE_NODE
#define TREE_NODE

template <typename T>
class tnode
{
public:
		// 数的元素值，和左右子节点
	T data;
	tnode<T> *left, *right;

		// 构造函数， 初始化各个值
	tnode(const T& d, tnode<T>* lptr = NULL, tnode<T>* rptr = NULL) :
		data(d), left(lptr), right(rptr)
	{}
};

#endif // !TREE_NODE
