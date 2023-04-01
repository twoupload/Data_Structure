// infix to prefix with stack
/** 
������ ���
temp �Լ��� ���ڿ��� ��´�.
exp �Լ��� temp �Լ��� �Ųٷ� ��´�.
exp �Լ��� postfix�� ���� ��� �״�� postfixȭ �Ѵ�.
convExp �Լ��� �Ųٷ� ����Ѵ�. 
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