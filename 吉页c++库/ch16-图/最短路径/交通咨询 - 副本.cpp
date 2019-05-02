#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

#include "m_list.cpp"

typedef int Vertex;
const int train_size = 100;
const int plane_size = 100;

struct train
{
	Vertex source;
	Vertex destination;
	bool state;//表火车状态，在途中为假，在站中为真
	//默认数组下表为火车号
	//默认速度为1千米/小时
};

struct plane
{
	Vertex source;
	Vertex destination;
	bool state;//表飞机状态，在途中为假，在站中为真
	//默认数组下表为飞机号
	//默认速度为1千米/小时
};

class train_table
{
public:
	train_table();   //设置火车静态数据
	void print();   //显示火车班次情况
	void arrive(int &num);  //火车到站
	void leave(int &num);  //火车离开
	bool get_number(Vertex source, Vertex destination, int &num);//得到火车号
	void add_train(Vertex source, Vertex destination);//添加火车
	void delete_train(int num);//删除火车
	void reform_train(Vertex source, Vertex destination, int num, bool s);//修改某班次火车
private:
	train tra[train_size];
	int count;
};

class plane_table
{
public:
	plane_table();   //设置飞机静态数据
	void print();   //显示飞机班次情况
	void arrive(int &num);  //飞机到站
	void leave(int &num);  //飞机离开
	bool get_number(Vertex source, Vertex destination, int &num);//得到飞机号
	void add_plane(Vertex source, Vertex destination);//添加飞机
	void delete_plane(int num);//删除飞机
	void reform_plane(Vertex source, Vertex destination, int num, bool s);//修改某班次飞机
private:
	plane pla[plane_size];
	int count;
};

plane_table::plane_table()
{
	pla[0].source = pla[1].source = pla[2].source = pla[3].source = 0;
	pla[4].source = pla[5].source = pla[6].source = pla[7].source = 1;
	pla[8].source = pla[9].source = pla[10].source = pla[11].source = 2;
	pla[12].source = pla[13].source = pla[14].source = pla[15].source = 3;
	pla[16].source = pla[17].source = pla[18].source = pla[19].source = 4;
	pla[0].destination = pla[8].destination = pla[12].destination = pla[16].destination = 1;
	pla[1].destination = pla[5].destination = pla[13].destination = pla[17].destination = 2;
	pla[2].destination = pla[6].destination = pla[10].destination = pla[18].destination = 3;
	pla[3].destination = pla[7].destination = pla[11].destination = pla[15].destination = 4;
	pla[4].destination = pla[9].destination = pla[14].destination = pla[19].destination = 0;
	count = 20;
	for (int i = 0; i < count; i++)
		pla[i].state = true;
}

bool plane_table::get_number(Vertex source, Vertex destination, int &num)
{
	bool temp = true;
	for (int i = 0; i < count; i++)
	{
		if (pla[i].source == source&&pla[i].destination == destination&&pla[i].state == true)
		{
			num = i;
			break;
		}
		else
			temp = false;
	}
	return temp;
}

void plane_table::add_plane(Vertex source, Vertex destination)
{
	count++;
	pla[count].source = source;
	pla[count].destination = destination;
	pla[count].state = true;
}

void plane_table::reform_plane(Vertex source, Vertex destination, int num, bool s)
{
	pla[num].source = source;
	pla[num].destination = destination;
	pla[num].state = s;
}


void plane_table::print()
{
	cout << "现在的飞机航班状况如下:" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "航班: " << i << "出发地: " << pla[i].source << "目的地: " << pla[i].destination;
		if (pla[i].state) cout << "状态:  在站中" << endl;
		else  cout << "状态:  已离开" << endl;
	}
}
void plane_table::delete_plane(int num)
{
	for (int i = num; i < count - 1; i++)
	{
		pla[i].destination = pla[i + 1].destination;
		pla[i].source = pla[i + 1].source;
		pla[i].state = pla[i + 1].state;
	}
	count--;
}
void plane_table::arrive(int &num)
{
	Vertex w;
	w = pla[num].destination;
	pla[w].destination = pla[w].source;
	pla[w].source = w;
	pla[w].state = true;
}

