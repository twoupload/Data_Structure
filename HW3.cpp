
#include <stdio.h>
#define NUM    300
int grid[NUM][NUM];
int visited[NUM][NUM];

int dfs(int m, int n, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == 1 || grid[i][j] != 1)
        return 0;

    visited[i][j] = 1;

    return 1 + dfs(m, n, i - 1, j) + dfs(m, n, i + 1, j) + dfs(m, n, i, j - 1) + dfs(m, n, i, j + 1);
}

int get_mine(int m, int n) {
    int result = 0;
    for (int i = 0; i < m; i++) { // 전부 0으로 채워넣는다. 
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                int count = dfs(m, n, i, j);
                if (count > 0) {
                    result++;
                }
            }
        }
    }
    return result;
}

int main() {
    int i = 0, j = 0, m = 0, n = 0, result = 0;

    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    result = get_mine(m, n);
    printf("%d\n", result);

    return 0;
}