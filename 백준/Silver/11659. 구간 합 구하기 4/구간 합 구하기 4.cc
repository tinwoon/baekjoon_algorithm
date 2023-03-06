#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

int N, M, a, b;
std::vector<int> sum;

int main() {
	scanf("%d %d", &N, &M);
	sum.assign(N + 1, 0);
	for (int k = 1; k <= N; k++) {
		scanf("%d", &a);
		sum[k] = sum[k - 1] + a;
	}
	for (int k = 0; k < M; k++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", sum[b] - sum[a - 1]);
	}
}