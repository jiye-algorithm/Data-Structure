#ifndef SET_FUNCTIONS
#define SET_FUNCTIONS

#include <set>

using namespace std;
	
	// 判断两个集合是否相等
template <typename T>
bool operator== (const set<T>& lhs, const set<T>& rhs);

	// 得到两个集合的并集
template <typename T>
set<T> operator+ (const set<T>& lhs, const set<T>& rhs);

	// 得到两个集合的交集
template <typename T>
set<T> operator* (const set<T>& lhs, const set<T>& rhs);

	// 得到两个集合的差集
template <typename T>
set<T> operator- (const set<T>& lhs, const set<T>& rhs);


/************************************************************************/
/*						函数实现                                                                     */
/************************************************************************/


	// 判断两个集合是否相等
template <typename T>
bool operator== (const set<T>& lhs, const set<T>& rhs)
{	
		// 如果两个集合元素个数不同， 一定不想等
	if (lhs.size() != rhs.size())
		return false;

	set<T>::iterator lhsIter = lhs.begin(),
							rhsIter = rhs.begin();
	while (lhsIter != lhs.end())
	{	
			// 如果发现两个集合中有不相等的元素， 退出
		if (*lhsIter != *rhsIter)
			break;

		lhsIter++; rhsIter++;
	}

		// 没有到结尾表示有不想等的元素
	if (rhsIter != rhs.end())
		return false;

	return true;
}

// 得到两个集合的并集
template <typename T>
set<T> operator+ (const set<T>& lhs, const set<T>& rhs)
{	
		// 准备一个结果集
	set<T> resultSet;

		// 准备两个集合的迭代器
	set<T>::iterator lhsIter = lhs.begin(),
							 rhsIter = rhs.begin();
		// 当两个集合都没有还有未遍历的元素时
	while (lhsIter != lhs.end() && rhsIter != rhs.end())
	{
			// 将遍历到的两个集合中较小的元素添加到结果集中
		if (*lhsIter < *rhsIter)		
		{
			resultSet.insert(*lhsIter);
			++lhsIter;
		}
		else if (*rhsIter < *lhsIter)
		{
			resultSet.insert(*rhsIter);
			++rhsIter;
		}
		else
		{
			resultSet.insert(*lhsIter);
			++lhsIter;  
			++rhsIter;
		}
	}

		// 添加还没有遍历到的元素
	while (lhsIter != lhs.end())
		resultSet.insert(*lhsIter++);
	while (rhsIter != rhs.end())
		resultSet.insert(*rhsIter++);

	return resultSet;
}

// 得到两个集合的交集
template <typename T>
set<T> operator* (const set<T>& lhs, const set<T>& rhs)
{
	// 准备一个结果集
	set<T> resultSet;

	// 准备两个集合的迭代器
	set<T>::iterator lhsIter = lhs.begin(),
						     	rhsIter = rhs.begin();
	// 当两个集合都没有还有未遍历的元素时
	while (lhsIter != lhs.end() && rhsIter != rhs.end())
	{
		// 将两个集合中相等的元素添加到结果集中
		if (*lhsIter < *rhsIter)
			++lhsIter;
		else if (*rhsIter < *lhsIter)
			++rhsIter;
		else
		{
			resultSet.insert(*lhsIter);
			++lhsIter;
			++rhsIter;
		}
	}

	return resultSet;
}

// 得到两个集合的差集
template <typename T>
set<T> operator- (const set<T>& lhs, const set<T>& rhs)
{
	// 准备一个结果集
	set<T> resultSet;

	// 准备两个集合的迭代器
	set<T>::iterator lhsIter = lhs.begin(),
								rhsIter = rhs.begin();
	// 当两个集合都没有还有未遍历的元素时
	while (lhsIter != lhs.end() && rhsIter != rhs.end())
	{
		// 将在 lhs集合中却不在 rhs集合中的元素添加到结果集中
		if (*lhsIter < *rhsIter)
		{
			resultSet.insert(*lhsIter);
			++lhsIter;
		}

		else if (*rhsIter < *lhsIter)
			++rhsIter;
		else
		{
			++lhsIter;
			++rhsIter;
		}
	}
	// 添加还没有遍历到的元素
	while (lhsIter++ != lhs.end())
		resultSet.insert(*lhsIter);

	return resultSet;
}

#endif // !SET_FUNCTIONS
