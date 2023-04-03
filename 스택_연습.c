// stack�� �̿��Ͽ� Reverse String.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK 100 //define�� �̿��Ͽ� stack�� �ִ��� 100���� ��´�. 

// ������ ��� ����
typedef int Data; // Data��� �̸����� int�� ����ϰ���.
typedef enum {false, true} bool; // bool ����� ������� �ʰ� bool ����

// ���� ���� -> ����ü ���
typedef struct {
	Data top; // ������ ���� ���� ��
	Data items[MAX_STACK]; // �������� ����� �迭 ����
}Stack;

// ������ ����� �Լ� ����
void InitStack(Stack* pstack); // ������ �ʱ�ȭ
bool IsEmpty(Stack* pstack); // ������ ����ִ��� Ȯ��
bool IsFull(Stack* pstack); // ������ �� á���� Ȯ��
void Push(Stack* pstack, Data item); // ������ top ���� item�� ����.
void Pop(Stack* pstack); // ������ top ���� ����
Data Peek(Stack* pstack); // ������ top ���� return ��.


void RevString(char* str, int len);


int main(void) { // ���� �Լ�
	char str[100]=""; // �ٲ�� ���� ���ڿ��� ���� �迭
	scanf("%s", &str); // �Է¹���.

	int len = strlen(str); // ���ڿ��� ����

	RevString(str, len); // �Լ��� �̿��� ���ڿ��� �ݴ�� ����.

	return 0;
}

// ���� �Լ� �� ��� �Լ� ����
void InitStack(Stack* pstack) {
	pstack->top = -1;
}

bool IsEmpty(Stack* pstack) {
	return pstack->top == -1; // top ���� -1�̶��(�ƹ��͵� ���� �ʾҴٸ�,) ���� return 
}

bool IsFull(Stack* pstack) {
	return pstack->top == MAX_STACK - 1; // top ���� define�� ������ -1 ���� ��(�ִ�� �� ��)�̶��, ���� return 
}

void Push(Stack* pstack, Data item) {
	if (IsFull(pstack)) exit(1);// ����, ���ÿ� �� ���� �� ���� ������ �� á�ٸ�, exit(1)�� �Ѵ�. ������ ���鼭 ����.
	pstack->items[++(pstack->top)] = item; // ������ top ���� �ϳ� ������Ű�� �װ��� items �迭�� item ���� �ִ´�. 
}

void Pop(Stack* pstack) {
	if (IsEmpty(pstack)) exit(1); // ���� ���ÿ� �ƹ��͵� ���ٸ�, ������ ���鼭 ����
	--(pstack->top);  // top ���� �ϳ� ����.
}

Data Peek(Stack* pstack) {
	if (IsEmpty(pstack)) exit(1);
	return pstack->items[pstack->top]; // top �� �ϳ��� return 
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