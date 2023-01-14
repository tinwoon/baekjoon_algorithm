#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <cstring>
#define DIV 1000000009

int T, N, M;

int dp[1001][1001];

int calculate(int m, int n) {
	if (m < 1 || n < 1) return 0;
	if (dp[m][n] != -1) return dp[m][n];

	return dp[m][n] = ( (calculate(m - 1, n - 1) + calculate(m - 1, n - 2))%DIV + calculate(m - 1, n - 3) ) % DIV;

}

int main() {
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	dp[1][1] = dp[1][2] = dp[1][3] = 1;

	while (T--)
	{
		scanf("%d %d", &N, &M);
		printf("%d\n", calculate(M, N));
	}

}