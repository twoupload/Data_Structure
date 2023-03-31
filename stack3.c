// 스택만들기
#include <stdio.h>
//#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK 100
typedef int Data;
typedef enum { false, true } bool;
typedef struct {
	Data items[MAX_STACK];
	int top;
}Stack;

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

EvalPostfix(char* str, int len);

int main(void) {
	char str[100] = " ";
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf(" %c", &str[i]);
	}
	int len = strlen(str);
	printf("%d", EvalPostfix(str, len));
}

int EvalPostfix(char* str, int len) {
	Stack stack;
	int op1, op2;
	InitStack(&stack);
	for (int i = 0; i < len; i++) {
		if(isdigit(str[i]))// 10진수로 나올 수 있는 수면 0이 아닌 수, 아니면 0 출력.
			Push(&stack, str[i]-'0');
		else {
			op2 = Peek(&stack), Pop(&stack);
			op1 = Peek(&stack), Pop(&stack);
			if (str[i] == '+')
				Push(&stack, op1 + op2);
			else if (str[i] == '-')
				Push(&stack, op1 - op2);
			else if (str[i] == '*')
				Push(&stack, op1 * op2);
			else if (str[i] == '/')
				Push(&stack, op1 / op2);
		}
	}
	return Peek(&stack);
}