void plane_table::leave(int &num)
{
	pla[num].state = false;
}

train_table::train_table()
{
	tra[0].source = tra[1].source = tra[2].source = tra[3].source = 0;
	tra[4].source = tra[5].source = tra[6].source = tra[7].source = 1;
	tra[8].source = tra[9].source = tra[10].source = tra[11].source = 2;
	tra[12].source = tra[13].source = tra[14].source = tra[15].source = 3;
	tra[16].source = tra[17].source = tra[18].source = tra[19].source = 4;
	tra[0].destination = tra[8].destination = tra[12].destination = tra[16].destination = 1;
	tra[1].destination = tra[5].destination = tra[13].destination = tra[17].destination = 2;
	tra[2].destination = tra[6].destination = tra[10].destination = tra[18].destination = 3;
	tra[3].destination = tra[7].destination = tra[11].destination = tra[15].destination = 4;
	tra[4].destination = tra[9].destination = tra[14].destination = tra[19].destination = 0;
	count = 20;
	for (int i = 0; i < count; i++)
		tra[i].state = true;
}

bool train_table::get_number(Vertex source, Vertex destination, int &num)
{
	bool temp = true;
	for (int i = 0; i < count; i++)
	{
		if (tra[i].source == source&&tra[i].destination == destination&&tra[i].state == true)
		{
			num = i;
			break;
		}
		else
			temp = false;
	}
	return temp;
}

void train_table::add_train(Vertex source, Vertex destination)
{
	count++;
	tra[count].source = source;
	tra[count].destination = destination;
	tra[count].state = true;
}

void train_table::reform_train(Vertex source, Vertex destination, int num, bool s)
{
	tra[num].source = source;
	tra[num].destination = destination;
	tra[num].state = s;
}


void train_table::print()
{
	cout << "现在的火车班次状况如下:" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "班次: " << i << "出发地: " << tra[i].source << "目的地: " << tra[i].destination;
		if (tra[i].state) cout << "状态:  在站中" << endl;
		else  cout << "状态:  已离开" << endl;
	}
}
void train_table::delete_train(int num)
{
	for (int i = num; i < count - 1; i++)
	{
		tra[i].destination = tra[i + 1].destination;
		tra[i].source = tra[i + 1].source;
		tra[i].state = tra[i + 1].state;
	}
	count--;
}
void train_table::arrive(int &num)
{
	Vertex w;
	w = tra[num].destination;
	tra[w].destination = tra[w].source;
	tra[w].source = w;
	tra[w].state = true;
}

void train_table::leave(int &num)
{
	tra[num].state = false;
}

const int infinity = 1000000;
template <class Weight, int graph_size>
class Digraph
{
public:
	Digraph();
	void out()const;//城市代码显示
	void state_data();   //设置城市静态数据
	void write()const;
	int get_count()const;
	void add();   //添加一个城市
	void rewrite();    //修改城市间信息
	void delete_operator();    //删除某个城市
	void write_distance()const;
	void write_price_train()const;
	void write_price_plane()const;
	void set_distance(Vertex source, Weight distance[])const;
	List<Vertex> set_shortest_of_two(Vertex source, Vertex destination, List<Vertex>& ld)const; //得到最短路径
	List<Vertex> set_minmoney_train(Vertex source, Vertex destination, List<Vertex>& ld)const;    //得到坐火车最省钱路径
	List<Vertex> set_minmoney_plane(Vertex source, Vertex destination, List<Vertex>& ld)const;    //得到乘飞机最省钱路径
	List<Vertex> set_mintime_train(Vertex source, Vertex destination, List<Vertex>& ld)const;    //得到坐火车最省时间路径
	List<Vertex> set_mintime_plane(Vertex source, Vertex destination, List<Vertex>& ld)const;    //得到坐飞机最省时间路径
	Weight get_distance(Vertex source, Vertex destination)const;    //得到source到dstination最短路径的值
	string name[graph_size];
protected:
	int count;
	Weight train_adjacency[graph_size][graph_size];//火车票价
	Weight plane_adjacency[graph_size][graph_size];  //飞机票价
	Weight distance_adjacency[graph_size][graph_size];//距离（千米）
};

