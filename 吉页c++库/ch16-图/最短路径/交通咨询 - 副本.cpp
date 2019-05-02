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
	bool state;//���״̬����;��Ϊ�٣���վ��Ϊ��
	//Ĭ�������±�Ϊ�𳵺�
	//Ĭ���ٶ�Ϊ1ǧ��/Сʱ
};

struct plane
{
	Vertex source;
	Vertex destination;
	bool state;//��ɻ�״̬����;��Ϊ�٣���վ��Ϊ��
	//Ĭ�������±�Ϊ�ɻ���
	//Ĭ���ٶ�Ϊ1ǧ��/Сʱ
};

class train_table
{
public:
	train_table();   //���û𳵾�̬����
	void print();   //��ʾ�𳵰�����
	void arrive(int &num);  //�𳵵�վ
	void leave(int &num);  //���뿪
	bool get_number(Vertex source, Vertex destination, int &num);//�õ��𳵺�
	void add_train(Vertex source, Vertex destination);//��ӻ�
	void delete_train(int num);//ɾ����
	void reform_train(Vertex source, Vertex destination, int num, bool s);//�޸�ĳ��λ�
private:
	train tra[train_size];
	int count;
};

class plane_table
{
public:
	plane_table();   //���÷ɻ���̬����
	void print();   //��ʾ�ɻ�������
	void arrive(int &num);  //�ɻ���վ
	void leave(int &num);  //�ɻ��뿪
	bool get_number(Vertex source, Vertex destination, int &num);//�õ��ɻ���
	void add_plane(Vertex source, Vertex destination);//��ӷɻ�
	void delete_plane(int num);//ɾ���ɻ�
	void reform_plane(Vertex source, Vertex destination, int num, bool s);//�޸�ĳ��ηɻ�
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
	cout << "���ڵķɻ�����״������:" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "����: " << i << "������: " << pla[i].source << "Ŀ�ĵ�: " << pla[i].destination;
		if (pla[i].state) cout << "״̬:  ��վ��" << endl;
		else  cout << "״̬:  ���뿪" << endl;
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
	cout << "���ڵĻ𳵰��״������:" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "���: " << i << "������: " << tra[i].source << "Ŀ�ĵ�: " << tra[i].destination;
		if (tra[i].state) cout << "״̬:  ��վ��" << endl;
		else  cout << "״̬:  ���뿪" << endl;
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
	void out()const;//���д�����ʾ
	void state_data();   //���ó��о�̬����
	void write()const;
	int get_count()const;
	void add();   //���һ������
	void rewrite();    //�޸ĳ��м���Ϣ
	void delete_operator();    //ɾ��ĳ������
	void write_distance()const;
	void write_price_train()const;
	void write_price_plane()const;
	void set_distance(Vertex source, Weight distance[])const;
	List<Vertex> set_shortest_of_two(Vertex source, Vertex destination, List<Vertex>& ld)const; //�õ����·��
	List<Vertex> set_minmoney_train(Vertex source, Vertex destination, List<Vertex>& ld)const;    //�õ�������ʡǮ·��
	List<Vertex> set_minmoney_plane(Vertex source, Vertex destination, List<Vertex>& ld)const;    //�õ��˷ɻ���ʡǮ·��
	List<Vertex> set_mintime_train(Vertex source, Vertex destination, List<Vertex>& ld)const;    //�õ�������ʡʱ��·��
	List<Vertex> set_mintime_plane(Vertex source, Vertex destination, List<Vertex>& ld)const;    //�õ����ɻ���ʡʱ��·��
	Weight get_distance(Vertex source, Vertex destination)const;    //�õ�source��dstination���·����ֵ
	string name[graph_size];
protected:
	int count;
	Weight train_adjacency[graph_size][graph_size];//��Ʊ��
	Weight plane_adjacency[graph_size][graph_size];  //�ɻ�Ʊ��
	Weight distance_adjacency[graph_size][graph_size];//���루ǧ�ף�
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

