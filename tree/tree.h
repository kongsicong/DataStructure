#ifndef _TREE_H_
#define _TREE_H_
namespace tree {
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

	typedef int Status;
	typedef char TElemType;
	typedef struct BiTNode {
		TElemType data;
		struct BiTNode *lchild;
		struct BiTNode *rchild;
	}BiTNode, *BiTree;


	Status CreateBiTree(BiTree &T);

	Status PreOrderTraverse(BiTree T, Status(*visit)(TElemType e));

	Status InOrderTraverse(BiTree T, Status(*visit)(TElemType e));

	Status PostOrderTraverse(BiTree T, Status(*visit)(TElemType e));

	Status LevelOrderTraverse(BiTree T, Status(*visit)(TElemType e));
}



#endif //_TREE_H_