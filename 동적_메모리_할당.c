#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int size, i;
	scanf_s("%d", &size);

	// Allocate dynamic memory
	int pn[size];

	for (i= 0; i < size; i++) {
		printf("%d\n", pn[i]);
	}

	return 0;
}

// ������ ���� �ʴ´�. size�� �������� ���� ���¿��� pn �迭�� ����� �־��� ����,
// ������ �迭������ �̸� ���� �־���� ������ ������ �����. 