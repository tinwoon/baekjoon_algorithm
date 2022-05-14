#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> dp;
std::vector<int> cost;
std::vector<int> need_day;

int calculate() {
	for (int i = 1; i <= N; i++) {
		dp[i] = std::max(dp[i - 1], dp[i]);
		if (i + need_day[i] <= N + 1) {
			dp[i + need_day[i]] = std::max(dp[i] + cost[i], dp[i + need_day[i]]);
		}
	}
	dp[N + 1] = std::max(dp[N], dp[N + 1]);

	return dp[N + 1];
}

int main() {
	scanf("%d", &N);
	dp.assign(N + 2, 0);
	cost.assign(N + 1, 0);
	need_day.assign(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &need_day[i], &cost[i]);
	}
	printf("%d", calculate());
}
