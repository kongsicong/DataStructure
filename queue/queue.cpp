#include "queue.h"
#include <stdlib.h>
namespace queue {
	Status InitQueue(LinkQueue &Q) {
		Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));
		if (!Q.front) exit(OVERFLOW);
		Q.front->next = nullptr;
		return OK;
	}

	Status DestroyQueue(LinkQueue &Q) {
		while (Q.front) {
			Q.rear = Q.front->next;
			free(Q.front);
			Q.front = Q.rear;
		}
		return OK;
	}

	Status ClearQueue(LinkQueue &Q) {
		QNode * cur = Q.front->next;
		while (cur) {
			Q.rear = cur->next;
			free(cur);
			cur = Q.rear;
		}
		Q.rear = Q.front;
		Q.front->next = nullptr;
		return OK;
	}

	Status QueueEmpty(LinkQueue Q) {
		if (Q.front == Q.rear) return TRUE;
		else return FALSE;
	}

	int QueueLength(LinkQueue Q) {
		int i = 0;
		for (QNode* cur = Q.front->next; cur != nullptr; cur = cur->next, i++);
		return i;
	}

	Status EnQueue(LinkQueue &Q, QElemType e) {
		QNode *node = (QNode*)malloc(sizeof(QNode));
		if (!node) return OVERFLOW;
		node->data = e;
		node->next = nullptr;
		Q.rear->next = node;
		Q.rear = node;
		return OK;
	}

	Status DeQueue(LinkQueue &Q, QElemType &e) {
		if (Q.front == Q.rear) return OVERFLOW;
		
		e = Q.front->next->data;
		if (Q.front->next == Q.rear) {
			free(Q.front->next);
			Q.front->next = nullptr;
			Q.rear = Q.front;
		}
		else {
			QNode* cur = Q.front->next;
			Q.front->next = cur->next;
			free(cur);
		}
		return OK;

	}

	Status GetHead(LinkQueue Q, QElemType &e) {
		if (Q.rear == Q.front) return ERROR;
		e = Q.front->next->data;
		return OK;
	}










	/*********************************************************************************************************************************************************/
	Status InitQueue(SqQueue &Q) {
		Q.base = (QElemType*)malloc(MAXQSIZE * sizeof(QElemType));
		if (!Q.base) return OVERFLOW;
		Q.front = Q.rear = 0;
		return OK;
	}
	Status DestroyQueue(SqQueue &Q) {
		free(Q.base);
		Q.base = nullptr;
		Q.front = Q.rear = 0;
		return OK;
	}
	Status ClearQueue(SqQueue &Q) {
		Q.front = Q.rear = 0;
		return OK;
	}
	Status QueueEmpty(SqQueue Q) {
		if (Q.front == Q.rear) return TRUE;
		else return FALSE;
	}
	int QueueLength(SqQueue Q) {
		return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
	}
	Status EnQueue(SqQueue &Q, QElemType e) {
		if ((Q.rear + 1) % MAXQSIZE == Q.front) return ERROR;
		Q.base[Q.rear] = e;
		Q.rear = (Q.rear + 1) % MAXQSIZE;
		return OK;
	}
	Status DeQueue(SqQueue &Q, QElemType &e) {
		if (QueueEmpty(Q)) return ERROR;
		e = Q.base[Q.front];
		Q.front = (Q.front + 1) % MAXQSIZE;
		return OK;
	}
}