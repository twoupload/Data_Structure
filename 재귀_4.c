// n�� �Է¹ް� 0���� ������ 3�� ����� ���ؼ� ����ϴ� ���α׷��� ������
// ��, �Լ��� �̿��� �����. �Ϲ����� �ݺ����� ��͸� �̿��� �ݺ��� �� �� ����ض�.
#include <stdio.h>

int sum(int k);
int rsum(int k);

int main(void) {
	int n;
	scanf_s("%d", &n);

	printf("%d\n", sum(n));
	printf("%d\n", rsum(n));

	return 0;
	}

int sum(int k) {
	int i, sum = 0;
	for (i = 0; i <= k; i += 3) sum += i;
	return sum;
}

int rsum(int k) {
	if (k == 0) return 0;
	else if (k % 3 == 0) return rsum(k - 3) + k;
	else return rsum(k - k % 3);
}
