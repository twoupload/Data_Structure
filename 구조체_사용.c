#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[10];
	int scores[3];
	int total;
}student;

int main(void) {
	int n;
	scanf_s("%d", &n);

	student* stu = malloc(sizeof(student) * n);
	for (int i = 0; i < n; i++) {
		scanf_s("%s", stu[i].name);
		stu[i].total = 0;
		for (int j = 0; j < 3; j++) {
			scanf_s("%d", &stu[i].scores[j]);
			stu[i].total += stu[i].scores[j];
		}
	}
	free(stu);
	return 0;
}