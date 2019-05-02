#ifndef GRAPH_CLASS
#define GRAPH_CLASS

#include<iostream>
#include <fstream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <functional>	// for less<T>

#include "y_except.h"
#include "y_pqueue.h"


using namespace std;

//const  int INFINITY = (int)((unsigned int)~0 >> 1);

/* ÿ������ڱ���
**	��һ��Ŀ���ڵ������е�Ŀ���±�
*/
class neighbor
{
public:
	// Ŀ����ڵ������е��±�
	int dest;
	//�ñߵ�Ȩֵ
	int weight;

	neighbor(int d = 0, int c = 0) : dest(d), weight(c)
	{}

	// �Ƚ��ڱߵ��ڵ������е��±�
	friend bool operator< (const neighbor& lhs, const neighbor& rhs)
	{
		return lhs.dest < rhs.dest;
	}

	// ���ڱߵ��±���Ϊ��׼�Ƚ������ڱ��Ƿ����
	friend bool operator== (const neighbor& lhs, const neighbor& rhs)
	{
		return lhs.dest == rhs.dest;
	}
};

/*	����
	����ÿ����Ļ�����Ϣ�� ������ɫ���ڱ߼���Ԫ�ء���ȵ���Ϣ
	*/
template <typename T>
class vertexInfo
{
public:
	// �����ɫ�� �ڱ���ͼ���㷨��ʹ��
	enum vertexColor{ WHITE, GRAY, BLACK };

	// ָ�����ʵ��ӳ��ĵ�����
	typename map<T, int>::iterator vtxMapLoc;

	// ����ڱ߼�
	set<neighbor> edges;
	// ������
	int inDegree;
	// ��ʶ�н������еĵ�ǰλ���Ƿ������Ч����
	bool occupied;
	// ��ǰ�����ɫ
	vertexColor color;


	int dataValue;

	// �õ�ĸ��ڵ㣬 ��ʶ��ʾĳ�ڵ���һ���ڱ�Ϊ�õ�
	int parent;

	// ���캯��
	vertexInfo() : inDegree(0), occupied(true)
	{}

	// constructor with iterator pointing to the vertex in the map
	vertexInfo(typename map<T, int>::iterator iter) :
		vtxMapLoc(iter), inDegree(0), occupied(true)
	{}
};

// ���һ�����޶�����ʹ�õĽ��
class miniInfo
{
	int endV;	// �յ�
	int pathWeight;		// �����㵽��ǰλ�õ�Ȩֵ

	// ����ǰ���ж����ȼ�
	friend bool operator< (const miniInfo& lhs, const miniInfo& rhs)
	{
		return lhs.pathWeight < rhs.pathWeight;
	}
};

/* ͼ�� �� �����㣬 �ߣ� ��һ��ӳ�������� �������е�ʵ����� ����ͼ�и��ֵ�����
*/
template <typename T>
class graph
{
public:
	class const_iterator : public map<T, int>::const_iterator
	{
	public:
		const_iterator()
		{}

		const_iterator(const typename map<T, int>::const_iterator iter)
		{
			*((typename map<T, int>::const_iterator *)this) = iter;
		}

		const T& operator *() const
		{
			typename map<T, int>::const_iterator p = *this;

			return p->first;
		}

	};

	graph();

	/*	��������		*/
	// �������캯��
	graph(const graph<T>& g);
	// ���ƹ��캯��
	graph<T>& operator= (const graph<T>& rhs);
	// ����
	~graph();

	// ͼ�ĵ����Ŀ
	int numberOfVertices() const;

	// ͼ�ıߵ���Ŀ
	int numberOfEdges() const;

	// �ж�ͼ�Ƿ�Ϊ��
	bool empty() const;

	// �õ��ߵ�Ȩֵ
	//ǰ������: ���ʵ������㶼��ͼ�У� ������ڣ� �����׳� ͼ�쳣
	int getWeight(const T& v1, const T& v2)const;

	// ���ñߵ�Ȩֵ
	//ǰ������: ���ʵ������㶼��ͼ�У� ������ڣ� �����׳� ͼ�쳣
	// ���������� ָ���ߵ�Ȩֵ��Ϊ w	
	void setWeight(const T& v1, const T& v2, int w);

		// �������
	int inDegree(const T& v) const;
		// ���س���
	int outDegree(const T& v) const;

