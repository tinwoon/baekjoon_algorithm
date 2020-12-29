#include <iostream>
#include <vector>
#include <math.h>
std::vector<bool> visited(1000001,false);

//전에 푼 에라토스테네스의 채를 활용

void is_prime(int n) {

	if (n == 0) {
		return;
	}

	for (int i = 3; i <= n; i+=2) {
		if (!visited[i]) {
			if (!visited[n-i]) {
				printf("%d = %d + %d\n", n, i, n-i);
				return;
			}
			
		}
	}
	printf("Goldbach's conjecture is wrong.\n");
	return;

}

int main() {
	int n = 1;
	for (long long i = 2; i <= 1000000; i++) {
		if (!visited[i]) {
			for (long long j = i * i; j <= 1000000; j += i) {
				visited[j] = true;
			}
		}
	}
	while (n) {
		scanf("%d", &n);
		is_prime(n);
	}
}
