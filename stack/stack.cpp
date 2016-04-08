#include "stack.h"
#include <stdlib.h>
namespace stack {

	Status InitStack(SqStack &S) {
		S.base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
		if (!S.base) return OVERFLOW;
		S.top = S.base;
		S.stackSize = STACK_INIT_SIZE;
		return OK;
	}

	Status DestroyStack(SqStack &S) {
		free(S.base);
		S.base = nullptr;
		S.top = nullptr;
		S.stackSize = 0;
		return OK;
	}

	Status ClearStack(SqStack &S) {
		S.top = S.base;
		return OK;
	}

	Status StackEmpty(SqStack &S) {
		if (S.top == S.base) return TRUE;
		else return false;
	}

	int StackLength(SqStack &S) {
		return (S.top - S.base);
	}

	Status GetTop(SqStack S, ElemType &e) {
		if (S.top == S.base) return ERROR;
		e = *(S.top - 1);
		return OK;
	}

	Status Pop(SqStack &S, ElemType &e) {
		if (S.top == S.base) return ERROR;
		e = *(S.top - 1);
		S.top--;
		return OK;
	}

	Status Push(SqStack &S, ElemType e) {
		if (S.top - S.base >= S.stackSize) {
			S.base = (ElemType*)realloc(S.base, (STACKINCREMENT + S.stackSize) * sizeof(ElemType));
			if (!S.base) return OVERFLOW;
		}

		S.top++;
		*(S.top) = e;
		S.stackSize = S.stackSize + STACKINCREMENT;
		return OK;
	}
}