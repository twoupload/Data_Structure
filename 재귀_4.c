// n을 입력받고 0부터 시작해 3의 배수만 더해서 출력하는 프로그램을 만들어라
// 단, 함수를 이용해 만들고. 일반적인 반복문과 재귀를 이용한 반복을 둘 다 사용해라.
#include <stdio.h>

int sum(int k);
int rsum(int k);

int main(void) {
	int n;
	scanf_s("%d", &n);

	printf("%d\n", sum(n));
	printf("%d\n", rsum(n));

	return 0;
	}

int sum(int k) {
	int i, sum = 0;
	for (i = 0; i <= k; i += 3) sum += i;
	return sum;
}

int rsum(int k) {
	if (k == 0) return 0;
	else if (k % 3 == 0) return rsum(k - 3) + k;
	else return rsum(k - k % 3);
}