template <class Weight, int graph_size>
Weight Digraph<Weight, graph_size>::get_distance(Vertex source, Vertex destination)const
{
	Weight distance;
	Weight distance[count];
	set_distance(Vertex source, Weight distance[]);
	distance = distance[destination];
	return distance;
}

template <class Weight, int graph_size>
void Digraph<Weight, graph_size>::state_data()
{
	for (int i = 0; i < graph_size; i++)
	{
		for (int j = 0; j < graph_size; j++)
		{
			train_adjacency[i][j] = train_adjacency[j][i] = infinity;
			plane_adjacency[i][j] = plane_adjacency[j][i] = infinity;
			distance_adjacency[i][j] = distance_adjacency[j][i] = infinity;

		}
	}
	name[0] = "beijing";
	name[1] = "shanghai";
	name[2] = "guangzhou";
	name[3] = "xian";
	name[4] = "qingdao";
	distance_adjacency[0][4] = distance_adjacency[4][0] = 2;
	distance_adjacency[0][1] = distance_adjacency[1][0] = 5;
	distance_adjacency[0][2] = distance_adjacency[2][0] = 3;
	distance_adjacency[1][2] = distance_adjacency[2][1] = 1;
	distance_adjacency[2][3] = distance_adjacency[3][2] = 2;
	distance_adjacency[1][3] = distance_adjacency[3][1] = 6;
	distance_adjacency[2][4] = distance_adjacency[4][2] = 10;
	distance_adjacency[4][3] = distance_adjacency[3][4] = 4;
	distance_adjacency[1][4] = distance_adjacency[4][1] = 6;
	plane_adjacency[0][4] = plane_adjacency[4][0] = 500;
	plane_adjacency[0][1] = plane_adjacency[1][0] = 500;
	plane_adjacency[0][2] = plane_adjacency[2][0] = 430;
	plane_adjacency[1][2] = plane_adjacency[2][1] = 510;
	plane_adjacency[2][3] = plane_adjacency[3][2] = 600;
	plane_adjacency[1][3] = plane_adjacency[3][1] = 655;
	plane_adjacency[2][4] = plane_adjacency[4][2] = 510;
	plane_adjacency[4][3] = plane_adjacency[3][4] = 540;
	plane_adjacency[1][4] = plane_adjacency[4][1] = 600;
	train_adjacency[0][4] = train_adjacency[4][0] = 58;
	train_adjacency[0][1] = train_adjacency[1][0] = 50;
	train_adjacency[0][2] = train_adjacency[2][0] = 43;
	train_adjacency[1][2] = train_adjacency[2][1] = 51;
	train_adjacency[2][3] = train_adjacency[3][2] = 68;
	train_adjacency[1][3] = train_adjacency[3][1] = 65;
	train_adjacency[2][4] = train_adjacency[4][2] = 51;
	train_adjacency[4][3] = train_adjacency[3][4] = 54;
	train_adjacency[1][4] = train_adjacency[4][1] = 60;


}
template <class Weight, int graph_size>
void Digraph<Weight, graph_size>::out()const
{

	cout << "城市代码如下:" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << i << " : " << name[i] << endl;
	}
}
template <class Weight, int graph_size>
Digraph<Weight, graph_size>::Digraph()
{
	count = 5;
}
template <class Weight, int graph_size>
int Digraph<Weight, graph_size>::get_count()const
{
	return count;
}

