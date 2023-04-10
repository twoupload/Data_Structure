// practice for linked list
#include <stdio.h>

typedef enum { false, true } bool;
typedef int Data;
typedef struct _Node  // 노드를 만드는 구조체
{
	Data item; // 노드의 값을 저장
	struct _Node* next; // 다음 노드의 주솟값을 저장(다음 노드의 값)
} Node;

typedef struct 
{
	Node* head; // 가장 처음 노드의 주소값
	int len; // 전체 linked list의 길이.
} LinkedList;

void InitList(LinkedList* plist) // 연결 리스트의 초기화
{
	plist->head = (Node*)malloc(sizeof(Node)); // head의 메모리 동적 할당.
	plist->head->next = NULL; // 노드의 다음 주소를 NULL로 한다. 아무것도 없다는 뜻
	plist->len = 0; // 연결 리스트가 0이다. = 아무것도 없다. 
}

bool IsEmpty(LinkedList* plist) 
{
	return plist->len == 0; // 만약 연결리스트가 비었을 경우 참을 반환한다. 
}

void InsertMiddle(LinkedList* plist, Data item, int pos) // 노드를 추가하는 것.
{
	Node* cur, * newNode; // cur : 연결을 끊고 새걸을 연결하기 위한 노드, newNode : 새 노드
	if (pos < 0 || pos > plist->len) // 잘못된 입력값일 때, = index가 잘못되었을때
		exit(1); // 오류

	newNode = (Node*)malloc(sizeof(Node)); // 새로운 노드를 할당
	newNode->item = item; // 값을 저장.
	newNode->next = NULL; // 다음 값을 가리키는 주소는 없다. 

	cur = plist->head; // cur 노드를 초기화한다. 처음 head 노드로 초기화한다. 
	for (int i = 0; i < pos; i++) // 반복한다. 
		cur = cur->next; // cur 노드는 현재 노드의 다음 값의 주소(다음 값)으로 간다. 
	newNode->next = cur->next; // 새 노드는 cur 노드의 다음 값이 다음 주소값이 되고
	cur->next = newNode; // cur 노드의 다음 값의 주소는 새 노드가 된다. 
	plist->len++; // 길이 증가
	// *** cur 노드를 새로 만들어서 사용하지만, cur 노드는 상태라고 가정하자. 그 상태의 노드를 cur가 가진다. 
}

void RemoveMiddle(LinkedList* plist, int pos) // 제거하는 노드.
{
	Node* cur, * temp; // 임시로 넣을 노드와 저정할 노드를 만들어 놓는다. 
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len) // 오류 상황을 보완하도록 한다. 
		exit(1);

	cur = plist->head; // 지정 노드를 향할 노드를 초기화한다. 
	for (int i = 0; i < pos; i++)
		cur = cur->next; // cur 노드 = 지정한 노드의 값(주소값)

	temp = cur->next; // 임시 노드는 cur 노드의 다음 노드. (삭제시킬 노드)
	cur->next = cur->next->next; // cur 노드의 다음으 temp 노드에서 temp 노드의 다음 (cur의 다음 다음)으로 바꾼다. 
	plist->len--; // 하나 줄이기.
	free(temp); // temp 삭제.
}

Data ReadItem(LinkedList* plist, int pos) // 해당 값을 뽑아내는 함수
{
	Node* cur; // 지정 노드를 만들어낸다. 
	if (IsEmpty(plist) || pos < 0 || pos >= plist->len) // pos가 오류가 나는 경우를 제외
		exit(1);

	cur = plist->head->next; // head의 next = 1 부터 시작한다.
	// 배열처럼 0 부터 시작하는데, 0이 쓸 데 없는 것일때, 1부터 시작한다고 생각.
	for (int i = 0; i < pos; i++) // 반복한다. 
		cur = cur->next; // cur은 cur의 다음값이 된다. 

	return cur->item; // cur의 데이터 값을 반환한다. 
}

void PrintList(LinkedList* plist) // 리스트를 출력하는 함수
{
	for (Node* cur = plist->head->next; cur != NULL; cur = cur->next) // 1부터 시작, NULL이 아닐때까지, cur을 ++한다.
		printf("%d\n", cur->item); // cur의 데이터 값을 출력한다. 
}

void ClearList(LinkedList* plist) // 싹 다 없애는 함수
{
	while (plist->head->next != NULL) // NULL이 나오기 전까지
		RemoveFirst(plist); // 싹 다 삭제한다. 
	free(plist->head); // head를 마지막으로 제거
}

// Merging Two List (꼬리 물기)
LinkedList* Concatenate(LinkedList* plist1, LinkedList* plist2) // 링크 연결 1, 링크 연결 2
{
	if (plist1->head->next == NULL) return plist2; // 만약 1이 없다면, 2만 출력
	else if (plist2->head->next == NULL) return plist1; // 만약 2가 없다면, 1만 출력
	else { // 1과 2가 다 있는 경우.
		Node* cur = plist1->head->next; // 지정노드는 1부터 시작한다. 
		while (cur->next != NULL) // 지정 노드가 NULL이 아닐때까지. 반복
			cur = cur->next; // 가장 마지막 값을 저장. 
		cur->next = plist2->head->next; // cur의 다음은 2의 1부터 시작.
		free(plist2->head); // 2를 삭제
		return plist1; // 1만 리턴한다. 
	}
}

// Advanced: Making Reverse List
// Make the list in reverse sequence.
void Reverse(LinkedList* plist)
{
	Node* prev = NULL, * cur = NULL; // 이전 노드와 지정 노드는 전부 NULL로 초기화
	Node* next = plist->head->next; // 다음 노드는 1번부터 시작
	while (next != NULL) // 다음 노드가 NULL이 아니게 될 때까지. 
	{
		prev = cur; // 이전 -> 현재
		cur = next; // 현재 -> 다음
		next = next->next; // 다음 -> 다음의 다음
		cur->next = prev; // 이전 노드가 현재의 다음 노드가 된다. (거꾸로 되는 것임으로.)
	}
	plist->head->next = cur; // 처음을 움직여준다. 
}