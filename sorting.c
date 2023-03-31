// 주어진 함수를 오름차순 정렬하시오.
#include <stdio.h>
#include <string.h>

void swap(int* p, int* q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void Sorting(int* a, int n) {
	int i, j, min;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i+1; j < n; j++) {
			if (a[j] < a[min])
				min = j;
		}
		swap(&a[i], &a[min]);
	}
}
int main(void) {
	int a[101] = { 6,1,78,99,65,45 };

	Sorting(a, 6);

	for (int i = 0; i < 6; i++) {
		printf("%d ", a[i]);
	}

	return 0;
}