/*
	2014��5��19�� 18:30:06
	��ҳ
	���ܣ����ؼ���ʹ��
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
		// �������Ķ��ؼ�
	multiset<product> mp;
		// ����ÿ����˾��Ա���õ�
	pair<multiset<product>::iterator, multiset<product>::iterator >iterPair;

	product prodArr[] =
	{ product("Microsoft", "Visual C++"), product("Inprise", "C++ Builder"),
	product("Microsoft", "Word"), product("Ramsoft", "MAS"),
	product("Inprise", "J Builder"), product("Adobe", "Photoshop"),
	product("Microsoft", "Excel"), product("Adobe", "Illustrator") };

		// �������ؼ�
	int sise = sizeof(prodArr) / sizeof(product);
	mp.insert(prodArr, prodArr + sise);

		// ɸѡ��˾
	set<product> sp(prodArr, prodArr + sise);
	set<product>::iterator iter = sp.begin();
		// ����������ж��ؼ���Ԫ��
		// ��ʽ��  ��˾��:
	  //                    ��Ʒ1�� ��Ʒ2������
	while (iter != sp.end())
	{
		cout << endl << iter->getCompany() << ": " << endl;
		iterPair = mp.equal_range(*iter);
			// ����ÿ����˾�Ĳ�Ʒ
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



