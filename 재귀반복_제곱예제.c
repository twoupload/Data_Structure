// 재귀함수를 각자 다르게 사용하여, 제곱하는 프로그램을 만드시오
#include <stdio.h>

int rpower(x, n);
int rpower2(x, n);

int main(void) {
	int x, n;
	scanf_s("%d", &x);
	scanf_s("%d", &n);

	printf("%d\n", rpower(x, n));
	printf("%d\n", rpower2(x, n));

	return 0;
}

int rpower(x, n) {
	if (n == 0) return 1;
	else return x * rpower(x, n - 1);
}

int rpower2(x, n) {
	if (n == 0) return 1;
	else if (n % 2 == 0) {
		int m = rpower2(x, n / 2);
		return m * m;
	}
	else return x * rpower2(x, n-1);
}