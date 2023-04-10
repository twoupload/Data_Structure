#include <stdio.h>

typedef int Data;
typedef enum { false, true } bool;

typedef struct _Node
{
	Data item;
	struct _Node* next;
} Node;

typedef struct
{
	Node* head;
	int len;
} LinkedList;

void InitLIst(LinkedList* plist) 
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head = NULL;
	plist->len = 0;
}

bool IsEmpty(LinkedList* plist)
{
	return plist->len == 0;
}

void InsertMiddle(LinkedList* plist, int pos, Data item)
{
	Node* cur, *newNode;
	if (IsEmpty(plist) || pos < 0 || pos < plist->len)
		exit(1);
	newNode = (Node*)malloc(sizeof(Node));
	newNode ->item = item;
	newNode->next = NULL;

	cur = plist->head;
	for (int i = 0; i < pos; i++)
		cur = cur->next;

	newNode->next = cur->next;
	cur->next = newNode;
	plist->len++;
}

void RemoveNode(LinkedList* plist, int pos)
{
	Node* cur, * temp;
	if (IsEmpty(plist) || pos < 0 || pos > plist->len)
		exit(1);

	cur = plist->head;
	for (int i = 0; i < pos; i++)
		cur = cur->next;
	temp = cur->next;
	cur->next = cur->next->next;
	plist->len--;
	free(temp);
}

Data ReadItem(LinkedList* plist, int pos)
{
	Node* cur;
	if (IsEmpty(plist) || pos > plist->len || pos < 0)
		exit(1);

	cur = plist->head->next;
	for (int i = 0; i < pos; i++)
		cur = cur->next;

	return cur->item;
}

void PrintList(LinkedList* plist)
{
	for (Node* cur = plist->head->next; cur != NULL; cur = cur->next)
		printf("%d\n", cur->item);
}

void ClearList(LinkedList* plist)
{
	while (plist->head->next != NULL)
		RemoveFirst(plist);
	free(plist->head);
}


// 꼬리물기
LinkedList* Concatenate(LinkedList* plist1, LinkedList* plist2)
{
	if (plist1->head == NULL) return plist2;
	else if (plist2->head == NULL) return plist1;
	else
	{
		Node* cur = plist1->head->next;
		while (cur->next != NULL) 
			cur = cur->next;

		cur->next = plist2->head->next;
		free(plist2);
		return plist1;
	}
}

// 반대로 출력하기.
void Reverse(LinkedList* plist)
{
	Node* prev = NULL, *cur = NULL;
	Node* next = plist->head->next;

	while (next != NULL)
	{
		prev = cur;
		cur = next;
		next = next->next;
		cur->next = prev;
	}
	plist->head->next = cur;
}