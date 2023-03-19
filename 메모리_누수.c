#include <stdio.h>
#include <stdlib.h>
void geneNumbers(int* pn, int s);

int main(void) {
	int size, i;
	scanf_s("%d", &size);
	int* pn = malloc(4 * size);

	geneNumbers(pn, size);
	for (int i = 0; i < size; i++) printf("%d\n", pn[i]);

	free(pn);
	return 0;
}

void geneNumbers(int* pn, int s) {
	int i;
	for (i = 0; i < s; i++) scanf_s("%d", &pn[i]);
}