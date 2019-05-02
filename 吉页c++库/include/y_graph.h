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

/* 每个点的邻边类
**	是一个目标在点向量中的目标下标
*/
class neighbor
{
public:
	// 目标点在点向量中的下标
	int dest;
	//该边的权值
	int weight;

	neighbor(int d = 0, int c = 0) : dest(d), weight(c)
	{}

	// 比较邻边的在点向量中的下标
	friend bool operator< (const neighbor& lhs, const neighbor& rhs)
	{
		return lhs.dest < rhs.dest;
	}

	// 以邻边的下标作为基准比较两条邻边是否相等
	friend bool operator== (const neighbor& lhs, const neighbor& rhs)
	{
		return lhs.dest == rhs.dest;
	}
};

/*	点类
	保存每个点的基本信息， 包括颜色、邻边集、元素、入度等信息
	*/
template <typename T>
class vertexInfo
{
public:
	// 点的颜色， 在遍历图的算法中使用
	enum vertexColor{ WHITE, GRAY, BLACK };

	// 指向对象实体映射的迭代器
	typename map<T, int>::iterator vtxMapLoc;

	// 点的邻边集
	set<neighbor> edges;
	// 点的入度
	int inDegree;
	// 标识中介向量中的当前位置是否存有有效数据
	bool occupied;
	// 当前点的颜色
	vertexColor color;


	int dataValue;

	// 该点的父节点， 标识表示某节点有一条邻边为该点
	int parent;

	// 构造函数
	vertexInfo() : inDegree(0), occupied(true)
	{}

	// constructor with iterator pointing to the vertex in the map
	vertexInfo(typename map<T, int>::iterator iter) :
		vtxMapLoc(iter), inDegree(0), occupied(true)
	{}
};

// 标记一个有限队列中使用的结点
class miniInfo
{
	int endV;	// 终点
	int pathWeight;		// 标记起点到当前位置的权值

	// 根据前置判断优先级
	friend bool operator< (const miniInfo& lhs, const miniInfo& rhs)
	{
		return lhs.pathWeight < rhs.pathWeight;
	}
};

/* 图类 ： 包含点， 边， 和一个映射向量， 保存所有的实体对象， 管理图中各种的数据
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

	/*	三大问题		*/
	// 拷贝构造函数
	graph(const graph<T>& g);
	// 复制构造函数
	graph<T>& operator= (const graph<T>& rhs);
	// 析构
	~graph();

	// 图的点的数目
	int numberOfVertices() const;

	// 图的边的数目
	int numberOfEdges() const;

	// 判断图是否为空
	bool empty() const;

	// 得到边的权值
	//前置条件: 访问的两个点都在图中， 如果不在， 函数抛出 图异常
	int getWeight(const T& v1, const T& v2)const;

	// 设置边的权值
	//前置条件: 访问的两个点都在图中， 如果不在， 函数抛出 图异常
	// 后置条件： 指定边的权值变为 w	
	void setWeight(const T& v1, const T& v2, int w);

		// 返回入度
	int inDegree(const T& v) const;
		// 返回出度
	int outDegree(const T& v) const;

		// 得到邻边集
	set<T> getNeighbors(const T& v) const;

	// 增加一条边
	// 前置条件： 边不再图中， 否则抛出 图异常
	// 后置条件： 图中多了一条边 v1 -> v2 权值为 weight
	void insertEdge(const T& v1, const T& v2, const int weight);

	// 插入一个点
	// 前置条件： 点不再图中， 否则抛出 图异常
	// 后置条件： 图中多了一个点
	void insertVertex(const T& v);

	// 删除点
	// 前置条件： 点存在图中， 否则抛出 图异常
	// 后置条件： 图中少了一个点
	void eraseVertex(const T& v);

	// 删除边
	// 前置条件： 边存在图中， 否则抛出 图异常
	// 后置条件： 图中少了一一条边  v1-> v2
	void eraseEdge(const T& v1, const T& v2);

	// 清空图
	void clear();

	// 这样做了是因为需要， 访问的点不能修改图的信息， 因为涉及到数据的同步问题
	typedef const_iterator iterator;

	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;
	
	////////////////////////////////////////////
	// 必须这样写， 可以将友元直接写入类中
