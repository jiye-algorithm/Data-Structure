#ifndef TREE_NODE
#define TREE_NODE

template <typename T>
class tnode
{
public:
		// ����Ԫ��ֵ���������ӽڵ�
	T data;
	tnode<T> *left, *right;

		// ���캯���� ��ʼ������ֵ
	tnode(const T& d, tnode<T>* lptr = NULL, tnode<T>* rptr = NULL) :
		data(d), left(lptr), right(rptr)
	{}
};

#endif // !TREE_NODE