template <class Weight, int graph_size>
void Digraph<Weight, graph_size>::rewrite()
{
	cout << "你要修改：1 城市名，2 城市间路程，3 城市间机票价格，4 城市间火车票价!" << endl;
	char c;
	cin >> c;
	int m;
	m = get_count();
	out();
	Vertex v, w;
	switch (c)
	{
	case '1':
		cout << "城市代码: ";
		cin >> v;
		cout << "您要改为: ";
		cin >> name[v];
		break;
	case '2':
		cout << "起始城市代码: ";
		cin >> v;
		cout << "目标城市代码: ";
		cin >> w;
		cout << "您要将距离改为: ";
		cin >> distance_adjacency[v][w];
		break;
	case '3':
		cout << "起始城市代码: ";
		cin >> v;
		cout << "目标城市代码: ";
		cin >> w;
		cout << "您要将机票价格改为: ";
		cin >> plane_adjacency[v][w];
		break;
	case '4':
		cout << "起始城市代码: ";
		cin >> v;
		cout << "目标城市代码: ";
		cin >> w;
		cout << "您要将火车票价改为: ";
		cin >> train_adjacency[v][w];
		break;
	}
}




template <class Weight, int graph_size>
void Digraph<Weight, graph_size>::delete_operator()
{
	out();
	Vertex v;
	cout << "你要删除的城市代码是: ";
	cin >> v;
	for (int i = 0; i < count; i++)
	{
		distance_adjacency[v][i] = distance_adjacency[i][v] = infinity;
		train_adjacency[v][i] = train_adjacency[i][v] = infinity;
		plane_adjacency[v][i] = plane_adjacency[i][v] = infinity;
	}
	count--;
}
template <class Weight, int graph_size>
void Digraph<Weight, graph_size>::add()
{
	out();
	cout << endl;
	cout << "请输入所添加城市名：";
	cin >> name[count++];
	cout << "请给出该城市可到达城市的代码及路程：（以:作为结束，以空格分开）" << endl;
	char c;
	do{
		Vertex w;
		c = cin.get();
		if ('0' <= c&&c <= '9')
		{
			w = c - '0';
			while ((c = cin.get()) >= '0'&&c <= '9')
				w = 10 * w + c - '0';
			Weight wt = c - '0';
			while ((c = cin.get()) >= '0'&&c <= '9')
				wt = 10 * wt + c - '0';
			distance_adjacency[count][w] = distance_adjacency[w][count] = wt;
		}
	} while (c != ':');
	cout << "请给出该城市可到达城市的代码及机票价格：（以:作为结束，以空格分开）" << endl;
	do{
		Vertex w;
		c = cin.get();
		if ('0' <= c&&c <= '9')
		{
			w = c - '0';
			while ((c = cin.get()) >= '0'&&c <= '9')
				w = 10 * w + c - '0';
			Weight wt = c - '0';
			while ((c = cin.get()) >= '0'&&c <= '9')
				wt = 10 * wt + c - '0';
			plane_adjacency[count][w] = plane_adjacency[w][count] = wt;
		}
	} while (c != ':');
	cout << "请给出该城市可到达城市的代码及火车票价：（以:作为结束，以空格分开）" << endl;
	do{
		Vertex w;
		c = cin.get();
		if ('0' <= c&&c <= '9')
		{
			w = c - '0';
			while ((c = cin.get()) >= '0'&&c <= '9')
				w = 10 * w + c - '0';
			Weight wt = c - '0';
			while ((c = cin.get()) >= '0'&&c <= '9')
				wt = 10 * wt + c - '0';
			train_adjacency[count][w] = train_adjacency[w][count] = wt;
		}
	} while (c != ':');


}

