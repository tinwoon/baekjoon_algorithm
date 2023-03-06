#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#define DIV 1000000007

int N, K;
std::vector< std::vector<int> > dp;
std::vector<int> sum;

//j+1 이후부터 j + 1 ~ K % K == 0인 값들
std::vector<int> ret_j(int j) {
	std::vector<int> ret;
	for (int start = j * 2; start <= K; start += j) {
		ret.emplace_back(start);
	}
	return ret;
}

int main() {
	scanf("%d %d", &N, &K);
	sum.assign(N + 1, 0);
	dp.assign(N + 1, std::vector<int>(K + 1, 0));
	std::fill(dp[1].begin(), dp[1].end(), 1);
	sum[1] = K;

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			dp[i][j] = (sum[i - 1]%DIV);
			auto ret_j_v = ret_j(j);
			for (int idx = 0; idx < ret_j_v.size(); idx++) {
				dp[i][j] = ((dp[i][j] - dp[i - 1][ret_j_v[idx]]) % DIV);
			}
			sum[i] = ((sum[i] + dp[i][j]) % DIV);
		}
	}
	printf("%d", sum[N]%DIV);
}