// stack overflow : 1) return�� ���� ����̰ų�, 2) ���� ������ ���� ��쿡 ���� �ݺ��� �ȴ�. 

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