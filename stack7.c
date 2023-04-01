// infix to prefix with stack
/** 
구현한 방법
temp 함수에 문자열을 담는다.
exp 함수에 temp 함수를 거꾸로 담는다.
exp 함수를 postfix를 만든 방법 그대로 postfix화 한다.
convExp 함수를 거꾸로 출력한다. 
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK 100
typedef int Data;
typedef enum { false, true }bool;
typedef struct {
	Data items[MAX_STACK];
	Data top;
}Stack;

void InitStack(Stack* pstack);
bool IsEmpty(Stack* pstack);
bool IsFull(Stack* pstack);
void Push(Stack* pstack, Data item);
void Pop(Stack* pstack);
Data Peek(Stack* pstack);

bool ComPriority(Data c1, char c2);
void Conv(char* exp, char* convExp, int len);

int main(void) {
	char temp[100] = "";
	char exp[100]="";
	char convExp[100]="";
	int cnt = 0;

	scanf("%s", &temp);

	int len = strlen(temp);

	for (int i = len - 1; i >= 0; i--) {
		exp[cnt] = temp[i];
		cnt++;
	}

	exp[len] = "\0";

	Conv(exp, convExp, len);

	for (int i = len-1; i >=0; i--) {
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
	return pstack->top==MAX_STACK - 1;
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
void Conv(char* exp, char* convExp, int len) {
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