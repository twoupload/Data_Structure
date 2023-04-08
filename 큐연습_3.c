#include "queue.h" // ť�� ���� ��ũ�� ����
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
{ // �մ��� ��������
	int id; // �մ��� id
	int arrival_time; // �մ��� ������ �ð�
	int service_time; // �մ��� ���񽺸� ���� �ð�.
}Customer; 

int waited_time = 0; // ���ð�
int served_customers = 0; // ���񽺸� �ް� �ִ� ���� ��
int num_customers = 0; // ������

int main() {
	int service_time = 0, duration = 10; // ���� Ÿ���� �ʱ�ȭ, �Ⱓ�� �ִ���̴� 10��.
	int clock = 0, id = 1; // �ð��� 0���� �ʱ�ȭ, ����(���̵�)�� 1�� �ʱ�ȭ
	Queue queue; // ť�� �����Ѵ�.

	InitQueue(&queue); // ť�� �ʱ�ȭ
	while (clock < duration) { // ���� ��� �ϰ� ���� ����,
		clock++; // �ð�++;
		printf("Time = %d\n", clock); // �ð��� ��Ÿ���� �ִ�.
		if (IsCustomerArrived()) // 
			InsertCustomer(&queue, id++, clock);
		if (service_time > 0) service_time--; // ���� ���� Ÿ���� 0�� �ƴ϶��, ����
		else service_time = RemoveCustomer(&queue, clock); //���� Ÿ���� 0�̶�� ����.
	}
	printfStat();
	return 0;
}

void InsertCustomer(Queue* pqueue, int id, int clock) {
	Customer c; // �մ��� �������� ����ü ����.
	int service_time = (int)(rand() % MAX_SERV_TIME) + 1; // ���� Ÿ���� �������� ����
	if (IsFull(pqueue)) return; // �� �� ��� ��ȯ

	c.id = id; // ���̵�
	c.arrival_time = clock; // ���� �ð�
	c.service_time = service_time; // ���� Ÿ��

	EnQueue(pqueue, c); // ť�� �մ��� ���� ������ ����. 
	printf("Customer %2d enters. service tiem: %d mins\n", id, service_time);
	num_customers++; // ���� ��
}

int RemoveCustomer(Queue* pqueue, int clock) {
	Customer customer; // ���� ��������
	int service_time = 0; // ���� Ÿ���� 0���� �ʱ�ȭ
	if (IsEmpty(pqueue)) return 0; // ť�� �ִ� ���� ���� �� �Լ� ����.
	customer = Peek(pqueue); // ���� ���������� peek�Ͽ� ������. 
	DeQueue(pqueue); // ����

	service_time = customer.service_time; // ���� Ÿ�� = ���� ���� Ÿ��
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