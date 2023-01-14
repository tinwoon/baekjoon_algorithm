#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#define DIV 1000000009

int T, N, M;

//dp[사용한 수][값] = 개수
std::vector< std::vector<int> > dp;

int calculate(int m, int n) {
	if (m < 1 || n < 1) return 0;
	if (dp[m][n] != -1) return dp[m][n];

	return dp[m][n] = ( (calculate(m - 1, n - 1) + calculate(m - 1, n - 2))%DIV + calculate(m - 1, n - 3) ) % DIV;

}

int main() {
	scanf("%d", &T);
	dp.assign(1001, std::vector<int>(1001, -1));
	dp[1][1] = dp[1][2] = dp[1][3] = 1;

	while (T--)
	{
		scanf("%d %d", &N, &M);
		printf("%d\n", calculate(M, N));
	}

}