#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void getMem(char **ppStr, int* pInt ) {

	char * tmp = (char*)malloc(100);
	strcpy(tmp, "hello world");
	*ppStr = tmp;
	*pInt = 100;

}

void freeMem( char **ppStr) {
	if (*ppStr == NULL) { return; }
	char * tmp = *ppStr;
	free(tmp);
	*ppStr = NULL;
}
void main() {
	char * pStr = NULL;
	int len = 0;


	getMem(&pStr, &len);
	printf("str = %s", pStr);
	printf("len = %d", len);
	freeMem(&pStr);
	printf("hello");

}