// ���� ����
// define�� �̿��� ���� ���� ���س��´�. 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK 100


// �ڽ��� �������� ����
typedef enum {false, true} bool;
typedef int Data;
// ����ü ���� ����. ����ü->����
typedef struct {
	Data items[MAX_STACK];
	Data top;
}Stack;

// ������ �ʱ�ȭ�ϴ� �Լ�
void InitStack(Stack* pstack) {
	pstack->top = -1; // ->�� ������ ������ �ּ��� ���� ���Ѵ�. 
}
// ������ ���� á���� Ȯ���ϴ� �Լ�
bool IsFull(Stack* pstack) {
	return pstack->top == MAX_STACK - 1;
}
// ������ ����ִ��� Ȯ���ϴ� �Լ�
bool IsEmpty(Stack* pstack) {
	return pstack->top == -1;
}
// ������ �ֻ���(top)�� �д� �Լ�
Data Peek(Stack* pstack) {
	if (IsEmpty(pstack)) // pstack�� ����ִ� ���==true(1)�� ���.
		exit(1); // �ٷ� ���α׷��� �����Ѵ�. exit(0) = ��������, exit(1) = �����޽����� ����Ͽ� ����.
	// ������� ���� ���.
	return pstack->items[pstack->top];
}
// ������ �ֻ����� ���� �Է��ϴ� �Լ�
void Push(Stack* pstack, Data item) {
	if (IsFull(pstack)) // ������ �� �� ���
		exit(1);
	pstack->items[++(pstack->top)] = item;
}
// ���� ���� ���� �����ϴ� �Լ�
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

