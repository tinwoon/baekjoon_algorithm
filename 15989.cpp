#include <iostream>
#include <vector>

//https://www.acmicpc.net/problem/15989
//반드시 외울 것(중복을 없애는 방법으로 자주 쓰임)

std::vector<int> dp;
int number[3] = { 1,2,3 };
int n;

int calculate() {
	dp[0] = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= n; j++) {
			if (j-number[i]>=0) {
				dp[j] += dp[j - number[i]];
			}
		}
	}
	return dp[n];
}

int main() {
	int test_num;
	scanf("%d", &test_num);
	while (test_num--) {
		scanf("%d", &n);
		dp.assign(n + 1, 0);
		printf("%d\n",calculate());
	}
}
