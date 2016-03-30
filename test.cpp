#include "list/list.h"
#include <stdlib.h>
#include <stdio.h>
int main() {
	//creat a list with 5 nodes;
	LinkList* list = CreateList(5);
	PrintLinkList(*list);

	LinkList* list2 = CreateList(6);
	PrintLinkList(*list2);

	LinkList* ls = InitalList();

	MergeLists(*ls, *list, *list2);
	PrintLinkList(*ls);
	printf("the list's length is %d\n", ls->data);


	list = ls;
	//search the 4th node of the list;
	int d;
	int pos = 4;
	if (GetElemOfList(*list, pos, d) == TRUE) printf("the %dth element of the list is %d\n", pos, d);
	else printf("out of range\n");

	//insert a node into the 1th of the list;
	pos = 1;
	int ins = 10;
	if (InsertIntoList(*list, pos, ins) == TRUE){
		printf("success to insert %d to the %dth position of list\n", ins, pos);
		printf("the list's length is %d\n", list->data);
	}
	else printf("fail to insert \n");
	PrintLinkList(*list);

	//insert a node into the 1th of the list;
	ins = 10000;
	if (push_back(*list, ins) == TRUE){
		printf("success to push back %d to the list\n", ins);
		printf("the list's length is %d\n", list->data);
	}
	else printf("fail to insert \n");
	PrintLinkList(*list);


	//delete the node from the 1th of the list;
	pos = 1;
	int deleteValue;
	if (DeleteFormList(*list, pos, deleteValue) == TRUE) {
		printf("success to delete %dth node with data %d from the list\n", pos, deleteValue);
		printf("the list's length is %d\n", list->data);
	}
	PrintLinkList(*list);

	//update the 1th of the list;
	pos = 1;
	int newValue = 1000;
	if (UpdateList(*list, pos, newValue) == TRUE) {
		printf("success to update the %dth of the list\n", pos);
		printf("the list's length is %d\n", list->data);
	}
	PrintLinkList(*list);

	//clear the list
	if (ClearList(*list) == TRUE) {
		printf("success to clear the list\n");
		printf("the list's length is %d\n", list->data);
	}
	PrintLinkList(*list);



	system("pause");
	return 0;
}