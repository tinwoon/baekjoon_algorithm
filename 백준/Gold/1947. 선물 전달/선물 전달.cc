#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

#define MOD 1000000000

int N;
std::vector<int> dp;

int main() {
	scanf("%d", &N);
	dp.assign(N + 1, 0);
	dp[2] = 1;
	for (int k = 3; k <= N; k++) {
		long long val = (((long long)(k - 1) * (long long)(dp[k - 1] + dp[k - 2])) % MOD);
		dp[k] = val;
	}
	printf("%d", dp[N]);
}