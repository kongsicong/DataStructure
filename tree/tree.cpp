#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
namespace tree {
	Status CreateBiTree(BiTree &T) {
		printf("input the value of the node:\n");
		char ch;
		ch = getchar();
		if (ch == '\n') ch = getchar();
		if (ch == ' ') T = nullptr;
		else {
			if (!(T = (BiTNode*)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
			T->data = ch;
			CreateBiTree(T->lchild);
			CreateBiTree(T->rchild);
		}
		return OK;
	}

	Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {
		if (T) {
			if (Visit(T->data)) {
				if (PreOrderTraverse(T->lchild, Visit)) {
					if (PreOrderTraverse(T->rchild, Visit)) return OK;
				}
			}
			return ERROR;
		}
		else return OK;
	}

	Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {
		if (T) {
			if (InOrderTraverse(T->lchild, Visit)) {
				if (Visit(T->data)) {
					if (InOrderTraverse(T->rchild, Visit)) return OK;
				}
			}
		}
		else return OK;
	}

	Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {
		if (T) {
			if (PostOrderTraverse(T->lchild, Visit)) {
				if (PostOrderTraverse(T->rchild, Visit)) {
					if (Visit(T->data)) return OK;
				}
			}
		}
		else return OK;
	}
}