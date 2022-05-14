#include <iostream>
#include <vector>
#include <algorithm>

std::vector<long long> dp;
int N = 0;

long long calculate(int n) {

	if (n >= 1) {
		dp[1] = 1;
	}
	if (n >= 2) {
		dp[2] = 2;
	}
	if (n >= 3) {
		dp[3] = 4;
	}
	for (int i = 4; i <= n; i++) {
		dp[i] = (dp[i - 1] % 1000000009 + dp[i - 2] % 1000000009 + dp[i - 3] % 1000000009) % 1000000009;
	}

	return dp[n];
}


int main() {
	
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &N);
		dp.assign(N + 1, 0);
		printf("%lli\n", calculate(N));
	}
	
}
