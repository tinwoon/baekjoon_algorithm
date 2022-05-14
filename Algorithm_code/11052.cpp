#include <vector>
#include <iostream>
#include <algorithm>

int n;
std::vector<int> value;
std::vector<int> dp;

//dp 포기하지말고 한 시간이라도 더 고민하기

int calculate() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] = std::max(dp[i],dp[j]+value[i-j]);
		}
	}
	return dp[n];
}


int main() {
	
	scanf("%d", &n);
	value.assign(n + 1, 0);
	dp.assign(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &value[i]);
	}
	printf("%d", calculate());

}
