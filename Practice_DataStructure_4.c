/**
// stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Stack reprsentation
#define MAX_STACK 100
typedef int Data;
typedef enum { false, true } bool;

typedef struct
{
	Data items[MAX_STACK];
	int top;
} Stack;

void InitStack(Stack* pstack)
{
	pstack->top = -1;
}

bool IsEmpty(Stack* pstack)
{
	return pstack->top == -1;
}

bool IsFull(Stack* pstack)
{
	return pstack->top == MAX_STACK - 1;
}

Data Peek(Stack* pstack)
{
	if (IsEmpty(pstack)) exit(1);
	return pstack->items[pstack->top];
}

void Push(Stack* pstack, Data item)
{
	if (IsFull(pstack)) exit(1);
	pstack->items[++(pstack->top)] = item;
}

void Pop(Stack* pstack)
{
	if (IsEmpty(pstack)) exit(1);
	--(pstack->top);
}

// Print a Reverse String
/**
void ReversePrint(char* s, int len)
{
	Stack stack;
	InitStack(&stack);

	for (int i = 0; i < len; i++)
		Push(&stack, s[i]);

	while (!IsEmpty(&stack))
	{
		printf("%c", Peek(&stack));
		Pop(&stack);
	}
}

int main(void)
{
	char str[101];
	scanf("%s", &str);

	int len = strlen(str);

	ReversePrint(str, len);

	return 0;
}
**/

// Parenthesis Matching
/**
bool IsParanBalanced(char* exp, int len)
{
	Stack stack;
	InitStack(&stack);

	for (int i = 0; i < len; i++)
	{
		if (exp[i] == '(') Push(&stack, exp[i]);
		else if (exp[i] == ')')
		{
			if (IsEmpty(&stack) == false) Pop(&stack);
			else return false;
		}
	}

	if (IsEmpty(&stack) == false) return false;
	else return true;
}

int main(void)
{
	char expression[101];
	scanf("%s", &expression);

	int len = strlen(expression);

	if (IsParanBalanced(expression, len)) printf("Balnced");
	else printf("UnBalanced");

	return 0;
}
**/

// Evaluate postfix notation
/**
int EvalPostfix(char* exp, int len)
{
	Stack stack;
	char expr[101]="";
	int j = 0;
	InitStack(&stack);
	int op1, op2;

	for (int i = 0; i < len; i++)
	{
		if (exp[i] != ' ')
		{
			expr[j++] = exp[i];
		}
	}

	int len2 = strlen(expr);

	for (int i = 0; i < len2; i++)
	{
		if (isdigit(expr[i])) Push(&stack, expr[i] - '0');
		else
		{
			op2 = Peek(&stack);
			Pop(&stack);
			op1 = Peek(&stack);
			Pop(&stack);
			if (expr[i] == '*') Push(&stack, op1 * op2);
			else if (expr[i] == '/') Push(&stack, op1 / op2);
			else if (expr[i] == '+') Push(&stack, op1 + op2);
			else if (expr[i] == '-') Push(&stack, op1 - op2);
		}
	}
	return Peek(&stack);
}

int main(void)
{
	char expression[101];
	scanf("%[^\n]s", &expression);
	int len = strlen(expression);
	
	printf("%d", EvalPostfix(expression, len));

	return 0;
}

// Converting infix to postfix
bool ComPriority(char peek, char temp)
{
	int op = 0, ot = 0;
	if (peek == '*' || peek == '/') op = 5;
	else op = 2;

	if (temp == '*' || temp == '/') ot = 5;
	else ot = 2;

	if (op < ot) return true;
	else return false;
}

void ConvInfixToPostfix(char* exp, char* convExp, int len)
{
	Stack stack;
	InitStack(&stack);

	char temp[101];
	int j = 0, k = 0;
	for (int i = 0; i < len; i++) {
		if (exp[i] != ' ') temp[j++] = exp[i];
	}

	int len_t = strlen(temp);

	for (int i = 0; i < len_t; i++)
	{
		if (isdigit(temp[i])) convExp[k++] = temp[i];
		else
		{
			while (!IsEmpty(&stack) && ComPriority(Peek(&stack), temp[i]))
			{
				convExp[k++] = Peek(&stack);
				Pop(&stack);
			}
			Push(&stack, temp[i]);
		}
	}
	while (!IsEmpty(&stack)) {
		convExp[k++] = Peek(&stack);
		Pop(&stack);
	}
}

int main(void)
{
	char expression[101];
	char convExp[101] = "";
	scanf("%[^\n]s", &expression);

	int len = strlen(expression);

	ConvInfixToPostfix(expression, convExp, len);

	printf("%s", convExp);

	return 0;
}
**/