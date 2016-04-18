#pragma once
#pragma execution_character_set("utf-8")
#include "testString.h"
#include <stdio.h>

void testString() {
	int choice = 1;
	while (choice) {
		printf("please input your choice:\n");
		printf("0 exit\n");
		printf("1 test string with fixed length\n");
		printf("2 test string with heap allocation\n");
		printf("3 test string index\n");
		scanf_s("%d", &choice);

		switch (choice) {
		case 0:
			return;
		case 1:
			testStringWithFixedLen();
			break;
		case 2:
			testStringWithHeapAlloc();
			break;
		case 3:
			testStringIndex();
			break;
		default:
			break;
		}
	}
}

void testStringWithFixedLen() {
	SString S;
	CreateString(S);
	PrintString(S);

	SString S2;
	CreateString(S2);
	PrintString(S2);

	SString T;
	StrConcat(T, S, S2);
	PrintString(T);


	SString Sub;
	SubString(Sub, T, 2, 3);
	PrintString(Sub);

	printf("compare two string:\n");
	SString s1;
	CreateString(s1);
	PrintString(s1);
	SString s2;
	CreateString(s2);
	PrintString(s2);
	int result = StrCompare(s1, s2);
	if (!result) printf("s1 == s2");
	else if (result > 0) printf("s1 > s2");
	else printf("s1 < s2");
	printf("\n");

}


void testStringIndex() {
	printf("input the main string:\n");
	SString S;
	CreateString(S);
	PrintString(S);

	printf("input the sub string:\n");
	SString S2;
	CreateString(S2);
	PrintString(S2);

	printf("general matching algirothm:\n");
	int pos = Index(S, S2, 1);
	printf("the position of the substring in the main string is: %d\n", pos);

	printf("kmp  matching algirothm:\n");
	pos = Index_KMP(S, S2, 1);
	printf("the position of the substring in the main string is: %d\n", pos);
}
void CreateString(SString &S) {
	char buffer[256];
	printf("input the string:\n");
	scanf("%s", buffer);
	StrAssign(S, buffer);
}
void PrintString(SString S) {
	int len = StrLength(S);
	printf("the length of the string is: %d\n", len);
	int i = 1;
	while (i <= len) {
		printf("%c", S[i]);
		i++;
	}
	printf("\n");
}

void testStringWithHeapAlloc() {
	SString S;
	CreateString(S);
	PrintString(S);

	SString S2;
	CreateString(S2);
	PrintString(S2);

	SString T;
	StrConcat(T, S, S2);
	PrintString(T);


	SString Sub;
	SubString(Sub, T, 2, 3);
	PrintString(Sub);

	printf("compare two string:\n");
	SString s1;
	CreateString(s1);
	PrintString(s1);
	SString s2;
	CreateString(s2);
	PrintString(s2);
	int result = StrCompare(s1, s2);
	if (!result) printf("s1 == s2");
	else if (result > 0) printf("s1 > s2");
	else printf("s1 < s2");
	printf("\n");
}

void CreateString(HString &S) {
	char buffer[256];
	printf("input the string:\n");
	scanf("%s", buffer);
	StrAssign(S, buffer);
}
void PrintString(HString S) {
	int len = StrLength(S);
	printf("the length of the string is: %d\n", len);
	int i = 0;
	while (i < len) {
		printf("%c", S.ch[i]);
		i++;
	}
	printf("\n");
}

