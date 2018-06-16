

#include <vector>
#include <list>
#include <deque>

using namespace std;


void test_constructor()
{

	// 1 - empty
	list<int> iList1;
	vector<int> iVector1;


	// 2- size
	list<int> iList2(3);
	vector<int> iVector2(3);

	// 3- size, init
	list<int> iList3(3, 999);
	vector<int> iVector3(3, 888);

	//4- init by array
	const int size = 8;
	int iArray[size] = { 1,2,3,4,5,6,7,8 };
	list<int> iList4(iArray, iArray + 3);
	vector<int> iVector4(iArray, iArray + 3);


	//5 - init by other list/vector
	list<int> iList5(iList4);
	vector<int> iVector5(iVector4);
	

}


#if 0
int main()
{
	
	test_constructor();
}
#endif