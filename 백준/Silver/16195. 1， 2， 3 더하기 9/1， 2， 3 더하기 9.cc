#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <cstring>

#define DIV 1000000009

int N, M, T, ans;
//dp[N][M] = N을 M개 이하로 만들 수 있는 경우의 수
int dp[1001][1001];

void init() {
	dp[1][1] = dp[2][1] = dp[3][1] = 1;
	return;
}

int calculate(int n, int m) {
	if (n <= 0 || m <= 0) return 0;
	if (dp[n][m] != -1) return dp[n][m];


	return dp[n][m] = (((calculate(n - 1, m - 1) + calculate(n - 2, m - 1)) % DIV) + calculate(n - 3, m - 1)) % DIV;
}



int main() {
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	init();

	while (T--) {
		ans = 0;
		scanf("%d %d", &N, &M);
		for (int k = 1; k <= M; k++) {
			ans = (ans + calculate(N, k))%DIV;
		}
		printf("%d\n", ans);
	}
}