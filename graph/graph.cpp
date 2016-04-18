#include "graph.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "../queue/queue.h"
namespace graph {

	//the graph stored as the array

	Status CreateGraph(MGraph &G) {
		/*printf("input the kind of the graph:\n");*/
		return OK;
	}


	Status CreateUDN(MGraph &G) {
		printf("input the number of the vertexs:\n");
		scanf("%d", &G.vexnum);
		printf("input the number of the arcs:\n");
		scanf("%d", &G.arcnum);
		printf("is there any info about the arc? 1 is yes, 0 is no:\n");
		int IncInfo;
		scanf("%d", &IncInfo);
		G.kind = UDN;
		//构造顶点向量
		for (int i = 0; i < G.vexnum; i++) {
			printf("input the %dth vertex:\n", i + 1);
			scanf("\n%c", &G.vexs[i]);
		}

		//初始化邻接矩阵
		for (int i = 0; i < G.vexnum; i++) {
			for (int j = 0; j < G.vexnum; j++) {
				G.arcs[i][j] = { INFINITY, nullptr };
			}
		}

		//构造邻接矩阵
		for (int i = 0; i < G.arcnum; i++) {
			printf("input two vertexs which are linked and the weight of the arc:\n");
			char v1;
			char v2;
			int weight;
			scanf("\n%c %c %d", &v1, &v2, &weight);
			int m = locateVex(G, v1);
			int n = locateVex(G, v2);
			if (m >= 0 && n >= 0) G.arcs[m][n].adj = weight;
			else {
				printf("error input of vertex\n");
				continue;
			}

			if (IncInfo) {
				printf("input the info about the arc:\n");
				char info[256];
				getchar();
				gets(info);
				G.arcs[m][n].info = info;
			}
			G.arcs[n][m] = G.arcs[m][n];

		}

		return OK;
	}

	int locateVex(MGraph G, VertexType v) {
		for (int i = 0; i < G.vexnum; i++) {
			if (G.vexs[i] == v) return i;
		}
		return -1;
	}

	/*************************************************************************************************************************************/
	//the graph stored as the adjacency list

	Status CreateDN(ALGraph &G) {
		printf("input the number of the vertexs:\n");
		scanf("%d", &G.vexnum);
		printf("input the number of the arcs:\n");
		scanf("%d", &G.arcnum);
		printf("is there any info about the arc? 1 is yes, 0 is no:\n");
		int IncInfo;
		scanf("%d", &IncInfo);
		G.kind = UDN;
		//构造顶点向量
		for (int i = 0; i < G.vexnum; i++) {
			printf("input the %dth vertex:\n", i + 1);
			scanf("\n%c", &G.vertices[i].data);
			G.vertices[i].firstarc = nullptr;
		}

		//构建定点相连的弧信息
		for (int i = 0; i < G.arcnum; i++) {
			printf("input two vertexs which are linked:v1 -> v2 \n");
			VertexType v1;
			VertexType v2;
			scanf("\n%c %c", &v1, &v2);
			int m = locateVex(G, v1);
			int n = locateVex(G, v2);

			ArcNode *newNode = (ArcNode*)malloc(sizeof(ArcNode));
			newNode->adjvex = n;
			newNode->nextarc = nullptr;
			if (IncInfo) {
				printf("input the info about the arc:\n");
				char info[256];
				getchar();
				gets(info);
				newNode->info = info;
			}

			ArcNode *end;
			if (G.vertices[m].firstarc) {
				for (end = G.vertices[m].firstarc; end->nextarc != nullptr; end = end->nextarc);
				end->nextarc = newNode;
			}
			else G.vertices[m].firstarc = newNode;

			
				
		}
		return OK;
	}

	int locateVex(ALGraph G, VertexType v) {
		for (int i = 0; i < G.vexnum; i++) {
			if (G.vertices[i].data == v) return i;
		}
		return -1;
	}

	Status DestroyGraph(ALGraph &G) {
		for (int i = 0; i < G.vexnum; i++) {
			ArcNode* next;
			for (ArcNode* cur = G.vertices[i].firstarc; cur != nullptr; cur = next) {
				next = cur->nextarc;
				free(cur);
			}
		}
		G.arcnum = 0;
		G.vexnum = 0;
		return OK;
	}
	
	
	void DFSTraverse(ALGraph G, Status(*visit)(VertexType v)) {
		bool visited[MAX_VERTEX_NUM];
		for (int i = 0; i < G.vexnum; i++) visited[i] = false;
		for (int i = 0; i < G.vexnum; i++) {
			if (!visited[i]) DFS(G, i, visit, visited);
		}
		printf("\n");
	}
	void DFS(ALGraph G, int n, Status(*visit)(VertexType v), bool visited[]) {
		visited[n] = true;
		visit(G.vertices[n].data);
		for (ArcNode *cur = G.vertices[n].firstarc; cur != nullptr; cur = cur->nextarc) {
			int i = cur->adjvex;
			if (!visited[i]) DFS(G, i, visit, visited);
		}
	}

	void BFSTraverse(ALGraph G, Status(*visit)(VertexType v)) {
		bool visited[MAX_VERTEX_NUM];
		for (int i = 0; i < G.vexnum; i++) {
			visited[i] = false;
		}
		queue::LinkQueue Q;
		queue::InitQueue(Q);
		for (int i = 0; i < G.vexnum; i++) {
			if (!visited[i]) {
				visited[i] = true;
				visit(G.vertices[i].data);
				queue::QElemType e;
				e = i;
				queue::EnQueue(Q, e);
				while (!queue::QueueEmpty(Q)) {
					queue::QElemType u;
					queue::DeQueue(Q, u);
					for (ArcNode* cur = G.vertices[u].firstarc; cur != nullptr; cur = cur->nextarc) {
						e = cur->adjvex;
						if (!visited[e]) {
							visited[e] = true;
							visit(G.vertices[e].data);
							queue::EnQueue(Q, e);
						}
					}
				}
			}
		}
		printf("\n");

	}

}