#pragma once
#pragma execution_character_set("utf-8")

#include "testGraph.h"
#include <stdio.h>
void testGraph() {
	int choice = 1;
	while (choice) {
		printf("please input your choice:\n");
		printf("0 exit\n");
		printf("1 test graph with array\n");
		printf("2 test graph with lsit\n");
		scanf_s("%d", &choice);

		switch (choice) {
		case 0:
			return;
		case 1:
			testGraphWithArray();
			break;
		case 2:
			testGraphWithList();
			break;
		case 3:
			break;
		default:
			break;
		}
	}

}
void testGraphWithArray() {
	MGraph G;
	printf("%d\n", sizeof(G));
	if (CreateUDN(G)) {
		printf("success to create graph.\n ");
		PrintGraph(G);
	}
}
void testGraphWithList() {
	ALGraph G;
	printf("%d\n", sizeof(G));
	if (CreateDN(G)) {
		printf("success to create graph.\n ");
		PrintGraph(G);
	}
	printf("Depth_First Search:\n");
	int(*Visit)(VertexType v) = visit;
	DFSTraverse(G, Visit);

	printf("Breadth_First Search:\n");
	BFSTraverse(G, Visit);

	printf("destroy the graph:\n");
	DestroyGraph(G);
	PrintGraph(G);
}
int visit(VertexType v) {
	printf("%c\t", v);
	return OK;
}
void PrintGraph(MGraph G) {
	printf("num of vertexs:\t%d\n", G.vexnum);
	printf("num of arcs:\t%d\n", G.arcnum);
	printf("the list of the vertexs:\n");
	for (int i = 0; i < G.vexnum; i++) {
		printf("%c ", G.vexs[i]);
	}
	printf("\n");
	printf("the matrics of the arcs:\n");
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			printf("%d\t", G.arcs[i][j].adj);
		}
		printf("\n");
	}
	printf("\n");
}

void PrintGraph(ALGraph G) {
	printf("num of vertexs:\t%d\n", G.vexnum);
	printf("num of arcs:\t%d\n", G.arcnum);
	printf("the list of the vertexs and their adjacent vertices:\n");
	for (int i = 0; i < G.vexnum; i++) {
		printf("%c ->", G.vertices[i].data);
		for (ArcNode *cur = G.vertices[i].firstarc; cur != nullptr; cur = cur->nextarc) printf("%d->", cur->adjvex);
		printf("\n");
	}
	
}