	cout << "���д�������:" << endl;
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
	cout << "��Ҫ�޸ģ�1 ��������2 ���м�·�̣�3 ���м��Ʊ�۸�4 ���м��Ʊ��!" << endl;
	char c;
	cin >> c;
	int m;
	m = get_count();
	out();
	Vertex v, w;
	switch (c)
	{
	case '1':
		cout << "���д���: ";
		cin >> v;
		cout << "��Ҫ��Ϊ: ";
		cin >> name[v];
		break;
	case '2':
		cout << "��ʼ���д���: ";
		cin >> v;
		cout << "Ŀ����д���: ";
		cin >> w;
		cout << "��Ҫ�������Ϊ: ";
		cin >> distance_adjacency[v][w];
		break;
	case '3':
		cout << "��ʼ���д���: ";
		cin >> v;
		cout << "Ŀ����д���: ";
		cin >> w;
		cout << "��Ҫ����Ʊ�۸��Ϊ: ";
		cin >> plane_adjacency[v][w];
		break;
	case '4':
		cout << "��ʼ���д���: ";
		cin >> v;
		cout << "Ŀ����д���: ";
		cin >> w;
		cout << "��Ҫ����Ʊ�۸�Ϊ: ";
		cin >> train_adjacency[v][w];
		break;
	}
}




