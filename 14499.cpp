#include <iostream>
#include <vector>

int N, M, x, y, K;
std::vector< std::vector<int> > map;
std::vector<int> dice(7,0);
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

//시뮬이라 알고리즘도 없다.

int bfs(int n, int x, int y) {
	auto tmp = dice;
	
	switch (n) {
		case 1:
			dice[1] = tmp[3];
			dice[3] = tmp[6];
			dice[4] = tmp[1];
			dice[6] = tmp[4];
			break;
		case 2:
			dice[1] = tmp[4];
			dice[3] = tmp[1];
			dice[4] = tmp[6];
			dice[6] = tmp[3];
			break;
		case 3:
			dice[1] = tmp[2];
			dice[2] = tmp[6];
			dice[5] = tmp[1];
			dice[6] = tmp[5];
			break;
		case 4:
			dice[1] = tmp[5];
			dice[2] = tmp[1];
			dice[5] = tmp[6];
			dice[6] = tmp[2];
			break;
	}
	if (map[x][y] == 0) map[x][y] = dice[1];
	else {
		dice[1] = map[x][y];
		map[x][y] = 0;
	}
	
	return dice[6];
}

int main() {
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
	map.assign(N, std::vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < K; i++) {
		int value;
		scanf("%d", &value);
		switch (value) {
			case 1: 
				if (x + dx[1] >= 0 && x + dx[1] < N && y + dy[1] >= 0 && y + dy[1] < M) {
					x += dx[1];
					y += dy[1];
					printf("%d\n", bfs(value, x, y));
				}
				break;
			case 2:
				if (x + dx[2] >= 0 && x + dx[2] < N && y + dy[2] >= 0 && y + dy[2] < M) {
					x += dx[2];
					y += dy[2];
					printf("%d\n", bfs(value, x, y));
				}
				break;
			case 3:
				if (x + dx[3] >= 0 && x + dx[3] < N && y + dy[3] >= 0 && y + dy[3] < M) {
					x += dx[3];
					y += dy[3];
					printf("%d\n", bfs(value, x, y));
				}
				break;
			case 4:
				if (x + dx[4] >= 0 && x + dx[4] < N && y + dy[4] >= 0 && y + dy[4] < M) {
					x += dx[4];
					y += dy[4];
					printf("%d\n", bfs(value, x, y));
				}
				break;
		}
	}

}
