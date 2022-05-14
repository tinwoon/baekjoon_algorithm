#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> dp;
int N = 0;

int calculate(int n) {


	dp[1] = 1;
	dp[2] = 2;
	
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2])%10007;
	}

	return dp[n];
}


int main() {
	
	scanf("%d", &N);
	dp.assign(1001, 0);
	printf("%d", calculate(N));
}
