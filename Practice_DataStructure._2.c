// Pointer

#include <stdio.h>
#include <stdlib.h>

// Reference operator
/**
int main(void)
{
	char c = 'A';
	char* pc = &c;

	printf("%c %p\n", c, pc);
	printf("%p %p\n", &c, &pc);
	printf("%d %d\n", sizeof(c), sizeof(pc));

	return 0;
}
**/

// Reference operator
/**
int main(void)
{
	int n = 3;
	int* pn = &n;

	printf("%d %p\n", n, pn);
	printf("%p %p\n", &n, &pn);
	printf("%d %d\n", sizeof(n), sizeof(pn));

	return 0;
}
**/

// Dereference operator
/**
int main(void)
{
	char c = 'A';
	char* pc = &c;

	printf("%c %c\n", c, *pc);

	*pc = 'C';
	printf("%c %c\n", c, *pc);

	return 0;
}
**/

// Using Pointers
/**
int main(void)
{
	int a, b, c; 
	int* p, * q, * r;

	a = 6, b = 10;
	p = &b, q = p, r = &c; // p = b의 주소, q = p = b의 주소, r = c의 주소.
	p = &a, * q = 8, * r = *p; // p = a의 주소, q의 값 = 8, r의 값 = p의 값 = 6;
	*r = a + *q + *&c; // r = 6 + 8 =

	printf("%d %d %d", a, b, c);

	return 0;
}
**/

/**
int main(void)
{
	int a, b, c;
	int* pa = &a, * pb = &b, * pc = &c;

	*pa = 10, * pb = 20;
	*pc = *pa + *pb;

	printf("%d %d %d", a, b, c);

	return 0;
}
**/

/**
// Two types for inter-funcion communication
void swap(int x, int y);
void swap2(int* px, int* py);

int main(void)
{
	int a = 5, b = 7;
	swap(a, b);
	printf("%d %d\n", a, b);
	swap2(&a, &b); // 주솟값 주의
	printf("%d %d\n", a, b);

	return 0;
}

// bad case
void swap(int x, int y)
{
	int temp;

	temp = x;
	x = y;
	y = temp;
}

// good case
void swap2(int* px, int* py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}
**/

// A pointer to a pointer
/**
int main()
{
	char c = 'A';
	char* pc = &c;
	char** ppc = &pc;

	printf("%p %p\n", pc, ppc);
	printf("%p %p\n", &pc, &ppc);
	printf("%d %d\n", sizeof(pc), sizeof(ppc));

	return 0;
}
**/

// Arithmetic Operations for Pointers
/**
int main()
{
	char c = 'A';
	char* pc = &c;
	char** ppc = &pc;

	printf("%p %p\n", pc, pc + 1); // +1 = 주어진 변수의 메모리 할당만큼 더해준다.
	printf("%p %p\n", ppc, ppc + 1);
	printf("%p %p\n", &c, &c + 1);
	printf("%p %p\n", &pc, &pc + 1);
	printf("%p %p\n", &ppc, &ppc + 1);

	return 0;
}
**/

/**
int main()
{
	char n = 20;
	char* pn = &n;
	char** ppn = &pn;

	printf("%p %p\n", pn, pn + 1); // +1 = 주어진 변수의 메모리 할당만큼 더해준다.
	printf("%p %p\n", ppn, ppn + 1);
	printf("%p %p\n", &n, &n + 1);
	printf("%p %p\n", &pn, &pn + 1);
	printf("%p %p\n", &ppn, &ppn + 1);

	return 0;
}
**/

// Array and Pointer
// 배열의 포인터는 항상 그 배열의 첫번째 index(0)을 가진다. 
/**
int main(void)
{
	int a[6] = { 5,3,1,2,4,6 };
	int* pa = a;

	printf("%d %d\n", *a, *pa);
	printf("%p %p\n", a, pa);
	printf("%p %p\n", &a, &pa);
	printf("%d %d\n", a[0], pa[0]);
	printf("%d %d\n", a[1], pa[1]);

	return 0;
}
**/

