#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void printArrayInt(int a[], int len) {
	printf(" calculate len = %d \n", sizeof(a )/sizeof(a[0]));
	for (int i = 0; i < len; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void main_sort() {

	printf("hello\n");
	int n = 0;

	int a[] = { 7,1,3,5,2,4,6 };

	n = sizeof(a) / sizeof(a[0]);

	printArrayInt(a, n);

	//for (int i = 0; i < n; i++) {
	//	printf("%d \t", a[i]);

	//}
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		printf("%d \t", a[i]);
	}
	printf("\n");
	system("pause");
	return;

}