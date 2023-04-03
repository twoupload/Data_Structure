// 괄호 맞추기
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef int Data;
typedef enum { false, true } bool;
typedef struct {
	Data top;
	Data items[MAX];
}Stack;

void Init(Stack* ps) {
	ps->top = -1;
}
bool Empty(Stack* ps) {
	return ps->top == -1;
}
bool Full(Stack* ps) {
	return ps->top == MAX - 1;
}
void Push(Stack* ps, Data item) {
	if (Full(ps)) exit(1);
	ps->items[++(ps->top)] = item;
}
void Pop(Stack* ps) {
	if (Empty(ps)) exit(1);
	--(ps->top);
}
Data Peek(Stack* ps) {
	if (Empty(ps)) exit(1);
	return ps->items[ps->top];
}

bool collect(char* exp, int len) {
	Stack stack;
	Init(&stack);

	for (int i = 0; i < len; i++) {
		if (exp[i] == '(') Push(&stack, exp[i]);
		else if (exp[i] == ')') {
			if (Empty(&stack)) return false;
			else Pop(&stack);
		}
	}
	if (Empty(&stack)) return true;
	else return false;
}

int main(void) {
	char exp[100]="";
	scanf("%s", &exp);

	int len = strlen(exp);

	if (collect(exp, len)) printf("Balanced");
	else printf("Unbalanced");

	return 0;
}