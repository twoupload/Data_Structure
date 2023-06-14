#include <stdio.h>
// #include <stdbool.h>
#define MAX_HEAP 100 // ���� ���� �ִ�ġ�� ����

typedef enum { false, true } bool; // ���� ������ ���� ��� #include <stdbool.h> ��� ��� ����
typedef char Data; // char�� Data��� ���

typedef struct {
	Data data; // �� ������ ��
	int priority; // �켱����
}HNode;

typedef struct {
	HNode items[MAX_HEAP + 1];
	int num; // ���� ä���� ����� ����
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