#include <stdio.h>
#include <stdlib.h>

int* getNumbers(int size);

int main(void) {
	int size, i;
	scanf_s("%d", &size);

	int* pn = getNumbers(size);
	for (int i = 0; i < size; i++) printf("%d\n", pn[i]);

	free(pn);
	return 0;
}

int* getNumbers(int size)
{
	int i;
	int* pn = malloc(4 * size);
	for (i = 0; i < size; i++) scanf_s("%d", &pn[i]);

	return pn;
}