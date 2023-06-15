#include <stdio.h>
#include <stdbool.h>

typedef struct _gnode {
	int id;
	struct _gnode* next;
}gNode;

typedef struct {
	int num;
	struct gnode** heads
}Graph;

void createNode(Graph* graph, int num) {
	graph->num = num;
	graph->heads = (gNode**)malloc(sizeof(gNode*) * num);
	for (int i = 0; i < num; i++) {
		graph->heads[i] = (gNode*)malloc(sizeof(gNode));
		graph->heads[i]->next = NULL;
	}
}

void desNode(Graph* graph) {
	for (int i = 0; i < graph->num; i++) {
		gNode* cur = graph->heads[i];
		while (cur != NULL) {
			gNode* temp = cur;
			cur = cur->next;
			free(temp);
		}
	}
	free(graph->heads);
}

void Add(Graph* graph, int src, int dest) {
	gNode* cur, * newNode1, * newNode2;

	newNode1 = (gNode*)malloc(sizeof(gNode));
	newNode1->id = dest;
	newNode1->next = NULL;

	cur = graph->heads[src];
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = newNode1;

	newNode2 = (gNode*)malloc(sizeof(gNode));
	newNode2->id = src;
	newNode2->next = NULL;

	cur = graph->heads[dest];
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = newNode2;
}

void DFS(Graph* graph) {
	Stack stack;
	bool* visited = (bool*)malloc(sizeof(bool) * graph->num);

	InitStack(&stack);
	Push(&stack, 0);
	while (!IsEmpty(&stack)) {
		gNode* cur;
		int vtx = SPeek(&stack);
		Pop(&stack);

		if (visited[vtx]) continue;
		else {
			Push(&stack, graph->heads[vtx]);
			printf("%d ", vtx);
		}

		cur = graph->heads[vtx]->next;
		while (cur != NULL) {
			if (!visited[cur->id])
				Push(&stack, cur->id);
			cur = cur->next;
		}
	}
}

void BFS(Graph* graph) {
	Queue queue;
	bool* visited = (bool*)malloc(sizeof(bool) * graph->num);
	for (int i = 0; i < graph->num; i++)
		visited[i] = false;

	InitQueue(&queue);
	EnQueue(&queue, 0);

	while (!IsEmpty(&queue)) {
		gNode* cur;
		int vtx = QPeek(&queue);
		DeQueue(&queue);

		if (visited[vtx]) continue;
		else {
			visited[vtx] = true;
			printf("%d ",vtx);
		}

		cur = graph->heads[vtx]->next;
		while (cur != NULL) {
			if (!visited[cur->id])
				EnQueue(&queue, cur->id);
			cur = cur->next;
		}
	}
}