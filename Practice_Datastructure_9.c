// Dynamic stack
#include <stdio.h>

typedef enum { false, true } bool;
typedef int Data;

typedef struct _Node
{
	Data item;
	struct _Node* next;
} Node;

typedef struct
{
	Node* top;
} DStack;

void InitStack(DStack* pstack)
{
	pstack->top = NULL;
}

bool IsEmpty(DStack* pstack)
{
	return pstack->top == NULL;
}

Data Peek(DStack* pstack)
{
	if (IsEmpty(pstack))
		exit(1);
	return pstack->top->item;
}

void Push(DStack* pstack, Data item)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->item = item;
	newNode->next = pstack->top;
	pstack->top = newNode;
}

void Pop(DStack* pstack)
{
	Node* temp;
	if (IsEmpty(pstack))
		exit(1);
	temp = pstack->top;
	pstack->top = pstack->top->next;
	free(temp);
}