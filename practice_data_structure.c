// 1 to n
/**#include <stdio.h>

int sum(int n);
int rsum(int n);

int main(void) {
	int n;
	scanf_s("%d", &n);

	printf("%d\n", sum(n));
	printf("%d\n", rsum(n));

	return 0;
}

int sum(int n) {
	int i, s = 0;
	for (i = 0; i <= n; i++) {
		s += i;
	}

	return s;
}

int rsum(int n) {
	if (n == 0) return 0;
	else {
		return n + rsum(n - 1);
	}
}
**/

// 3의 배수만큼 더하기.
/**#include <stdio.h>

int sum(int n);
int rsum(int n);

int main(void) {
	int n;
	scanf_s("%d", &n);

	printf("%d\n", sum(n));
	printf("%d\n", rsum(n));

	return 0;
}

int sum(int n) {
	int i, s = 0;
	for (i = 0; i < n; i += 3) {
		s += i;
	}
	return s;
}

int rsum(int n) {
	if (n == 0) return 0;
	else if (n % 3 == 0) return rsum(n-3) + n;
	else rsum(n - n % 3);
}**/

// Finding a Maximum
/**#include <stdio.h>
#include <string.h>


int FindMax(int* arr, int n);
int rFindMax(int* arr, int n);

int main(void) {
	int arr[6] = { 5,1,66,99,87,54 };
	int n = 6;
	

	printf("%d\n",FindMax(arr,n));
	printf("%d\n",rFindMax(arr,n));

	return 0;
}

int FindMax(int* arr, int n) {
	int i, max;
	max = arr[0];
	for (i = 0; i < n; i++) {
		if (max < arr[i]) max = arr[i];
	}
	return max;
}

int rFindMax(int* arr, int n) {
	if (n == 1) return arr[0];
	else {
		int max = rFindMax(arr, n - 1);
		if (max < arr[n - 1]) return arr[n - 1];
		else return max;
	}
}**/

//Printin a Reverse String
/**#include <stdio.h>
void Printing(char* str, int n);
void rPrinting(char* str, int n);

int main(void) {
	char str[5];
	for (int i = 0; i < 5; i++) {
		scanf_s(" %c", &str[i]);
	}

	Printing(str, 5);
	printf("\n");
	rPrinting(str, 5);

	return 0;
}

void Printing(char* str, int n) {
	int i;
	for (i = n - 1; i >= 0; i--) {
		printf("%c", str[i]);
	}
}

void rPrinting(char* str, int n) {
	if (n == 0) return;
	else {
		printf("%c", str[n-1]);
		rPrinting(str, n-1);
	}
}*/ 

// Printing banary number
/**#include <stdio.h>

void rBinary(int n);

int main(void) {
	int n;
	scanf_s("%d", &n);

	rBinary(n);

	return 0;
}

void rBinary(int n) {
	if (n == 0) return;
	else {
		rBinary (n / 2);
		printf("%d", n % 2);
	}
}**/

// X's Power
/**#include <stdio.h>

int power(int x, int n);
int rpower(int x, int n);
int rrpower(int x, int n);

int main(void) {
	int n, x;
	scanf_s("%d %d", &x, &n);

	printf("%d\n", power(x, n));
	printf("%d\n", rpower(x, n));
	printf("%d\n", rrpower(x, n));

	return 0;
}

int power(int x, int n) {
	int pow = 1;
	int i;

	for (int i = 0; i < n; i++) pow *= x;
	return pow;
}

int rpower(int x, int n) {
	int pow = 1;
	if (n == 0) return 1;
	else {
		return x * rpower(x, n - 1);
	}
}

int rrpower(int x, int n) {
	if (n == 0) return 1;
	else if (n % 2 == 0) {
		int m = rrpower(x, n / 2);
		return m * m;
	}
	else return x * rrpower(x, n - 1);
}**/

// fibonacci Numbers
/**#include <stdio.h>

int fibo(int n) {
	int prev = 1, cur = 1 , next = 1;
	if (n == 1 || n == 2) printf("1");
	else {
		for (int i = 3; i <= n; i++) {
			prev = cur, cur = next;
			next = prev + cur;
		}
	}
	return next;
}

int rfibo(int n) {
	if (n == 1 || n == 2) return 1;
	else return rfibo(n - 1) + rfibo(n - 2);
}

int main(void) {
	int n;
	scanf_s("%d", &n);

	printf("%d\n",fibo(n));
	printf("%d\n",rfibo(n));

	return 0;
}**/

// sortint and Binary
#include <stdio.h>
void swap(int* a, int* b);
void Sorting(int* arr, int n);
int Binary(int* arr, int len, int target);
int Binary(int* arr, int low, int high, int target);

int main(void) {
	int Numbers[6] = { 5,1,99,87,16,24 };

	int target;
	

	Sorting(Numbers,6);

	printf("Numbers: ");
	for (int i = 0; i < 6; i++) printf("%d ", Numbers[i]);
	printf("\n");
	scanf_s("%d", &target);

	printf("%d", Binary(Numbers, 5, target));
	printf("%d", rBinary(Numbers, 0, 6, target));
}

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void Sorting(int* arr, int n) {
	int i, j, min;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i+1; j < n; j++) {
			if (arr[j] < arr[min]) min = j;
		}
		swap(&arr[i], &arr[min]);
	}
}

int Binary(int* arr, int len, int target) {
	int first = 0, last = len - 1, mid;
	while (first <= last) {
		mid = (first + last) / 2;
		if (target == arr[mid]) return mid;
		else {
			if (target < arr[mid]) last = mid - 1;
			else first = mid + 1;
		}
	}
	return -1;
}

int rBinary(int* arr, int low, int high, int target) {
	if (low > high) return -1;
	else {
		int mid = (low + high) / 2;
		if (target == arr[mid]) return mid;
		else if (target > arr[mid]) {
			rBinary(arr, mid + 1, high, target);
		}
		else rBinary(arr, low, mid - 1, target);
	}

}