
friend istream& operator>> (istream& istr, graph<T>& g)
{
	// 起点和终点
	T v1, v2;
	int nVertics, nEdges;
	int weight;

	// 将原来的图清空
	if (g.numVertices > 0)
		g.clear();

	// 插入所有的点
	cin >> nVertics;
	for (int i = 0; i < nVertics; ++i) {
		cin >> v1;
		g.insertVertex(v1);
	}

	// 插入所有的边
	cin >> nEdges;
	for (int i = 0; i < nEdges; ++i) {
		cin >> v1;
		cin >> v2;
		cin >> weight;
		g.insertEdge(v1, v2, weight);
	}

	return istr;
}

// 输出运算符重载
friend ostream& operator<< (ostream& ostr, const graph<T>& g)
{
	for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied)
	{
		cout << g.vInfo[i].vtxMapLoc->first << "  in-degree: " << g.vInfo[i].inDegree
			<< "  out-degree: " << g.vInfo[i].edges.size()
			<< " Edges: ";
		// 遍历边集
		set<neighbor>::iterator setIter;
		set<neighbor>& edgeSet = g.vInfo[i].edges;
		for (setIter = edgeSet.begin(); setIter != edgeSet.end(); ++setIter) {
			cout << g.vInfo[setIter->dest].vtxMapLoc->first << "(" << setIter->weight << "), ";
		}
		cout << endl;
	}

	return ostr;
}

// 广度有限遍历
friend set<T> bfs(graph<T>& g, const T& sVertex)
{
	// 已访问数据的存放位置
	set<T>  visitSet;
	// 正在访问的数据
	queue<T> visitQueue;

	// 处理头接点
	int pos = g.getvInfoIndex(sVertex);
	if (pos == -1)
		throw graphError("bfs（）函数试图访问的点不在图中");

	for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied)
		g.vInfo[i].color = vertexInfo<T>::WHITE;

	visitQueue.push(pos);

	// 开始进行访问每个顶点
	while (!visitQueue.empty())
	{
		int cur = visitQueue.top();
		visitQueue.pop();
		g.vInfo[cur].color = vertexInfo<T>::BLACK;
		visitSet.insert(g.vInfo[cur].vtxMapLoc->first);

		// 遍历边集
		set<neighbor>& edgeSet = g.vInfo[i].edges;
		set<neighbor>::iterator setIter;
		for (setIter = edgeSet.begin(); setIter != edgeSet.end(); ++setIter)
		{
			if (g.vInfo[setIter->dest].color == vertexInfo<T>::WHITE)
			{
				visitQueue.push(setIter->dest);
				g.vInfo[setIter->dest].color = vertexInfo<T>::GRAY;
			}
		}
	}

	return visitSet;
}

// 最小路径
friend int minimumPath(graph<T>& g, const T& sVertex, const T& eVertex, list<T>& path)
{
	int returnValue = -1;

	// 判断点是否在图中
	int pos1 = g.getvInfoIndex(sVertex);
	int pos2 = g.getvInfoIndex(eVertex);
	if (pos1 == -1 || pos2 == -1)
		throw graphError("minimumPath（）算法试图访问的点不在图中");

	for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied)
	{
		g.vInfo[i].color = vertexInfo<T>::WHITE;
		g.vInfo[i].dataValue = INFINITY;
	}

	// 组装头结点到优先队列中
	miniInfo vertexData;
	miniPQ<miniInfo, less<miniInfo> > minPathPQ;

	vertexData.endV = pos1;
	vertexData.pathWeight = 0;
	g.vInfo[pos1].dataValue = 0;
	g.vInfo[pos1].parent = pos1;

	bool foundMinPath = false;
	// 开始访问优先队列，直到队列为空
	while (!minPathPQ.empty())
	{
		vertexData = minPathPQ.top();
		minPathPQ.pop();

		int cur = vertexData.endV;
		g.vInfo[cur].color = vertexInfo<T>::BLACK;

		// 如果找到目标， 退出
		if (cur == pos2)
		{
			foundMinPath = true;
			break;
		}

		if (g.vInfo[cur].color != vertexInfo<T>::BLACK)
		{
			g.vInfo[cur].color = vertexInfo<T>::BLACK;

			// 访问邻边
			set<neighbor>& edgeSet = g.vInfo[i].edges;
			set<neighbor>::iterator setIter;
			for (setIter = edgeSet.begin(); setIter != edgeSet.end(); ++setIter)
			{
				int newMinWeight = 0;
				int dest = setIter->dest;

				if (g.vInfo[dest].color == vertexInfo<T>::WHITE)	// 如果dest还没还有访问结束
				if ((newMinWeight = setIter->weight + g.vInfo[cur].dataValue) < g.vInfo[dest].dataValue)	// 新的权值小于dest的原来的权值信息
				{
					// 更新结点的信息， 包括权值，和父节点信息， 访问情况
					vertexData.endV = dest;
					vertexData.pathWeight = newMinWeight;

					// 更新入队元素的信息
					g.vInfo[dest].parent = cur;
					g.vInfo[dest].dataValue = newMinWeight;

					minPathPQ.push(vertexData);
				}
			}	// end 边集遍历for
		}	// end if(color != BlACK)
	}	// end while(empty)

	path.erase(path.begin(), path.end());

	// 处理找到最短路径的情况
	// * 回溯取出路劲， 和权值
	if (foundMinPath)
	{
		cur = pos2;
		while (cur != pos1)
		{
			path.push_front(g.vInfo[cur].vtxMapLoc->first);	//  将当前结点加入最短路径
			cur = g.vInfo[cur].parent;
		}
		path.push_front(sVertex);
		returnValue = g.vInfo[pos2].dataValue;
	}

	return returnValue;
}

