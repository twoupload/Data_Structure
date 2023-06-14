#include "Heap.h"
#include <stdbool.h>

typedef Heap PQueue;

void InitPQueue(PQueue* ppqueue) {
	InitHeap(ppqueue);
}

bool IsPQEmpty(PQueue* ppqueue)
{
	return IsEmpty(ppqueue);
}
bool IsPQFuLL(PQueue* ppqueue)
{
	return IsFull(ppqueue);
}

void Enqueue(PQueue* ppqueue, int data, int priority)
{
	Insert(ppqueue, data, priority);
}
int Dequeue(PQueue* ppqueue)
{
	return Delete(ppqueue);
}
