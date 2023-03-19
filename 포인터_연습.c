#include <stdio.h>

int main(void) {
	char c = 'A';
	char* pc = &c;

	printf("%c %p\n", c, pc);
	printf("%p %p\n", &c, &pc);
	printf("%d %d\n", sizeof(c), sizeof(pc));

	return 0;
}