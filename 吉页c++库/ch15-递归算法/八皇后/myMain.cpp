/*
	2014年7月8日 19:59:16
	吉页
	功能：
		八皇后问题模拟解决
*/


#include <iostream>
#include <vector>

#ifdef true
#Pragma message(“EIGHT_QUEENS_GRAPHICAL”)
#endif 

// graphical display of 8-Queens solution
#include "E:\study\data stucture\data STL\DataStruct_CppSTL/include/d_gqueen.h"

using namespace std;

int main()
{
	int row;
	vector<int> queenList(8);
	chessBoard board;

	// enter a starting row for queen in column 0
	cout << "Enter row for queen in column 0: ";
	cin >> row;
	cout << endl;

	// see if there is a solution
	if (queens(queenList, row))
	{
		board.setQueens(queenList);
		// display the solution
		board.drawBoard();
	}
	else
		cout << "No solution" << endl;

	return 0;
}
