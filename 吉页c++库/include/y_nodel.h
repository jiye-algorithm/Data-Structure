#ifndef NODE_FUNCTIONS
#define NODE_FUNCTIONS


#include <iostream>
#include <string>
#include "y_node.h"
#include "y_dnode.h"

using namespace std;

	// 输出单链表结点， 
template<typename T>
void writeLinkedList(node<T> *front, const string& separator = " ");

	// 输出双链表
template<typename T>
void writeDLinkedList(dnode<T> *header, const string& separator = " ");

	// 向链表中指定位置后插入元素
template<typename T>
void insert(dnode<T> *curr, const T& item);

	// 删除链表指定位置的元素
template<typename T>
void erase(dnode<T>* cur);



	/*							函数实现						*/


	// 输出单链表结点， 
template<typename T>
void writeLinkedList(node<T> *front, const string& separator)
{
	while (front != NULL )
	{
		cout << front->nodeValue << separator;
		front = front->next;
	}
}

// 输出双链表
template<typename T>
void writeDLinkedList(dnode<T> *header, const string& separator)
{
		// 记录当前结点的前后结点
	dnode<T>* nextNodes = header->next;

		//空链表
	if (nextNodes == header)
		return;

		//全部后结点
	while (nextNodes != header)
	{
		cout << nextNodes->nodeValue << separator;
		nextNodes = nextNodes->next;
	}
}

// 向链表中指定位置后插入元素
template<typename T>
void insert(dnode<T> *curr, const T& item)
{
	dnode<T>* newNode = new dnode<T>(item);

	newNode->prev = curr;
	newNode->next = curr->next;

	curr->next->prev = newNode;
	curr->next = newNode;

}

// 删除链表指定位置的元素
template<typename T>
void erase(dnode<T>* cur)
{
	cur->next->prev = cur->prev;
	cur->prev->next = cur->next;

	delete cur;
}

#endif // !NODE_FUNCTIONS
