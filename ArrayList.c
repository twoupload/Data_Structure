// ArrayList �Ϲ����� ����Ʈ�� �ٷ�� c���.
#include <stdio.h>

#define MAX_LIST 100

typedef enum { false, true } bool;
typedef int Data;

typedef struct {
	Data items[MAX_LIST]; // ����Ʈ�� ���� �迭�� ����
	int len; // ����Ʈ�� ����.
} ArrayList;

void InitList(ArrayList* plist) // ����Ʈ�� �ʱ�ȭ�ϴ� ��
{ 
	plist->len = 0; // ����Ʈ�� ���̸� 0���� �����. 
}
bool IsEmpty(ArrayList* plist) // ����Ʈ�� ����ִ��� Ȯ���ϴ� �Լ�
{
	return plist->len == 0; // ����Ʈ�� ���̰� 0�ϰ��(����ִ� ���), ���� ��ȯ
}
bool IsFull(ArrayList* plist) // ����Ʈ�� �� á���� Ȯ���ϴ� �Լ�
{
	return plist->len == MAX_LIST; // ����Ʈ�� �� �� ���, ���� ��ȯ
}
void InsertMiddle(ArrayList* plist, int pos, Data item) // �߰� �κ��� ����
{
	if (IsFull(plist) || pos<0 || pos > plist->len) // ����Ʈ�� ����� �ְų�, ���ϴ� �κ��� 0���� �۰ų�, ����Ʈ�� ���̺��� ū ���� index�� ��� ���.
		exit(1); // ������ �ߵ��� ��.
	for (int i = plist->len - 1; i >= pos; i--) // �ƴ� ���: ���� �� �ִ� ���: len-1���� ��ġ���� ã�ư���.
		plist->items[i + 1] = plist->items[i]; // �������� ���� ����.
	plist->items[pos] = item; // �ִ� index�� item�� ���� �ִ´�. 
	plist->len++; // ���� ����.
}
void RemoveMiddle(ArrayList* plist,int pos) // �߰� �� ����
{
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len) // �ִ� ��ġ�� 0���� �۰ų�, ���̺��� ���� ���, ����ִ� ��� ����.
		exit(1); // ������ �ߵ��� ����.
	for (int i = pos; i < plist->len; i++) // �ִ� ��ġ ���� ���� ������ �ݺ�
		plist->items[i] = plist->items[i + 1]; // �������� ����. 
	plist->len--; // ���� ����
}
Data ReadItem(ArrayList* plist, int pos) // �о�� ��. ť�� ���ÿ��� peek�� �ش�
{
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len) // ����ְų�, �ִ� ��ġ�� �˸��� �ʴ� ��� ����
		exit(1); // ������ �ߵ��� ��. 
	return plist->items[pos]; // �ش��ϴ� ��ġ�� ���� ��ȯ��. 
}
void PrintList(ArrayList* plist) // ����ϴ� ����.
{
	for (int i = 0; i < plist->len; i++) // 0���� ���̱��� �ݺ�.
		printf("%d\n", plist->items[i]); // ����ϵ��� ��. 
}