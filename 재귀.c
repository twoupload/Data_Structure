#include <stdio.h>

void Recursive(int n) {
	// Base case : termination condition // 종료의 조건이 나온다. 
	if (n == 0) return;

	// Recursive case // 재귀의 조건이 나온다. 
	else {
		printf("Recursive call: %d\n", n);

		Recursive(n - 1);
	}
}

int main(void) {

	int i = 5;

	Recursive(i);

	return 0;
}