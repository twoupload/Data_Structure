// 1���� n������ ���� ���� ����ϴ� �Լ��� ���� ���α׷��� ���α׷����϶�.
#include <stdio.h>

// for �ݺ����� �̿��Ͽ� ����ϴ� ���
int sum(int n) {
	int i, sum = 0;
	for (i = 0; i <= n; i++) {
		sum += i;
	}
	return sum;
}

// ��� �Լ��� �̿��� ���(Recursive)
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