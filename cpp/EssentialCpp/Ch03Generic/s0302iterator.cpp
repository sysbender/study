


#include <iostream>
#include <vector>
#include <list>

using namespace std;


/*
 * dispaly with iterator
 */
template <typename elemType>
void display(const vector<elemType> &vec, ostream &os)
{
	vector<elemType>::const_iterator iter_begin = vec.begin();
	vector<elemType>::const_iterator iter_end = vec.end();


	for(; iter_begin != iter_end; ++iter_begin)
	{
		os << *iter_begin << " ";
		
	}
	os << endl;
}

void test_display()
{
	
	int iArray[] = {1,2,3,4,5};
	vector<int> iVec(iArray, iArray+5);
	display(iVec,cout);
}



/*
 * find with iterator
 *
 */

template <typename iterType, typename elemType>
iterType 
find_iter(iterType first, iterType last, const elemType & value)
{
	for(;first !=last ; ++first)
	{
		if (*first == value)
			return first;
	}

	return last;
}

void test_find_iter()
{
	
	const int size = 8;
	int iArray[] = { 1,1,2,3,5,8,13,21 };

	vector<int> iVector(iArray, iArray + size);
	list<int> iList(iArray, iArray + size);

	int * piArray = find_iter(iArray, iArray+size, 13);
	if(piArray != iArray+size)
	{
		cout << " find in array by iter = " << *piArray << endl;
	}else
	{
		cout << " find in array by iter = " << "not found" << endl;
	}


	vector<int>::const_iterator piVector = find_iter(iVector.begin(), iVector.end(), 8);

	if (piVector != iVector.end())
	{
		cout << " find in vector by iter = " << *piVector << endl;
	}
	else
	{
		cout << " find in vector by iter = " << "not found" << endl;
	}


	list<int>::const_iterator piList = find_iter(iList.begin(), iList.end(), 5);

	if (piList != iList.end())
	{
		cout << " find in list by iter = " << *piList << endl;
	}
	else
	{
		cout << " find in list by iter = " << "not found" << endl;
	}
}

#if 0
int main()
{
	test_display();
	test_find_iter();
	system("pause");
	return 0;
}

#endif