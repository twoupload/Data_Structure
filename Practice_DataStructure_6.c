#include <stdio.h>

#define MAX_LIST 100

typedef enum { false, true } bool;
typedef int Data;

// general List
/**
typedef struct
{
	Data items[MAX_LIST];
	int len;
} ArrayList;

void InitList(ArrayList* plist)
{
	plist->len = 0;
}

bool IsEmpty(ArrayList* plist)
{
	return plist->len == 0;
}

bool IsFull(ArrayList* plist)
{
	return plist->len == MAX_LIST;
}

void InsertMiddle(ArrayList* plist, Data item, int pos)
{
	if (IsFull(plist) || pos < 0, pos > plist->len)
		exit(1);

	for (int i = plist->len - 1; i >= pos; i--)
		plist->items[i + 1] = plist->items[i];
	plist->items[pos];
	plist->len++;
}

void RemoveMiddle(ArrayList* plist, int pos)
{
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len)
		exit(1);
	for (int i = 0; i < pos; i++)
	{
		plist->items[i] = plist->items[i + 1];
	}
	plist->len--;
}

Data ReadItem(ArrayList* plist, int pos)
{
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len)
		exit(1);
	return plist->items[pos];
}

void PrintList(ArrayList* plist)
{
	for (int i = 0; i < plist->len; i++)
		printf("%d\n", plist->items[i]);
}
**/

typedef struct _Node {
	Data item;
	struct _Node* next;
} Node;

typedef struct {
	Node* head;
	int len;
} LinkedList;

void InitList(LinkedList* plist) {
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head = NULL;
	plist->len = 0;
}

bool IsEmpty(LinkedList* plist) {
	return plist->len == 0;
}

void InsertFirst(LinkedList* plist, Data item, int pos)
{
	Node* newNode;

	if (IsEmpty(plist) || pos < 0 || pos > plist->len)
		exit(1);
	newNode = (Node*)malloc(sizeof(Node));
	newNode->item = item;
	newNode->next = NULL;

	if (plist->head == NULL)
		plist->head = newNode;
	else
	{
		newNode->next = plist->head;
		plist->head = newNode;
	}
	plist->len++;
}

void InsertMiddle(LinkedList* plist, Data item, int pos) {
	Node* cur, * newNode;

	if (pos < 0 || pos > plist->len)
		exit(1);

	newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->item = item;

	cur = plist->head;
	for (int i = 0; i < pos; i++)
		cur = cur->next;

	newNode->next = cur->next;
	cur->next = newNode;
	plist->len++;
}

void RemoveFirst(LinkedList* plist)
{
	if (IsEmpty(plist) || plist->head == NULL)
		exit(1);
	plist->head = plist->head->next;
}

void RemoveMiddle(LinkedList* plist, int pos) {
	Node* cur, * temp;

	if (pos < 0 || pos > plist->len)
		exit(1);

	cur = plist->head;
	for (int i = 0; i < pos; i++)
		cur = cur->next;

	temp = cur->next;
	cur->next = cur->next->next;
	plist->len--;

	free(temp);
}

Data ReadItem(LinkedList* plist, int pos) {
	Node* cur;
	if (IsEmpty(plist) || pos < 0 || pos > plist->len)
		exit(1);

	cur = plist->head;
	for (int i = 0; i < pos; i++)
		cur = cur->next;

	return cur->item;
}

void PrintList(LinkedList* plist)
{
	Node* cur;
	cur = plist->head;
	for (cur = plist->head; cur != NULL; cur = cur->next)
		printf("%d\n", cur->item);
}

void ClearList(LinkedList* plist)
{
	while (plist->head->next != NULL)
		RemoveFirst(plist);
	free(plist->head);
}

LinkedList* Concatenate(LinkedList* plist1, LinkedList* plist2)
{
	if (plist1->head->next == NULL) return plist2;
	else if (plist2->head->next == NULL) return plist1;
	else {
		Node* cur = plist1->head->next;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = plist2->head->next;
		free(plist2->head);
		return plist1;
	}
}

// Making Reverse List
void Reverse(LinkedList* plist)
{
	Node* prev = NULL, *cur = NULL;
	Node* next = plist->head->next;
	while (next != NULL)
	{
		prev = cur;
		cur = next;
		next = next->next;
	}
	plist->head->next = cur;
}

void Reverse(LinkedList* plist)
{
	Node* prev = NULL, * cur = NULL;
	Node* next = plist->head->next;
	while (next != NULL)
	{
		prev = cur;
		cur = next;
		next = next->next;
	}
	plist->head->next = cur;
}