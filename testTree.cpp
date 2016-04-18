#pragma once
#pragma execution_character_set("utf-8")

#include "testTree.h"
#include <stdio.h>
void testTree() {
	Status(*Visit)(TElemType e) = &PrintTElemType;
	BiTree T;
	CreateBiTree(T);
	printf("traverse binary tree with preorder:\n");
	PreOrderTraverse(T, Visit);
	printf("\n");

	printf("traverse binary tree with inorder:\n");
	InOrderTraverse(T, Visit);
	printf("\n");

	printf("traverse binary tree with postorder:\n");
	PostOrderTraverse(T, Visit);
	printf("\n");
}


Status PrintTElemType(TElemType e) {
	printf("%c", e);
	return OK;
}