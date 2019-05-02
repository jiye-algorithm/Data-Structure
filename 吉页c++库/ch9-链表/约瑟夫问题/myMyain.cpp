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

		/*遍历结点， 删除m 步长的前一个元素， 每次操作保证头结点不参与
			保证下次解决问题时各参量有相同的条件, 这样可以保证问题被正确地解决
		*/
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cur = cur->next;

				// 保证头结点不参与
			if (cur == dList)
				cur = cur->next;
		}
			// 请出前一个结点元素
		cout << "删除元素 ： " << cur->prev->nodeValue << " ";
		if (dList == cur->prev)
			cur = cur->next;
		erase(cur->prev);
	}

	cout << endl << "最后的元素为： " << cur->nodeValue << endl;

		// 释放资源
	delete cur;
	delete dList;
}

int main()
{
	int n, m;
	randomNumber rnd;

	cout << "请输入参与约瑟夫问题的人数： ";
	cin >> n;

		// 随机生成一个 1 ~  n 之间数字作为步长
	m = 1 + rnd.random(n);

	cout << "您输入的步长为" << m << "参与问题的元素个数为： " << n << endl;
	cout << "下面是对问题的描述： " << endl;

	josephus(n, m);

	cout << endl <<  endl << "问题描述结束， 谢谢使用本软件， 您的支持永远是我们不竭的动力！" << endl;
	system("pause");
}