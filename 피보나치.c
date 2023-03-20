// 피보나치 수열을 작성해 보자.
#include <stdio.h>

int fibo(int n);

int main(void) {
	int n;
	scanf_s("%d", &n);

	printf("%d\n", fibo(n));
	printf("%d\n", rfibo(n));

	return 0;
}

int fibo(int n) {
	int i;
	if (n == 1 || n == 2) return 1;
	else {
		int prev = 1, cur = 1, next = 1;
		for (i = 3; i <= n; i++) {
			prev = cur, cur = next;
			next = cur + prev;
		}

		return next;
	}
}

int rfibo(int n) {
	if (n == 1 || n == 2) return 1;
	else return rfibo(n - 1) + rfibo(n - 2);
}
