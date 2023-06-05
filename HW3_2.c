#include <stdio.h>
#define NUM	300
int grid[NUM][NUM];
int temp[NUM][NUM]; // grid의 수 비교용 임시 배열

int configFind(int m, int n, int i, int j) // 임시 배열과 grid 비교 함수
{
	if (i < 0 || i >= m || j < 0 || j >= n) // 아예 나올 수 없는 경우
		return 0;
	else if (temp[i][j] == 1 || grid[i][j] != 1) // 이미 계산한 경우
		return 0;

	temp[i][j] = 1; // 중복 방지를 위한 조정.

	return 1 + configFind(m, n, i - 1, j) + configFind(m, n, i, j - 1) + configFind(m, n, i + 1, j) + configFind(m, n, i, j + 1); // 0,0부터 시작 -> 각 행과 열마다 1씩 증가하며 재귀해서 판단.
}

// MODIFY THIS CODE
int get_mine(int m, int n) {
	int result = 0;
	for (int i = 0; i < m; i++)
	{ // temp 배열을 모조리 0으로 초기화
		for (int j = 0; j < n; j++)
			temp[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 1) { // 지뢰인 경우
				int count = configFind(m, n, i, j); // 해당 index의 구역 여부를 결정한다. 
				if (count > 0) { // count가 0 이상인 경우 == 해당하는 index에 지뢰 구역이 있는 경우. 
					result++; // result 증가
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