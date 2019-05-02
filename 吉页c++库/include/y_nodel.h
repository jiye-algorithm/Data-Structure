#ifndef NODE_FUNCTIONS
#define NODE_FUNCTIONS


#include <iostream>
#include <string>
#include "y_node.h"
#include "y_dnode.h"

using namespace std;

	// ����������㣬 
template<typename T>
void writeLinkedList(node<T> *front, const string& separator = " ");

	// ���˫����
template<typename T>
void writeDLinkedList(dnode<T> *header, const string& separator = " ");

	// ��������ָ��λ�ú����Ԫ��
template<typename T>
void insert(dnode<T> *curr, const T& item);

	// ɾ������ָ��λ�õ�Ԫ��
template<typename T>
void erase(dnode<T>* cur);



	/*							����ʵ��						*/


	// ����������㣬 
template<typename T>
void writeLinkedList(node<T> *front, const string& separator)
{
	while (front != NULL )
	{
		cout << front->nodeValue << separator;
		front = front->next;
	}
}

// ���˫����
template<typename T>
void writeDLinkedList(dnode<T> *header, const string& separator)
{
		// ��¼��ǰ����ǰ����
	dnode<T>* nextNodes = header->next;

		//������
	if (nextNodes == header)
		return;

		//ȫ������
	while (nextNodes != header)
	{
		cout << nextNodes->nodeValue << separator;
		nextNodes = nextNodes->next;
	}
}

// ��������ָ��λ�ú����Ԫ��
template<typename T>
void insert(dnode<T> *curr, const T& item)
{
	dnode<T>* newNode = new dnode<T>(item);

	newNode->prev = curr;
	newNode->next = curr->next;

	curr->next->prev = newNode;
	curr->next = newNode;

}

// ɾ������ָ��λ�õ�Ԫ��
template<typename T>
void erase(dnode<T>* cur)
{
	cur->next->prev = cur->prev;
	cur->prev->next = cur->next;

	delete cur;
}

#endif // !NODE_FUNCTIONS
