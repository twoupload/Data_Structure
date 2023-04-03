// stack을 이용하여 Reverse String.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK 100 //define을 이용하여 stack의 최댓값을 100으로 잡는다. 

// 스택의 요소 구현
typedef int Data; // Data라는 이름으로 int를 사용하겠음.
typedef enum {false, true} bool; // bool 헤더를 사용하지 않고 bool 구현

// 스택 구현 -> 구조체 사용
typedef struct {
	Data top; // 스택의 가장 위의 값
	Data items[MAX_STACK]; // 스택으로 사용할 배열 구현
}Stack;

// 스택을 사용할 함수 구현
void InitStack(Stack* pstack); // 스택을 초기화
bool IsEmpty(Stack* pstack); // 스택이 비어있는지 확인
bool IsFull(Stack* pstack); // 스택이 다 찼는지 확인
void Push(Stack* pstack, Data item); // 스택의 top 값에 item을 넣음.
void Pop(Stack* pstack); // 스택의 top 값을 삭제
Data Peek(Stack* pstack); // 스택의 top 값을 return 함.


void RevString(char* str, int len);


int main(void) { // 메인 함수
	char str[100]=""; // 바뀌기 전의 문자열을 담을 배열
	scanf("%s", &str); // 입력받음.

	int len = strlen(str); // 문자열의 길이

	RevString(str, len); // 함수를 이용해 문자열을 반대로 만듦.

	return 0;
}

// 스택 함수 및 사용 함수 구현
void InitStack(Stack* pstack) {
	pstack->top = -1;
}

bool IsEmpty(Stack* pstack) {
	return pstack->top == -1; // top 값이 -1이라면(아무것도 넣지 않았다면,) 참을 return 
}

bool IsFull(Stack* pstack) {
	return pstack->top == MAX_STACK - 1; // top 값이 define한 값보다 -1 작은 값(최대로 찬 것)이라면, 참을 return 
}

void Push(Stack* pstack, Data item) {
	if (IsFull(pstack)) exit(1);// 만약, 스택에 더 넣을 수 없을 정도로 꽉 찼다면, exit(1)를 한다. 에러를 내면서 종료.
	pstack->items[++(pstack->top)] = item; // 스택의 top 값을 하나 증가시키고 그것을 items 배열에 item 값을 넣는다. 
}

void Pop(Stack* pstack) {
	if (IsEmpty(pstack)) exit(1); // 만약 스택에 아무것도 없다면, 에러를 내면서 종료
	--(pstack->top);  // top 값을 하나 종료.
}

Data Peek(Stack* pstack) {
	if (IsEmpty(pstack)) exit(1);
	return pstack->items[pstack->top]; // top 값 하나를 return 
}


void RevString(char* str, int len) {
	Stack stack;
	char ch[100] = {0};
	int idx = 0;
	InitStack(&stack);

	for (int i = 0; i < len; i++) {
		Push(&stack, str[i]);
	}

	while (!IsEmpty(&stack)) {
		ch[idx++] = Peek(&stack);
		Pop(&stack);
	}
	for (int i = 0; i < len; i++) {
		printf("%c", ch[i]);
	}
}