// �迭�� ���� 4���ؼ� �迭�� ������� ����ϴ� ���α׷� �����
// ���� : �Լ��� �̿��Ͽ� ���� ��, �Լ��� �����͸� ������� ���� ��.

#include <stdio.h>
void multiply4(int* pa, int len);

int main(void) {
	int a[5] = { 5,3,2,1,4 }, i;
	multiply4(a, 5);
	for (i = 0; i < 5; i++) printf("%d\n", a[i]);
	return 0;
}

void multiply4(int* pa, int len) {
	int i;

	for (i = 0; i < len; i++) {
		pa[i] *= 4;
	}
}