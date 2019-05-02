#ifndef PERMUTE_FUNTIONS
#define PERMUTE_FUNTIONS

#include <iostream>
#include <vector>
#include <algorithm>

#include "y_util.h"

// output the list of all permutations of the
// integer values in the range [index,permList.size())
void permute(vector<int> permList, int index);


/************************************************************************/
/*							实现                                                                     */
/************************************************************************/


// output the list of all permutations of the
// integer values in the range [index,permList.size())
void permute(vector<int> permList, int index)
{
	int size = permList.size();
	
	if (index == size - 1)
		writeVector(permList);
	else
	{	
			// 对没有改变的序列输出
		permute(permList, index + 1);

		for (int i = index + 1; i < size; ++i)
		{
			swap(permList[index], permList[i]);
			permute(permList, index + 1);
		}
	}
}

#endif // !PERMUTE_FUNTIONS
