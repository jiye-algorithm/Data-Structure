#include <iostream>
#include <vector>

using namespace std;

void search(vector<int>& va, int b)
{
	bool exist = false;

	int size = va.size();
	for (int i = 0; i < size; ++i)
	{
		if (va[i] == b)
		{
			exist = true;
			break;
		}
	}

	if ( false == exist)
		va.push_back(b);
}

int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[5] = { 1, 2, 3, 4, 6 };

	vector<int> va(a, a + 5);
	vector<int> vb(b, b + 5);

	for (size_t i = 0; i < vb.size(); ++i)
	{
		search(va, vb[i]);
	}

	for (size_t i = 0; i < va.size(); ++i)
	{
		cout << va[i] << "   ";
	}
	cout << endl;


	system("pause");
	return 0;
}

