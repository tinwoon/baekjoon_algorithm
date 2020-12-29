#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

//dp 2차원 점화식

int N;
std::vector< std::vector<int> > dp;

void calculate() {
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k]%10007;
			}
		}
	}
	printf("%d",std::accumulate(dp[N].begin(), dp[N].end(),0) % 10007);
	
}

int main() {
	scanf("%d", &N);
	dp.assign(N+1, std::vector<int>(10));
	calculate();
}
