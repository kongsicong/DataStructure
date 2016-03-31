#include "list.h"
#include <stdio.h>
#include <stdlib.h>
namespace mylib {
	LinkList* InitalList() {
		LinkList* L = (LinkList*)malloc(sizeof(LinkList));
		L->data = 0;
		L->next = nullptr;
		return L;
	}
	LinkList* CreateList(int n) {
		if (n < 0) {
			printf("n should be greater than 0");
			return nullptr;
		}
		LNode* L = (LinkList*)malloc(sizeof(LNode));
		L->data = n;
		L->next = nullptr;
		LNode* prev = L;
		for (int i = 1; i <= n; i++) {
			LNode* node = (LinkList*)malloc(sizeof(LNode));
			printf("please input the %dth number:", i);
			scanf_s("%d", &node->data);
			node->next = prev->next;
			prev->next = node;
			prev = node;
		}
		return L;
	}

	void PrintLinkList(LinkList& L) {
		if (L.data == 0) {
			printf("the list is empty");
			return;
		}
		LNode* current;
		for (current = L.next; current != nullptr; current = current->next) {
			printf("%d->", current->data);
		}
		printf("\n");
	}

	Status GetElemOfList(LinkList& L, int pos, int& value) {
		if (L.data < pos) return FALSE;
		int i = 1;
		LNode* current;
		for (current = L.next; i != pos; i++) {
			current = current->next;
		}
		value = current->data;
		return TRUE;
	}
	int lenghOfList(LinkList& L) {
		return L.data;
	}

	Status InsertIntoList(LinkList& L, int pos, int value) {
		if (pos < 1 || pos > L.data){
			printf("out of range\n");
			return FALSE;
		}

		LNode* node = (LNode*)malloc(sizeof(LNode));
		node->data = value;
		L.data++;
		if (pos == 1) {
			node->next = L.next;
			L.next = node;
			return TRUE;
		}
		LNode * current;
		int i = 1;
		for (current = L.next; i != pos - 1; i++) {
			current = current->next;
		}

		node->next = current->next;
		current->next = node;
		return TRUE;
	}
	Status push_back(LinkList& L, int value) {
		LNode* node = (LNode*)malloc(sizeof(LNode));
		node->data = value;
		node->next = nullptr;
		LNode* prev = &L;
		for (LNode* current = L.next; current != nullptr; current = current->next) {
			prev = prev->next;
		}
		prev->next = node;
		return TRUE;
		L.data++;
	}

	Status pop_back(LinkList& L, int& value) {
		if (L.data == 0) {
			printf("the list is empty\n");
			return FALSE;
		}
		LNode* current;
		for (current = L.next; current != nullptr; current = current->next);
		value = current->data;
		free(current);
		L.data--;
		return TRUE;
	}

	Status DeleteFormList(LinkList& L, int pos, int& deleteValue) {
		if (pos < 1 || pos > L.data) {
			printf("out of range \n");
			return FALSE;
		}

		LNode * current;
		LNode * prev;
		int i = 1;
		for (prev = &L; i != pos; i++) {
			prev = prev->next;
		}
		current = prev->next;
		prev->next = current->next;
		deleteValue = current->data;
		free(current);
		L.data--;
		return TRUE;
	}

	Status UpdateList(LinkList& L, int pos, int newValue) {
		if (pos < 1 || pos > L.data){
			printf("out of range\n");
			return FALSE;
		}

		LNode * current;
		int i = 1;
		for (current = L.next; i != pos; i++) {
			current = current->next;
		}
		current->data = newValue;
		return TRUE;
	}

	Status ClearList(LinkList& L) {
		LNode* current = L.next;
		LNode* next;
		while (current != nullptr) {
			next = current->next;
			free(current);
			current = next;
		}
		L.data = 0;
		return TRUE;
	}

	void MergeLists(LinkList& Ls, LinkList& La, LinkList& Lb) {
		LNode* pa = La.next;
		LNode* pb = Lb.next;
		LNode* current = &Ls;
		while (pa != nullptr && pb != nullptr) {
			if (pa->data <= pb->data) {
				current->next = pa;
				pa = pa->next;
			}
			else {
				current->next = pb;
				pb = pb->next;
			}
			current = current->next;
		}
		Ls.data = La.data + Lb.data;
		free(&La);
		free(&Lb);
		current->next = pa == nullptr ? pb : pa;

	}
}
