#include <iostream>
#include <vector>
#include <algorithm>
int n, value;
std::vector<int> coin;
std::vector<int> dp;

//https://www.acmicpc.net/problem/2294
//마찬가지 입니다

int calculate(int value) {
	dp[0] = 0;
	for (int i = 0; i < coin.size(); i++) {
		dp[coin[i]] = 1;
	}

	for (int i = 0; i < coin.size(); i++) {
		for (int j = 1; j <= value; j++) {
			if (j - coin[i] >= 0) {
				dp[j] = std::min(dp[j], dp[j-coin[i]] + dp[coin[i]]);
			}
		}
	}
	return dp[value];
}

int main() {
	scanf("%d %d", &n, &value);
	coin.assign(n, 0);
	dp.assign(value + 1, 100000000);
	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}
	printf("%d", calculate(value)>=100000000?-1:calculate(value));
}
