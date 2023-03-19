#include <stdio.h>

int main(void) {
	int a[6] = { 1,2,3,4,5,6 };
	int* pend = a + 6;
	int* pi = NULL;

	for (pi = a; pi < pend; pi++) printf("%d\n", *pi);

	return 0;
}