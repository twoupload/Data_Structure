// practice for linked list
#include <stdio.h>

typedef enum { false, true } bool;
typedef int Data;
typedef struct _Node  // ��带 ����� ����ü
{
	Data item; // ����� ���� ����
	struct _Node* next; // ���� ����� �ּڰ��� ����(���� ����� ��)
} Node;

typedef struct 
{
	Node* head; // ���� ó�� ����� �ּҰ�
	int len; // ��ü linked list�� ����.
} LinkedList;

void InitList(LinkedList* plist) // ���� ����Ʈ�� �ʱ�ȭ
{
	plist->head = (Node*)malloc(sizeof(Node)); // head�� �޸� ���� �Ҵ�.
	plist->head->next = NULL; // ����� ���� �ּҸ� NULL�� �Ѵ�. �ƹ��͵� ���ٴ� ��
	plist->len = 0; // ���� ����Ʈ�� 0�̴�. = �ƹ��͵� ����. 
}

bool IsEmpty(LinkedList* plist) 
{
	return plist->len == 0; // ���� ���Ḯ��Ʈ�� ����� ��� ���� ��ȯ�Ѵ�. 
}

void InsertMiddle(LinkedList* plist, Data item, int pos) // ��带 �߰��ϴ� ��.
{
	Node* cur, * newNode; // cur : ������ ���� ������ �����ϱ� ���� ���, newNode : �� ���
	if (pos < 0 || pos > plist->len) // �߸��� �Է°��� ��, = index�� �߸��Ǿ�����
		exit(1); // ����

	newNode = (Node*)malloc(sizeof(Node)); // ���ο� ��带 �Ҵ�
	newNode->item = item; // ���� ����.
	newNode->next = NULL; // ���� ���� ����Ű�� �ּҴ� ����. 

	cur = plist->head; // cur ��带 �ʱ�ȭ�Ѵ�. ó�� head ���� �ʱ�ȭ�Ѵ�. 
	for (int i = 0; i < pos; i++) // �ݺ��Ѵ�. 
		cur = cur->next; // cur ���� ���� ����� ���� ���� �ּ�(���� ��)���� ����. 
	newNode->next = cur->next; // �� ���� cur ����� ���� ���� ���� �ּҰ��� �ǰ�
	cur->next = newNode; // cur ����� ���� ���� �ּҴ� �� ��尡 �ȴ�. 
	plist->len++; // ���� ����
	// *** cur ��带 ���� ���� ���������, cur ���� ���¶�� ��������. �� ������ ��带 cur�� ������. 
}

void RemoveMiddle(LinkedList* plist, int pos) // �����ϴ� ���.
{
	Node* cur, * temp; // �ӽ÷� ���� ���� ������ ��带 ����� ���´�. 
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len) // ���� ��Ȳ�� �����ϵ��� �Ѵ�. 
		exit(1);

	cur = plist->head; // ���� ��带 ���� ��带 �ʱ�ȭ�Ѵ�. 
	for (int i = 0; i < pos; i++)
		cur = cur->next; // cur ��� = ������ ����� ��(�ּҰ�)

	temp = cur->next; // �ӽ� ���� cur ����� ���� ���. (������ų ���)
	cur->next = cur->next->next; // cur ����� ������ temp ��忡�� temp ����� ���� (cur�� ���� ����)���� �ٲ۴�. 
	plist->len--; // �ϳ� ���̱�.
	free(temp); // temp ����.
}

Data ReadItem(LinkedList* plist, int pos) // �ش� ���� �̾Ƴ��� �Լ�
{
	Node* cur; // ���� ��带 ������. 
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len) // pos�� ������ ���� ��츦 ����
		exit(1);

	cur = plist->head->next; // head�� next = 1 ���� �����Ѵ�.
	// �迭ó�� 0 ���� �����ϴµ�, 0�� �� �� ���� ���϶�, 1���� �����Ѵٰ� ����.
	for (int i = 0; i < pos; i++) // �ݺ��Ѵ�. 
		cur = cur->next; // cur�� cur�� �������� �ȴ�. 

	return cur->item; // cur�� ������ ���� ��ȯ�Ѵ�. 
}

void PrintList(LinkedList* plist) // ����Ʈ�� ����ϴ� �Լ�
{
	for (Node* cur = plist->head->next; cur != NULL; cur = cur->next) // 1���� ����, NULL�� �ƴҶ�����, cur�� ++�Ѵ�.
		printf("%d\n", cur->item); // cur�� ������ ���� ����Ѵ�. 
}

void ClearList(LinkedList* plist) // �� �� ���ִ� �Լ�
{
	while (plist->head->next != NULL) // NULL�� ������ ������
		RemoveFirst(plist); // �� �� �����Ѵ�. 
	free(plist->head); // head�� ���������� ����
}

// Merging Two List (���� ����)
LinkedList* Concatenate(LinkedList* plist1, LinkedList* plist2) // ��ũ ���� 1, ��ũ ���� 2
{
	if (plist1->head->next == NULL) return plist2; // ���� 1�� ���ٸ�, 2�� ���
	else if (plist2->head->next == NULL) return plist1; // ���� 2�� ���ٸ�, 1�� ���
	else { // 1�� 2�� �� �ִ� ���.
		Node* cur = plist1->head->next; // �������� 1���� �����Ѵ�. 
		while (cur->next != NULL) // ���� ��尡 NULL�� �ƴҶ�����. �ݺ�
			cur = cur->next; // ���� ������ ���� ����. 
		cur->next = plist2->head->next; // cur�� ������ 2�� 1���� ����.
		free(plist2->head); // 2�� ����
		return plist1; // 1�� �����Ѵ�. 
	}
}

// Advanced: Making Reverse List
// Make the list in reverse sequence.
void Reverse(LinkedList* plist)
{
	Node* prev = NULL, * cur = NULL; // ���� ���� ���� ���� ���� NULL�� �ʱ�ȭ
	Node* next = plist->head->next; // ���� ���� 1������ ����
	while (next != NULL) // ���� ��尡 NULL�� �ƴϰ� �� ������. 
	{
		prev = cur; // ���� -> ����
		cur = next; // ���� -> ����
		next = next->next; // ���� -> ������ ����
		cur->next = prev; // ���� ��尡 ������ ���� ��尡 �ȴ�. (�Ųٷ� �Ǵ� ��������.)
	}
	plist->head->next = cur; // ó���� �������ش�. 
}