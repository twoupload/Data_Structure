#include <stdio.h>
#define NUM	300
int grid[NUM][NUM];
int temp[NUM][NUM]; // grid�� �� �񱳿� �ӽ� �迭

int configFind(int m, int n, int i, int j) // �ӽ� �迭�� grid �� �Լ�
{
	if (i < 0 || i >= m || j < 0 || j >= n) // �ƿ� ���� �� ���� ���
		return 0;
	else if (temp[i][j] == 1 || grid[i][j] != 1) // �̹� ����� ���
		return 0;

	temp[i][j] = 1; // �ߺ� ������ ���� ����.

	return 1 + configFind(m, n, i - 1, j) + configFind(m, n, i, j - 1) + configFind(m, n, i + 1, j) + configFind(m, n, i, j + 1); // 0,0���� ���� -> �� ��� ������ 1�� �����ϸ� ����ؼ� �Ǵ�.
}

// MODIFY THIS CODE
int get_mine(int m, int n) {
	int result = 0;
	for (int i = 0; i < m; i++)
	{ // temp �迭�� ������ 0���� �ʱ�ȭ
		for (int j = 0; j < n; j++)
			temp[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 1) { // ������ ���
				int count = configFind(m, n, i, j); // �ش� index�� ���� ���θ� �����Ѵ�. 
				if (count > 0) { // count�� 0 �̻��� ��� == �ش��ϴ� index�� ���� ������ �ִ� ���. 
					result++; // result ����
				}
			}
		}
	}
	return result;
}

int main() {
	/* DO NOT MODIFY */
	int i = 0, j = 0, m = 0, n = 0, result = 0;

	scanf("%d %d", &m, &n);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &grid[i][j]);
		}
	}

	result = get_mine(m, n);
	printf("%d\n", result);
	/* DO NOT MODIFY */
}