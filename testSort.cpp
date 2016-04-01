#include "testSort.h"
#include <stdio.h>
void testSort() {
	int choice = 1;
	while (choice) {
		printf("please input your choice:\n");
		printf("0 exit\n");
		printf("1 test InsertSortWithArray\n");
		scanf_s("%d", &choice);

		switch (choice) {
		case 0:
			break;
		case 1:
			testInsertSortWithArray();
			break;
		default:
			break;
		}
	}

}
void testInsertSortWithArray() {
	array a;
	createArray(a);
	printArray(a);

	InsertSortWithArray(a);
	printf("after sort:\n");
	printArray(a);
}

void createArray(array &a) {
	printf("please input the length of the array:\n");
	int n;
	scanf("%d", &n);
	a.length = n;
	for (int i = 0; i < a.length; i++) {
		printf("%dth:\t", i+1);
		scanf_s("%d", &a.r[i].key);
	}
}
void printArray(array &a) {
	if (!a.length) return;
	for (int i = 0; i < a.length; i++) {
		printf("%d\t", a.r[i].key);
	}
	printf("\n");
}