// ���ڸ� �Է¹ް� �׿� ���� ����� ����ϴ� ���α׷��� ����ÿ�.
// �� ���� �Է°� ����� �Լ��� ���� ��.

#include <stdio.h>
#define ARRAY 5

void inputNumber(int num[], int len) {
	int i;
	for (i = 0; i < len; i++) {
		scanf_s("%d", &num[i]);
	}
}

double getAverage(int num[], int len) {
	int sum = 0, i;
	for (i = 0; i < len; i++) {
		sum += num[i];
	}

	return (double)sum / (double)len;
}

int main(void) {
	int number[ARRAY];

	inputNumber(number, ARRAY);
	printf("Average: %.3lf", getAverage(number, ARRAY));

	return 0;
}