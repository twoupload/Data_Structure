// �־��� �Լ��� ���Ͽ� ���� ū ���� ����ϴ� ���α׷��� �ۼ��Ͽ���
// ��, �ݺ��� ��͸� ����� ��.
#include <stdio.h>

int findMax(int* arr,int n);
int rfindMax(int* arr,int n);

int main(void) {
	int numbers [6] = { 10,11,15,99,17,88 };

	printf("%d\n", findMax(numbers, 6));
	printf("%d\n", rfindMax(numbers, 6));

	return 0;
}

int findMax(int* arr, int n) {
	int i = 0;
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if (max < arr[i]) max = arr[i];
	}
	return max;
}

int rfindMax(int* arr, int n) {
	if (n == 1) return arr[0];
	else {
		int max = rfindMax(arr, n - 1);
		if (max < arr[n - 1]) return arr[n - 1];
		else return max;
	}
}