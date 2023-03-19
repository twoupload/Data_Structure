#include <stdio.h>

int main(void) {
	char c = 'A';
	char* pc = &c;
	char** ppc = &pc;

	printf("%p %p\n",pc,ppc);
	printf("%p %p\n", &pc, &ppc);
	printf("%d", sizeof(pc));
	printf("%d" ,sizeof(ppc));

	return 0;
}