#include <iostream>

#include "../../include/y_dnode.h"
#include "../../include/y_nodel.h"
#include "../../include/y_random.h"

using namespace std;

void josephus(int n, int m)
{
	dnode<int>	*dList = new dnode<int>(),
						*cur;

	for (int i = 1; i <= n; ++i)
		insert(dList, i);

	cur = dList->next;

		/*������㣬 ɾ��m ������ǰһ��Ԫ�أ� ÿ�β�����֤ͷ��㲻����
			��֤�´ν������ʱ����������ͬ������, �������Ա�֤���ⱻ��ȷ�ؽ��
		*/
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cur = cur->next;

				// ��֤ͷ��㲻����
			if (cur == dList)
				cur = cur->next;
		}
			// ���ǰһ�����Ԫ��
		cout << "ɾ��Ԫ�� �� " << cur->prev->nodeValue << " ";
		if (dList == cur->prev)
			cur = cur->next;
		erase(cur->prev);
	}

	cout << endl << "����Ԫ��Ϊ�� " << cur->nodeValue << endl;

		// �ͷ���Դ
	delete cur;
	delete dList;
}

int main()
{
	int n, m;
	randomNumber rnd;

	cout << "���������Լɪ������������� ";
	cin >> n;

		// �������һ�� 1 ~  n ֮��������Ϊ����
	m = 1 + rnd.random(n);

	cout << "������Ĳ���Ϊ" << m << "���������Ԫ�ظ���Ϊ�� " << n << endl;
	cout << "�����Ƕ������������ " << endl;

	josephus(n, m);

	cout << endl <<  endl << "�������������� ллʹ�ñ������ ����֧����Զ�����ǲ��ߵĶ�����" << endl;
	system("pause");
}