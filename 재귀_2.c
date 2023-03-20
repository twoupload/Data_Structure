// 1부터 n까지의 수의 합을 출력하는 함수를 가진 프로그램을 프로그래밍하라.
#include <stdio.h>

// for 반복문을 이용하여 계산하는 방법
int sum(int n) {
	int i, sum = 0;
	for (i = 0; i <= n; i++) {
		sum += i;
	}
	return sum;
}

// 재귀 함수를 이용한 방법(Recursive)
int rsum(int n) {
	if (n == 0) return 0;
	else return rsum(n - 1) + n;
}

int main(void) {
	int k;
	scanf_s("%d", &k);

	printf("%d\n", sum(k));
	printf("%d\n", rsum(k));

	return 0;
}