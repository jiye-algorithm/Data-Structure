#ifndef NODE_CLASS
#define NODE_CLASS


template <typename T>
class node
{
public:
	T nodeValue;
	node* next;

	node() : next(NULL)
	{}

	node(const T& item, node* nextNode) :
		nodeValue(item), next(nextNode)
	{}
};


#endif // !NODE_CLASS
