// ������� ����.
#include <stdio.h>

// ���� ����� ����.
#define ARRAY_SIZE 5


int main(void)
{
	int numbers[ARRAY_SIZE], i;
	
	printf("Input five numbers\n");

	// scanf�� ���ڸ� �迭�� �ִ´�. 
	for (i = 0; i < ARRAY_SIZE; i++) scanf_s("%d", &numbers[i]);

	// �Ųٷ� ���.
	for (i= ARRAY_SIZE - 1; i >= 0; i--) printf("%d " , numbers[i]);

	return 0;
}