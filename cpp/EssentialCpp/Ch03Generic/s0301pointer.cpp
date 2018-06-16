/*
 * algorithm
 * container
 *	sequential - array, vector, list
 *	associative - 
 *		set - key
 *		map - key, value
 *
 *
 *
 */


#include <vector>
#include <iostream>
using namespace  std;

/*
 * find int in vector
 */
const int * find_vector_int(const vector<int> &vec, int value)
{
	for(int ix =0; ix <vec.size(); ++ix)
	{
		if (vec[ix] == value) { return & vec[ix]; }

	}
	return 0;
}


void test_find_vector_int()
{
	int iArray_size = 6;
	int iArray[] = {1,2,3,4,5,6};
	vector<int> iVector(iArray, iArray+iArray_size);

	auto pInt = find_vector_int(iVector, 5);
	cout << "test_find_vector_int= " << *pInt << endl;

}

/*
 * find any type in vector
 */


template <typename elemType>
const elemType * 
find_vector_any ( const vector<elemType> &vec, const elemType value)
{
	for(int i=0; i<vec.size(); ++i)
	{
		if(vec[i] == value)
		{
			return &vec[i];
		}
	}
	return 0;
}


void test_find_vector_any()
{
	int vec_size = 6;
	vector<char> cVector = {'a','b','c','d','e','f'};
	auto p = find_vector_any(cVector, 'd');

	cout << "test_find_vector_any= " << *p << endl;
}


/*
 * find array size by subscript
 */

template <typename elemType>
const elemType * 
find_array_size( const elemType *array, int size, const elemType &value)
{
	if (!array || size < 1) { return 0; }
	for(int i =0; i<size; ++i)
	{
		if(array[i] == value)
		{
			return &array[i];
		}
	}
	return 0;
}






/*
 * find array size by pointer
 *
 */


template <typename elemType>
const elemType * 
find_array_size_pointer(const elemType * array, int size , const elemType &value)
{
	if (!array || size < 1) { return 0; }

	for(int i=0;i<size; ++i, ++array)
	{
		if(*array == value)
		{
			return array;
		}
	}
	return 0;
}


void test_find_array_size()
{
	const int size = 6;
	int iArray[size] = { 1,2,3,4,5,6 };

	auto p = find_array_size(iArray, size, 5);

	cout << "find_array_size= "<< *p <<endl;

	auto p2 = find_array_size_pointer(iArray, size, 5);
	cout << "find_array_size= " << *p2 << endl;
}


/*
 * find array sentinel
 */



template <typename elemType>
const elemType *
find_array_sentinel(const elemType *first, const elemType * last , const elemType &value)
{
	if (!first || !last) { return 0; }

	for( ;first != last; ++first )
	{
		if(*first == value)
		{
			return first;
		}
	}

	return 0;
	
}


void test_find_array_sentinel()
{
	int iArray[8] = { 1,1,2,3,4,8,13,21 };
	double dArray[6] = { 1.5, 2.0, 2.5, 3.0 , 3.5, 4.0 };
	string sArray[4] = { "pooh", "piglet", "eeyore", "trigger" };
	vector<string> sVector;
	sVector.push_back("hello");

	auto pi = find_array_sentinel(iArray, iArray + 8, iArray[3]);
	cout << "find_array_sentinel int=" << *pi << endl;

	const double *pd = find_array_sentinel(dArray, dArray + 6, 3.0);
	cout << "find_array_sentinel double = " << *pd << endl;


	const string * ps = find_array_sentinel(sArray, sArray + 4, string("piglet"));
	cout << "find_array_sentinel string = " << ps->c_str() << endl;

	// not working with empty vector
	const string * psv = find_array_sentinel(&sVector[0], &sVector[0]+1, string("hello"));
	cout << "find_array_sentinel in empty string vector = " << psv->c_str() << endl;

}

#if 0
int main()
{
	
	test_find_vector_int();
	test_find_vector_any();
	test_find_array_size();
	test_find_array_sentinel();
	system("pause");
	return 0;
}
#endif
