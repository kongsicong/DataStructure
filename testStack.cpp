#pragma once
#pragma execution_character_set("utf-8")

#include "testStack.h"
#include <stdio.h>
void testStack() {
	int choice = 1;
	while (choice) {
		printf("please input your choice:\n");
		printf("0 exit\n");
		printf("1 test basic stack\n");
		printf("2 test number system conversion\n");
		printf("3 test parenthesis matching\n");
		printf("4 test line edit\n");
		scanf_s("%d", &choice);

		switch (choice) {
		case 0:
			return;
		case 1:
			testBasicStack();
			break;
		case 2:
			conversion();
			break;
		case 3:
			parenthesisMatch();
			break;
		case 4:
			lineEdit();
			break;
		default:
			break;
		}
	}
}
void testBasicStack() {
	SqStack S;
	InitStack(S);
	if (StackEmpty(S)) printf("the Stack S is Empty");
	PrintStack(S);
	printf("add item to the stack.\n");
	CreateStack(S);
	PrintStack(S);
	printf("pop the top of the stack:\n");
	ElemType e;
	Pop(S, e);
	PrintStack(S);
	printf("the element that is popped out: %d\n", e.key);
	ClearStack(S);
	printf("clear the stack:\n");
	PrintStack(S);
	printf("destroy the stack:\n");
	DestroyStack(S);
	PrintStack(S);
}
void conversion() {
	SqStack S;
	InitStack(S);
	int N;
	printf("input the decimal number:\n");
	scanf_s("%d", &N);
	printf("input the the number system after conversion:\n");
	int d;
	scanf_s("%d", &d);
	while (N) {
		ElemType e;
		e.key = N % d;
		Push(S, e);
		N = N / d;
	}
	PrintStack(S);
	printf("the conversion result is:\n");
	while (!StackEmpty(S)) {
		ElemType e;
		Pop(S, e);
		printf("%d", e.key);
	}
	printf("\n");
	PrintStack(S);
	DestroyStack(S);
}
void parenthesisMatch() {
	char s[100];
	printf("please input the string which consists of paretheses:\n");
	scanf("%s", s);
	SqStack S;
	InitStack(S);
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
			ElemType e;
			e.key = s[i];
			Push(S, e);
		}
		else if (s[i] == ']' || s[i] == '}' || s[i] == ')') {
			ElemType e;
			Pop(S, e);
			if (e.key != s[i] - 1 && e.key != s[i] - 2) {
				printf("the parentheses are not matching.\n");
				return;
			}
		}
	}
	if (StackEmpty(S)) {
		printf("the parentheses are matching.\n");
	}
	DestroyStack(S);
}
void lineEdit() {
	SqStack S;
	InitStack(S);
	char ch;
	ch = getchar();
	ElemType e;
	while (ch != EOF) {
		while (ch != EOF && ch != '\n') {
			switch (ch) {
			case '#': 
				Pop(S, e);
				break;
			case '@':
				ClearStack(S);
				break;
			default:
				e.key = ch;
				Push(S, e);
				break;
			}
			ch = getchar();
		}

		PrintStack(S);
		ClearStack(S);
		if (ch != EOF) ch = getchar();
	}
	DestroyStack(S);
}
void CreateStack(SqStack &S) {
	int len = 0;
	printf("please inpute the number of the stack:\n");
	scanf_s("%d", &len);
	if (len < 0) return;
	for (int i = 0; i < len; i++) {
		printf("input the value:\n");
		ElemType e;
		scanf_s("%d", &e.key);
		Push(S, e);
	}
}

void PrintStack(SqStack S) {
	int len = StackLength(S);
	printf("the stack's length is: %d\n", len);
	printf("the stack's capacity is: %d\n", S.stackSize);
	if (len <= 0) return;
	for (int i = 0; i < len; i++) {
		ElemType e = *(S.top - i - 1);
		printf("%d\t", e.key);
	}
	printf("\n");
}