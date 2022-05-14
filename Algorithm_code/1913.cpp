#include <iostream>
#include <vector>

//달팽이 시뮬레이션 문제
//이전에도 벌집 문제와 비슷한 내역이니 숙지하는 것도 괜찮을 수도 있다.

int N, M;
int map[1001][1001];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
std::pair<int, int> ans;

void calculate() {
	int x = (N / 2);
	int y = (N / 2);
	int num = 1;
	for (int i = 1; i <= N / 2; i++) {
		x += dx[3];
		y += dy[3];
		map[x][y] = ++num;
		for (int k = 0; k < 4; k++) {
			for (int l = 1; l <= 2 * i; l++) {
				if (k == 0 && l == 1) continue;
				x += dx[k];
				y += dy[k];
				map[x][y] = ++num;
			}
		}
	}
}

int main() {
	scanf("%d", &N);
	scanf("%d", &M);
	map[N / 2][N / 2] = 1;
	calculate();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
			if (map[i][j] == M) ans = std::make_pair(i, j);
		}
		printf("\n");
	}
	printf("%d %d", ans.first + 1, ans.second + 1);

}