// 신호 관리
// producer가 큐에서 어떠한 것을 집어 넣고
// consumer가 큐에서 그것을 차례대로 뽑는다. 

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
// 제공자의 관련 프로세스
void Producer(Queue* buffer, Data data) { // 제공자 함수(buffer의 이름으로 큐, 데이터)
	if (lock(buffer) == false) { // lock이 걸려있는가? 접근 가능한 상태인가?
		if (!IsFull(buffer)) { // 큐가 가득차지 않았다면, 
			Enqueue(buffer, data); // 큐에 데이터 값을 넣는다. 
		}
		unlock(buffer); // buffer에 대한 lock을 풀어준다. 
	}
}

// 소비자의 관련 프로세스
void Consumer(Queue* buffer, Data data) {
	if (lock(buffer) == false) { // 지금은 접근 가능한가?
		if (!IsEmpty(buffer)) { // buffer라는 큐가 비어있지 않았다면, 
			Data data= dequeue(buffer); // buffer을 뽑아낸다. 
		}
		unlock(buffer); // 락을 해제한다. 
	}
}