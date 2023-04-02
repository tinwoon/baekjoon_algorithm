#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>

#define MIN_VAL -10000
#define I (int)

int T, W;
//T시간에 val번 나무에 자두 있음.
bool data[1001][2];
//T번째 시간에 W만큼 움직일 수 있고, N번 위치에 있을 때 먹을 수 있는 최대의 자두
int dp[1001][31][2];

int calculate(int t, int w, int n) {
	if (t == 0) return 0;
	if (dp[t][w][n]) return dp[t][w][n];

	int stay = 0, move = 0;

	stay = calculate(t - 1, w, n) + I data[t][n];
	if(w) move = calculate(t - 1, w - 1, (n + 1) % 2) + I data[t][(n + 1) % 2];

	return dp[t][w][n] = std::max(stay, move);
}

int main() {
	scanf("%d %d", &T, &W);

	for (int k = T; k >= 1; k--) {
		int val;
		scanf("%d", &val);
		data[k][val - 1] = true;
	}
	printf("%d", calculate(T, W, 0));
}