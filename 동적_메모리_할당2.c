#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int size, i;
	scanf_s("%d", &size);

	// Allocate dynamic memory
	// pn�� ����Ʈ�� �ؼ�(pn�̶� ���ڿ� �޸𸮸� �Ҵ��� int ũ���� size ��ŭ�� ������ �ּҸ� �ְ���) ���� �޸� �Ҵ�.
	int* pn = malloc(sizeof(int) * size);

	for (i = 0; i < size; i++) scanf_s("%d", &pn[i]);
	for (i = 0; i < size; i++) printf("%d ", pn[i]);

	free(pn); // Release memory

	return 0;

}