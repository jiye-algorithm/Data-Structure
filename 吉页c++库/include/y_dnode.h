#ifndef DNODE_CLASS
#define  DNODE_CLASS

template <typename T>
class dnode
{
public:
	T nodeValue;
	dnode * prev,  *next;

	dnode() :
		prev(this), next(this)
	{}

	dnode(const T& item) : nodeValue(item)
	{
		prev = next = this;
	}
};

#endif // !DNODE_CLASS
