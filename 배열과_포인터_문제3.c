// 배열의 수를 4곱해서 배열을 순서대로 출력하는 프로그램 만들기
// 조건 : 함수를 이용하여 만들 것, 함수와 포인터를 연관지어서 만들 것.

#include <stdio.h>
void multiply4(int* pa, int len);

int main(void) {
	int a[5] = { 5,3,2,1,4 }, i;
	multiply4(a, 5);
	for (i = 0; i < 5; i++) printf("%d\n", a[i]);
	return 0;
}

void multiply4(int* pa, int len) {
	int i;

	for (i = 0; i < len; i++) {
		pa[i] *= 4;
	}
}