		// �õ��ڱ߼�
	set<T> getNeighbors(const T& v) const;

	// ����һ����
	// ǰ�������� �߲���ͼ�У� �����׳� ͼ�쳣
	// ���������� ͼ�ж���һ���� v1 -> v2 ȨֵΪ weight
	void insertEdge(const T& v1, const T& v2, const int weight);

	// ����һ����
	// ǰ�������� �㲻��ͼ�У� �����׳� ͼ�쳣
	// ���������� ͼ�ж���һ����
	void insertVertex(const T& v);

	// ɾ����
	// ǰ�������� �����ͼ�У� �����׳� ͼ�쳣
	// ���������� ͼ������һ����
	void eraseVertex(const T& v);

	// ɾ����
	// ǰ�������� �ߴ���ͼ�У� �����׳� ͼ�쳣
	// ���������� ͼ������һһ����  v1-> v2
	void eraseEdge(const T& v1, const T& v2);

	// ���ͼ
	void clear();

	// ������������Ϊ��Ҫ�� ���ʵĵ㲻���޸�ͼ����Ϣ�� ��Ϊ�漰�����ݵ�ͬ������
	typedef const_iterator iterator;

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;
	
	////////////////////////////////////////////
	// ��������д�� ���Խ���Ԫֱ��д������
#include "y_galgs.h"
	////////  �ⲿ��������
		// �������������
	//friend istream& operator>> (istream& istr, graph<T>& g);

	//	// ������������
	//friend ostream& operator<< (ostream& ostr, graph<T>& g);

	//	// ������ޱ���
	//friend set<T> bfs(graph<T>& g, const T& sVertex);

	//	// ��С·��: �������ý����Ϣ dataValue ���Լ�¼���ʵ��ĸ����㵽��ʼ���Ȩֵ�� 
	//	// �������ȶ��к͹�����ȵķ�ʽ����ÿ���㣬 ��¼���ʹ��̵ľ�Ϊ��㱾������ԡ�parent ��¼·���� dataValue��¼Ȩֵ
	//	// ǰ�������� �����㶼��ͼ�У� �����׳� graphError �쳣
	//	// ����ֵ�� ��С��Ȩֵ
	//friend int minimumPath(graph<T>& g, const T& sVertex, const T& eVertex, list<T>& path);

	//	// ���·���� �������ù�����ȵķ�ʽ�� ������̵�·���� ���ý������ dataValue��¼�����ı����� 
	//	// ǰ�������� �����㶼��ͼ�У� �����׳� graphError �쳣
	//	// ����ֵ�� ���·���ı���
	//friend int shortestPath(graph<T>& g, const T& sVertex, const T& eVertex, list<T>& path);

	//	// ����������: �㷨���ù�����Ⱥ����ȶ��нṹ���������齨�� ���ȶ��еķ�ʽ���Ƶ�Ԫ�س�����ʱ�� ����Ԫ�ز����Ԫ�ص�ֵ
	//	// ���н�һ���Ż��� ��Ϊ���Ѿ�����ֵ�˹�����ȿ���ʹ��¼����ֵ�ĵ���ʱ���£�
	//	// �㷨����ͼ�ĵ�����Լ�¼���ʵĹ��̣� dataValue ��¼�ˣ� �������и�����ϵ��֮���Ȩֵ��Ϣ�� parent��¼ǰ�����
	//	// ǰ�������� �����㶼��ͼ�У� �����׳� graphError �쳣
	//friend int minSpanTree(graph<T>& g, graph<T>& MST);

	//	// �ж�ͼ���Ƿ��޻�
	//	// ����������������㷨�� ���ؼ�������װ��һ�����������У�
	//	// ����ֵ�� ������������������㷨��һ���쳣ʱ��ʾ�л��� �����޻�
	//friend bool acyclic(graph<T>& g);

	//	// �������
	//	// ������������㷨��ͼ���б���
	//friend void dfs(graph<T>& g, list<T>& dfsList);

	//	//��������
	//	// ����������ȵķ�ʽ�������� Ȼ�����ݲ���ͷ��㣬 
	//	// ������ȱ�֤�ˣ� ���ʵ�˳�� ����ͷ��㱣֤�˷��ϵ�����ʽ
	//friend void topologicalSort(graph<T>& g, list<T>& tlist);

	//friend graph<T> transpose(graph<T>& g);

