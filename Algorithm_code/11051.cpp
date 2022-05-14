//파스칼의 삼각형을 원리로 기억해서 풀면 된다.

#include <iostream>
#include <vector>

int dp[1001][1001];
int N, K;

int calculate() {
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) dp[i][j] = 1;
			else (dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]) %= 10007;
		}
	}
	return dp[N][K];
}

int main() {
	scanf("%d %d", &N, &K);
	printf("%d", calculate());
}
