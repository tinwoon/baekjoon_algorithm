#include <iostream>
#include <algorithm>
#include <vector>

//색종이 3문제
//해당 문제는 다르게 푸는 방법이 있다.
//현재는 그냥 단순히 구현했지만, x, y를 기준으로 오른쪽의 얼마만큼이 연속되는지 저장하면 된다.
//예를 들면 1,1좌표에서 오른쪽까지 10만큼이 1이면 dp[1][1] = 10이다.
//이런 방식으로 2,1 좌표에서의 dp[2][1]은 몇인지 확인하고 높이를 계속해서 측정하면서 확인한다.

int N;
bool map[101][101];
int min_x = 100, min_y = 100, max_x = 1, max_y = 1;
int ans = -1;

bool is_true(int x, int y, int i, int j) {
	if (x == 11 && y == 11 && i == 1 && j == 12) {
		printf("");
	}
	for (int s_x = i; s_x < i + x; s_x++) {
		for (int s_y = j; s_y < j + y; s_y++) {
			if (!map[s_x][s_y]) return false;
		}
	}
	return true;
}

int calculate() {
	for (int x = max_x - min_x + 10; x >= 1; x--) {
		for (int y = max_y - min_y + 10; y >= 1; y--) {
			if (x * y <= ans) continue;
			for (int i = min_x; i <= max_x + 10; i++) {
				for (int j = min_y; j <= max_y + 10; j++) {
					if (is_true(x, y, i, j)) {
						ans = std::max(x * y, ans);
					}
				}
			}
		}
	}
	return ans;
}

int main() {
	scanf("%d", &N);
	for (int k = 0; k < N; k++) {
		int x, y;
		scanf("%d %d", &x, &y);
		min_x = std::min(min_x, x);
		min_y = std::min(min_y, y);
		max_x = std::max(max_x, x);
		max_y = std::max(max_y, y);
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				map[i][j] = true;
			}
		}
	}
	printf("%d", calculate());
}