// 最短路径
friend int shortestPath(graph<T>& g, const T& sVertex, const T& eVertex, list<T>& path)
{
	// 判断点是否在图中
	int pos1 = g.getvInfoIndex(sVertex);
	int pos2 = g.getvInfoIndex(eVertex);
	if (pos1 == -1 || pos2 == -1)
		throw graphError("minimumPath（）算法试图访问的点不在图中");

	// 设置初始信息
	bool foundShortestPath = false;
	for (int i = 0; i < g.vInfo.size(); ++i)
	{
		g.vInfo[i].color = vertexInfo<T>::WHITE;
		g.vInfo[i].dataValue = 0;
	}

	// 组装首元素
	queue<int> visitQueue;

	g.vInfo[pos1].dataValue = 0;
	g.vInfo[pos1].parent = pos1;

	visitQueue.push(pos1);

	// 循环处理队列， 更新访问到的每个元素的属性值， 记录访问过程
	while (!visitQueue.empty() && !foundShortestPath)
	{
		int cur = visitQueue.top();
		visitQueue.pop();

		// 如果找到退出
		if (cur == pos2)
			foundShortestPath = true;
		else
		{
			if (g.vInfo[cur].color != vertexInfo<T>::BLACK)
			{
				g.vInfo[cur].color = vertexInfo<T>::BLACK;

				// 访问边集
				set<neighbor>& edgeSet = g.vInfo[cur].edges;
				set<neighbor>::iterator setIter;
				for (setIter = edgeSet.begin(); setIter != edgeSet.end(); ++setIter)
				{
					int dest = setIter->dest;
					if (g.vInfo[dest].color == vertexInfo<T>::WHITE)
					{
						g.vInfo[dest].color = vertexInfo<T>::GRAY;
						visitQueue.push(dest);
						g.vInfo[dest].parent = cur;
						g.vInfo[dest].dataValue = g.vInfo[cur].dataValue + 1;
					}
				}
			}
		}
	}

	int returnValue = -1;
	//	回溯最短路劲， 返回
	if (foundShortestPath)
	{
		cur = pos2;
		while (cur != pos1)
		{
			path.push_front(g.vInfo[cur].vtxMapLoc->first);
			cur = g.vInfo[cur].parent;
		}
		path.push_front(sVertex);
		returnValue = g.vInfo[pos2].dataValue;
	}

	return returnValue;
}