	//friend void strongComponents(graph<T>& g, vector<set<T> >& component);

private:
	typedef map<T, int> VertexMap;

	// �洢����������Ϣ���ӳ�����ʵ�����������
	VertexMap vtxMap;

	// ӳ��ʵ��
	// �洢ͼ�е�ĸ�����Ϣ�� ͼ���������ݹ���һ�ݿ����Ѵﵽͬ���Ĳ��衣
	vector<vertexInfo<T> > vInfo;

	// �����ߺ͵����Ŀ
	int numVertices;
	int numEdges;

	// �洢�����п��õ������
	stack<int> availStack;



	// �õ���Ϣ��ͼ�е�ӳ��ʵ�壬 ����ӳ������������ֵ
	int getvInfoIndex(const T& v) const;

		// ��������б���ͼ, ���õݹ�ķ�ʽʵ��ͼ��������ȷ��ʣ� ��ͼ�г��ֻ�ʱ�� �׳�ͼ�쳣
		// ������������Ҫ��ͼ�еĻ������жϴ���ʱ�����Զ��쳣�Ĳ����� �õ�ͼ�л������
		// ǰ�������� ���ʵ���ͼ�� �� �����׳� ͼ�쳣
	/*����᡿
			1�� �˴�����ͼ����ɫ��ǵ�Ӧ�þ��е�����״̬(Ŀǰ���ڵ�һ��״̬)�� ���Ǽ�¼�������Էǳ��õķ�װ
			2�� ������Ƚ�����ջ�Ľṹ��ͨ��������ǣ� ֱ��ʵ�ֻ�������ϵͳջ����ɣ������õݹ�ķ�ʽ��
	*/
		// ���������ڲ�����
	//friend void dfsVisit(graph<T>& g, const T& sVertex, list<T>& dfsList,
	//	bool checkForCycle);
};


//////////////////////////////////////////////////////////////////////////
//									ͼ���ʵ�ִ���
//////////////////////////////////////////////////////////////////////////

template <typename T>
int graph<T>::getvInfoIndex(const T& v) const
{
	// �õ���Ϣ��ӳ���
	typename vertexMap::const_iterator iter = vtxMap.find(v);

	// ���û���ҵ��� ����-1
	int pos = -1;
	if (iter != vtxMap.end())
		pos = iter->second;

	return pos;
}

template <typename T>
graph<T>::graph() : numEdges(0), numVertices(0)
{}

template <typename T>
graph<T>::graph(const graph<T>& g)
{
	*this = g;
}

template <typename T>
graph<T>& graph<T>::operator= (const graph<T>& rhs)
{
	// ��������Լ��Ž��и�ֵ
	if (this != &rhs)
		return *this;

	// ���ԭ��ͼ
	this->clear();

	// ���Ƹ���ͼ����
	this->numEdges = rhs.numEdges;
	this->numVertices = rhs.numVertices;
	this->vInfo = rhs.vInfo;
	this->vtxMap = rhs.vtxMap;
	this->availStack = rhs.availStack;

	// ������ӳ�䵽���ʵ���Ϣ���λ��
	typename map<T, int>::const_iterator mi;
	for (mi = vtxMap.begin(); mi != vtxMap.end(); ++mi)
	{
		vInfo[mi->second].vtxMapLoc = mi;
	}

	return *this;
}

template <typename T>
graph<T>::~graph()
{
	clear();
}

template <typename T>
int graph<T>::numberOfVertices() const
{
	return numVertices;
}

// ͼ�ıߵ���Ŀ
template <typename T>
int graph<T>::numberOfEdges() const
{
	return numEdges;
}

// �ж�ͼ�Ƿ�Ϊ��
template <typename T>
bool graph<T>::empty() const
{
	return numVertices == 0;
}

// �õ��ߵ�Ȩֵ
//ǰ������: ���ʵ������㶼��ͼ�У� ������ڣ� �����׳� ͼ�쳣
template <typename T>
int graph<T>::getWeight(const T& v1, const T& v2)const
{
	// ����v1Ԫ�أ�
	int pos1 = getvInfoIndex(v1), pos2 = getvInfoIndex(v2);

	// ���v1����v2����ͼ�У� �׳��쳣
	if (pos1 == -1 || pos2 == -1)
		throw graphError("getWeight��������:  �㲻����");

	// �õ� v1->v2�ߵ�Ȩֵ
	const set<neighbor>& edgeSet = vInfo[pos1].edges;
	set<neighbor>::const_iterator iter;

	// ����ҵ��ñ�
	if ((iter = edgeSet.find(neighbor(pos2))) != edgeSet.end())
		return iter->weight;
	else
		return -1;

}

