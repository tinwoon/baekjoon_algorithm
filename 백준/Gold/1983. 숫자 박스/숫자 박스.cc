#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

int N;
int u_empty = 0, l_empty = 0;
std::vector< std::vector< std::vector<int> > > dp;
std::vector<int> data[2];

int calculate(int n, int upper_empty, int lower_empty) {
	if (n == 0 || (upper_empty == -1 && lower_empty == -1)) return 0;

	if (dp[n][upper_empty][lower_empty] != INT_MIN) return dp[n][upper_empty][lower_empty];

	int u_idx = N - n - (u_empty - upper_empty);
	int l_idx = N - n - (l_empty - lower_empty);

	if (u_idx >= data[0].size() || l_idx >= data[1].size()) return dp[n][upper_empty][lower_empty] = 0;

	//위만 비우거나, 아래만 비우거나, 둘다 그대로거나
	int one = INT_MIN, two = INT_MIN, four = 0;
	if (upper_empty > 0) one = calculate(n - 1, upper_empty - 1, lower_empty);
	if (lower_empty > 0) two = calculate(n - 1, upper_empty, lower_empty - 1);
	four = data[0][u_idx] * data[1][l_idx] + calculate(n - 1, upper_empty, lower_empty);

	return dp[n][upper_empty][lower_empty] = std::max({ one, two, four });
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < N; k++) {
			int v;
			scanf("%d", &v);
			if (!v) {
				if (i == 0) u_empty++;
				else l_empty++;
			}
			else data[i].emplace_back(v);
		}
	}
	dp.assign(N + 1, std::vector<std::vector<int>>(u_empty + 1, std::vector<int>(l_empty + 1, INT_MIN)));
	printf("%d", calculate(N, u_empty, l_empty));
}