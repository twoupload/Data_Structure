#include "queue.h" // 큐에 대한 매크로 정의
#include <stdlib.h>
#include <stdio.h>

#define MAX_SERV_TIME 10
#define MAX_QUEUE 100

typedef enum { false, true } bool;
typedef int Data;

typedef struct {
	int front, rear;
	Data items[MAX_QUEUE];
}Queue;

void InitQueue(Queue* pqueue);
bool IsFull(Queue* pqueue);
bool IsEmpty(Queue* pqueue);
Data Peek(Queue* pqueue);
void EnQueue(Queue* pqueue);
void DeQueue(Queue* pqueue);

void InitQueue(Queue* pqueue) {
	pqueue->front = pqueue->rear = 0;
}
bool IsFull(Queue* pqueue) {
	return pqueue->front == (pqueue->rear + 1) % MAX_QUEUE;
}
bool IsEmpty(Queue* pqueue) {
	return pqueue->front = pqueue->rear;
}
Data Peek(Queue* pqueue) {
	if (IsEmpty(pqueue)) exit(1);
	return pqueue->items[pqueue->front];
}
void EnQueue(Queue* pqueue, Data item) {
	if (IsFull(pqueue)) exit(1);
	pqueue->items[pqueue->front] = item;
	pqueue->rear = (pqueue->rear + 1) % MAX_QUEUE;
}
void DeQueue(Queue* pqueue) {
	if (IsEmpty(pqueue)) exit(1);
	pqueue->front = (pqueue->front + 1) % MAX_QUEUE;
}

typedef struct
{ // 손님의 인적사항
	int id; // 손님의 id
	int arrival_time; // 손님이 도착한 시간
	int service_time; // 손님이 서비스를 받은 시간.
}Customer; 

int waited_time = 0; // 대기시간
int served_customers = 0; // 서비스를 받고 있는 고객의 수
int num_customers = 0; // 대기순번

int main() {
	int service_time = 0, duration = 10; // 서비스 타임의 초기화, 기간의 최대길이는 10분.
	int clock = 0, id = 1; // 시간을 0으로 초기화, 순번(아이디)는 1로 초기화
	Queue queue; // 큐를 지정한다.

	InitQueue(&queue); // 큐를 초기화
	while (clock < duration) { // 지금 운영을 하고 있을 때만,
		clock++; // 시간++;
		printf("Time = %d\n", clock); // 시간을 나타내고 있다.
		if (IsCustomerArrived()) // 
			InsertCustomer(&queue, id++, clock);
		if (service_time > 0) service_time--; // 만약 서비스 타임이 0이 아니라면, 감소
		else service_time = RemoveCustomer(&queue, clock); //서비스 타임이 0이라면 삭제.
	}
	printfStat();
	return 0;
}

void InsertCustomer(Queue* pqueue, int id, int clock) {
	Customer c; // 손님의 인적사항 구조체 생성.
	int service_time = (int)(rand() % MAX_SERV_TIME) + 1; // 서비스 타임을 무작위로 선정
	if (IsFull(pqueue)) return; // 다 찬 경우 반환

	c.id = id; // 아이디
	c.arrival_time = clock; // 도착 시간
	c.service_time = service_time; // 서비스 타임

	EnQueue(pqueue, c); // 큐에 손님의 인적 사항을 넣음. 
	printf("Customer %2d enters. service tiem: %d mins\n", id, service_time);
	num_customers++; // 고객의 수
}

int RemoveCustomer(Queue* pqueue, int clock) {
	Customer customer; // 고객의 인적사항
	int service_time = 0; // 서비스 타임을 0으로 초기화
	if (IsEmpty(pqueue)) return 0; // 큐에 있는 것을 삭제 후 함수 종료.
	customer = Peek(pqueue); // 고객의 인적사항을 peek하여 꺼낸다. 
	DeQueue(pqueue); // 삭제

	service_time = customer.service_time; // 서비스 타임 = 고객의 서비스 타임
	printf("Customer %2d: %2d mins service starts. waiting time: %2d mins\n", customer.id, service_time, clock - customer.arrival_time);

	served_customers++;
	waited_time += clock - customer.arrival_time;

	return service_time;
}

bool IsCustomerArrived() {
	double prob = rand() / (double)RAND_MAX;
	if (prob >= 0.5) return true;
	else return false;
}

void PrintStat() {
	printf("\nTotal waiting time = %d mins\n", waited_time);
	printf("Average waiting time per customer = %.2f mins\n", (double)waited_time / served_customers);
	printf("Number of served customer = %d\n", served_customers);
	printf("Number of waiting customers = %d\n", num_customers - served_customers);

}