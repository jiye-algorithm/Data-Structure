/*
	2014年5月19日 18:30:06
	吉页
	功能：多重集的使用
*/

#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <iomanip>

#include "../../include/y_prod.h"

using namespace std;

int main()
{
		// 保存对象的多重集
	multiset<product> mp;
		// 遍历每个公司成员是用到
	pair<multiset<product>::iterator, multiset<product>::iterator >iterPair;

	product prodArr[] =
	{ product("Microsoft", "Visual C++"), product("Inprise", "C++ Builder"),
	product("Microsoft", "Word"), product("Ramsoft", "MAS"),
	product("Inprise", "J Builder"), product("Adobe", "Photoshop"),
	product("Microsoft", "Excel"), product("Adobe", "Illustrator") };

		// 构建多重集
	int sise = sizeof(prodArr) / sizeof(product);
	mp.insert(prodArr, prodArr + sise);

		// 筛选公司
	set<product> sp(prodArr, prodArr + sise);
	set<product>::iterator iter = sp.begin();
		// 遍历输出所有多重集的元素
		// 格式：  公司名:
	  //                    产品1， 产品2。。。
	while (iter != sp.end())
	{
		cout << endl << iter->getCompany() << ": " << endl;
		iterPair = mp.equal_range(*iter);
			// 遍历每个公司的产品
		while (iterPair.first != iterPair.second)
		{
			cout << setw(10) << (iterPair.first)->getName();
			++(iterPair.first);
		}
		cout << endl;
		++iter;
	}

	system("pause");
}



