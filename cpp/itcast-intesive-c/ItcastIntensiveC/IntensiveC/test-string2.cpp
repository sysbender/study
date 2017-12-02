#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char g_buf[1000];

void trim(char * str) {
	int t = strlen(str);
	char * buf = (char *)malloc(strlen(str) + 1);


	char * tmp = buf;
	int len = 0;
	

	strcpy(buf, str);
	while (isspace(*tmp) && *tmp !='\0'  ) {
		tmp++;
	}
	char * start = tmp;
	while (!isspace(*tmp) && *tmp != '\0') {
		tmp++;
		len++;
	}

	strncpy(str, start, len);
	*(str + len) = '\0';

}
void reverse_inplace(char * str) {
	
	char * tmpStart = str;
	int len = strlen(str);
	char * tmpEnd = str + strlen(str) - 1;

	while (tmpStart < tmpEnd) {
		char t = *tmpStart;
		*tmpStart = *tmpEnd;
		*tmpEnd = t;
		tmpStart++;
		tmpEnd--;
	}

}
/*
1. recursive print
2. recursive to global
3. re
*/
void reverse_recursive_print(char * str) {
	if (str == NULL || *str=='\0') { return; }


	reverse_recursive_print(str +1);
	printf("\n%c", *str);

}

void reverse_recursive_g(char * str) {
	if (str == NULL || *str == '\0') { return; }

	reverse_recursive_g(str + 1);
	//printf("\n%c", *str);
	 
	strncat(g_buf, str, 1);

}
void reverse_recursive_l(char * str, char * buf) {
	if (str == NULL || *str == '\0') { return; }

	reverse_recursive_l(str + 1, buf);
	//printf("\n%c", *str);

	strncat(buf, str, 1);

}

void main_str2() {

	//char * test_trim = "   abc   ";  // constant, can not write
	char test_re[] = "abcdef";	// local , can be written
	//trim(test);
	//reverse_inplace(test_re);
	//printf("test = %s", test_re);


	memset(g_buf, 0, sizeof(g_buf));

	//reverse_recursive_print(test_re);
	reverse_recursive_g(test_re);
	printf(" g= %s ", g_buf);
	

	{
		char mybuf[1024] = {0}; // must init to 0, otherwise it's not  a str
		reverse_recursive_l(test_re, mybuf);
		printf("l = %s",mybuf);
	}

}