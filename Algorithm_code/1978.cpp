#include <iostream>
#include <math.h>


// �Ҽ� ã�� �˰����� �� �������
bool prime(int N) {
	if (N < 2) return false;
	for (int i = 2; i * i <= N; i++) {
		if (N % i == 0) {
			return false;
		}
	}
	return true;
}


int main() {
	int num;
	int data;
	int rst = 0;
	scanf("%d", &num);
	while (num--) {
		scanf("%d", &data);
		if (prime(data)) rst++;
	}
	printf("%d", rst);
}
