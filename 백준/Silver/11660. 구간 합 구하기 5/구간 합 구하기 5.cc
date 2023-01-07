#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

int N, M;
std::vector< std::vector<int> > data;
std::vector< std::vector<int> > sum;

int calculate(int a, int b, int c, int d) {
	return (sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1]);
}

int main() {
	scanf("%d %d", &N, &M);
	data.assign(N + 1, std::vector<int>(N + 1, 0));
	sum.assign(N + 1, std::vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &data[i][j]);
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + data[i][j];
		}
	}
	for (int k = 0; k < M; k++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%d\n", calculate(a, b, c, d));
	}
}