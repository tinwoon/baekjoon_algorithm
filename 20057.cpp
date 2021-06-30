#include <iostream>
#include <vector>

int N;
int map[500][500];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int tx[4][9] = { {-2,-1,-1,-1,0,1,1,1,2}, {0,1,0,-1,2,1,0,-1,0}, {-2,-1,-1,-1,0,1,1,1,2}, {0,-1,0,1,-2,-1,0,1,0} };
int ty[4][9] = { {0,-1,0,1,-2,-1,0,1,0}, {2,1,1,1,0,-1,-1,-1,-2}, {0,1,0,-1,2,1,0,-1,0}, {2,1,1,1,0,-1,-1,-1,-2} };
int portion[9] = { 2,10,7,1,5,10,7,1,2 };

int ans = 0;

void calculate(int x, int y, int dir, int increment) {
	int c_increment = increment;
	int nx = x, ny = y;
	while (c_increment--) {

		if (nx == 0 && ny == 0) return;

		nx += dx[dir];
		ny += dy[dir];
		int sum = 0;

		for (int k = 0; k < 9; k++) {
			int px = nx + tx[dir][k];
			int py = ny + ty[dir][k];
			if (px >= 0 && px < N && py >= 0 && py < N) {
				map[px][py] += portion[k] * map[nx][ny] / 100;
				sum += portion[k] * map[nx][ny] / 100;
			}
			else {
				ans += portion[k] * map[nx][ny] / 100;
				sum += portion[k] * map[nx][ny] / 100;
			}
		}

		int alpha_x = nx + dx[dir];
		int alpha_y = ny + dy[dir];
		if (alpha_x >= 0 && alpha_x < N && alpha_y >= 0 && alpha_y < N) map[alpha_x][alpha_y] += map[nx][ny] - sum;
		else ans += map[nx][ny] - sum;
		map[nx][ny] = 0;

	}
	if (dir == 1 || dir == 3) calculate(nx, ny, (dir + 1) % 4, increment + 1);
	else calculate(nx, ny, (dir + 1) % 4, increment);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	calculate(N / 2, N / 2, 0, 1);
	printf("%d", ans);
}
