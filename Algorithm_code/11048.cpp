#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

std::vector< std::vector<int> > map;
std::vector< std::vector<int> > value;

int N, M;

int dp(int a, int b) {

	if (a == 1 && b == 1) {
		value[1][1] = map[1][1];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			value[i][j] = std::max({ value[i - 1][j - 1] + map[i][j], value[i - 1][j] + map[i][j], value[i][j - 1] + map[i][j] });
		}
	}

	return value[N][M];
}

int main() {

	scanf("%d %d", &N, &M);
	map.assign(N+1, std::vector<int>(M+1, 0));
	value.assign(N+1, std::vector<int>(M+1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d", dp(1,1));
}
