#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_STACK 100
typedef int Data;
typedef struct {
	Data top;
	Data items[MAX_STACK];
}Stack;

void InitStack(Stack* pstack) {
	pstack->top = -1;
}

bool IsFull(Stack* pstack) {
	return pstack->top == MAX_STACK - 1;
}

bool IsEmpty(Stack* pstack) {
	return pstack->top == -1;
}

void Push(Stack* pstack, Data item) {
	if (IsFull(pstack)) exit(1);
	pstack->items[++(pstack->top)] = item;
}

Data Peek(Stack* pstack) {
	if (IsEmpty(pstack)) exit(1);
	return pstack->items[pstack->top];
}

void Pop(Stack* pstack) {
	if (IsEmpty(pstack)) exit(1);
	--(pstack->top);
}

int Copetition_P(Data P) {
	char DtocP = P;
	switch (DtocP) {
		case '(' :
			return 1;
			break;
		case ')' :
			return 10;
			break;
		case '+' :
			return 2;
			break;
		case '-' :
			return 2;
			break;
		case '*' :
			return 5;
			break;
		case '/' :
			return 5;
			break;
	}
}

int Copetition_S(char s) {
	switch (s) {
	case '(':
		return 1;
		break;
	case ')':
		return 10;
		break;
	case '+':
		return 2;
		break;
	case '-':
		return 2;
		break;
	case '*':
		return 5;
		break;
	case '/':
		return 5;
		break;
	}
}

bool ComPriority(Data P, char s) {
	if (Competition_P(P) > Competition_S(s)) return true;
	else if (Competition_P(P) < Competition_S(s)) return false;
}

void ConvInfinxToPostfix(char* str, char* conv, int len) {
	Stack stack;
	int idx = 0;
	InitStack(&stack);
	for (int i = 0; i < len; i++) {
		if (isdigit(str[i])) conv[idx++] = str[i];
		else {
			while (!IsEmpty(&stack) && ComPriority(Peek(&stack), str[i])) {
				conv[idx++] = Peek(&stack);
				Pop(&stack);
			}
			Push(&stack, str[i]);
		}
	}
	while (!IsEmpty(&stack)) {
		conv[idx++] = Peek(&stack);
		Pop(&stack);
	}
}

int main(void) {
	char str[100];
	char conv[100];
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf(" %c", &str[i]);
	}

	ConvInfinxToPostfix(&str, &conv, n);

	return 0;
}