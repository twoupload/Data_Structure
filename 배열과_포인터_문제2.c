// �迭�� ������� ����ϴ� ���α׷� �����
// ���� : �Լ��� �̿��Ͽ� ���� ��, �Լ��� �����͸� ������� ���� ��.

#include <stdio.h>
void printArray(int* pa, int len);

int main(void) {
	int a[5] = { 5,3,2,1,4 };
	printArray(a, 5);
	return 0;
}

void printArray(int* pa, int len) {
	int i;
	for (i = 0; i < len; i++) {
		printf("%d\n", pa[i]);
	}
}