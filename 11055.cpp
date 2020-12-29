#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<int> dp;
std::vector<int> value;


int calculate() {

	if (N >= 1) {
		dp[1] = value[1];
	}

	for (int i = 2; i <= N; i++) {
		dp[i] = value[i];
		for (int j = i - 1; j >= 1; j--) {
			if (value[i] > value[j]) {
				dp[i] = std::max(dp[i], dp[j] + value[i]);
			}
		}
	}

	
	return *std::max_element(dp.begin(), dp.end());
}

int main() {
	scanf("%d", &N);
	dp.assign(N + 1, 0);
	value.assign(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &value[i]);
	}
	printf("%d", calculate());
}
