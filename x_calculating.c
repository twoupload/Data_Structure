// �־��� ���ڸ� �����ϴ� ���α׷��� �����ÿ�.
// �� �ݺ����� ����Լ��� �̿��Ͽ� ���α׷��� ����ÿ�.

#include <stdio.h>

int power(int x, int n) {
	int i;
	int pow = 1;

	for (i = 0; i < n; i++) {
		pow *= x;
	}
	return pow;
}

int rpower(int x, int n) {
	if (n == 0) return 1;
	else return x * rpower(x, n - 1);
}

int main(void) {
	int n;
	int x;
	scanf_s("%d", &x);
	scanf_s("%d", &n);

	printf("%d\n", power(x, n));
	printf("%d\n", rpower(x, n));

	return 0;
}