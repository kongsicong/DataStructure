#ifndef _ARRAY_H_
#define _ARRAY_H_

namespace mylib {
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
		int *elem;
		int length;
		int capacity;
	}array;

	Status InitArray(array &a);
	Status InsertIntoArray(array &a, int pos, int val);
	Status push_back(array &a, int val);
	Status DeleteFromArray(array &a, int pos, int &val);
	Status pop_out(array &a, int& val);
	Status GetElemOfArray(array &a, int pos, int &val);
	Status MergeArrays(array &s, array &a, array &b);
	int length(array &a);
	int capacity(array &a);
	Status ClearArray(array &a);

	void PrintArray(array &a);
}

#endif //_ARRAY_H_