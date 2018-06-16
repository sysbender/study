#include "LibMat.h"

#include <typeinfo>

void print (LibMat & mat)
{
	std::cout << "in global print(): about to print mat.print()\n";
	mat.print();
}
int main()
{
	// print 
	//LibMat libmat;
	//print(libmat);

//	Book book("101 story","arabe");
//	print(book);

	AudioBook ab("-title-", "-author-", "-narrator-");
	print(ab);
 


}


