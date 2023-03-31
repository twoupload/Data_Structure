#include <stdio.h> // main �Լ��� �����ϱ� ���� ���
#include <stdlib.h> 
#include <ctype.h> // digit �Լ��� �����ϱ� ���� ���
#include <string.h>// strlen �Լ��� �����ϱ� ���� ���

#define MAX_STACK 100 // ������ �ִ��� 100���� ����
typedef int Data; // int ���� 'Data'��� ���� ����
typedef enum { false, true } bool; // enum ������ 'bool'�̶�� ���� ����. 0�϶� false, 1�϶� true.
typedef struct { // ����ü Stack
	Data top; // ������ ���� ��.
	Data items[MAX_STACK]; // ���� �迭.
}Stack;

void InitStack(Stack* pstack); // ������ �ʱ�ȭ�ϴ� �Լ�
bool IsEmpty(Stack* pstack); // ������ ����ִ��� Ȯ���ϴ� �Լ�
bool IsFull(Stack* pstack); // ������ �� á���� Ȯ���ϴ� �Լ�
void Push(Stack* pstack, Data item); // ���ÿ� ���� ����ִ� �Լ�
void Pop(Stack* pstack); // ���ÿ� top ���� �����ϴ� �Լ�
Data Peek(Stack* pstack); // ������ top ���� ��ȯ�ϴ� �Լ�

bool ComPriority(Data c1, char c2);
void ConvInfixToPostfix(char* str, char* conv, int len); // Infix�� Postfix�� ��ȯ�ϴ� �Լ�

int main(void) { // main �Լ�
	char exp[100]=""; // ������� �Է¹��� �迭
	char convExp[100]=""; // Postfix�� ��ȯ �� �־��� �迭
	int len; // exp�� ����.

	scanf("%s", &exp); // ������� �Է¹���

	len = strlen(exp); // strlen�� ���� exp�� ���̸� ����

	ConvInfixToPostfix(exp, convExp, len); // exp�� conv�Ͽ� convExp�Լ��� ����ִ� �Լ�

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
	Stack stack; // stack�� �ҷ��´�. 
	int idx = 0; // conv�� ���ʷ� ������ ��ġ
	InitStack(&stack); // ������ �ʱ�ȭ�Ѵ�. 
	for (int i = 0; i < len; i++) { // str�� ���̸�ŭ for������ �ݺ�.
		if (isdigit(exp[i])) { // isdigit = ���� ������, �� �� ���� �ƴѰ� ������, 0 return
			convExp[idx] = exp[i]; // str[i]�� ������ ��� conv�� ���� �����Ѵ�.  
			idx++; //���� ���� idx�� �����Ѵ�.
		}
		else { // �������� �ƴ� ���, '������'�� ���.
			while (!IsEmpty(&stack) && ComPriority(Peek(&stack), exp[i])) { // ������ ������� �ʰ�, �����ڸ� ���ؼ� ���ΰ��
				// ComPriority(Peek(&stack),str[i]) : �� �����ڸ� ���Ͽ� ������� �� ū��?
				// Peek�� �����ڰ� �� ���� ���
				convExp[idx++] = Peek(&stack); // conv �迭�� stack�� top�� �ִ� �����ڸ� peek�Ͽ� �ִ´�.
				Pop(&stack); // �����ڸ� ����
			}
			Push(&stack, exp[i]); // �����ڸ� �ִ´�.
		}
	}
	while (!IsEmpty(&stack)) { // ������ ���� �� ������ �ݺ��Ѵ�.
		convExp[idx++] = Peek(&stack); // ���ÿ� �ִ� ��� �����ڸ� conv �Լ��� �ִ´�. 
		Pop(&stack); // ������ ���� �����Ѵ�. 
	}
}
