// 해당하는 문자를 찾는 프로그램을 함수를 이용해 나타내어라.
#include <stdio.h>

int Binary(int a[], int n, int target) {
	int first, last, mid;
	first = 0, last = n - 1;
	while (first <= last) {
		mid = (first + last) / 2;
		if (a[mid] == target) return mid;
		else {
			if (a[mid] < target) first = mid + 1;
			else last = mid - 1;
		}
	}
	return -1;
}

int rBinary(int a[], int low, int high, int target) {
	if (low > high) return -1;
	else {
		int mid = (low + high) / 2;
		if (target == a[mid]) return mid;
		else if (target < a[mid]) rBinary(a, low, mid - 1, target);
		else rBinary(a, mid + 1, high, target);
	}
}
int main(void) {
	int a[6] = { 1,2,3,4,5,6 };
	int target;
	scanf_s("%d", &target);

	printf("%d\n", Binary(a, 6, target));
	printf("%d\n", rBinary(a, 0, 6, target));
}