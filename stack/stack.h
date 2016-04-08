#ifndef _STACK_H_
#define _STACK_H_
namespace stack {
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

#define LIST_INIT_SIZE 20
#define LISTINCREMENT 5
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

	typedef int Status;
	typedef struct {
		int key;
	}ElemType;
	typedef struct {
		ElemType *base;
		ElemType *top;
		int stackSize;
	}SqStack;


	Status InitStack(SqStack &S);
	Status DestroyStack(SqStack &S);
	Status StackEmpty(SqStack &S);
	int StackLength(SqStack &S);
	Status GetTop(SqStack S, ElemType &e);
	Status Push(SqStack &S, ElemType e);
	Status Pop(SqStack &S, ElemType &e);
	Status StackTraverse(SqStack S, Status(*visit)());
}
#endif //_STACK_H_