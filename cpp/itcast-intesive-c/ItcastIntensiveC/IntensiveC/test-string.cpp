#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void stringCopy(char * from , char* to) {
	for (; *from != '\0'; from++, to++) {
		*to = *from;
	}
	*to = '\0';
}


void stringCopy2(char * from ,char * to) {
	do  {
		*to = *from;
		to++;
		from++;
	} while (*(from-1) != '\0');
}


void stringCopy3(char * from, char * to) {
 while((*to++ = *from++) !='\0'){}
}


int strfreq(char * str, char * key) {
	if (str == NULL || key == NULL) {
		return 0;
	}
	int count = 0;
	
	char * tmpstr = str;
	char * resultstr = str;

	while ((resultstr=strstr(tmpstr, key)) != NULL) {
		count++;
		tmpstr = resultstr + strlen(key)-1;
	}
 
	return count;
}

void main_string() {
	// 1. specify len, padding with \0
	char buf2[100] = { 'a','b','c' };

	//2. not specify len, 
	//the compile will calculate the item, but not padding \0

	char buf1[] = { 'a','b','c' };
	// init char array with string, ending with \0
	char buf3[] = "abc"; 
	//get len of array, array is a data type
	printf("buf3 len = %d\n", sizeof(buf3)/sizeof(buf3[0])); 
	//get len of str , str is not a data type
	printf("str3 len = %d\n", strlen(buf3));

	// manupulate the memory with index[] or pointer, 
	char buf5[100] = "abc";
	char *p = &buf5[0];
	for (int i=0; i < strlen(buf5); i++) {
		printf("[ %d ]= %c ", i, buf5[i]);
		printf(" %c", *(p+i));
	}

	char * orig = "hello world!";
	char  copy[100];
	stringCopy3(orig, copy);

	printf(" copy = %s", copy);

	char * s = "abc1abc23abc456";
	int count = strfreq(s, "abc");
	printf("abc in s = %d\n",count );

	system("pause");


}