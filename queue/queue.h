#ifndef _QUEUE_H_
#define _QUEUE_H_
namespace queue {
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

	typedef int Status;
	typedef int  QElemType;
	typedef struct QNode {
		QElemType data;
		struct QNode *next;
	}QNode;
	typedef struct {
		QNode *front;
		QNode *rear;
	}LinkQueue;

	Status InitQueue(LinkQueue &Q);
	Status DestroyQueue(LinkQueue &Q);
	Status ClearQueue(LinkQueue &Q);
	Status QueueEmpty(LinkQueue Q);
	int QueueLength(LinkQueue Q);
	Status GetHead(LinkQueue Q, QElemType &e);
	Status EnQueue(LinkQueue &Q, QElemType e);
	Status DeQueue(LinkQueue &Q, QElemType &e);
	//Status QueueTraverse(LinkQueue Q, visit());


#define MAXQSIZE 100
	typedef struct {
		QElemType *base;
		int front;
		int rear;
	}SqQueue;
	
	Status InitQueue(SqQueue &Q);
	Status DestroyQueue(SqQueue &Q);
	Status ClearQueue(SqQueue &Q);
	Status QueueEmpty(SqQueue Q);
	int QueueLength(SqQueue Q);
	Status GetHead(SqQueue Q, QElemType &e);
	Status EnQueue(SqQueue &Q, QElemType e);
	Status DeQueue(SqQueue &Q, QElemType &e);
}
#endif //_QUEUE_H_