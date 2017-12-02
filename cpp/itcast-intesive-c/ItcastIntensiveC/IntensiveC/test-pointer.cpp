#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char * getStr() {
	char * tmp = NULL;
	tmp = "abcdef"; // constant, 
	return tmp;
}

void getStrPP(char ** ppStr) {
	char *pTmp = (char *)malloc(100);
	strcpy(pTmp, "abc");
	*ppStr = pTmp;


}

void main_p() {
	int i = 100;
	char a[100] = "abc";
	char *p1 = (char *)&a;
	printf(" str = %s \n" , p1);



	char * p = getStr();
//	*(p + 2) = 'r';
	printf("str = %s \n", p);

	// **
	char * pChar1 = NULL;

	getStrPP(&pChar1);
	printf("pChar1 = %s", pChar1);

 }