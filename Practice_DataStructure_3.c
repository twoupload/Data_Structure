// Recursive
//#include <stdio.h>

/**
void Recursive(int n) {
	if (n == 0) return; //end condition
	else {
		printf("Recursive call : %d\n", n);
		Recursive(n - 1);
	}
}
**/

// summing from 1 to n
/**
int sum(int n);
int rsum(int n);

int main(void)
{
	int n;
	scanf("%d", &n);

	printf("%d\n", sum(n));
	printf("%d\n", rsum(n));

	return 0;
}

int sum(int n) {
	int s = 0;
	for (int i = 1; i <= n; i++)
		s += i;
	return s;
}

int rsum(int n)
{
	if (n == 0) return 0;
	else
		return rsum(n - 1) + n;
}
**/

// multiples of three
/**
int sum(int n)
{
	int sum = 0;
	for (int i = 0; i <= n; i += 3)
		sum = sum + i;
	return sum;
}

int rsum(int n)
{
	if (n == 0) return 0;
	else if (n % 3 != 0)
		return rsum(n - n % 3);
	else
		return rsum(n - 3) + n;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	printf("%d\n",sum(n));
	printf("%d\n",rsum(n));

	return 0;
}
**/

// finding maximum
/**
int findMax(int* arr, int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

int rfindMax(int* arr, int n)
{
	if (n == 1) return arr[0];
	else
	{
		int max = rfindMax(arr, n - 1);
		if (max < arr[n - 1])
			return arr[n - 1];
		else
			return max;
	}
}
**/

// printing a reverse string
/**
void rprint(char* s, int n)
{
	for (int i = n; i >= 0; i--)
		printf("%c", s[i]);
}

void rrprint(char* s, int n)
{
	if (n == 0) return;
	else
	{
		printf("%c", s[n - 1]);
		return rrprint(s, n - 1);
	}
}
**/

// binary
/**
void binary(int n)
{
	if (n == 0)
		return;
	else
	{
		binary(n / 2);
		printf("%d", n % 2);
	}
}
**/

// calculating x's power
/**
int power(int x, int n)
{
	int pow = 1;
	for (int i = 0; i < n; i++)
		pow *= x;
	return pow;
}

int rpower(int x, int n)
{
	if (n == 0) return 1;
	else return x * rpower(x, n - 1);
}

int rpower2(int x, int n)
{
	if (n == 0) return 1;
	else if (n % 2 == 0)
	{
		int m = rpower2(x, n / 2);
		return m * m;
	}
	else return x * rpower2(x, n - 1);
}
**/

// Fibonacci Numbers
/**
int fibo(int n)
{
	if (n == 1 || n == 2) return 1;
	else
	{
		int prev = 1, cur = 1, next = 1;
		for (int i = 3; i <= n; i++) {
			prev = cur, cur = next;
			next = prev + cur;
		}
		return next;
	}
}

int rfibo(int n)
{
	if (n == 1 || n == 2) return 1;
	else return rfibo(n - 1) + rfibo(n - 2);
}

int rfiboTail(int n,  int prev, int cur)
{
	if (n == 1 || n == 2) return cur;
	else return rfiboTail(n - 1, cur, prev + cur);
}

int findMax(int* arr, int n, int max)
{
	if (n == 1) return max;
	else {
		if (max < arr[n - 1])
			max = arr[n - 1];
	}
}
**/