// ���ñߵ�Ȩֵ
//ǰ������: ���ʵ������㶼��ͼ�У� ������ڣ� �����׳� ͼ�쳣
// ���������� ָ���ߵ�Ȩֵ��Ϊ w	
template <typename T>
void graph<T>::setWeight(const T& v1, const T& v2, int w)
{
	// ����v1Ԫ�أ�
	int pos1 = getvInfoIndex(v1), pos2 = getvInfoIndex(v2);

	// ���v1����v2����ͼ�У� �׳��쳣
	if (pos1 == -1 || pos2 == -1)
		throw graphError("setWeight��������:  �㲻����");

	// �õ� v1->v2�ߵı�
	const set<neighbor>& edgeSet = vInfo[pos1].edges;
	set<neighbor>::const_iterator iter;

	// ����ҵ��ñ�
	if ((iter = edgeSet.find(neighbor(pos2))) != edgeSet.end())
		return iter->weight = w;
	else
		throw graphError("setWeight(): ���ʵı߲�����")
}

// return the number of edges entering  v
template <typename T>
int graph<T>::inDegree(const T& v) const
{
	// find the vInfo index for v
	int pos = getvInfoIndex(v);

	if (pos != -1)
		// in-degree is stored in vInfo[pos]
		return vInfo[pos].inDegree;
	else
		// throw an exception
		throw graphError("graph inDegree(): vertex not in the graph");
}

// return the number of edges leaving  v
template <typename T>
int graph<T>::outDegree(const T& v) const
{
	// find the vInfo index for v
	int pos = getvInfoIndex(v);

	if (pos != -1)
		// out-degree is number of elements in the edge set
		return vInfo[pos].edges.size();
	else
		// throw an exception
		throw graphError("graph outDegree(): vertex not in the graph");
}

// return the list of all adjacent vertices
template <typename T>
set<T> graph<T>::getNeighbors(const T& v) const
{
	// set returned
	set<T> adjVertices;

	// obtain the position of v from the map
	int pos = getvInfoIndex(v);

	// if v not in list of vertices, throw an exception
	if (pos == -1)
		throw
		graphError("graph getNeighbors(): vertex not in the graph");

	// construct an alias for the set of edges in vertex pos
	const set<neighbor>& edgeSet = vInfo[pos].edges;
	// use setIter to traverse the edge set
	set<neighbor>::const_iterator setIter;

	// index of vertexInfo object corresponding to an adjacent vertex
	int aPos;

	for (setIter = edgeSet.begin(); setIter != edgeSet.end(); setIter++)
	{	// "(*setIter).dest" is index into vInfo
		aPos = (*setIter).dest;
		// insert vertex data into a set. vInfo[aPos].vtxMapLoc"
		// is a map iterator. dereference it to access the vertex
		adjVertices.insert((*vInfo[aPos].vtxMapLoc).first);
	}

	return adjVertices;
}

// ����һ����
// ǰ�������� ��Ӧ��ͼ�У� �����׳� ͼ�쳣
// ���������� ͼ�ж���һ���� v1 -> v2 ȨֵΪ weight
template <typename T>
void graph<T>::insertEdge(const T& v1, const T& v2, const int weight)
{
	// ����v1Ԫ�أ�
	int pos1 = getvInfoIndex(v1), pos2 = getvInfoIndex(v2);

	// ���v1����v2����ͼ�У� �׳��쳣
	if (pos1 == -1 || pos2 == -1)
		throw graphError("insertEdge��������:  �㲻����");
	else if (pos1 == pos2)
		throw graphError("insertEdge��������:  �����Ի�����");

	// ���� v1->v2��
	pair<set<neighbor>::const_iterator, bool> result = vInfo[pos1].edges.insert(neighbor(v2, weight));

	if (result.second)
	{
		numEdges++;
		vInfo[pos2].inDegree++;
	}
}

