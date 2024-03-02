#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <map>
#include <tuple>

std::vector< std::vector<int> > map;
std::vector< std::vector<int> > dp;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int N, M;

int calculate(int a, int b) {
	if (a == N - 1 && b == M - 1) return dp[a][b] = 1;

	if (dp[a][b] != -1) return dp[a][b];

	dp[a][b] = 0;
	for (int k = 0; k < 4; k++) {
		int nx = a + dx[k];
		int ny = b + dy[k];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[a][b] > map[nx][ny]) {
			dp[a][b] += calculate(nx, ny);
		}
	}

	return dp[a][b];
}

int main() {
	scanf("%d %d", &N, &M);
	map.assign(N, std::vector<int>(M, 0));
	dp.assign(N, std::vector<int>(M, -1));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d\n", calculate(0,0));
}

