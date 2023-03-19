#include <stdio.h>
#define ARRAY_SIZE 5

void inputNumbers(int num[], int len) {
	for (int i = 0; i < len; i++) {
		scanf_s("%d", &num[i]);
	}
}
double computeAverage(int num[], int len) {
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += num[i];
	}

	double avr = (double)sum / (double)(len);

	return avr;
}

int main()
{
	int numbers[ARRAY_SIZE];

	inputNumbers(numbers, ARRAY_SIZE);
	printf("average: %.3lf", computeAverage(numbers, ARRAY_SIZE));

	return 0;
}