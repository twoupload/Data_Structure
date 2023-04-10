// ArrayList 일반적인 리스트를 다루는 c언어.
#include <stdio.h>

#define MAX_LIST 100

typedef enum { false, true } bool;
typedef int Data;

typedef struct {
	Data items[MAX_LIST]; // 리스트를 담을 배열을 설정
	int len; // 리스트의 길이.
} ArrayList;

void InitList(ArrayList* plist) // 리스트를 초기화하는 것
{ 
	plist->len = 0; // 리스트의 길이를 0으로 맞춘다. 
}
bool IsEmpty(ArrayList* plist) // 리스트가 비어있는지 확인하는 함수
{
	return plist->len == 0; // 리스트의 길이가 0일경우(비어있는 경우), 참을 반환
}
bool IsFull(ArrayList* plist) // 리스트가 다 찼는지 확인하는 함수
{
	return plist->len == MAX_LIST; // 리스트가 다 찬 경우, 참을 반환
}
void InsertMiddle(ArrayList* plist, int pos, Data item) // 중간 부분을 삽입
{
	if (IsFull(plist) || pos<0 || pos > plist->len) // 리스트가 비어져 있거나, 원하는 부분이 0보다 작거나, 리스트의 길이보다 큰 값을 index로 잡는 경우.
		exit(1); // 오류가 뜨도록 함.
	for (int i = plist->len - 1; i >= pos; i--) // 아닌 경우: 넣을 수 있는 경우: len-1부터 위치까지 찾아간다.
		plist->items[i + 1] = plist->items[i]; // 뒷쪽으로 수를 당긴다.
	plist->items[pos] = item; // 넣는 index의 item의 값을 넣는다. 
	plist->len++; // 길이 증가.
}
void RemoveMiddle(ArrayList* plist,int pos) // 중간 값 삭제
{
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len) // 넣는 위치가 0보다 작거나, 길이보다 작은 경우, 비어있는 경우 제외.
		exit(1); // 오류를 뜨도록 유도.
	for (int i = pos; i < plist->len; i++) // 넣는 위치 부터 길이 끝까지 반복
		plist->items[i] = plist->items[i + 1]; // 왼쪽으로 당긴다. 
	plist->len--; // 길이 감소
}
Data ReadItem(ArrayList* plist, int pos) // 읽어내는 것. 큐와 스택에서 peek에 해당
{
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len) // 비어있거나, 넣는 위치가 알맞지 않는 경우 제외
		exit(1); // 오류가 뜨도록 함. 
	return plist->items[pos]; // 해당하는 위치의 값을 반환함. 
}
void PrintList(ArrayList* plist) // 출력하는 과정.
{
	for (int i = 0; i < plist->len; i++) // 0부터 길이까지 반복.
		printf("%d\n", plist->items[i]); // 출력하도록 함. 
}