#include "y_galgs.h"
	////////  外部造作函数
		// 输入运算符重载
	//friend istream& operator>> (istream& istr, graph<T>& g);

	//	// 输出运算符重载
	//friend ostream& operator<< (ostream& ostr, graph<T>& g);

	//	// 广度有限遍历
	//friend set<T> bfs(graph<T>& g, const T& sVertex);

	//	// 最小路径: 程序利用结点信息 dataValue 属性记录访问到的各个点到初始点的权值， 
	//	// 利用优先队列和广度优先的方式访问每个点， 记录访问过程的均为结点本身的属性。parent 记录路劲， dataValue记录权值
	//	// 前置条件： 两个点都在图中， 否则抛出 graphError 异常
	//	// 返回值： 最小的权值
	//friend int minimumPath(graph<T>& g, const T& sVertex, const T& eVertex, list<T>& path);

	//	// 最短路径： 程序利用广度优先的方式， 搜索最短的路径， 利用结点属性 dataValue记录经过的边数， 
	//	// 前置条件： 两个点都在图中， 否则抛出 graphError 异常
	//	// 返回值： 最短路劲的边数
	//friend int shortestPath(graph<T>& g, const T& sVertex, const T& eVertex, list<T>& path);

	//	// 最下生成树: 算法利用广度优先和优先队列结构对树进行组建， 优先队列的方式控制当元素出队列时， 后续元素不会对元素的值
	//	// 进行进一步优化， 因为它已经最优值了广度优先可以使记录过程值的到及时更新，
	//	// 算法利用图的点的属性记录访问的过程， dataValue 记录了， 生成树中各个联系点之间的权值信息， parent记录前驱结点
	//	// 前置条件： 两个点都在图中， 否则抛出 graphError 异常
	//friend int minSpanTree(graph<T>& g, graph<T>& MST);

	//	// 判读图中是否无环
	//	// 利用深度优先搜索算法， 将关键操作封装在一个辅助函数中，
	//	// 返回值： 当函数捕获到深度优先算法的一个异常时表示有环， 否则无环
	//friend bool acyclic(graph<T>& g);

	//	// 深度优先
	//	// 利用深度优先算法对图进行遍历
	//friend void dfs(graph<T>& g, list<T>& dfsList);

	//	//拓扑排序
	//	// 利用深度优先的方式访问数据 然后将数据插入头结点， 
	//	// 深度优先保证了， 访问的顺序， 插入头结点保证了符合的排序方式
	//friend void topologicalSort(graph<T>& g, list<T>& tlist);

	//friend graph<T> transpose(graph<T>& g);

	//friend void strongComponents(graph<T>& g, vector<set<T> >& component);

private:
	typedef map<T, int> VertexMap;

	// 存储各个结点的信息点和映射对象实体的向量索引
	VertexMap vtxMap;

	// 映射实体
	// 存储图中点的各种信息， 图中所有数据共享一份拷贝已达到同步的步骤。
	vector<vertexInfo<T> > vInfo;

	// 存数边和点的数目
	int numVertices;
	int numEdges;

	// 存储向量中可用点的索引
	stack<int> availStack;



	// 得到信息在图中的映射实体， 即在映射向量的索引值
	int getvInfoIndex(const T& v) const;

		// 深度优先有遍历图, 利用递归的方式实现图的深度优先访问， 当图中出现环时， 抛出图异常
		// 其他函数当需要对图中的环进行判断处理时，可以对异常的捕获处理， 得到图中环的情况
		// 前置条件： 访问点在图中 ， 否则抛出 图异常
	/*【体会】
			1、 此处利用图的颜色标记点应该具有的三种状态(目前处于的一种状态)， 这是记录数据特性非常好的封装
			2、 深度优先借助于栈的结构，通常情况下是， 直接实现或是利用系统栈来完成（即利用递归的方式）
	*/
		// 必须在类内不定义
	//friend void dfsVisit(graph<T>& g, const T& sVertex, list<T>& dfsList,
	//	bool checkForCycle);
};


//////////////////////////////////////////////////////////////////////////
//									图类的实现代码
//////////////////////////////////////////////////////////////////////////

