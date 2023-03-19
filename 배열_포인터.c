#include <stdio.h>

int main(void) {
	int a[6] = { 5,3,1,2,4,6 };
	int* pa = a;

	printf("%d %d\n", *a, *pa);
	printf("%p %p\n", a, pa);
	printf("%p %p\n",&a, &pa);
	printf("%d %d\n", a[0], pa[0]);
	printf("%d %d\n", a[1], pa[0]);

	return 0;
}