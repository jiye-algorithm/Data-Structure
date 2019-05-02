#ifndef SET_FUNCTIONS
#define SET_FUNCTIONS

#include <set>

using namespace std;
	
	// �ж����������Ƿ����
template <typename T>
bool operator== (const set<T>& lhs, const set<T>& rhs);

	// �õ��������ϵĲ���
template <typename T>
set<T> operator+ (const set<T>& lhs, const set<T>& rhs);

	// �õ��������ϵĽ���
template <typename T>
set<T> operator* (const set<T>& lhs, const set<T>& rhs);

	// �õ��������ϵĲ
template <typename T>
set<T> operator- (const set<T>& lhs, const set<T>& rhs);


/************************************************************************/
/*						����ʵ��                                                                     */
/************************************************************************/


	// �ж����������Ƿ����
template <typename T>
bool operator== (const set<T>& lhs, const set<T>& rhs)
{	
		// �����������Ԫ�ظ�����ͬ�� һ�������
	if (lhs.size() != rhs.size())
		return false;

	set<T>::iterator lhsIter = lhs.begin(),
							rhsIter = rhs.begin();
	while (lhsIter != lhs.end())
	{	
			// ������������������в���ȵ�Ԫ�أ� �˳�
		if (*lhsIter != *rhsIter)
			break;

		lhsIter++; rhsIter++;
	}

		// û�е���β��ʾ�в���ȵ�Ԫ��
	if (rhsIter != rhs.end())
		return false;

	return true;
}

// �õ��������ϵĲ���
template <typename T>
set<T> operator+ (const set<T>& lhs, const set<T>& rhs)
{	
		// ׼��һ�������
	set<T> resultSet;

		// ׼���������ϵĵ�����
	set<T>::iterator lhsIter = lhs.begin(),
							 rhsIter = rhs.begin();
		// ���������϶�û�л���δ������Ԫ��ʱ
	while (lhsIter != lhs.end() && rhsIter != rhs.end())
	{
			// �������������������н�С��Ԫ����ӵ��������
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

		// ��ӻ�û�б�������Ԫ��
	while (lhsIter != lhs.end())
		resultSet.insert(*lhsIter++);
	while (rhsIter != rhs.end())
		resultSet.insert(*rhsIter++);

	return resultSet;
}

// �õ��������ϵĽ���
template <typename T>
set<T> operator* (const set<T>& lhs, const set<T>& rhs)
{
	// ׼��һ�������
	set<T> resultSet;

	// ׼���������ϵĵ�����
	set<T>::iterator lhsIter = lhs.begin(),
						     	rhsIter = rhs.begin();
	// ���������϶�û�л���δ������Ԫ��ʱ
	while (lhsIter != lhs.end() && rhsIter != rhs.end())
	{
		// ��������������ȵ�Ԫ����ӵ��������
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

// �õ��������ϵĲ
template <typename T>
set<T> operator- (const set<T>& lhs, const set<T>& rhs)
{
	// ׼��һ�������
	set<T> resultSet;

	// ׼���������ϵĵ�����
	set<T>::iterator lhsIter = lhs.begin(),
								rhsIter = rhs.begin();
	// ���������϶�û�л���δ������Ԫ��ʱ
	while (lhsIter != lhs.end() && rhsIter != rhs.end())
	{
		// ���� lhs������ȴ���� rhs�����е�Ԫ����ӵ��������
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
	// ��ӻ�û�б�������Ԫ��
	while (lhsIter++ != lhs.end())
		resultSet.insert(*lhsIter);

	return resultSet;
}

#endif // !SET_FUNCTIONS
