//배열 연습1
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST 100

typedef int Data;
typedef enum { false, true } bool;
typedef struct {
	Data items[MAX_LIST];
	int len;
}ArrayList;

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
void InsertMiddle(ArrayList* plist, int pos, Data item) 
{
	if (IsFull(plist) || pos < 0 || pos > plist->len)
		exit(1);
	for (int i = plist->len - 1; i >= pos; i--) {
		plist->items[i+1] = plist->items[i];
	}
	plist->items[pos] = item;
	plist->len++;
}
void RemoveMiddle(ArrayList* plist, int pos) 
{
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len)
		exit(1);
	for (int i = pos; i < plist->len; i++) {
		plist->items[i] = plist->items[i+1];
	}
	plist->len--;
}
Data ReadItem(ArrayList* plist, int pos) 
{
	if (IsEmpty(plist) || pos >= pos || pos < 0)
		exit(1);
	return plist->items[pos];
}
void PrintList(ArrayList* plist, int len) 
{
	for (int i = 0; i < len; i++)
		printf("%d\n", plist->items[i]);
}