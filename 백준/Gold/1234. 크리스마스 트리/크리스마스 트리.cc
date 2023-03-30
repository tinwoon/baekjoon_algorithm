#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

int n, r, g, b;
long long dp[11][101][101][101];
long long F[11];

long long factorial(int n) {
	if (F[n]) return F[n];
	
	return F[n] = (n * factorial(n - 1));
}

//N층의 R,G,B 개수만큼 남아있을 때
long long calculate(int N, int R, int G, int B) {
	if (R < 0 || G < 0 || B < 0) return 0;

	if (dp[N][R][G][B]) return dp[N][R][G][B];

	if (N == 0) return dp[N][R][G][B] = 1;

	long long ret = 0;

	if ((N % 3) == 0) {
		ret += calculate(N - 1, R - (N / 3), G - (N / 3), B - (N / 3)) * (F[N] / F[N / 3] / F[N / 3] / F[N / 3]);
	}
	if ((N % 2) == 0) {
		ret += calculate(N - 1, R - (N / 2), G - (N / 2), B) * (F[N] / F[N / 2] / F[N / 2]);
		ret += calculate(N - 1, R - (N / 2), G, B - (N / 2)) * (F[N] / F[N / 2] / F[N / 2]);
		ret += calculate(N - 1, R, G - (N / 2), B - (N / 2)) * (F[N] / F[N / 2] / F[N / 2]);
	}
	ret += calculate(N - 1, R - N, G, B);
	ret += calculate(N - 1, R, G - N, B);
	ret += calculate(N - 1, R, G, B - N);
	
	return dp[N][R][G][B] = ret;
}


int main() {
	F[1] = 1;
	dp[n][r][g][b] = 1;
	(void)factorial(10);
	scanf("%d %d %d %d", &n, &r, &g, &b);

	printf("%lld\n", calculate(n, r, g, b));
}