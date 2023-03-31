// 스택제작 2
#include <stdio.h>
//#include <stdbool.h>

#define MAX_STACK 100
typedef enum {false, true} bool;
typedef int Data;
typedef struct {
	Data items[MAX_STACK];
	Data top;
}Stack;

void InitStack(Stack* pstack);
bool IsFull(Stack* pstack);
bool IsEmpty(Stack* pstack);
void Pust(Stack* pstack, int len, int item);
Data Peek(Stack* pstack);
void Pop(Stack* pstack);

bool IsParanBalanced(char* exp, int len);

int main(void) {

	char str[100] = " ";
	int n,i;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf(" %c", &str[i]);
	}

	if (IsParanBalanced(str, n)) printf("Balanced");
	else printf("Unbalanced");
	
	return 0;
}

void InitStack(Stack* pstack) {
	pstack->top = -1;
}

bool IsFull(Stack* pstack) {
	return pstack->top == MAX_STACK - 1;
}

bool IsEmpty(Stack* pstack) {
	return pstack->top == -1;
}

Data Peek(Stack* pstack) {
	if (IsEmpty(pstack))
		exit(1);
	return pstack->items[pstack->top];
}

void Push(Stack* pstack, Data item) {
	if (IsFull(pstack)) exit(1);
	pstack->items[++(pstack->top)] = item;
}

void Pop(Stack* pstack) {
	if (IsEmpty(pstack)) exit(1);
	--(pstack->top);
}

bool IsParanBalanced(char* str, int len) {
	Stack stack;
	InitStack(&stack);

	for (int i = 0; i < len; i++) {
		if (str[i] == '(') Push(&stack, str[i]);
		else if (str[i] == ')') {
			if (IsEmpty(&stack)) return false;
			else Pop(&stack);
		}
	}
	if (IsEmpty(&stack)) return true;
	else return false;
}
