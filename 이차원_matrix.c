#include <stdio.h>

int main(void) {


	int row, col, matrix[6][6];

	for (row = 0; row < 6; row++)
	{
		for (col = 0; col < 6; col++) {
			if (row < col) matrix[row][col] = 1;
			else if (row == col) matrix[row][col] = 0;
			else matrix[row][col] = -1;
		}
	}

	for (row = 0; row < 6; row++) {
		for (col = 0; col < 6; col++) {
			printf("%3d ", matrix[row][col]);
		}
		printf("\n");
	}
	return 0;
}