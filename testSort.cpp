#include "testSort.h"
#include <stdio.h>
void testSort() {
	int choice = 1;
	while (choice) {
		printf("please input your choice:\n");
		printf("0 exit\n");
		printf("1 test InsertSortWithArray\n");
		printf("2 test BinarySortWithArray\n");
		printf("3 test ShellSortWithArray\n");
		printf("4 test BubbleSortWithArray\n");
		printf("5 test QuickSortWithArray\n");
		printf("6 test SimpleSelectSortWithArray\n");
		printf("7 test HeapSortWithArray\n");
		scanf_s("%d", &choice);

		switch (choice) {
		case 0:
			return;
		case 1:
			testInsertSortWithArray();
			break;
		case 2:
			testBinarySortWithArray();
			break;
		case 3:
			testShellSortWithArray();
			break;
		case 4:
			testBubbleSortWithArray();
			break;
		case 5:
			testQuickSortWithArray();
			break;
		case 6:
			testSelectSortWithArray();
			break;
		case 7:
			testHeapSortWithArray();
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
	printf("after insert sort:\n");
	printArray(a);
}
void testBinarySortWithArray() {
	array a;
	createArray(a);
	printArray(a);

	BinarySortWithArray(a);
	printf("after binary sort:\n");
	printArray(a);
}

void testShellSortWithArray() {
	array a;
	createArray(a);
	printArray(a);

	ShellSort(a);
	printf("after shell sort:\n");
	printArray(a);
}

void testBubbleSortWithArray() {
	array a;
	createArray(a);
	printArray(a);

	BubbleSortWithArray(a);
	printf("after bubble sort:\n");
	printArray(a);

}

void testQuickSortWithArray() {
	array a;
	createArray(a);
	printArray(a);

	QuickSortWithArray(a, 0, a.length -1);
	printf("after quick sort:\n");
	printArray(a);
}

void testSelectSortWithArray() {
	array a;
	createArray(a);
	printArray(a);

	SelectSortWithArray(a);
	printf("after simple select sort:\n");
	printArray(a);
}

void testHeapSortWithArray() {
	HeapType a;
	createArray(a);
	printArray(a);

	HeapSortWithArray(a);
	printf("after heap sort:\n");
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

void createArray(HeapType &H) {
	printf("please input the length of the array:\n");
	int n;
	scanf("%d", &n);
	H.length = n;
	for (int i = 1; i <= H.length; i++) {
		printf("%dth:\t", i);
		scanf_s("%d", &H.r[i].key);
	}
}
void printArray(HeapType &H) {
	if (!H.length) return;
	for (int i = 1; i <= H.length; i++) {
		printf("%d\t", H.r[i].key);
	}
	printf("\n");
}