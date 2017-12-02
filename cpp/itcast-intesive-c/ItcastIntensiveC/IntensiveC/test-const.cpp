#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main_const() {

	char * str = "hello";
	char buf[100] = { 0 };
	char * p1 = NULL;
	const char * p2 = NULL;
	p2 = buf;
	buf[0] = 'c';

	printf("buf= %s", buf);




}