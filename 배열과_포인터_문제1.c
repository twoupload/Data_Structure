// 주어진 배열 중 가장 작은 수를 출력하는 프로그램을 제작하라.

#include <stdio.h>

int main(void) {
	int a[6] = { 32,12,31,42,15,24 };
	int* pend = a + 6;;
	int* smallest = a;
	int* pi = NULL;

	for (pi = a; pi < pend; pi++) {
		if (*pi < *smallest) smallest = pi;
	}

	printf("%d", *smallest);

	return;
}