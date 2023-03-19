// 가장 작은 수 순서로 오름차순 정렬하라.
#include <stdio.h>
#define Array 6

void Swap(int* a, int* b);
void Sort(int* list, int len);

int main(void) {
	int i;
	int li[Array] = { 10,21,5,8,1,12 };
	Sort(li, Array);
	
	for (i = 0; i < Array; i++) {
		printf("%d ", li[i]);
	}

	return 0;
}

void Swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Sort(int* list, int len) {
	int i, j, min;

	for (i = 0; i < len - 1; i++) {
		min = i;
		for (j = i + 1; j < len; j++) {
			if (list[j] < list[min]) {
				min = j;
			}

			Swap(&list[i], &list[min]);
		}
	}
}


