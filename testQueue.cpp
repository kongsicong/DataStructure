#include "testQueue.h"
#include <stdio.h>
void testQueue() {
	int choice = 1;
	while (choice) {
		printf("please input your choice:\n");
		printf("0 exit\n");
		printf("1 test queue with list\n");
		printf("2 test queue with array\n");
		scanf_s("%d", &choice);

		switch (choice) {
		case 0:
			return;
		case 1:
			testQueueWithList();
			break;
		case 2:
			testQueueWithArray();
			break;
		
		default:
			break;
		}
	}
	
}

void testQueueWithList() {
	LinkQueue Q;
	InitQueue(Q);
	PrintQueue(Q);
	CreateQueue(Q);
	PrintQueue(Q);
	printf("delete the head of the queue:\n");
	QElemType e;
	DeQueue(Q, e);
	PrintQueue(Q);
	printf("clear the queue:\n");
	ClearQueue(Q);
	PrintQueue(Q);
	if (QueueEmpty(Q)) printf("the queue is empty\n");
	DestroyQueue(Q);
}

void testQueueWithArray() {
	SqQueue Q;
	InitQueue(Q);
	PrintQueue(Q);
	CreateQueue(Q);
	PrintQueue(Q);
	printf("delete the head of the queue:\n");
	QElemType e;
	DeQueue(Q, e);
	PrintQueue(Q);
	printf("clear the queue:\n");
	ClearQueue(Q);
	PrintQueue(Q);
	if (QueueEmpty(Q)) printf("the queue is empty\n");
	DestroyQueue(Q);
}



void PrintQueue(LinkQueue Q) {
	printf("the length of the queue is: %d\n", QueueLength(Q));
	if (Q.front == Q.rear) return;
	for (QNode *cur = Q.front->next; cur != nullptr; cur = cur->next) {
		printf("%d->", cur->data);
	}
	printf("\n");
} 

void CreateQueue(LinkQueue &Q) {
	int len;
	printf("input the length of the queue:\n");
	scanf_s("%d", &len);

	for (int i = 0; i < len; i++) {
		QElemType e;
		printf("input the %dth value of the queue:\n", i);
		scanf_s("%d", &e);
		EnQueue(Q, e);
	}
}

void PrintQueue(SqQueue Q) {
	printf("the length of the queue is: %d\n", QueueLength(Q));
	for (int i = Q.front; i != Q.rear; i = (i + 1) % MAXQSIZE) printf("%d->", Q.base[i]);
	printf("\n");
}

void CreateQueue(SqQueue &Q) {
	int len;
	printf("input the length of the queue:\n");
	scanf_s("%d", &len);

	for (int i = 0; i < len; i++) {
		QElemType e;
		printf("input the %dth value of the queue:\n", i);
		scanf_s("%d", &e);
		EnQueue(Q, e);
	}
}