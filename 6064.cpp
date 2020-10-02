#include <iostream>
#include <vector>
#include <math.h>


// %�� ����Ͽ� Ȯ�ΰ���
// ���� x�� ���� ���� ���� ����� ���� �ּ�ȭ�ϰ�
// �� ����� ������ y���� ���Ͽ� ã�� ���
int calculate(int M, int N, int x, int y) {
	if (y == N) y = 0;
	for (int i = 0; i < 40000; i++) {
		if (((x + (M * i)) % N == y)) {
			return x + (M * i);
		}
	}
	return -1;
}

int main() {
	int M, N = 0;
	int x, y = 0;
	int num = 0;
	scanf("%d", &num);
	while (num--) {
		scanf("%d %d %d %d", &M, &N, &x, &y);
		printf("%d\n", calculate(M, N, x, y));
	}

	return 0;

}