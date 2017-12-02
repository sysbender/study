#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char * getStr1() {
	char*p1 = 		//stack
		"abcdefg2"; // global
	return p1;
}
char* getStr2() {
	char *p2 =		// stack
		"abcdefg2"; // global
	return p2;
}


char * getMem(int num) { // heap
	char * p1 = NULL;
	p1 = (char *)malloc(sizeof(char *)* num);
	if (p1==NULL) {
		return NULL;
	}
	return p1;
}

char * getMem2() { // stack
	char buf[64];
	strcpy(buf, "123456");
	printf("buf = %s", buf);
	return buf;
}
void main_four() {
	// global
	char * p1 = NULL;   // stack area
	char * p2 = NULL;	// stack area
	p1 = getStr1();
	p2 = getStr2();
	printf("str p1 = %s, p2 = %s \n", p1, p2);

	printf("p1 addr = %p, p2 addr= %p \n", (void*)p1, (void*)p2); //  how to print addr


	// heap
	char * tmp = NULL;
	tmp = getMem(10);
	if (tmp == NULL) {
		return;
	}
	strcpy(tmp, "111222"); // copy str to tmp memory

	char * tmp2 = NULL;
	
	tmp2 = getMem2();

	char aaa[100];
	for (int i = 10; i < 99; i++) {
		aaa[i] = 'a';
	}
	printf(" tmp2 = %s", tmp2);

	// test stack memory direction ; release and debug are different
	int a = 1;
	int b = 2;
	printf(" addr a= %p, b=%p", &a, &b);

	// test heap memory direction

}