// 最小生成树
friend int minSpanTree(graph<T>& g, graph<T>& MST)
{
	minInfo vertexData;
	miniPQ<miniInfo, less<miniInfo> > minSpanTreePQ;
	int pos_sVertex = -1;

	// 记录树的信息
	int minSpanTreeWeight = 0;
	int minSpanTreeSize = 0;

	// 初始信息	
	for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied)
	{
		if (pos_sVertex = -1)
			pos_sVertex = i;
		g.vInfo[i].color = vertexInfo<T>::WHITE;
		g.vInfo[i].dataValue = INFINITY;
	}

	// 组装首元素
	vertexData.endV = pos_sVertex;
	vertexData.pathWeight = 0;
	g.vInfo[pos_sVertex].parent = pos_sVertex;
	g.vInfo[pos_sVertex].dataValue = 0;

	minSpanTreePQ.push(vertexData);

	// 遍历优先队列， 更新各个的点的属性， 记录访问过程，
	while (!minSpanTreePQ.empty())
	{
		vertexData = minSpanTreePQ.top();
		minSpanTreePQ.pop();

		int cur = vertexData.endV;

		if (g.vInfo[cur].color != vertexInfo<T>::BLACK)
		{
			// 更新树的信息
			minSpanTreeSize++;
			minSpanTreeWeight += vertexData.pathWeight;
			// 如果生成树已经完成， 跳出循环
			if (minSpanTreeSize == g.numVertices)
				break;

			g.vInfo[cur].color = vertexInfo<T>::BLACK;
			// 访问邻边集
			set<neighbor>& edgeSet = g.vInfo[cur].edges;
			set<neighbor>::iterator setIter;
			for (setIter = edgeSet.begin(); setIter != edgeSet.end(); ++setIter)
			{
				int dest = setIter->dest;
				// 将为访问的邻边加入到优先队列中
				if (g.vInfo[dest].color == vertexInfo<T>::WHITE)
				if (setIter->weight < g.vInfo[dest].dataValue)
				{
					vertexData.endV = dest;
					vertexData.pathWeight = setIter->weight;
					g.vInfo[dest].parent = cur;
					g.vInfo[dest].dataValue = setIter->weight;
				}
			} // end for（遍历邻边）
		}	// end if (没有访问）
	}	// end while (非空)

	// 清空最小生成树的信息
	MST.clear();

	// 得到最小生成树
	for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied)
	{
		MST.insertVertex(g.vInfo[i].vtxMapLoc->first);
	}

	// 构建最小生成树的边
	int parentPos;
	T v1, v2;
	for (int i = pos_sVertex + 1; i < g.vInfo.size(); ++i)
	{
		parentPos = g.vInfo[i].parent;
		v1 = g.vInfo[parentPos].vtxMapLoc->first;
		v2 = g.vInfo[i].vtxMapLoc->first;
		MST.insertEdge(v1, v2, g.vInfo[i].dataValue);
	}
	return minSpanTreeWeight;
}


// 判读图中是否无环

friend bool acyclic(graph<T>& g)
{
	// 深度遍历的链表
	list<T> dfsList;

	// 初始化准备变量
	for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied)
		g.vInfo[i].color = vertexInfo<T>::WHITE;

	try
	{
		// 利用深度优先方式判读是否有环
		for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied && g.vInfo[i].color == vertexInfo<T>::WHITE)
			dfsVisit(g, g.vInfo[i].vtxMapLoc->first, dfsList, true);
	}
	catch (const graphError& )
	{			// 捕获图中环的情况， 返回值
		return false;
	}
	return true;
}

// 深度优先有遍历图, 利用递归的方式实现图的深度优先访问， 当图中出现环时， 抛出图异常e
private:
	friend void dfsVisit(graph<T>& g, const T& sVertex, list<T>& dfsList,
		bool checkForCycle)
	{
		// 初始记录变量， 
		set<neighbor>::iterator setIter;
		vector<vertexInfo<T> >& vlist = g.vInfo;

		// 处理首元素
		int pos = g.getvInfoIndex(sVertex);
		if (pos == -1)
			throw graphError("dfsvisit(); 函数试图访问一个不存在图中的点");

		vlist[pos].color = vertexInfo<T>::GRAY;	// 标记点正在处于访问状态

		// 判断， 利用递归的方式访问下一个元素， 当发现环时抛出异常
		set<neighbor>& edgeSet = vlist[pos].edges;
		for (setIter = edgeSet.begin(); setIter != edgeSet.end(); ++setIter)
		{
			if (vlist[setIter->dest].color == vertexInfo<T>::WHITE)
			{
				dfsVisit(g, g.vInfo[setIter->dest].vtxMapLoc->first, dfsList, checkForCycle);
			}
			else if (vlist[setIter->dest].color == vertexInfo<T>::GRAY && checkForCycle)
				throw graphError("图中出现环中结构");

			// 记录访问点
			vlist[pos].color = vertexInfo<T>::BLACK;
			dfsList.push_front(vlist[pos].vtxMapLoc->first);
		}
	}
