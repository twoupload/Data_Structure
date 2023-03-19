// ºÐ¼ö °ö¼À
#include <stdio.h>

typedef struct {
	int numerator;
	int denominator;
}fraction;

int main(void) {
	fraction f1 = { 4,5 };
	fraction f2 = { 3,7 };
	fraction f3;

	f3.denominator = f1.denominator * f2.denominator;
	f3.numerator = f1.numerator * f2.numerator;

	printf("%d / %d", f3.numerator, f3.denominator);
	return 0;
}