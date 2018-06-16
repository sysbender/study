

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;


bool less_than(int v1, int v2)
{
	return v1 < v2;
}



bool greater_than(int v1, int v2)
{
	return v1 > v2;
}

vector<int> filter_for(const vector<int> &vec, int filter_value, bool (*pred)(int, int))
{
	vector<int> nvec;
	for(auto v : vec)
	{
		if( pred(v, filter_value) )
		{
			nvec.push_back(v);
		}
	}
	return nvec;
}



void test_filter_for()
{
	const int size = 8;
	int iArray[] = { 6, 10, 8, 4, 10,  7,10,9 };

	vector<int> iVector(iArray, iArray + size);


	auto vec = filter_for(iVector, 5, less_than);

	for (auto element : vec)
	{
		cout << element << " ";
	}
	cout << endl;
}



/*
 *

 */

int count_occurs(const vector<int> &vec, int value)
{
	
	vector<int>::const_iterator iter= vec.begin();
	int count = 0;

	while( (iter= find(iter, vec.end(), value)) !=vec.end())
	{
		count++;
		++iter;
	}

	return count;
}


void test_count_occurs()
{
	
	const int size = 8;
	int iArray[] = { 6, 10, 8, 4, 10,  7,10,9 };

	vector<int> iVector(iArray, iArray + size);
	int count = count_occurs(iVector, 10);
	cout << "count of 10 = " << count << endl;
}


/*
 * function object and functional object adapter
 */


vector<int> 
filter_functional(const vector<int> &vec, int value, less<int> &less_than)
{
	vector<int> nvec;
	vector<int>::const_iterator iter = vec.begin();


	while((iter=find_if(iter, vec.end(), bind2nd(less_than, value))) != vec.end())
	{
		nvec.push_back(*iter);
		iter++;
	}

	return nvec;
}


void test_filter_functional()
{
	const int size = 8;
	int iArray[] = { 6, 10, 8, 4, 10,  7,10,9 };

	vector<int> iVector(iArray, iArray + size);
	auto r = filter_functional(iVector, 8, less<int>());
	for(auto v:r)
	{
		cout << v << " ";
	}
	cout << endl;
}



int main()
{
	test_filter_for();
	test_count_occurs();
	test_filter_functional();
	system("pause");
	return 0;
}