// 문자열을 입력받아, 그 문자열을 반대로 출력하시오.
#include <stdio.h>
#include <stdlib.h>

// 반복문을 이용한 형태
void rprint(char* str, int n) {
	int i;
	for (i = n - 1; i >= 0; i--) printf("%c", str[i]);
}

// 재귀를 이용한 형태.
void rrprint(char* str, int n) {
	if (n == 0) return;
	else {
		printf("%c", str[n - 1]);
		rrprint(str, n - 1);
	}
}

int main(void) {
	int n;
	scanf_s("%d", &n);

	char* str = malloc(sizeof(char) * n);
	
	for (int i = 0; i < n; i++) {
		scanf_s(" %c", & str[i]);
	}

	rprint(str, n);
	printf("\n");
	rrprint(str, n);

	return 0;
}