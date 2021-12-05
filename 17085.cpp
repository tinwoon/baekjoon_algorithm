#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//십자가 풀기 문제
//단순 구현 문제이다.
//재귀적으로 동작시켜 풀었다.

int N, M;
std::vector< std::vector<char> > map;
int ans = 0;

int two_level[2];

bool is_ok(int index, int k) {
	int n = index / M;
	int m = index % M;

	for (int size = 0; size < k + 1; size++) {
		int top, down, left, right;
		top = n - size;
		down = n + size;
		left = m - size;
		right = m + size;

		if (left < 0 || right >= M || top < 0 || down >= N) {
			return false;
		}
		if (map[top][m] != '#' || map[down][m] != '#' || map[n][left] != '#' || map[n][right] != '#') {
			return false;
		}

	}

	return true;
}

void change_map(int index, int k, char value) {

	int n = index / M;
	int m = index % M;

	for (int size = 0; size < k + 1; size++) {
		int top, down, left, right;
		top = n - size;
		down = n + size;
		left = m - size;
		right = m + size;

		map[top][m] = map[down][m] = map[n][left] = map[n][right] = value;

	}
}

void calculate(int first, int second, int level) {


	if (level == 2) {
		ans = std::max(ans, (1 + two_level[0] * 4) * (1 + two_level[1] * 4));
		return;
	}

	for (int k = 0; k < (N > M ? N : M); k++) {
		if (is_ok(level == 0 ? first : second, k)) {
			change_map(level == 0 ? first : second, k, 'O');
			two_level[level] = k;
			calculate(first, second, level + 1);
			change_map(level == 0 ? first : second, k, '#');
		}
	}
}

void indexing() {

	for (int i = 0; i < N * M; i++) {
		for (int j = i + 1; j < N * M; j++) {
			calculate(i, j, 0);
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	map.assign(N, std::vector<char>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
		}
	}
	indexing();
	printf("%d", ans);
}