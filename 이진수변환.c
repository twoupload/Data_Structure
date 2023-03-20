// 주어진 십진수 숫자를 이진수로 변환하시오
// 단, 재귀함수를 이용하시오.
#include <stdio.h>

void binary(int n);

int main(void) {
	int n;
	scanf_s("%d", &n);

	binary(n);

	return 0;
}

void binary(int n) {
	if (n == 0) return;
	else {
		binary(n / 2);
		printf("%d", n % 2);
	}
}