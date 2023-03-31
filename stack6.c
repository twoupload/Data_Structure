#include <stdio.h> // main 함수를 시작하기 위한 헤더
#include <stdlib.h> 
#include <ctype.h> // digit 함수를 시작하기 위한 헤더
#include <string.h>// strlen 함수를 시작하기 위한 헤더

#define MAX_STACK 100 // 스택의 최댓값을 100으로 지정
typedef int Data; // int 형의 'Data'라는 형을 제작
typedef enum { false, true } bool; // enum 형태의 'bool'이라는 형을 제작. 0일때 false, 1일때 true.
typedef struct { // 구조체 Stack
	Data top; // 스택의 가장 위.
	Data items[MAX_STACK]; // 스택 배열.
}Stack;

void InitStack(Stack* pstack); // 스택을 초기화하는 함수
bool IsEmpty(Stack* pstack); // 스택이 비어있는지 확인하는 함수
bool IsFull(Stack* pstack); // 스택이 다 찼는지 확인하는 함수
void Push(Stack* pstack, Data item); // 스택에 값을 집어넣는 함수
void Pop(Stack* pstack); // 스택에 top 값을 삭제하는 함수
Data Peek(Stack* pstack); // 스택의 top 값을 반환하는 함수

bool ComPriority(Data c1, char c2);
void ConvInfixToPostfix(char* str, char* conv, int len); // Infix를 Postfix로 변환하는 함수

int main(void) { // main 함수
	char exp[100]=""; // 산술식을 입력받을 배열
	char convExp[100]=""; // Postfix로 변환 뒤 넣어질 배열
	int len; // exp의 길이.

	scanf("%s", &exp); // 산술식을 입력받음

	len = strlen(exp); // strlen을 통해 exp의 길이를 구함

	ConvInfixToPostfix(exp, convExp, len); // exp를 conv하여 convExp함수에 집어넣는 함수

	for (int i = 0; i < len; i++) {
		printf("%c ", convExp[i]);
	}

	return 0;
}

void InitStack(Stack* pstack) {
	pstack->top = -1;
}
bool IsEmpty(Stack* pstack) {
	return pstack->top == -1;
}
bool IsFull(Stack* pstack) {
	return pstack->top == MAX_STACK-1;
}
void Push(Stack* pstack, Data item) {
	if (IsFull(pstack)) exit(1);
	pstack->items[++(pstack->top)] = item;
}
void Pop(Stack* pstack) {
	if (IsEmpty(pstack)) exit(1);
	--(pstack->top);
}
Data Peek(Stack* pstack) {
	if (IsEmpty(pstack)) exit(1);
	return pstack->items[pstack->top];
}

bool ComPriority(Data c1, char c2) {
	int p1, p2;
	c1 = (char)c1;

	if (c1 == '*' || c1 == '/') {
		p1 = 5;
	}
	else {
		p1 = 2;
	}

	if (c2 == '*' || c2 == '/') {
		p2 = 5;
	}
	else {
		p2 = 2;
	}

	if (p1 >= p2) return true;
	else return false;
}

void ConvInfixToPostfix(char* exp, char* convExp, int len) {
	Stack stack; // stack을 불러온다. 
	int idx = 0; // conv에 차례로 저장할 장치
	InitStack(&stack); // 스택을 초기화한다. 
	for (int i = 0; i < len; i++) { // str의 길이만큼 for문으로 반복.
		if (isdigit(exp[i])) { // isdigit = 수가 나오면, 그 수 수가 아닌게 나오면, 0 return
			convExp[idx] = exp[i]; // str[i]가 숫자인 경우 conv에 수를 저장한다.  
			idx++; //넣을 수록 idx는 증가한다.
		}
		else { // 십진수가 아닌 경우, '연산자'인 경우.
			while (!IsEmpty(&stack) && ComPriority(Peek(&stack), exp[i])) { // 스택이 비어있지 않고, 연산자를 비교해서 참인경우
				// ComPriority(Peek(&stack),str[i]) : 두 연산자를 비교하여 어느것이 더 큰가?
				// Peek한 연산자가 더 작은 경우
				convExp[idx++] = Peek(&stack); // conv 배열에 stack의 top에 있는 연산자를 peek하여 넣는다.
				Pop(&stack); // 연산자를 삭제
			}
			Push(&stack, exp[i]); // 연산자를 넣는다.
		}
	}
	while (!IsEmpty(&stack)) { // 스택이 전부 빌 때까지 반복한다.
		convExp[idx++] = Peek(&stack); // 스택에 있는 모든 연산자를 conv 함수에 넣는다. 
		Pop(&stack); // 스택을 전부 삭제한다. 
	}
}
