// ���ڿ��� �Է¹޾�, �� ���ڿ��� �ݴ�� ����Ͻÿ�.
#include <stdio.h>
#include <stdlib.h>

// �ݺ����� �̿��� ����
void rprint(char* str, int n) {
	int i;
	for (i = n - 1; i >= 0; i--) printf("%c", str[i]);
}

// ��͸� �̿��� ����.
void rrprint(char* str, int n) {
	if (n == 0) return;
	else {
		printf("%c", str[n - 1]);
		rrprint(str, n - 1);
	}
}

int main(void) {
	int n;
	scanf_s("%d", &n);

	char* str = malloc(sizeof(char) * n);
	
	for (int i = 0; i < n; i++) {
		scanf_s(" %c", & str[i]);
	}

	rprint(str, n);
	printf("\n");
	rrprint(str, n);

	return 0;
}