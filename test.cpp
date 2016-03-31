//#include "list/list.h"
#include "array/array.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "test.h"

int main(int argc, char * argv[]) {
	
	char option[20];
	printf("please input the test option:\n");
	scanf("%s",option);

	while (strcmp(option, "exit")) {
		if (!strcmp(option, "list")) testList();
		else if (!strcmp(option, "array")) testArray();
		else if (!strcmp(option, "queue")) testQueue();


		printf("please input the test option:\n");
		scanf("%s", option);
	}
	


	return 0;
}