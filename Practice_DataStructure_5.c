// Queue (circular queue)
#include <stdio.h>
#include <stdlib.h>

// Queue settings
#define MAX_QUEUE 100
#define MAX_STACK 100
typedef enum { false, true } bool;
typedef int Data;

typedef struct
{
	Data items[MAX_STACK];
	int top;
} Stack;

typedef struct {
	Data items[MAX_QUEUE];
	int front, rear;
}Queue;

void InitStack(Stack* pstack)
{
	pstack->top = -1;
}

bool IsEmpty(Stack* pstack)
{
	return pstack->top == -1;
}

bool IsFull(Stack* pstack)
{
	return pstack->top == MAX_STACK - 1;
}

Data PeekS(Stack* pstack)
{
	if (IsEmpty(pstack)) exit(1);
	return pstack->items[pstack->top];
}

void Push(Stack* pstack, Data item)
{
	if (IsFull(pstack)) exit(1);
	pstack->items[++(pstack->top)] = item;
}

void Pop(Stack* pstack)
{
	if (IsEmpty(pstack)) exit(1);
	--(pstack->top);
}

void InitQueue(Queue* pqueue)
{
	pqueue->front = pqueue->rear = 0;
}

bool IsEmptyQ(Queue* pqueue)
{
	return pqueue->front = pqueue->rear;
}

bool IsFullQ(Queue* pqueue)
{
	return pqueue->front == (pqueue->rear + 1) % MAX_QUEUE;
}

Data PeekQ(Queue* pqueue)
{
	if (IsEmpty(pqueue)) exit(1);
	return pqueue->items[pqueue->front];
}

void EnQueue(Queue* pqueue, Data item)
{
	if (IsFull(pqueue)) exit(1);
	pqueue->items[pqueue->rear] = item;
	pqueue->rear = (pqueue->rear + 1) % MAX_QUEUE;
}

void DeQueue(Queue* pqueue)
{
	if (IsEmpty(pqueue)) exit(1);
	pqueue->front = (pqueue->front + 1) % MAX_QUEUE;
}

// Buffer Management
/**
void Producer(Queue* buffer, Data data)
{
	if (lock(buffer) == false)
	{
		if (!IsFull(buffer)) {
			EnQueue(buffer, data);
		}
		unlock(buffer);
	}
}

void Consumer(Queue* buffer, Data data)
{
	if (lock(buffer) == false)
	{
		if (!IsEmpty(buffer)) {
			Data data = Peek(buffer);
		}
		unlock(buffer);
	}
}
**/

// bank simulator
/**
#define MAX_SERV_TIME 100
typedef struct
{
	int id;
	int arrival_time;
	int service_time;
} Customer;

int waited_time = 0;
int served_customers = 0;
int num_customers = 0;

void InsertCustomer(Queue* pqueue, int id, int clock);
int RemoveCustomer(Queue* pqueue, int clock);
bool IsCustomerArrived();
void PrintStat();

int main(void)
{
	int service_time = 0, duration = 10;
	int clock = 0, id = 1;
	Queue queue;

	InitQueue(&queue);
	while (clock < duration) {
		clock++;
		printf("Time = %d\n", clock);
		if (IsCustomerArrived())
			InsertCustomer(&queue, id++, clock);
		if (service_time > 0) service_time--;
		else service_time = RemoveCustomer(&queue, clock);
	}
	PrintStat();
	return 0;
}

void InsertCustomer(Queue* pqueue, int id, int clock)
{
	Customer c;
	int service_time = (int)(rand() % MAX_SERV_TIME) + 1;

	if (IsFull(pqueue))
		return;

	c.id = id;
	c.arrival_time = clock;
	c.service_time = service_time;

	EnQueue(pqueue, c);
	printf("Customer %2d enters. service time: %d mins\n", id, service_time);
	num_customers++;
}

int RemoveCustomer(Queue* pqueue, int clock)
{
	Customer customer;
	int service_time = 0;

	if (IsEmpty(pqueue)) return 0;

	customer = Peek(pqueue);
	Dequeue(pqueue);

	service_time = customer.service_time;
	printf("Customer %2d: %2d mins service starts. waiting time: %2d mins\n", customer.id, service_time, clock - customer.arrival_time);

	served_customers++;
	waited_time += clock - customer.arrival_time;

	return service_time;
}
bool IsCustomerArrived()
{
	double prob = rand() / (double)RAND_MAX;
	if (prob >= 0.5) return true;
	else return false;
}
void PrintStat()
{
	printf("\nTotal waiting time = %d mins\n", waited_time);
	printf("Average waiting time per customer = %.2f mins\n", (double)waited_time / served_customers);
	printf("Number of served customer = %d\n", served_customers);
	printf("Number of waiting customers = %d\n", num_customers - served_customers);
}
**/

// Checking a palindrome using stack and queue
bool checkPalindrome(char* str, int len)
{
	Stack stack;
	Queue queue;

	InitStack(&stack);
	InitQueue(&queue);

	for (int i = 0; i < len; i++)
	{
		Push(&stack, str[i]);
		Enqueue(&queue, str[i]);
	}

	while (!IsEmptyQ(&queue))
	{
		if (PeekS(&stack) == PeekQ(&queue)) {
			Pop(&stack);
			DeQueue(&queue);
		}
		else
			return false;
	}
	return true;
}

int main(void) {
	char str[101];
	scanf("%s", &str);

	int len = strlen(str);

	if (checkPalindrome(str, len)) printf("Palindrome");
	else printf("Not Palindrome");
}