template <class Weight, int graph_size>
void Digraph<Weight, graph_size>::delete_operator()
{
	out();
	Vertex v;
	cout << "��Ҫɾ���ĳ��д�����: ";
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
	cout << "����������ӳ�������";
	cin >> name[count++];
	cout << "������ó��пɵ�����еĴ��뼰·�̣�����:��Ϊ�������Կո�ֿ���" << endl;
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
	cout << "������ó��пɵ�����еĴ��뼰��Ʊ�۸񣺣���:��Ϊ�������Կո�ֿ���" << endl;
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
	cout << "������ó��пɵ�����еĴ��뼰��Ʊ�ۣ�����:��Ϊ�������Կո�ֿ���" << endl;
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
	cout << "��ʾ����:" << endl;
	for (Vertex v = 0; v < count; v++)
	{
		cout << "����:  " << name[v] << ":  ";
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
	cout << "��ʾ��Ʊ��:" << endl;
	for (Vertex v = 0; v < count; v++)
	{
		cout << "����:  " << name[v] << ":  ";
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
	cout << "��ʾ�ɻ�Ʊ��:" << endl;
	for (Vertex v = 0; v < count; v++)
	{
		cout << "����:  " << name[v] << ":  ";
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
	// ��¼���·��
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

	// ������ȡ��Ȩֵ��С�ĵ�
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

		// ����ҵ��ĵ���Ŀ���, ��¼������
		if (v == dest)
		{
			path.insert(0, v);
			ld.insert(0, distance[v]);
			break;
		}

		for (w = 0; w < count; w++)
		if (min + distance_adjacency[v][w] < distance[w])
			distance[w] = min + distance_adjacency[v][w];

		// ���v�ķ������ԣ�����¼
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

	// ������ȡ��Ȩֵ��С�ĵ�
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

		// ����ҵ��ĵ���Ŀ���, ��¼������
		if (v == destination)
		{
			path.insert(0, v);
			ld.insert(0, distance[v]);
			break;
		}

		for (w = 0; w < count; w++)
		if (!found[w] && min + train_adjacency[v][w] < distance[w])
			distance[w] = min + train_adjacency[v][w];

		// ���v�ķ������ԣ�����¼
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

	// ������ȡ��Ȩֵ��С�ĵ�
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

		// ����ҵ��ĵ���Ŀ���, ��¼������
		if (v == destination)
		{
			path.insert(0, v);
			ld.insert(0, distance[v]);
			break;
		}

		for (w = 0; w < count; w++)
		if (!found[w] && min + train_adjacency[v][w] < distance[w])
			distance[w] = min + plane_adjacency[v][w];

		// ���v�ķ������ԣ�����¼
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

	// ������ȡ��Ȩֵ��С�ĵ�
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

		// ����ҵ��ĵ���Ŀ���, ��¼������
		if (v == destination)
		{
			path.insert(0, v);
			ld.insert(0, distance[v]);
			break;
		}

		for (w = 0; w < count; w++)
		if (min + (distance_adjacency[v][w] + 1) < distance[w])
			distance[w] = min + (distance_adjacency[v][w] + 1);

		// ���v�ķ������ԣ�����¼
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

	// ������ȡ��Ȩֵ��С�ĵ�
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

		// ����ҵ��ĵ���Ŀ���, ��¼������
		if (v == destination)
		{
			path.insert(0, v);
			ld.insert(0, distance[v]);
			break;
		}

		for (w = 0; w < count; w++)
		if (min + (distance_adjacency[v][w] + 2) < distance[w])
			distance[w] = min + (distance_adjacency[v][w] + 2);

		// ���v�ķ������ԣ�����¼
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
			<< "      ��ӭʹ�øý�ͨ��ѯϵͳ!        " << endl
			<< "          1--�༭������Ϣ            " << endl
			<< "          2--�༭�𳵰��            " << endl
			<< "          3--�༭�ɻ�����            " << endl
			<< "          4--����Ѵ洢ͼ����Ϣ      " << endl
			<< "          5--ѡ�����ž���            " << endl
			<< "          6--�˳�ϵͳ                " << endl
			<< "-------------------------------------" << endl
			<< "��ѡ�����:" << endl;
		cin >> c;
		switch (c)
		{
		case '1':
			cout << "-------------------------------------" << endl
				<< "          1--��ӳ���                " << endl
				<< "          2--�޸ĳ�����Ϣ            " << endl
				<< "          3--ɾ������                " << endl
				<< "-------------------------------------" << endl
				<< "��ѡ�����:" << endl;
			int ce;
			cin >> ce;
			if (ce == 1)  transport.add();
			if (ce == 2)  transport.rewrite();
			if (ce == 3)  transport.delete_operator();
			break;
		case '2':
			cout << "------------------------------------" << endl
				<< "       1--��ӻ𳵰��              " << endl
				<< "       2--�޸�ĳ��λ�            " << endl
				<< "       3--ɾ��ĳ��λ�            " << endl
				<< "------------------------------------" << endl
				<< "��ѡ��:";
			char z;
			cin >> z;
			if (z == '1')
			{
				transport.out();
				Vertex source, destination;
				cout << "�����������д���:";
				cin >> source;
				cout << "�������յ���д���:";
				cin >> destination;
				table1.add_train(source, destination);
			}
			if (z == '2')
			{
				int num, a;
				bool s;
				cout << "��Ҫ�޸ĵĻ𳵰����:";
				cin >> num;
				cout << "���˻𳵵�״̬��: 1--��վ��2--�뿪";
				cin >> a;
				if (a == 1)  s = true;
				if (a == 2)  s = false;
				transport.out();
				Vertex source, destination;
				cout << "����û𳵳�������д���:";
				cin >> source;
				cout << "������û��յ���д���:";
				cin >> destination;
				table1.reform_train(source, destination, num, s);
			}
			if (z == '3')
			{
				int num;
				cout << "��Ҫɾ���Ļ𳵰����";
				table1.print();
				cin >> num;
				table1.delete_train(num);
			}
		case '3':
			cout << "------------------------------------" << endl
				<< "       1--��ӷɻ�����              " << endl
				<< "       2--�޸�ĳ����ɻ�            " << endl
				<< "       3--ɾ��ĳ����ɻ�            " << endl
				<< "------------------------------------" << endl
				<< "��ѡ��:";
			char x;
			cin >> x;
			if (x == '1')
			{
				transport.out();
				Vertex source, destination;
				cout << "�����������д���:";
				cin >> source;
				cout << "�������յ���д���:";
				cin >> destination;
				table2.add_plane(source, destination);
			}
			if (x == '2')
			{
				int num, a;
				bool s;
				cout << "��Ҫ�޸ĵķɻ�������:";
				cin >> num;
				cout << "���˷ɻ���״̬��: 1--��վ��2--�뿪";
				cin >> a;
				if (a == 1)  s = true;
				if (a == 2)  s = false;
				transport.out();
				Vertex source, destination;
				cout << "����û𳵳�������д���:";
				cin >> source;
				cout << "������û��յ���д���:";
				cin >> destination;
				table2.reform_plane(source, destination, num, s);
			}
			if (x == '3')
			{
				int num;
				cout << "��Ҫɾ���ķɻ�������";
				table2.print();
				cin >> num;
				table2.delete_plane(num);
			}
		case '4':
			transport.write();
			break;
		case '5':
			cout << "------------------------------------" << endl
				<< "         1--��ʡʱ��·�ߣ��𳵣�    " << endl
				<< "         2--��ʡʱ��·�ߣ��ɻ���    " << endl
				<< "         3--��ʡ�ʽ�·�ߣ��𳵣�    " << endl
				<< "         4--��ʡ�ʽ�·�ߣ��ɻ���    " << endl
				<< "------------------------------------" << endl
				<< "��ѡ��:" << endl;
			char cel;
			cin >> cel;

			if (cel == '1')
			{
				List<Vertex> path, ld;
				transport.out();
				Vertex source, destination;
				cout << "�����������д���:";
				cin >> source;
				cout << "�������յ���д���:";
				cin >> destination;
				cout << "���ž�������:";
				path = transport.set_minmoney_train(source, destination, ld);
				int next = infinity;
				cout << "���·��Ϊ�� ";
				for (i = path.size() - 1; i > 0; --i)
				{
					path.retrieve(i, next);
					cout << next << "  ->  ";
				}
				// ������һ��Ԫ��
				path.retrieve(i, next);
				cout << next;
				cout << endl;
				cout << "��Ӧ��ÿ��·��ǰ��Ϊ�� ";
				next = infinity;
				for (i = ld.size() - 1; i > 0; --i)
				{
					ld.retrieve(i, next);
					cout << next << "  ->  ";
				}
				// ������һ��Ԫ��
				ld.retrieve(i, next);
				cout << next;
			}
			if (cel == '2')
			{
				List<Vertex> path, ld;
				transport.out();
				Vertex source, destination;
				cout << "�����������д���:";
				cin >> source;
				cout << "�������յ���д���:";
				cin >> destination;
				cout << "���ž�������:";
				path = transport.set_minmoney_train(source, destination, ld);
				int next = infinity;
				cout << "���·��Ϊ�� ";
				for (i = path.size() - 1; i > 0; --i)
				{
					path.retrieve(i, next);
					cout << next << "  ->  ";
				}
				// ������һ��Ԫ��
				path.retrieve(i, next);
				cout << next;
				cout << endl;
				cout << "��Ӧ��ÿ��·��ǰ��Ϊ�� ";
				next = infinity;
				for (i = ld.size() - 1; i > 0; --i)
				{
					ld.retrieve(i, next);
					cout << next << "  ->  ";
				}
				// ������һ��Ԫ��
				ld.retrieve(i, next);
			}
			if (cel == '3')
			{
				List<Vertex> path, ld;
				transport.out();
				Vertex source, destination;
				cout << "�����������д���:";
				cin >> source;
				cout << "�������յ���д���:";
				cin >> destination;
				cout << "���ž�������:";
				path = transport.set_minmoney_train(source, destination, ld);
				int next = infinity;
				cout << "���·��Ϊ�� ";
				for (i = path.size() - 1; i > 0; --i)
				{
					path.retrieve(i, next);
					cout << next << "  ->  ";
				}
				// ������һ��Ԫ��
				path.retrieve(i, next);
				cout << next;
				cout << endl;
				cout << "��Ӧ��ÿ��·��ǰ��Ϊ�� ";
				next = infinity;
				for (i = ld.size() - 1; i > 0; --i)
				{
					ld.retrieve(i, next);
					cout << next << "  ->  ";
				}
				// ������һ��Ԫ��
				ld.retrieve(i, next);
			}
			if (cel == '4')
			{
				List<Vertex> path, ld;
				transport.out();
				Vertex source, destination;
				cout << "�����������д���:";
				cin >> source;
				cout << "�������յ���д���:";
				cin >> destination;
				cout << "���ž�������:";
				path = transport.set_minmoney_plane(source, destination, ld);
				int next = infinity;
				cout << "���·��Ϊ�� ";
				for (i = path.size() - 1; i > 0; --i)
				{
					path.retrieve(i, next);
					cout << next << "  ->  ";
				}
				// ������һ��Ԫ��
				path.retrieve(i, next);
				cout << next;
				cout << endl;
				cout << "��Ӧ��ÿ��·��ǰ��Ϊ�� ";
				next = infinity;
				for (i = ld.size() - 1; i > 0; --i)
				{
					ld.retrieve(i, next);
					cout << next << "  ->  ";
				}
				// ������һ��Ԫ��
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


