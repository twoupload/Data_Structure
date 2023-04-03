// infix to postfix
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100
typedef int Data;
typedef enum {false, true} bool;
typedef struct {
	Data top;
	Data items[MAX];
}Stack;

void Init(Stack* pstack) {
	pstack->top = -1;
}
bool IsFull(Stack* pstack) {
	return pstack->top == MAX - 1;
}
bool IsEmpty(Stack* pstack) {
	return pstack->top == -1;
}
void Push(Stack* pstack, Data item) {
	if (IsFull(pstack)) exit(1);
	pstack->items[++(pstack->top)]=item;
}
void Pop(Stack* pstack) {
	if (IsEmpty(pstack)) exit(1);
	--(pstack->top);
}
Data Peek(Stack* pstack) {
	if(IsEmpty(pstack)) exit(1);
	return pstack->items[pstack->top];
}

bool Competition(Data Peek, char exp_i);
void ConvInfixToPostfix(char* exp, char* ConvExp, int len);

int main(void) {
	char exp[100]="";
	char ConvExp[100]="";
	int len;

	scanf("%s", &exp);
	len = strlen(exp);

	ConvInfixToPostfix(exp, ConvExp, len);
	
	printf("%s", ConvExp);

	return 0;
}

bool Competition(Data Peek, char exp_i) {
	int p1, p2;
	Peek = (char)Peek;

	if (Peek == '*' || Peek == '/') p1 = 6;
	else p1 = 2;

	if (exp_i == '*' || exp_i == '/') p2 = 6;
	else p2 = 2;

	if (p1 >= p2) return true;
	else return false;
}
void ConvInfixToPostfix(char* exp, char* ConvExp, int len) {
	Stack stack;
	int idx = 0;
	Init(&stack);

	for (int i = 0; i < len; i++) {
		if (isdigit(exp[i])) {
			ConvExp[idx++] = exp[i];
		}
		else {
			while (!IsEmpty(&stack) && Competition(Peek(&stack), exp[i])) {
				ConvExp[idx++] = Peek(&stack);
				Pop(&stack);
			}
			Push(&stack, exp[i]);
		}
	}
	while (!IsEmpty(&stack)) {
		ConvExp[idx++] = Peek(&stack);
		Pop(&stack);
	}
}