/**
int main(void)
{
	int a[6] = { 1,2,3,4,5,6 };
	int* pend = a + 6;
	int* pi = NULL;

	for (pi = a; pi < pend; pi++)
	{
		printf("%d\n", *pi);
	}

	return 0;
}
**/

// print the smallest array value using points
/**
int main(void)
{
	int a[6] = { 32,12,31,42,15,24 };
	int* pend = a + 6;
	int* psmallest = a;
	int* pi = NULL;

	for (pi = a + 1; pi < pend; pi++)
	{
		if (*pi < *psmallest)
			psmallest = pi;
	}

	printf("%d", *psmallest);

	return 0;
}
**/

// Passing a pointer (instead of an array) to a function
/**
void printArray(int* pa, int len);

int main(void)
{
	int a[5] = { 5,3,2,1,4 };
	printArray(a, 5);
	return 0;
}

void printArray(int* pa, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d\n", pa[i]);
}
**/

// Multiplying 4 for each element in the array
/**
void multiply4(int* pa, int len);

int main(void)
{
	int a[5] = { 5,3,2,1,4 }, i;
	multiply4(a, 5);
	for (int i = 0; i < 5; i++)
		printf("%d\n", a[i]);
	return 0;
}

void multiply4(int* pa, int len)
{
	for (int i = 0; i < len; i++)
		pa[i] *= 4;
}
**/

// Dynamic Memory Allocation
/**
int main(void)
{
	int size, i;
	scanf("%d", &size);

	int* pn = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
		scanf("%d", &pn[i]);

	for (i = 0; i < size; i++)
		printf("%d", pn[i]);

	free(pn);

	return 0;
}
**/

/**
void geneNumbers(int* pn, int s);

int main(void)
{
	int size, i;
	scanf("%d", &size);
	int* pn = malloc(4 * size);

	geneNumbers(pn, size);
	for (i = 0; i < size; i++)
		printf("%d\n", pn[i]);
	free(pn);
	return 0;
}

void geneNumbers(int* pn, int s)
{
	int i;
	for (i = 0; i < s; i++)
		scanf("%d", &pn[i]);
}
**/

// structure

typedef struct
{
	char name[10];
	int scores[3];
	int total;
} student;
/**
int main(void)
{
	student s = { "Alice", 80, 70, 60 };

	printf("%s\n", s.name);

	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", s.scores[i]);
	}
	return 0;
}
**/

// Using Structures
/**
int main(void)
{
	int n;
	scanf("%d", &n);

	student* s = malloc(sizeof(student) * n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &s[i].name);
		s[i].total = 0;
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &s[i].scores[j]);
			s[i].total += s[i].scores[j];
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", s[i].total);
	
	free(s);
	return 0;
}
**/

// Multiplying two fractions
/**
typedef struct
{
	int numerator;
	int denominator;
} fraction;

int main(void)
{
	fraction f1 = { 4,5 };
	fraction f2 = { 3,7 };
	fraction f3;
	fraction f4;

	f3.denominator = f1.denominator * f2.denominator;
	f3.numerator = f1.numerator * f2.numerator;

	f4.denominator = f1.denominator * f2.denominator;
	f4.numerator = (f1.numerator * f2.denominator) + (f2.numerator * f1.denominator);

	printf("%d / %d\n", f3.numerator, f3.denominator);
	printf("%d / %d\n", f4.numerator, f4.denominator);
	return 0;
}
**/

// Selection Sort
/**
void Selection(int* list, int n)
{
	int i, j, min;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
		{
			if (list[i] < list[min])
				min = j;
		}
		swap(list[i], list[min]);
	}
}
**/

// Asymptotic Notation
int search(int arr[], int len, int target)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == target)
			return i;
	}
	return -1;
}

int BSearch(int arr[], int len, int target)
{
	int first, last, mid;
	first = 0, last = len - 1;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (target == arr[mid])
			return mid;
		else
		{
			if (target < arr[mid])
				last = mid - 1;
			else
				first = mid + 1;

		}
	}
	return -1;
}