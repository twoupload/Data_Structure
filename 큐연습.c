#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE 100

typedef int Data;
typedef enum { false, true }bool;
typedef struct {
	int front, rear;
	Data items[MAX_QUEUE];
}Queue;

void Initqueue(Queue* pqueue) {
	pqueue->front = pqueue->rear = 0;
}

bool IsEmpty(Queue* pqueue) {
	return pqueue->front = pqueue->rear;
}

bool IsFull(Queue* pqueue) {
	return pqueue->front == (pqueue->rear + 1) % MAX_QUEUE;
}

Data Peek(Queue* pqueue) {
	if (IsEmpty(pqueue)) exit(1);
	return pqueue->items[pqueue->front];
}

void Enqueue(Queue* pqueue, Data item) {
	if (IsFull(pqueue)) exit(1);
	pqueue->items[pqueue->rear] = item;
	pqueue->rear = (pqueue->rear + 1) % MAX_QUEUE;
}

void Dequeue(Queue* pqueue) {
	if (IsEmpty(pqueue)) exit(1);
	pqueue->front = (pqueue->front + 1) % MAX_QUEUE;
}