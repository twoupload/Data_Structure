// ���ڸ� �Է� ������, �Ųٷ� ����ϴ� ���α׷��� �ۼ��϶�.
#include <stdio.h>
#define ARRAY 5

int main(void) {
	int numbers[ARRAY], i;
	
	printf("Input the numbers\n");

	for (i = 0; i < ARRAY; i++) scanf_s("%d", &numbers[i]);

	for (i = ARRAY - 1; i >= 0; i--) printf("%d ", numbers[i]);

	return 0;
}