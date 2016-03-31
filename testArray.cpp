#include "testArray.h"
#include "array/array.h"
#include <stdio.h>
#include <stdlib.h>

using namespace mylib;
void testArray() {
	array a;
	if (InitArray(a) == OVERFLOW) {
		printf("fail to initialize array\n");
		exit(EXIT_FAILURE);
	}
	PrintArray(a);
	array b;
	if (InitArray(b) == OVERFLOW) {
		printf("fail to initialize array\n");
		exit(EXIT_FAILURE);
	}
	PrintArray(b);

	for (int i = 0; i < 20; i++) {
		push_back(a, i*i);
	}
	PrintArray(a);

	for (int i = 0; i < 20; i++) {
		push_back(b, i * 10 + 5);
	}
	PrintArray(b);

	array c;
	if (MergeArrays(c, a, b) == OK) PrintArray(c);


	if (InsertIntoArray(a, 20, 100) == OVERFLOW) {
		printf("fail to insert\n");
		exit(EXIT_FAILURE);
	}
	PrintArray(a);

	push_back(a, 200);
	PrintArray(a);
	int val;
	pop_out(a, val);
	PrintArray(a);

	ClearArray(a);
	PrintArray(a);

	/*if (GetElemOfArray(a, 0, val) == OVERFLOW) {
	printf("OVERFLOW\n");
	exit(EXIT_FAILURE);
	}*/


	system("pause");
}