#include <iostream>
#include <vector>
#include <algorithm>

std::vector<long long> dp;

long long calculate(int n) {
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (i == 1 || i == 2 || i == 3) {
			dp[i] = i;
			continue;
		}
		dp[i] = dp[i - 1] + 1;
		for (int j = 2; i - j >= 2; j++) {
			dp[i] = std::max(dp[i], dp[i - (j + 1)] * j);
		}
	}
	return dp[n];
}

int main() {
	int n;
	scanf("%d", &n);
	dp.assign(n + 1, 0);
	calculate(n);
	printf("%lli", calculate(n));
}