// ����һ����
// ǰ�������� �㲻��ͼ�У� �����׳� ͼ�쳣
// ���������� ͼ�ж���һ����
template <typename T>
void graph<T>::insertVertex(const T& v)
{
	// ���ҵ��Ƿ�����ͼ��
	int pos = getvInfoIndex(v);

	if (pos != -1)
		throw graphError("insertVertex������ ���������ͼ��");

	// ����Ϣ��ӳ�䵽ͼ��
	pair<typename map<T, int>::const_iterator, bool> result = vtxMap.insert(typename map<T, int>::value_type(v, 0));

	if (result.second)
	{
		// �Ƿ����������δʹ�õ�λ��
		if (!availStack.empty())
		{
			pos = availStack.top();
			availStack.pop();

			// �����������صĿ������캯��
			// ץס����Ԫ�ص���Ԫ��ӳ�������ԣ� ���в����� �򵥿��
			vInfo[pos] = vertexInfo<T>(result.first);
		}
		else
		{
			vInfo.push_back(vertexInfo<T>(result.first));
			pos = numVertices;
		}

		// ��������
		numVertices++;
		vtxMap[v] = pos;
	}
	else
		throw graphError("insertVertex������ ����ʧ��");
}

// ɾ����
// ǰ�������� �����ͼ�У� �����׳� ͼ�쳣
// ���������� ͼ������һ����
template <typename T>
void graph<T>::eraseVertex(const T& v)
{
	int pos = getvInfoIndex(v);

	if (pos = -1)
		throw  graphError("eraseVertex() �����ڷ���һ�������ڵ㡣");

	/* �ֶ�ɾ�������ص���Ϣ  */
	// ɾ�������еļ�¼
	vInfo[pos].occupied = false;
	availStack.push(pos);

	// �ӳ�������ɾ��
	set<neighbor>& edgeSet = vInfo[pos].edges;
	set<neighbor>::iterator iter;
	for (iter = edgeSet.begin(); iter != edgeSet.end(); ++iter)
	{
		vInfo[iter->dest].inDegree--;
		numEdges--;
	}
	edgeSet.erase(edgeSet.begin(), edgeSet.end());

	// ���������ɾ��
	for (int i = i; i < vInfo.size(); ++i) if (vInfo[i].occupied)
	{
		edgeSet = vInfo[i].edges;
		for (iter = edgeSet.begin(); iter != edgeSet.end(); ++iter)
		{
			if (iter.dest == pos)
			{
				edgeSet.erase(iter);
				numEdges--;
				break;
			}
		}
	}
	// ��ӳ����ɾ����
	vtxMap.erase(v);
	numVertices--;

}

// ɾ����
// ǰ�������� �ߴ���ͼ�У� �����׳� ͼ�쳣
// ���������� ͼ������һһ����  v1-> v2
template <typename T>
void graph<T>::eraseEdge(const T& v1, const T& v2)
{
	// ����v1Ԫ�أ�
	int pos1 = getvInfoIndex(v1), pos2 = getvInfoIndex(v2);

	// ���v1����v2����ͼ�У� �׳��쳣
	if (pos1 == -1 || pos2 == -1)
		throw graphError("eraseEdge��������:  �㲻����");

	set<neighbor>& edgeSet = vInfo[pos1].edges;
	set<neighbor>::const_iterator iter;
	// ��Ҫɾ���ı�
	iter = edgeSet.find(neighbor(pos2));

	// Ҫɾ���ı߲���ͼ��
	if (iter == edgeSet.end())
		throw graphError("eraseEdge������ ɾ�������ڵı�");

	edgeSet.erase(iter);
	vInfo[pos2].inDegree--;
	numEdges--;
}

// ���ͼ
template <typename T>
void graph<T>::clear()
{
	vtxMap.erase(vtxMap.begin(), vtxMap.end());
	vInfo.erase(vInfo.begin(), vInfo.end());

	while (!availStack.empty())
	{
		availStack.pop();
	}

	numEdges = 0;
	numVertices = 0;
}

template <typename T>
typename graph<T>::iterator graph<T>::begin()
{
	return (typename graph<T>::iterator)vtxMap.begin();
}

template <typename T>
typename graph<T>::iterator graph<T>::end()
{
	return typename graph<T>::iterator(vtxMap.end());
}

template <typename T>
typename graph<T>::const_iterator graph<T>::begin() const
{
	return (typename graph<T>::const_iterator)vtxMap.begin();
}

template <typename T>
typename graph<T>::const_iterator graph<T>::end() const
{
	return (typename graph<T>::const_iterator)vtxMap.begin();
}




#endif // !GRAPH_CLASS



