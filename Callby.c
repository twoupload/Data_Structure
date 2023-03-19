#include <stdio.h>

void swap1(int x, int y);
void swap2(int* px, int* py);

int main(void) {
	int a = 5, b = 7;
	swap1(a, b);
	printf("%d %d\n", a, b);
	swap2(&a, &b);
	printf("%d %d\n", a, b);
	return 0;
}

void swap1(int x, int y) {
	int temp = x;
	x = y;
	y = temp;
}

void swap2(int* px, int* py) {
	int temp = *px;
	*px = *py;
	*py = temp;
}