#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct teacher {
	char name[64];
	int age;
}teacher;

struct teacherType {
	char name[64];
	int age;
} teacharType;

void main_array() {

	int a;
	int b[10];  // 40 bytes


	printf("b= %d\n", b);
	printf("&b= %d\n", &b);

	printf("b+1= %d\n", b+1);
	printf("&b+1= %d\n", &b+1);

	struct teacher t1;   // must use 'struct'
	teacherType t2;


	char * p2 = NULL;
	p2 = (char*)malloc(100);

}