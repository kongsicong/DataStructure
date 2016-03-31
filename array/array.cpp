#include "array.h"
#include <stdlib.h>
#include <stdio.h>
namespace mylib {
	Status InitArray(array &a) {
		a.elem = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
		if (!a.elem) return OVERFLOW;
		a.length = 0;
		a.capacity = LIST_INIT_SIZE;
		return OK;
	}
	Status InsertIntoArray(array &a, int pos, int val) {
		if (pos < 0 || pos > a.length) {
			free(a.elem);
			return OVERFLOW;
		}
		if (a.length >= a.capacity) {
			a.elem = (int*)realloc(a.elem, (LISTINCREMENT + LIST_INIT_SIZE) * sizeof(int));
			if (!a.elem) return OVERFLOW;
			a.capacity = LISTINCREMENT + LIST_INIT_SIZE;
		}

		for (int i = a.length - 1; i >= pos; i--) {
			a.elem[i + 1] = a.elem[i];
		}
		a.elem[pos] = val;
		a.length = a.length + 1;
		return OK;
	}
	Status push_back(array &a, int val) {
		if (a.length >= a.capacity) {
			a.elem = (int*)realloc(a.elem, (LISTINCREMENT + LIST_INIT_SIZE) * sizeof(int));
			if (!a.elem) return OVERFLOW;
			a.capacity = LISTINCREMENT + LIST_INIT_SIZE;
		}
		a.elem[a.length] = val;
		a.length = a.length + 1;
		return OK;
	}
	Status DeleteFromArray(array &a, int pos, int &val) {
		if (pos < 0 || pos >= a.length) {
			free(a.elem);
			return OVERFLOW;
		}
		val = a.elem[pos];
		for (int i = pos; i < a.length; i++) {
			a.elem[i] = a.elem[i + 1];
		}
		a.length = a.length - 1;
		return OK;
	}

	Status pop_out(array &a, int& val) {
		val = a.elem[a.length - 1];
		a.length = a.length - 1;
		return OK;
	}
	Status GetElemOfArray(array &a, int pos, int &val) {
		if (!a.capacity || !a.elem) return OVERFLOW;
		if (pos < 0 || pos >= a.length) {
			free(a.elem);
			return OVERFLOW;
		}
		val = a.elem[pos];
		return OK;
	}
	Status MergeArrays(array &s, array &a, array &b) {
		s.elem = (int*)malloc((a.length + b.length) * sizeof(int));
		s.length = a.length + b.length;
		s.capacity = s.length;
		int i = 0, j = 0, k = 0;
		while (i < a.length || j < b.length) {
			i = i == a.length ? a.length : i;
			j = j == b.length ? b.length : j;
			int va = i == a.length ? INT_MAX : a.elem[i];
			int vb = j == b.length ? INT_MAX : b.elem[j];
			if (va < vb) {
				s.elem[k] = va;
				i++;
				k++;
			}
			else {
				s.elem[k] = vb;
				j++;
				k++;
			}
		}
		return OK;
	}
	int length(array &a) {
		return a.length;
	}
	int capacity(array &a) {
		return a.capacity;
	}
	Status ClearArray(array &a) {
		free(a.elem);
		a.length = 0;
		a.capacity = 0;
		a.elem = nullptr;
		return OK;
	}

	void PrintArray(array &a) {
		printf("length %d\t capacity %d\n", a.length, a.capacity);
		if (!a.length) return;
		for (int i = 0; i < a.length; i++) {
			printf("%d\t", a.elem[i]);
		}
		printf("\n");
	}
}