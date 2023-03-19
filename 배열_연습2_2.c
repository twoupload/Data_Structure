// 숫자를 입력받고 그에 대한 평균을 출력하는 프로그램을 만드시오.
// 단 숫자 입력과 평균은 함수로 만들 것.

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