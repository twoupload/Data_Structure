// 스택 제작
// define을 이용해 관련 값을 정해놓는다. 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK 100


// 자신의 변수형을 지정
typedef enum {false, true} bool;
typedef int Data;
// 구조체 변수 지정. 구조체->스택
typedef struct {
	Data items[MAX_STACK];
	Data top;
}Stack;

// 스택을 초기화하는 함수
void InitStack(Stack* pstack) {
	pstack->top = -1; // ->는 스택의 포인터 주소의 값을 말한다. 
}
// 스택이 가득 찼는지 확인하는 함수
bool IsFull(Stack* pstack) {
	return pstack->top == MAX_STACK - 1;
}
// 스택이 비어있는지 확인하는 함수
bool IsEmpty(Stack* pstack) {
	return pstack->top == -1;
}
// 스택의 최상위(top)을 읽는 함수
Data Peek(Stack* pstack) {
	if (IsEmpty(pstack)) // pstack이 비어있는 경우==true(1)일 경우.
		exit(1); // 바로 프로그램을 종료한다. exit(0) = 정상종료, exit(1) = 에러메시지를 출력하여 종료.
	// 비어있지 않은 경우.
	return pstack->items[pstack->top];
}
// 스택의 최상위에 값을 입력하는 함수
void Push(Stack* pstack, Data item) {
	if (IsFull(pstack)) // 스택이 꽉 찰 경우
		exit(1);
	pstack->items[++(pstack->top)] = item;
}
// 가장 위의 값을 제거하는 함수
void Pop(Stack* pstack) {
	if (IsEmpty(pstack)) exit(1);
	--(pstack->top);
}

void ReversePrint(char* s, int len) {
	Stack stack;
	char ch;

	InitStack(&stack);
	for (int i = 0; i < len; i++)
		Push(&stack, s[i]);

	while (!IsEmpty(&stack))
	{
		ch = Peek(&stack);
		printf("%c", ch);
		Pop(&stack);
	}
}

int main(void) {
	char s[100];
	memset(s, 0, sizeof s);

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf(" %c", &s[i]);
	}
	
	int len = strlen(s);

	ReversePrint(s, len);

	return 0;
}

