#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

int N;
std::vector<int> a, b;
std::vector< std::vector<int> > dp;

//n번 층의 왼쪽 회전횟수 (value)
int calculate(int n, int value) {
	if (n == N) return 0;
	if (dp[n][value] != -1) return dp[n][value];

	int cur = (a[n] + value) % 10;
	
	int left_turn = (b[n] - cur + 10) % 10;
	int left = left_turn + calculate(n + 1, (value + left_turn) % 10);

	int right_turn = (cur - b[n] + 10) % 10;
	int right = right_turn + calculate(n + 1, value);

	return dp[n][value] = left < right ? left : right;

}

int main() {
	scanf("%d", &N);
	a.assign(N, 0);
	b.assign(N, 0);
	for (int k = 0; k < N; k++) {
		scanf("%1d", &a[k]);
	}
	for (int k = 0; k < N; k++) {
		scanf("%1d", &b[k]);
	}
	dp.assign(N, std::vector<int>(10, -1));

	printf("%d\n", calculate(0, 0));
}