template <class Weight, int graph_size>
void Digraph<Weight, graph_size>::write()const
{
	write_distance();
	write_price_train();
	write_price_plane();
}
template <class Weight, int graph_size>
void Digraph<Weight, graph_size>::write_distance()const
{
	cout << "显示距离:" << endl;
	for (Vertex v = 0; v < count; v++)
	{
		cout << "城市:  " << name[v] << ":  ";
		for (Vertex w = 0; w < count; w++)
		{
			if (distance_adjacency[v][w] != infinity)
				cout << "(" << name[w] << "@" << distance_adjacency[v][w] << ")";
		}
		cout << endl;
	}
}
template <class Weight, int graph_size>
void Digraph<Weight, graph_size>::write_price_train()const
{
	cout << "显示火车票价:" << endl;
	for (Vertex v = 0; v < count; v++)
	{
		cout << "城市:  " << name[v] << ":  ";
		for (Vertex w = 0; w < count; w++)
		{
			if (train_adjacency[v][w] != infinity)
				cout << "(" << name[w] << "@" << train_adjacency[v][w] << ")";
		}
		cout << endl;
	}
}
template <class Weight, int graph_size>
void Digraph<Weight, graph_size>::write_price_plane()const
{
	cout << "显示飞机票价:" << endl;
	for (Vertex v = 0; v < count; v++)
	{
		cout << "城市:  " << name[v] << ":  ";
		for (Vertex w = 0; w < count; w++)
		{
			if (plane_adjacency[v][w] != infinity)
				cout << "(" << name[w] << "@" << plane_adjacency[v][w] << ")";
		}
		cout << endl;
	}
}
template <class Weight, int graph_size>
void Digraph<Weight, graph_size>::set_distance(Vertex source, Weight distance[])const
{
	Vertex v, w;
	bool found[graph_size];
	for (v = 0; v < count; v++)
	{
		found[v] = false;
		distance[v] = distance_adjacency[source][v];
	}
	found[source] = true;
	distance[source] = 0;
	for (int i = 0; i < count; i++)
	{
		Weight min = infinity;
		for (w = 0; w < count; w++)  if (!found[w])
		if (distance[w] < min)
		{
			v = w;
			min = distance[w];
		}
		found[v] = true;
		for (w = 0; w < count; w++)
		if (min + distance_adjacency[v][w] < distance[w])
			distance[w] = min + distance_adjacency[v][w];
	}
}

template <class Weight, int graph_size>
List<Vertex> Digraph<Weight, graph_size>::set_shortest_of_two(Vertex source, Vertex destination, List<Vertex>& ld)const
{
	Vertex v, w;
	// 记录最短路径
	List<Vertex> path;
	Weight distance[graph_size];
	bool found[graph_size];
	for (v = 0; v < count; v++)
	{
		found[v] = false;
		distance[v] = distance_adjacency[source][v];
	}
	found[source] = true;
	distance[source] = 0;
	path.insert(0, source);
	ld.insert(0, distance[source]);

	// 访问以取得权值最小的点
	while (true)
	{
		Weight min = infinity;
		for (w = 0; w < count; w++)  if (!found[w])
		{
			if (distance[w] < min)
			{
				min = distance[w];
				v = w;
			}
		}

		// 如果找到的点是目标点, 记录并跳出
		if (v == dest)
		{
			path.insert(0, v);
			ld.insert(0, distance[v]);
			break;
		}

		for (w = 0; w < count; w++)
		if (min + distance_adjacency[v][w] < distance[w])
			distance[w] = min + distance_adjacency[v][w];

		// 标记v的访问特性，并记录
		found[v] = true;
		path.insert(0, v);
		ld.insert(0, distance[v]);

	}

	return path;
}

template <class Weight, int graph_size>
List<Vertex> Digraph<Weight, graph_size>::set_minmoney_train(Vertex source, Vertex destination, List<Vertex>& ld)const
{
	Vertex v, w;
	int i;
	List<Vertex> path;
	Weight distance[graph_size];
	bool found[graph_size];
	for (v = 0; v < count; v++)
	{
		found[v] = false;
		distance[v] = train_adjacency[source][v];
	}
	found[source] = true;
	distance[source] = 0;
	path.insert(0, source);
	ld.insert(0, distance[source]);

	// 访问以取得权值最小的点
	while (true)
	{
		Weight min = infinity;
		for (w = 0; w < count; w++)  if (!found[w])
		{
			if (distance[w] < min)
			{
				min = distance[w];
				v = w;
			}
		}

		// 如果找到的点是目标点, 记录并跳出
		if (v == destination)
		{
			path.insert(0, v);
			ld.insert(0, distance[v]);
			break;
		}

		for (w = 0; w < count; w++)
		if (!found[w] && min + train_adjacency[v][w] < distance[w])
			distance[w] = min + train_adjacency[v][w];

		// 标记v的访问特性，并记录
		found[v] = true;
		path.insert(0, v);
		ld.insert(0, distance[v]);

	}

	return path;
}

