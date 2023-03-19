#include <stdio.h>

int main(void) {
	char c = 'A';
	char* pc = &c;

	printf("%c %c\n", c, *pc);

	*pc = 'C';

	printf("%c %c", c, *pc);

	return 0;
}