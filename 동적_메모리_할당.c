#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int size, i;
	scanf_s("%d", &size);

	// Allocate dynamic memory
	int pn[size];

	for (i= 0; i < size; i++) {
		printf("%d\n", pn[i]);
	}

	return 0;
}

// 구동이 되지 않는다. size가 정해지지 않은 상태에서 pn 배열의 상수로 넣었기 때문,
// 정적인 배열에서는 미리 값을 넣어놓지 않으면 오류가 생긴다. 