template <class Weight, int graph_size>
List<Vertex> Digraph<Weight, graph_size>::set_minmoney_plane(Vertex source, Vertex destination, List<Vertex>& ld)const
{
	Vertex v, w;
	List<Vertex> path;
	Weight distance[graph_size];
	bool found[graph_size];
	for (v = 0; v < v; v++)
	{
		found[v] = false;
		distance[v] = plane_adjacency[source][v];
	}
	found[source] = true;
	distance[source] = 0;
	path.insert(0, source);
	ld.insert(0, distance[source]);

	// 访问以取得权值最小的点
	while (true)
	{
		Weight min = infinity;
		for (w = 0; w < count; w++)  if (!found[w])
		{
			if (distance[w] < min)
			{
				min = distance[w];
				v = w;
			}
		}

		// 如果找到的点是目标点, 记录并跳出
		if (v == destination)
		{
			path.insert(0, v);
			ld.insert(0, distance[v]);
			break;
		}

		for (w = 0; w < count; w++)
		if (!found[w] && min + train_adjacency[v][w] < distance[w])
			distance[w] = min + plane_adjacency[v][w];

		// 标记v的访问特性，并记录
		found[v] = true;
		path.insert(0, v);
		ld.insert(0, distance[v]);

	}

	return path;
}

template <class Weight, int graph_size>
List<Vertex> Digraph<Weight, graph_size>::set_mintime_train(Vertex source, Vertex destination, List<Vertex>& ld)const
{
	Vertex v, w;
	List<Vertex> path;
	Weight distance[graph_size];
	bool found[graph_size];
	for (v = 0; v < count; v++)
	{
		found[v] = false;
		distance[v] = distance_adjacency[source][v];
	}
	found[source] = true;
	distance[source] = 0;
	path.insert(0, source);
	ld.insert(0, distance[source]);

	// 访问以取得权值最小的点
	while (true)
	{
		Weight min = infinity;
		for (w = 0; w < count; w++)  if (!found[w])
		{
			if (distance[w] < min)
			{
				min = distance[w];
				v = w;
			}
		}

		// 如果找到的点是目标点, 记录并跳出
		if (v == destination)
		{
			path.insert(0, v);
			ld.insert(0, distance[v]);
			break;
		}

		for (w = 0; w < count; w++)
		if (min + (distance_adjacency[v][w] + 1) < distance[w])
			distance[w] = min + (distance_adjacency[v][w] + 1);

		// 标记v的访问特性，并记录
		found[v] = true;
		path.insert(0, v);
		ld.insert(0, distance[v]);

	}

	return path;
}

template <class Weight, int graph_size>
List<Vertex> Digraph<Weight, graph_size>::set_mintime_plane(Vertex source, Vertex destination, List<Vertex>& ld)const
{
	Vertex v, w;
	List<Vertex> path;
	Weight distance[graph_size];
	bool found[graph_size];
	for (v = 0; v < count; v++)
	{
		found[v] = false;
		distance[v] = distance_adjacency[source][v];
	}
	found[source] = true;
	distance[source] = 0;
	path.insert(0, source);
	ld.insert(0, distance[source]);

	// 访问以取得权值最小的点
	while (true)
	{
		Weight min = infinity;
		for (w = 0; w < count; w++)  if (!found[w])
		{
			if (distance[w] < min)
			{
				min = distance[w];
				v = w;
			}
		}

		// 如果找到的点是目标点, 记录并跳出
		if (v == destination)
		{
			path.insert(0, v);
			ld.insert(0, distance[v]);
			break;
		}

		for (w = 0; w < count; w++)
		if (min + (distance_adjacency[v][w] + 2) < distance[w])
			distance[w] = min + (distance_adjacency[v][w] + 2);

		// 标记v的访问特性，并记录
		found[v] = true;
		path.insert(0, v);
		ld.insert(0, distance[v]);

	}

	return path;
}

