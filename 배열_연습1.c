// 헤더파일 지정.
#include <stdio.h>

// 지정 상수로 지정.
#define ARRAY_SIZE 5


int main(void)
{
	int numbers[ARRAY_SIZE], i;
	
	printf("Input five numbers\n");

	// scanf한 숫자를 배열에 넣는다. 
	for (i = 0; i < ARRAY_SIZE; i++) scanf_s("%d", &numbers[i]);

	// 거꾸로 출력.
	for (i= ARRAY_SIZE - 1; i >= 0; i--) printf("%d " , numbers[i]);

	return 0;
}