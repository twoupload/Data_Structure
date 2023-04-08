//Palindrome Checker를 스택과 큐로 풀어보자
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max 100

typedef int Data;
typedef enum { false, true }bool;

typedef struct {
	int front, rear;
	Data items_q[Max];
}Queue;
typedef struct {
	int top;
	Data items_s[Max];
}Stack;

InitStack(Stack* pstack) {
	pstack->top = -1;
}
bool IsEmp(Stack* pstack) {
	return pstack->top == -1;
}
bool IsFul(Stack* pstack) {
	return pstack->top == Max - 1;
}
void Push(Stack* pstack, Data item) {
	if (IsFul(pstack)) exit(1);
	pstack->items_s[++(pstack->top)] = item;
}
void Pop(Stack* pstack) {
	if (IsEmp(pstack)) exit(1);
	--(pstack->top);
}
Data Peek_s(Stack* pstack) {
	return pstack->items_s[pstack->top];
}

InitQueue(Queue* pqueue) {
	pqueue->front = pqueue->rear = 0;
}
bool IsEmpty(Queue* pqueue) {
	return pqueue->front == pqueue->rear;
}
bool IsFull(Queue* pqueue) {
	return pqueue->front == (pqueue->rear + 1) % Max;
}
void Enqueue(Queue* pqueue, Data item) {
	if (IsFull(pqueue)) exit(1);
	pqueue->items_q[pqueue->rear] = item;
	pqueue->rear=(pqueue->rear + 1) % Max;
}
void Dequeue(Queue* pqueue) {
	if (IsEmpty(pqueue)) exit(1);
	pqueue->front = (pqueue->front + 1) % Max;
}
Data Peek_q(Queue* pqueue) {
	if (IsEmpty(pqueue)) exit(1);
	return pqueue->items_q[pqueue->front];
}

bool checkPalindrome(char* str, int len) {
	Stack stack;
	Queue queue;

	InitStack(&stack);
	InitQueue(&queue);
	for (int i = 0; i < len; i++) {
		Push(&stack, str[i]);
		Enqueue(&queue, str[i]);
	}

	while (!IsEmpty(&queue)) {
		if (Peek_s(&stack) == Peek_q(&queue)) {
			Pop(&stack);
			Dequeue(&queue);
		}
		else
			return false;
	}
	return true;
}

int main(void) {
	char str[101];
	int len;
	scanf("%s", &str);
	len = strlen(str);

	if (checkPalindrome(str, len))
		printf("This is Palindrome");


	else printf("This is not Palindrome");
	return 0;
}