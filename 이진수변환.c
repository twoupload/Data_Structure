// �־��� ������ ���ڸ� �������� ��ȯ�Ͻÿ�
// ��, ����Լ��� �̿��Ͻÿ�.
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