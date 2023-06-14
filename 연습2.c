#include <stdio.h>
// #include <stdbool.h>
#define MAX_HEAP 100 // 힙에 대한 최대치를 고정

typedef enum { false, true } bool; // 참과 거짓을 결정 대신 #include <stdbool.h> 대신 사용 가능
typedef char Data; // char를 Data라고 사용

typedef struct {
	Data data; // 들어갈 데이터 값
	int priority; // 우선순위
}HNode;

typedef struct {
	HNode items[MAX_HEAP + 1];
	int num; // 현재 채워진 노드의 갯수
}Heap;

void InitHeap(Heap* pheap)
{
	pheap->num = 0;
}

bool IsEmpty(Heap* pheap)
{
	return pheap->num == 0;
}

bool IsFull(Heap* pheap)
{
	return pheap->num == MAX_HEAP;
}

void Insertion(Heap* pheap, Data data, int priority)
{
	HNode* newNode;
	int idx = pheap->num + 1;
	if (IsFull(pheap)) exit(1);
}