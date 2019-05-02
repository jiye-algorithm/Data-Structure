
friend istream& operator>> (istream& istr, graph<T>& g)
{
	// �����յ�
	T v1, v2;
	int nVertics, nEdges;
	int weight;

	// ��ԭ����ͼ���
	if (g.numVertices > 0)
		g.clear();

	// �������еĵ�
	cin >> nVertics;
	for (int i = 0; i < nVertics; ++i) {
		cin >> v1;
		g.insertVertex(v1);
	}

	// �������еı�
	cin >> nEdges;
	for (int i = 0; i < nEdges; ++i) {
		cin >> v1;
		cin >> v2;
		cin >> weight;
		g.insertEdge(v1, v2, weight);
	}

	return istr;
}

// ������������
friend ostream& operator<< (ostream& ostr, const graph<T>& g)
{
	for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied)
	{
		cout << g.vInfo[i].vtxMapLoc->first << "  in-degree: " << g.vInfo[i].inDegree
			<< "  out-degree: " << g.vInfo[i].edges.size()
			<< " Edges: ";
		// �����߼�
		set<neighbor>::iterator setIter;
		set<neighbor>& edgeSet = g.vInfo[i].edges;
		for (setIter = edgeSet.begin(); setIter != edgeSet.end(); ++setIter) {
			cout << g.vInfo[setIter->dest].vtxMapLoc->first << "(" << setIter->weight << "), ";
		}
		cout << endl;
	}

	return ostr;
}

// ������ޱ���
friend set<T> bfs(graph<T>& g, const T& sVertex)
{
	// �ѷ������ݵĴ��λ��
	set<T>  visitSet;
	// ���ڷ��ʵ�����
	queue<T> visitQueue;

	// ����ͷ�ӵ�
	int pos = g.getvInfoIndex(sVertex);
	if (pos == -1)
		throw graphError("bfs����������ͼ���ʵĵ㲻��ͼ��");

	for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied)
		g.vInfo[i].color = vertexInfo<T>::WHITE;

	visitQueue.push(pos);

	// ��ʼ���з���ÿ������
	while (!visitQueue.empty())
	{
		int cur = visitQueue.top();
		visitQueue.pop();
		g.vInfo[cur].color = vertexInfo<T>::BLACK;
		visitSet.insert(g.vInfo[cur].vtxMapLoc->first);

		// �����߼�
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

// ��С·��
friend int minimumPath(graph<T>& g, const T& sVertex, const T& eVertex, list<T>& path)
{
	int returnValue = -1;

	// �жϵ��Ƿ���ͼ��
	int pos1 = g.getvInfoIndex(sVertex);
	int pos2 = g.getvInfoIndex(eVertex);
	if (pos1 == -1 || pos2 == -1)
		throw graphError("minimumPath�����㷨��ͼ���ʵĵ㲻��ͼ��");

	for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied)
	{
		g.vInfo[i].color = vertexInfo<T>::WHITE;
		g.vInfo[i].dataValue = INFINITY;
	}

	// ��װͷ��㵽���ȶ�����
	miniInfo vertexData;
	miniPQ<miniInfo, less<miniInfo> > minPathPQ;

	vertexData.endV = pos1;
	vertexData.pathWeight = 0;
	g.vInfo[pos1].dataValue = 0;
	g.vInfo[pos1].parent = pos1;

	bool foundMinPath = false;
	// ��ʼ�������ȶ��У�ֱ������Ϊ��
	while (!minPathPQ.empty())
	{
		vertexData = minPathPQ.top();
		minPathPQ.pop();

		int cur = vertexData.endV;
		g.vInfo[cur].color = vertexInfo<T>::BLACK;

		// ����ҵ�Ŀ�꣬ �˳�
		if (cur == pos2)
		{
			foundMinPath = true;
			break;
		}

		if (g.vInfo[cur].color != vertexInfo<T>::BLACK)
		{
			g.vInfo[cur].color = vertexInfo<T>::BLACK;

			// �����ڱ�
			set<neighbor>& edgeSet = g.vInfo[i].edges;
			set<neighbor>::iterator setIter;
			for (setIter = edgeSet.begin(); setIter != edgeSet.end(); ++setIter)
			{
				int newMinWeight = 0;
				int dest = setIter->dest;

				if (g.vInfo[dest].color == vertexInfo<T>::WHITE)	// ���dest��û���з��ʽ���
				if ((newMinWeight = setIter->weight + g.vInfo[cur].dataValue) < g.vInfo[dest].dataValue)	// �µ�ȨֵС��dest��ԭ����Ȩֵ��Ϣ
				{
					// ���½�����Ϣ�� ����Ȩֵ���͸��ڵ���Ϣ�� �������
					vertexData.endV = dest;
					vertexData.pathWeight = newMinWeight;

					// �������Ԫ�ص���Ϣ
					g.vInfo[dest].parent = cur;
					g.vInfo[dest].dataValue = newMinWeight;

					minPathPQ.push(vertexData);
				}
			}	// end �߼�����for
		}	// end if(color != BlACK)
	}	// end while(empty)

	path.erase(path.begin(), path.end());

	// �����ҵ����·�������
	// * ����ȡ��·���� ��Ȩֵ
	if (foundMinPath)
	{
		cur = pos2;
		while (cur != pos1)
		{
			path.push_front(g.vInfo[cur].vtxMapLoc->first);	//  ����ǰ���������·��
			cur = g.vInfo[cur].parent;
		}
		path.push_front(sVertex);
		returnValue = g.vInfo[pos2].dataValue;
	}

	return returnValue;
}

