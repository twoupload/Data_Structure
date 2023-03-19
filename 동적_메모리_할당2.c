#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int size, i;
	scanf_s("%d", &size);

	// Allocate dynamic memory
	// pn을 포인트로 해서(pn이란 상자에 메모리를 할당해 int 크기의 size 만큼의 공간의 주소를 주겠음) 동적 메모리 할당.
	int* pn = malloc(sizeof(int) * size);

	for (i = 0; i < size; i++) scanf_s("%d", &pn[i]);
	for (i = 0; i < size; i++) printf("%d ", pn[i]);

	free(pn); // Release memory

	return 0;

}