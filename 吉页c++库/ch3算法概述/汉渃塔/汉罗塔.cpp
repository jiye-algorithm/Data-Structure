/*
	2014年4月12日 15:19:58
	吉页
	功能： 程序描述汉罗塔问题的解决过程
*/

#include <iostream>
#include <string>

using namespace std;

void hanoi(int n, const string& initNeedle, const string& endNeedle, const string& tempNeedle);

int main()
{
	// 盘子的名称， 便于描述问题
	int n;
	string beginNeedle = "A",
		middleNeedle = "B",
		endNeedle = "C";

	cout << "请输入盘子的数目： ";
	cin >> n;
	cout << "要解决的盘子数： " << n << endl;
	hanoi(n, beginNeedle, endNeedle, middleNeedle);

	system("pause");

	return 0;

}

void hanoi(int n, const string& initNeedle, const string& endNeedle, const string& tempNeedle)
{
	if (0 == n)	//	将最后一个盘子从起始杆移动到目的杆
		cout << "move " << initNeedle << "  to " << endNeedle << endl;
	else
	{
		// 把n -1 个盘子从以 endNeedle 为临时杆， 从initNeedle移动到tempNeedle
		hanoi(n - 1, initNeedle, tempNeedle, endNeedle);

		//	将最后一个盘子从起始杆移动到目的杆，
		cout << "move " << initNeedle << "  to " << endNeedle << endl;

		// 把n -1 个盘子从以 initNeedle 为临时杆， 从tempNeedle移动到endNeedle
		hanoi(n - 1, tempNeedle, endNeedle, initNeedle);
	}

	return;
}