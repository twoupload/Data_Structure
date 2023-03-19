#include <stdio.h>
typedef struct
{
	char name[10];
	int scores[3];
} STUDENT;

int main(void) {
	STUDENT s1 = { "Alice",80,70,60 };
	printf("%s\n", s1.name);

	for (int i = 0; i < 3; i++) {
		printf("%d\n", s1.scores[i]);
	}
	return 0;
}