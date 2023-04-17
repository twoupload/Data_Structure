// Array
//#include <stdio.h>
//#define ARRAY_SIZE 5

/**
int main(void)
{
	int score[3] = { 52, 17, 61 };

	for (int i = 0; i < 3; i++)
		printf("%d ", score[i]);
	printf("\n");

	printf("%d\n", score[0]);
	printf("%d\n", score[1]);
	printf("%d\n", score[2]);
	return 0;
}
**/

// print reversely
/**
int main(void)
{
	int numbers[ARRAY_SIZE], i;
	printf("Input five numbers\n");

	for (i = 0; i < 5; i++)
		scanf("%d", &numbers[i]);

	for (i = 4; i >= 0; i--)
		printf("%d ", numbers[i]);

	return 0;
}
**/

// Calculating the averabe of values in the array
/**
void inputNumbers(int num[], int len);
double computeAverage(int num[], int len);

int main(void)
{
	int numbers[ARRAY_SIZE] = { 0 };

	inputNumbers(numbers, ARRAY_SIZE);

	printf("average: %.3lf", computeAverage(numbers, ARRAY_SIZE));

	return 0;
}

void inputNumbers(int num[], int len)
{
	for (int i = 0; i < len; i++)
		scanf("%d", &num[i]);
}

double computeAverage(int num[], int len)
{
	double sum = 0;
	for (int i = 0; i < len; i++)
		sum += num[i];
	return sum / (double)len;
}
**/

// Two-Dimensional Arrays
/**
int main(void)
{
	int row, col, matrix[6][6];

	for (row = 0; row < 6; row++)
	{
		for (col = 0; col < 6; col++)
		{
			if (row == col)
				matrix[row][col] = 0;
			else if (row > col)
				matrix[row][col] = -1;
			else
				matrix[row][col] = 1;
		}
	}

	for (row = 0; row < 6; row++)
	{
		for (col = 0; col < 6; col++)
		{
			printf("%3d", matrix[row][col]);
		}
		printf("\n");
	}
}
**/