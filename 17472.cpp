#include <iostream>
#include <vector>
#include <string.h>

bool map[11][11];
bool visited[11][11];
//섬 별로 번호 저장
int island_map[11][11];
//x 섬의 좌표들을 저장
std::vector< std::pair<int, int> > island_loc;

int N, M;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void calculate(int i, int j, int count) {

	if (visited[i][j] || i < 0 || i >= N || j < 0 || j >= M) return;

	visited[i][j] = true;
	for (int k = 0; k < 4; k++) {
		int nx = i + dx[k];
		int ny = j + dy[k];
		if (!visited[nx][ny] && map[nx][ny]) {
			calculate(nx, ny, count);
		}
	}
	return;
}

int main() {
	memset(island_map, -1, sizeof(island_map));
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			memset(visited, -1, sizeof(visited));
			if (map[i][j]) calculate(i, j, count++);
		}
	}
}