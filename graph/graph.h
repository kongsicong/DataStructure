#ifndef _GRAPH_H_
#define _GRAPH_H_
namespace graph {
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

	typedef int Status;

#define MAX_VERTEX_NUM 20
	typedef char InfoType;
	typedef char VertexType;
	typedef enum { DG, DN, UDG, UDN } GraphKind;
	//the graph stored as the array
#define INFINITY INT_MAX

	typedef int VRType;
	
	typedef struct ArcCell {
		VRType adj;
		InfoType *info;
	}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	typedef struct {
		VertexType vexs[MAX_VERTEX_NUM];
		AdjMatrix arcs;
		int vexnum;
		int arcnum;
		GraphKind kind;
	}MGraph;

	Status CreateGraph(MGraph &G);
	Status CreateUDN(MGraph &G);
	int locateVex(MGraph G, VertexType v);

	


	/*****************************************************************************************************************************************************/

	//the graph stored as the adjacency list
	typedef struct ArcNode {
		int adjvex;
		struct ArcNode *nextarc;
		InfoType *info;
	}ArcNode;

	typedef struct VNode {
		VertexType data;
		ArcNode *firstarc;
	}VNode, AdjList[MAX_VERTEX_NUM];

	typedef struct {
		AdjList vertices;
		int vexnum;
		int arcnum;
		int kind;
	}ALGraph;
	Status CreateDN(ALGraph &G);
	int locateVex(ALGraph G, VertexType v);
	Status DestroyGraph(ALGraph &G);

	//depth_first search
	void DFSTraverse(ALGraph G, Status(*visit)(VertexType v));
	void DFS(ALGraph G, int n, Status(*visit)(VertexType v), bool visited[]);
	

	//breadth_first search
	void BFSTraverse(ALGraph G, Status(*visit)(VertexType v));
}

#endif // _GRAPH_H_