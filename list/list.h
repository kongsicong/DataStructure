#ifndef _LIST_H_
#define _LIST_H_
namespace mylib {
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

	typedef int Status;
	typedef struct LNode{
		int data;
		struct LNode * next;
	} LinkList, LNode;
	//创建带有n个节点的链表
	LinkList* InitalList();
	LinkList* CreateList(int n);
	int lenghOfList(LinkList& L);
	void PrintLinkList(LinkList& L);
	Status GetElemOfList(LinkList& L, int pos, int& value); // search
	Status InsertIntoList(LinkList& L, int pos, int value);// add
	Status push_back(LinkList& L, int value);
	Status DeleteFormList(LinkList& L, int pos, int& deleteValue); // delete
	Status pop_back(LinkList& L, int& value);
	Status UpdateList(LinkList& L, int pos, int newValue); // update
	Status ClearList(LinkList& L);

	void MergeLists(LinkList& Ls, LinkList& La, LinkList& Lb);
}

#endif //_LIST_H_