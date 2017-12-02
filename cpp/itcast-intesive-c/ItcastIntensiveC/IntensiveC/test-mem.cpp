#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void main_memory() {

	int a;
	a = 10;
	void *p = &a;
	*((int *)p) = 20;

	printf("a= %d \n", a);

}