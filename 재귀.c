#include <stdio.h>

void Recursive(int n) {
	// Base case : termination condition // ������ ������ ���´�. 
	if (n == 0) return;

	// Recursive case // ����� ������ ���´�. 
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