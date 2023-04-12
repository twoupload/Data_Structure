#include <stdio.h>

typedef enum { false, true } bool;
typedef int Data;
typedef struct _Node
{
	Data item;
	struct _Node* prev;
	struct _Node* next;
} Node;

typedef struct
{
	Node* head;
	int len;
}DoubleLinkedList;

void InitLIst(DoubleLinkedList* plist)
{
	Node* dummy1, * dummy2;
	dummy1 = (Node*)malloc(sizeof(Node));
	dummy2 = (Node*)malloc(sizeof(Node));

	dummy1->prev = NULL;
	dummy1->next = dummy2;
	dummy1->prev = dummy1;
	dummy2->next = NULL;

	plist->head = dummy1;
	plist->len = 0;
}

void InsetMiddle(DoubleLinkedList* plist, int pos, Data item)
{
	Node* cur, * newNode;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->item = item;
	newNode->prev = NULL;
	newNode->next = NULL;

	cur = plist->head;
	for (int i = 0; i < pos; i++)
		cur = cur->next;

	newNode->prev = cur;
	newNode->next = cur->next;
	cur->next->prev = newNode;
	cur->next = newNode;
	plist->len++;
}

void RemoveMiddle(DoubleLinkedList* plist, int pos)
{
	Node* cur, * temp;
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len)
		exit(1);

	cur = plist->head;
	for (int i = 0; i < pos; i++)
		cur = cur->next;

	temp = cur->next;
	temp->next->prev = cur;
	cur->next = temp->next;

	plist->len--;
	free(temp);
}