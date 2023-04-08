// Dequeue = front와 rear에서 둘 다 add, remove가 가능한 자료구조.
// Palindrome = 서로 짝을 이루는 단어 찾기.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DEQUE 100

typedef enum { false, true }bool;
typedef int Data;
typedef struct {
	int front, rear;
	Data items[MAX_DEQUE];
}Deque;

void InitDeque(Deque* pdeque) {
	pdeque->front == pdeque->rear;
}
bool IsFull(Deque* pdeque) {
	return pdeque->front = (pdeque->rear + 1) % MAX_DEQUE;
}
bool IsEmpty(Deque* pdeque) {
	return pdeque->front = pdeque->rear;
}
void AddFront(Deque* pdeque, Data item) {

}
void AddRear(Deque* pdeque, Data item) {
	if (IsFull(pdeque)) exit(1);
	pdeque->items[pdeque->rear] = item;
	pdeque->rear = (pdeque->rear + 1) % MAX_DEQUE;
}
void RemoveFront(Deque* pdeque) {
	if (IsEmpty(pdeque)) exit(1);
	pdeque->front = (pdeque->front + 1) % MAX_DEQUE;
}
void RemoveRear(Deque* pdeque);
Data PeekFront(Deque* pdeque) {
	if (IsEmpty(pdeque)) exit(1);
	return pdeque->items[(pdeque->front+1)%MAX_DEQUE];
}
Data PeekRear(Deque* pdeque) {
	if (IsEmpty(pdeque)) exit(1);
	return pdeque->items[pdeque->rear];
}


bool checkPalindrome(char* str, int len) {
	Deque deq;

	InitDeque(&deq);
	for (int i = 0; i < len; i++) 
		AddRear(&deq, str[i]);

	while (len > 1) 
	{
		if (PeekFront(&deq) == PeekRear(&deq))
		{
			RemoveFront(&deq), RemoveRear(&deq);
			len = len - 2;
		}
		else
			return false;
	}
	return true;
}

int main(void) {
	char Get_Palindrome[101];
	scanf("%s", &Get_Palindrome);

	int len = strlen(Get_Palindrome);

	if (checkPalindrome(Get_Palindrome, len))
		printf("This is Palindrome");
	else
		printf("This is not Palindrome");
}