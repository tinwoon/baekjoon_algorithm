#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <cstring>

#define DIV 1000000007

int N, L, R;
long long dp[101][101][101];


int main() {
	scanf("%d %d %d", &N, &L, &R);

	dp[1][1][1] = 1;

	for (int n = 2; n <= N; n++) {
		for (int l = 1; l <= L; l++) {
			for (int r = 1; r <= R; r++) {
				dp[n][l][r] = ((dp[n - 1][l - 1][r]) + (dp[n - 1][l][r - 1]) + ((n - 2) * dp[n - 1][l][r])) % DIV;
			}
		}
	}

	printf("%lld", dp[N][L][R]);
}