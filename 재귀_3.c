// stack overflow : 1) return이 없는 경우이거나, 2) 종료 조건이 없는 경우에 무한 반복이 된다. 

// stack overflow
void Recursive(int n) {
	printf("Recursive call: %d\n", n);
	Recursive(n - 1);
}

// Not stack overflow
void Recursive(int n) {
	if (n == 0) return 0;
	else
	{
		printf("Recursive call: %d\n", n);
		Recursive(n - 1);
	}
}