public:
	// 深度优先
	friend void dfs(graph<T>& g, list<T>& dfsList)
	{
		// 初始化变量性息
		for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied)
			g.vInfo[i].color = vertexInfo<T>::WHITE;

		// 利用广度优先的方式访问图中每个点
		for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied && g.vInfo[i].color == vertexInfo<T>::WHITE)
		{
			dfsVisit(g, g.vInfo[i].vtxMapLoc->first, dfsList, false);
		}
	}

	friend  void topologicalSort(graph<T>& g, list<T>& tlist)
	{
		// 初始化工作
		tlist.erase(tlist.begin(), tlist.end());

		// 准备变量
		for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied)
		{
			g.vInfo[i].color = vertexInfo<T>::WHITE;
		}

		// 迭代图中的每个点， 进行拓扑排序， 当出现环时， 抛出异常
		for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied && g.vInfo[i].color == vertexInfo<T>::WHITE)
		{
			try
			{
				dfsVisit(g, g.vInfo[i].vtxMapLoc->first, tlist, true);
			}
			catch (graphError& )
			{
				// 很好的处理， 这里不需要对异常做处理， 所以抛出更为准确的信息
				throw graphError("topologicalSort(), 调用一个有环的图， 这样将陷入死循环");
			}
		}
	}

	friend graph<T> transpose(graph<T>& g)
	{
		// 初始化变量
		graph<T> gt = g;

		// 准备变量
		for (int i = 0; i < gt.vInfo.size(); ++i) if (g.vInfo[i].occupied)
		{
			gt.vInfo[i].edges.erase(gt.vInfo[i].edges.begin(), gt.vInfo[i].edges.end());
			gt.vInfo[i].inDegree = 0;
		}

		// 开始访问变量,迭代原图， 得到新的图
		for (int i = 0; i < gt.vInfo.size(); ++i) if (gt.vInfo[i].occupied)
		{
			set<neighbor>& edgeSet = g.vInfo[i].edges;
			set<neighbor>::iterator setIter;
			for (setIter = edgeSet.begin(); setIter != edgeSet.end(); ++setIter)
			{
				gt.vInfo[setIter->dest].edges.insert(neighbor(i, weight));
				gt.vInfo[i].inDegree++;
			}
		}

		// 返回新的图
		return gt;
	}

	friend  void strongComponents(graph<T>& g, vector<set<T> >& component)
	{
		// list of vertices visited by dfs() for graph g
		list<T> dfsGList;

		// list of vertices visited by dfsVisit() for g transpose
		list<T> dfsGTList;

		// used to scan dfsGList and dfsGTList objects
		list<T>::iterator gIter, gtIter;

		// transpose of the graph
		graph<T> gt;

		// set for an individual strong component
		set<T> scSet;

		int i;

		// clear the return vector
		component.resize(0);

		// execute depth-first tranversal of g
		dfs(g, dfsGList);

		// compute gt
		gt = transpose(g);

		// initialize all vertices in gt to WHITE (unvisited)
		for (i = 0; i < gt.vInfo.size(); i++)
		if (gt.vInfo[i].occupied)
			gt.vInfo[i].color = vertexInfo<T><T>::WHITE;

		// call dfsVisit() for gt from vertices in dfsGList
		gIter = dfsGList.begin();
		while (gIter != dfsGList.end())
		{
			// call dfsVisit() only if vertex has not been visited
			if (gt.vInfo[gt.getvInfoIndex(*gIter)].color ==
				vertexInfo<T><T>::WHITE)
			{
				// clear dfsGTList and scSet
				dfsGTList.erase(dfsGTList.begin(), dfsGTList.end());
				scSet.erase(scSet.begin(), scSet.end());

				// do dfsVisit() in gt for starting vertex *gIter
				dfsVisit(gt, *gIter, dfsGTList, false);

				// copy vertices from the list to set scSet
				for (gtIter = dfsGTList.begin(); gtIter != dfsGTList.end();
					gtIter++)
					scSet.insert(*gtIter);

				// add strong component set to the vector
				component.push_back(scSet);
			}
			gIter++;
		}
	}