#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

//���ǿ� ��ȸ ����
//��Ʈ����ŷ�� dp�� Ȱ���Ͽ� ������ Ǯ �� �ִ�.
//dp[n][visited]���·� n�� ��带 visited���¿��� �ּڰ��� �ǹ��Ѵ�.

int N;
std::vector< std::vector<int> > weight;
std::vector< std::vector<int> > dp;

int calculate(int node, int visited) {

	if (visited == (1 << N) - 1) {
		if (weight[node][0] != 0) {
			return weight[node][0];
		}
		return INT_MAX;
	}

	if (dp[node][visited] != -1) return dp[node][visited];
	dp[node][visited] = INT_MAX;

	for (int k = 0; k < N; k++) {
		if (visited & (1 << k) || weight[node][k] == 0) continue;
		long long candidate = (long long)weight[node][k] + (long long)calculate(k, visited | (1 << k));
		dp[node][visited] = (int)std::min((long long)dp[node][visited], candidate);
	}
	return dp[node][visited];
}

int main() {
	scanf("%d", &N);
	weight.assign(N, std::vector<int>(N, 0));
	dp.assign(N, std::vector<int>((1 << N), -1));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &weight[i][j]);
		}
	}
	printf("%d", calculate(0, 1));
}