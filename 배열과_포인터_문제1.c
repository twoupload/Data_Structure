// �־��� �迭 �� ���� ���� ���� ����ϴ� ���α׷��� �����϶�.

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