int main()
{
	Digraph<int, 50>  transport;
	transport.state_data();
	train_table  table1;
	plane_table table2;
	char c;
	int i;
	do
	{
		cout << "-------------------------------------" << endl
			<< "      欢迎使用该交通咨询系统!        " << endl
			<< "          1--编辑城市信息            " << endl
			<< "          2--编辑火车班次            " << endl
			<< "          3--编辑飞机航班            " << endl
			<< "          4--输出已存储图的信息      " << endl
			<< "          5--选择最优决策            " << endl
			<< "          6--退出系统                " << endl
			<< "-------------------------------------" << endl
			<< "请选择操作:" << endl;
		cin >> c;
		switch (c)
		{
		case '1':
			cout << "-------------------------------------" << endl
				<< "          1--添加城市                " << endl
				<< "          2--修改城市信息            " << endl
				<< "          3--删除城市                " << endl
				<< "-------------------------------------" << endl
				<< "请选择操作:" << endl;
			int ce;
			cin >> ce;
			if (ce == 1)  transport.add();
			if (ce == 2)  transport.rewrite();
			if (ce == 3)  transport.delete_operator();
			break;
		case '2':
			cout << "------------------------------------" << endl
				<< "       1--添加火车班次              " << endl
				<< "       2--修改某班次火车            " << endl
				<< "       3--删除某班次火车            " << endl
				<< "------------------------------------" << endl
				<< "请选择:";
			char z;
			cin >> z;
			if (z == '1')
			{
				transport.out();
				Vertex source, destination;
				cout << "输入出发点城市代码:";
				cin >> source;
				cout << "请输入终点城市代码:";
				cin >> destination;
				table1.add_train(source, destination);
			}
			if (z == '2')
			{
				int num, a;
				bool s;
				cout << "您要修改的火车班次是:";
				cin >> num;
				cout << "这趟火车的状态是: 1--到站，2--离开";
				cin >> a;
				if (a == 1)  s = true;
				if (a == 2)  s = false;
				transport.out();
				Vertex source, destination;
				cout << "输入该火车出发点城市代码:";
				cin >> source;
				cout << "请输入该火车终点城市代码:";
				cin >> destination;
				table1.reform_train(source, destination, num, s);
			}
			if (z == '3')
			{
				int num;
				cout << "您要删除的火车班次是";
				table1.print();
				cin >> num;
				table1.delete_train(num);
			}
		case '3':
			cout << "------------------------------------" << endl
				<< "       1--添加飞机航班              " << endl
				<< "       2--修改某航班飞机            " << endl
				<< "       3--删除某航班飞机            " << endl
				<< "------------------------------------" << endl
				<< "请选择:";
			char x;
			cin >> x;
			if (x == '1')
			{
				transport.out();
				Vertex source, destination;
				cout << "输入出发点城市代码:";
				cin >> source;
				cout << "请输入终点城市代码:";
				cin >> destination;
				table2.add_plane(source, destination);
			}
			if (x == '2')
			{
				int num, a;
				bool s;
				cout << "您要修改的飞机航班是:";
				cin >> num;
				cout << "这趟飞机的状态是: 1--到站，2--离开";
				cin >> a;
				if (a == 1)  s = true;
				if (a == 2)  s = false;
				transport.out();
				Vertex source, destination;
				cout << "输入该火车出发点城市代码:";
				cin >> source;
				cout << "请输入该火车终点城市代码:";
				cin >> destination;
				table2.reform_plane(source, destination, num, s);
			}
			if (x == '3')
			{
				int num;
				cout << "您要删除的飞机航班是";
				table2.print();
				cin >> num;
				table2.delete_plane(num);
			}
		case '4':
			transport.write();
			break;
		case '5':
			cout << "------------------------------------" << endl
				<< "         1--最省时间路线（火车）    " << endl
				<< "         2--最省时间路线（飞机）    " << endl
				<< "         3--最省资金路线（火车）    " << endl
				<< "         4--最省资金路线（飞机）    " << endl
				<< "------------------------------------" << endl
				<< "请选择:" << endl;
			char cel;
			cin >> cel;

			if (cel == '1')
			{
				List<Vertex> path, ld;
				transport.out();
				Vertex source, destination;
				cout << "输入出发点城市代码:";
				cin >> source;
				cout << "请输入终点城市代码:";
				cin >> destination;
				cout << "最优决策如下:";
				path = transport.set_minmoney_train(source, destination, ld);
				int next = infinity;
				cout << "最短路劲为： ";
				for (i = path.size() - 1; i > 0; --i)
				{
					path.retrieve(i, next);
					cout << next << "  ->  ";
				}
				// 输出最后一个元素
				path.retrieve(i, next);
				cout << next;
				cout << endl;
				cout << "对应的每个路劲前置为： ";
				next = infinity;
				for (i = ld.size() - 1; i > 0; --i)
				{
					ld.retrieve(i, next);
					cout << next << "  ->  ";
				}
				// 输出最后一个元素
				ld.retrieve(i, next);
				cout << next;
			}
			if (cel == '2')
			{
				List<Vertex> path, ld;
				transport.out();
				Vertex source, destination;
				cout << "输入出发点城市代码:";
				cin >> source;
				cout << "请输入终点城市代码:";
				cin >> destination;
				cout << "最优决策如下:";
				path = transport.set_minmoney_train(source, destination, ld);
				int next = infinity;
				cout << "最短路劲为： ";
				for (i = path.size() - 1; i > 0; --i)
				{
					path.retrieve(i, next);
					cout << next << "  ->  ";
				}
				// 输出最后一个元素
				path.retrieve(i, next);
				cout << next;
				cout << endl;
				cout << "对应的每个路劲前置为： ";
				next = infinity;
				for (i = ld.size() - 1; i > 0; --i)
				{
					ld.retrieve(i, next);
					cout << next << "  ->  ";
				}
				// 输出最后一个元素
				ld.retrieve(i, next);
			}
			if (cel == '3')
			{
				List<Vertex> path, ld;
				transport.out();
				Vertex source, destination;
				cout << "输入出发点城市代码:";
				cin >> source;
				cout << "请输入终点城市代码:";
				cin >> destination;
				cout << "最优决策如下:";
				path = transport.set_minmoney_train(source, destination, ld);
				int next = infinity;
				cout << "最短路劲为： ";
				for (i = path.size() - 1; i > 0; --i)
				{
					path.retrieve(i, next);
					cout << next << "  ->  ";
				}
				// 输出最后一个元素
				path.retrieve(i, next);
				cout << next;
				cout << endl;
				cout << "对应的每个路劲前置为： ";
				next = infinity;
				for (i = ld.size() - 1; i > 0; --i)
				{
					ld.retrieve(i, next);
					cout << next << "  ->  ";
				}
				// 输出最后一个元素
				ld.retrieve(i, next);
			}
			if (cel == '4')
			{
				List<Vertex> path, ld;
				transport.out();
				Vertex source, destination;
				cout << "输入出发点城市代码:";
				cin >> source;
				cout << "请输入终点城市代码:";
				cin >> destination;
				cout << "最优决策如下:";
				path = transport.set_minmoney_plane(source, destination, ld);
				int next = infinity;
				cout << "最短路劲为： ";
				for (i = path.size() - 1; i > 0; --i)
				{
					path.retrieve(i, next);
					cout << next << "  ->  ";
				}
				// 输出最后一个元素
				path.retrieve(i, next);
				cout << next;
				cout << endl;
				cout << "对应的每个路劲前置为： ";
				next = infinity;
				for (i = ld.size() - 1; i > 0; --i)
				{
					ld.retrieve(i, next);
					cout << next << "  ->  ";
				}
				// 输出最后一个元素
				ld.retrieve(i, next);
			}
		case '6':
			break;
		}

	} while (c > 0 && c < 7);

	cout << endl;
	system("pause");
	return 0;
}


