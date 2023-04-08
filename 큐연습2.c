// ��ȣ ����
// producer�� ť���� ��� ���� ���� �ְ�
// consumer�� ť���� �װ��� ���ʴ�� �̴´�. 

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
// �������� ���� ���μ���
void Producer(Queue* buffer, Data data) { // ������ �Լ�(buffer�� �̸����� ť, ������)
	if (lock(buffer) == false) { // lock�� �ɷ��ִ°�? ���� ������ �����ΰ�?
		if (!IsFull(buffer)) { // ť�� �������� �ʾҴٸ�, 
			Enqueue(buffer, data); // ť�� ������ ���� �ִ´�. 
		}
		unlock(buffer); // buffer�� ���� lock�� Ǯ���ش�. 
	}
}

// �Һ����� ���� ���μ���
void Consumer(Queue* buffer, Data data) {
	if (lock(buffer) == false) { // ������ ���� �����Ѱ�?
		if (!IsEmpty(buffer)) { // buffer��� ť�� ������� �ʾҴٸ�, 
			Data data= dequeue(buffer); // buffer�� �̾Ƴ���. 
		}
		unlock(buffer); // ���� �����Ѵ�. 
	}
}