template <typename T>
int graph<T>::getvInfoIndex(const T& v) const
{
	// 得到信息的映射点
	typename vertexMap::const_iterator iter = vtxMap.find(v);

	// 如果没有找到， 返回-1
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
	// 如果不是自己才进行赋值
	if (this != &rhs)
		return *this;

	// 清空原有图
	this->clear();

	// 复制各个图属性
	this->numEdges = rhs.numEdges;
	this->numVertices = rhs.numVertices;
	this->vInfo = rhs.vInfo;
	this->vtxMap = rhs.vtxMap;
	this->availStack = rhs.availStack;

	// 将向量映射到合适的信息点的位置
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

// 图的边的数目
template <typename T>
int graph<T>::numberOfEdges() const
{
	return numEdges;
}

// 判断图是否为空
template <typename T>
bool graph<T>::empty() const
{
	return numVertices == 0;
}

// 得到边的权值
//前置条件: 访问的两个点都在图中， 如果不在， 函数抛出 图异常
template <typename T>
int graph<T>::getWeight(const T& v1, const T& v2)const
{
	// 查找v1元素，
	int pos1 = getvInfoIndex(v1), pos2 = getvInfoIndex(v2);

	// 如果v1或是v2不在图中， 抛出异常
	if (pos1 == -1 || pos2 == -1)
		throw graphError("getWeight（）函数:  点不存在");

	// 得到 v1->v2边的权值
	const set<neighbor>& edgeSet = vInfo[pos1].edges;
	set<neighbor>::const_iterator iter;

	// 如果找到该边
	if ((iter = edgeSet.find(neighbor(pos2))) != edgeSet.end())
		return iter->weight;
	else
		return -1;

}

// 设置边的权值
//前置条件: 访问的两个点都在图中， 如果不在， 函数抛出 图异常
// 后置条件： 指定边的权值变为 w	
template <typename T>
void graph<T>::setWeight(const T& v1, const T& v2, int w)
{
	// 查找v1元素，
	int pos1 = getvInfoIndex(v1), pos2 = getvInfoIndex(v2);

	// 如果v1或是v2不在图中， 抛出异常
	if (pos1 == -1 || pos2 == -1)
		throw graphError("setWeight（）函数:  点不存在");

	// 得到 v1->v2边的边
	const set<neighbor>& edgeSet = vInfo[pos1].edges;
	set<neighbor>::const_iterator iter;

	// 如果找到该边
	if ((iter = edgeSet.find(neighbor(pos2))) != edgeSet.end())
		return iter->weight = w;
	else
		throw graphError("setWeight(): 访问的边不存在")
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

// 增加一条边
// 前置条件： 边应该图中， 否则抛出 图异常
// 后置条件： 图中多了一条边 v1 -> v2 权值为 weight
template <typename T>
void graph<T>::insertEdge(const T& v1, const T& v2, const int weight)
{
	// 查找v1元素，
	int pos1 = getvInfoIndex(v1), pos2 = getvInfoIndex(v2);

	// 如果v1或是v2不在图中， 抛出异常
	if (pos1 == -1 || pos2 == -1)
		throw graphError("insertEdge（）函数:  点不存在");
	else if (pos1 == pos2)
		throw graphError("insertEdge（）函数:  发生自环现象");

	// 插入 v1->v2边
	pair<set<neighbor>::const_iterator, bool> result = vInfo[pos1].edges.insert(neighbor(v2, weight));

	if (result.second)
	{
		numEdges++;
		vInfo[pos2].inDegree++;
	}
}

// 插入一个点
// 前置条件： 点不再图中， 否则抛出 图异常
// 后置条件： 图中多了一个点
template <typename T>
void graph<T>::insertVertex(const T& v)
{
	// 查找点是否已在图中
	int pos = getvInfoIndex(v);

	if (pos != -1)
		throw graphError("insertVertex（）， 插入点已在图中");

	// 将信息点映射到图中
	pair<typename map<T, int>::const_iterator, bool> result = vtxMap.insert(typename map<T, int>::value_type(v, 0));

	if (result.second)
	{
		// 是否存在向量中未使用的位置
		if (!availStack.empty())
		{
			pos = availStack.top();
			availStack.pop();

			// 这里利用重载的拷贝构造函数
			// 抓住向量元素的主元是映射点的特性， 进行操作， 简单快捷
			vInfo[pos] = vertexInfo<T>(result.first);
		}
		else
		{
			vInfo.push_back(vertexInfo<T>(result.first));
			pos = numVertices;
		}

		// 后续工作
		numVertices++;
		vtxMap[v] = pos;
	}
	else
		throw graphError("insertVertex（）： 插入失败");
}

// 删除点
// 前置条件： 点存在图中， 否则抛出 图异常
// 后置条件： 图中少了一个点
template <typename T>
void graph<T>::eraseVertex(const T& v)
{
	int pos = getvInfoIndex(v);

	if (pos = -1)
		throw  graphError("eraseVertex() ：正在访问一个不存在点。");

	/* 分段删除与点相关的信息  */
	// 删除向量中的记录
	vInfo[pos].occupied = false;
	availStack.push(pos);

	// 从出度入手删除
	set<neighbor>& edgeSet = vInfo[pos].edges;
	set<neighbor>::iterator iter;
	for (iter = edgeSet.begin(); iter != edgeSet.end(); ++iter)
	{
		vInfo[iter->dest].inDegree--;
		numEdges--;
	}
	edgeSet.erase(edgeSet.begin(), edgeSet.end());

	// 从入度入手删除
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
	// 在映射中删除点
	vtxMap.erase(v);
	numVertices--;

}

// 删除边
// 前置条件： 边存在图中， 否则抛出 图异常
// 后置条件： 图中少了一一条边  v1-> v2
template <typename T>
void graph<T>::eraseEdge(const T& v1, const T& v2)
{
	// 查找v1元素，
	int pos1 = getvInfoIndex(v1), pos2 = getvInfoIndex(v2);

	// 如果v1或是v2不在图中， 抛出异常
	if (pos1 == -1 || pos2 == -1)
		throw graphError("eraseEdge（）函数:  点不存在");

	set<neighbor>& edgeSet = vInfo[pos1].edges;
	set<neighbor>::const_iterator iter;
	// 找要删除的边
	iter = edgeSet.find(neighbor(pos2));

	// 要删除的边不在图中
	if (iter == edgeSet.end())
		throw graphError("eraseEdge（）： 删除不存在的边");

	edgeSet.erase(iter);
	vInfo[pos2].inDegree--;
	numEdges--;
}

// 清空图
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



