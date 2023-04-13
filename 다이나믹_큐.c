#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;
typedef int Data;

typedef struct _Node
{
	Data item;
	struct _Node* next;
} Node;

typedef struct
{
	Node* rear;
	Node* front;
}DQueue;

void InitQueue(DQueue* pqueue)
{
	pqueue->front = pqueue->rear = NULL;
}

bool IsEmpty(DQueue* pqueue)
{
	return pqueue->front == NULL;
}

Data Peek(DQueue* pqueue)
{
	if (IsEmpty(pqueue))
		exit(1);
	return pqueue->front->item;
}

void EnQueue(DQueue* pqueue, Data item)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->item = item;

	if (IsEmpty(pqueue))
		exit(1);
	else {
		pqueue->rear->next = newNode;
		pqueue->rear = newNode;
	}
}

void DeQueue(DQueue* pqueue)
{
	Node* temp;
	if (IsEmpty(pqueue))
		exit(1);
	temp = pqueue->front;
	if (temp->next == NULL) // 하나뿐인 경우.
		pqueue->front = pqueue->rear = NULL;
	else
		pqueue->front = temp->next;
	free(temp);
}