// ���·��
friend int shortestPath(graph<T>& g, const T& sVertex, const T& eVertex, list<T>& path)
{
	// �жϵ��Ƿ���ͼ��
	int pos1 = g.getvInfoIndex(sVertex);
	int pos2 = g.getvInfoIndex(eVertex);
	if (pos1 == -1 || pos2 == -1)
		throw graphError("minimumPath�����㷨��ͼ���ʵĵ㲻��ͼ��");

	// ���ó�ʼ��Ϣ
	bool foundShortestPath = false;
	for (int i = 0; i < g.vInfo.size(); ++i)
	{
		g.vInfo[i].color = vertexInfo<T>::WHITE;
		g.vInfo[i].dataValue = 0;
	}

	// ��װ��Ԫ��
	queue<int> visitQueue;

	g.vInfo[pos1].dataValue = 0;
	g.vInfo[pos1].parent = pos1;

	visitQueue.push(pos1);

	// ѭ��������У� ���·��ʵ���ÿ��Ԫ�ص�����ֵ�� ��¼���ʹ���
	while (!visitQueue.empty() && !foundShortestPath)
	{
		int cur = visitQueue.top();
		visitQueue.pop();

		// ����ҵ��˳�
		if (cur == pos2)
			foundShortestPath = true;
		else
		{
			if (g.vInfo[cur].color != vertexInfo<T>::BLACK)
			{
				g.vInfo[cur].color = vertexInfo<T>::BLACK;

				// ���ʱ߼�
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
	//	�������·���� ����
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

// ��С������
friend int minSpanTree(graph<T>& g, graph<T>& MST)
{
	minInfo vertexData;
	miniPQ<miniInfo, less<miniInfo> > minSpanTreePQ;
	int pos_sVertex = -1;

	// ��¼������Ϣ
	int minSpanTreeWeight = 0;
	int minSpanTreeSize = 0;

	// ��ʼ��Ϣ	
	for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied)
	{
		if (pos_sVertex = -1)
			pos_sVertex = i;
		g.vInfo[i].color = vertexInfo<T>::WHITE;
		g.vInfo[i].dataValue = INFINITY;
	}

	// ��װ��Ԫ��
	vertexData.endV = pos_sVertex;
	vertexData.pathWeight = 0;
	g.vInfo[pos_sVertex].parent = pos_sVertex;
	g.vInfo[pos_sVertex].dataValue = 0;

	minSpanTreePQ.push(vertexData);

	// �������ȶ��У� ���¸����ĵ�����ԣ� ��¼���ʹ��̣�
	while (!minSpanTreePQ.empty())
	{
		vertexData = minSpanTreePQ.top();
		minSpanTreePQ.pop();

		int cur = vertexData.endV;

		if (g.vInfo[cur].color != vertexInfo<T>::BLACK)
		{
			// ����������Ϣ
			minSpanTreeSize++;
			minSpanTreeWeight += vertexData.pathWeight;
			// ����������Ѿ���ɣ� ����ѭ��
			if (minSpanTreeSize == g.numVertices)
				break;

			g.vInfo[cur].color = vertexInfo<T>::BLACK;
			// �����ڱ߼�
			set<neighbor>& edgeSet = g.vInfo[cur].edges;
			set<neighbor>::iterator setIter;
			for (setIter = edgeSet.begin(); setIter != edgeSet.end(); ++setIter)
			{
				int dest = setIter->dest;
				// ��Ϊ���ʵ��ڱ߼��뵽���ȶ�����
				if (g.vInfo[dest].color == vertexInfo<T>::WHITE)
				if (setIter->weight < g.vInfo[dest].dataValue)
				{
					vertexData.endV = dest;
					vertexData.pathWeight = setIter->weight;
					g.vInfo[dest].parent = cur;
					g.vInfo[dest].dataValue = setIter->weight;
				}
			} // end for�������ڱߣ�
		}	// end if (û�з��ʣ�
	}	// end while (�ǿ�)

	// �����С����������Ϣ
	MST.clear();

	// �õ���С������
	for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied)
	{
		MST.insertVertex(g.vInfo[i].vtxMapLoc->first);
	}

	// ������С�������ı�
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


// �ж�ͼ���Ƿ��޻�

friend bool acyclic(graph<T>& g)
{
	// ��ȱ���������
	list<T> dfsList;

	// ��ʼ��׼������
	for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied)
		g.vInfo[i].color = vertexInfo<T>::WHITE;

	try
	{
		// ����������ȷ�ʽ�ж��Ƿ��л�
		for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied && g.vInfo[i].color == vertexInfo<T>::WHITE)
			dfsVisit(g, g.vInfo[i].vtxMapLoc->first, dfsList, true);
	}
	catch (const graphError& )
	{			// ����ͼ�л�������� ����ֵ
		return false;
	}
	return true;
}

// ��������б���ͼ, ���õݹ�ķ�ʽʵ��ͼ��������ȷ��ʣ� ��ͼ�г��ֻ�ʱ�� �׳�ͼ�쳣e
private:
	friend void dfsVisit(graph<T>& g, const T& sVertex, list<T>& dfsList,
		bool checkForCycle)
	{
		// ��ʼ��¼������ 
		set<neighbor>::iterator setIter;
		vector<vertexInfo<T> >& vlist = g.vInfo;

		// ������Ԫ��
		int pos = g.getvInfoIndex(sVertex);
		if (pos == -1)
			throw graphError("dfsvisit(); ������ͼ����һ��������ͼ�еĵ�");

		vlist[pos].color = vertexInfo<T>::GRAY;	// ��ǵ����ڴ��ڷ���״̬

		// �жϣ� ���õݹ�ķ�ʽ������һ��Ԫ�أ� �����ֻ�ʱ�׳��쳣
		set<neighbor>& edgeSet = vlist[pos].edges;
		for (setIter = edgeSet.begin(); setIter != edgeSet.end(); ++setIter)
		{
			if (vlist[setIter->dest].color == vertexInfo<T>::WHITE)
			{
				dfsVisit(g, g.vInfo[setIter->dest].vtxMapLoc->first, dfsList, checkForCycle);
			}
			else if (vlist[setIter->dest].color == vertexInfo<T>::GRAY && checkForCycle)
				throw graphError("ͼ�г��ֻ��нṹ");

			// ��¼���ʵ�
			vlist[pos].color = vertexInfo<T>::BLACK;
			dfsList.push_front(vlist[pos].vtxMapLoc->first);
		}
	}
public:
	// �������
	friend void dfs(graph<T>& g, list<T>& dfsList)
	{
		// ��ʼ��������Ϣ
		for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied)
			g.vInfo[i].color = vertexInfo<T>::WHITE;

		// ���ù�����ȵķ�ʽ����ͼ��ÿ����
		for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied && g.vInfo[i].color == vertexInfo<T>::WHITE)
		{
			dfsVisit(g, g.vInfo[i].vtxMapLoc->first, dfsList, false);
		}
	}

	friend  void topologicalSort(graph<T>& g, list<T>& tlist)
	{
		// ��ʼ������
		tlist.erase(tlist.begin(), tlist.end());

		// ׼������
		for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied)
		{
			g.vInfo[i].color = vertexInfo<T>::WHITE;
		}

		// ����ͼ�е�ÿ���㣬 ������������ �����ֻ�ʱ�� �׳��쳣
		for (int i = 0; i < g.vInfo.size(); ++i) if (g.vInfo[i].occupied && g.vInfo[i].color == vertexInfo<T>::WHITE)
		{
			try
			{
				dfsVisit(g, g.vInfo[i].vtxMapLoc->first, tlist, true);
			}
			catch (graphError& )
			{
				// �ܺõĴ��� ���ﲻ��Ҫ���쳣������ �����׳���Ϊ׼ȷ����Ϣ
				throw graphError("topologicalSort(), ����һ���л���ͼ�� ������������ѭ��");
			}
		}
	}

	friend graph<T> transpose(graph<T>& g)
	{
		// ��ʼ������
		graph<T> gt = g;

		// ׼������
		for (int i = 0; i < gt.vInfo.size(); ++i) if (g.vInfo[i].occupied)
		{
			gt.vInfo[i].edges.erase(gt.vInfo[i].edges.begin(), gt.vInfo[i].edges.end());
			gt.vInfo[i].inDegree = 0;
		}

		// ��ʼ���ʱ���,����ԭͼ�� �õ��µ�ͼ
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

		// �����µ�ͼ
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