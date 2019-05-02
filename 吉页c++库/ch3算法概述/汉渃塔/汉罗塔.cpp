/*
	2014��4��12�� 15:19:58
	��ҳ
	���ܣ� ������������������Ľ������
*/

#include <iostream>
#include <string>

using namespace std;

void hanoi(int n, const string& initNeedle, const string& endNeedle, const string& tempNeedle);

int main()
{
	// ���ӵ����ƣ� ������������
	int n;
	string beginNeedle = "A",
		middleNeedle = "B",
		endNeedle = "C";

	cout << "���������ӵ���Ŀ�� ";
	cin >> n;
	cout << "Ҫ������������� " << n << endl;
	hanoi(n, beginNeedle, endNeedle, middleNeedle);

	system("pause");

	return 0;

}

void hanoi(int n, const string& initNeedle, const string& endNeedle, const string& tempNeedle)
{
	if (0 == n)	//	�����һ�����Ӵ���ʼ���ƶ���Ŀ�ĸ�
		cout << "move " << initNeedle << "  to " << endNeedle << endl;
	else
	{
		// ��n -1 �����Ӵ��� endNeedle Ϊ��ʱ�ˣ� ��initNeedle�ƶ���tempNeedle
		hanoi(n - 1, initNeedle, tempNeedle, endNeedle);

		//	�����һ�����Ӵ���ʼ���ƶ���Ŀ�ĸˣ�
		cout << "move " << initNeedle << "  to " << endNeedle << endl;

		// ��n -1 �����Ӵ��� initNeedle Ϊ��ʱ�ˣ� ��tempNeedle�ƶ���endNeedle
		hanoi(n - 1, tempNeedle, endNeedle, initNeedle);
	}

	return;
}