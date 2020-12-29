#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector< std::vector<long long> > dp;


long long calculate() {
	if (N >= 1) {
		dp[1][0] = 0;
		dp[1][1] = 1;
	}
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	return dp[N][0] + dp[N][1];
}

int main() {
	scanf("%d", &N);
	dp.assign(N + 1, std::vector<long long>(2, 0));
	printf("%lli", calculate());
}
