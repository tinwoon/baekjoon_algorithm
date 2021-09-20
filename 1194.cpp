#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <tuple>

//전형적인 비트마스크 + dp문제이다
//쉬우니 설명은 생략한다.

std::vector< std::vector<char> > map;
std::vector< std::vector< std::vector<bool> > > visited;
int N, M;
std::pair<int, int> start;
std::pair<int, int> end;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int calculate() {
	//x,y, 횟수, 열쇠
	std::queue< std::tuple<int, int, int, int> > q;
	q.emplace(std::make_tuple(start.first, start.second, 0, 0));
	visited[start.first][start.second][0] = true;

	while (!q.empty()) {
		int x, y, count, key;
		std::tie(x, y, count, key) = q.front();
		q.pop();

		if (map[x][y] == '1') return count;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (map[nx][ny] == '#') continue;
				else if (std::islower(map[nx][ny])) {
					if (!visited[nx][ny][key | (1 << (map[nx][ny] - 'a'))]) {
						visited[nx][ny][key | (1 << (map[nx][ny] - 'a'))] = true;
						q.emplace(std::make_tuple(nx, ny, count + 1, key | (1 << (map[nx][ny] - 'a'))));
					}
				}
				else if (std::isupper(map[nx][ny])) {
					if (!visited[nx][ny][key] && (key & (1 << (map[nx][ny] - 'A')))) {
						visited[nx][ny][key] = true;
						q.emplace(std::make_tuple(nx, ny, count + 1, key));
					}
				}
				else if (!visited[nx][ny][key]) {
					visited[nx][ny][key] = true;
					q.emplace(std::make_tuple(nx, ny, count + 1, key));
				}
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d %d", &N, &M);
	map.assign(N, std::vector<char>(M, 0));
	visited.assign(N, std::vector< std::vector<bool> >(M, std::vector<bool>(64, false)));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == '0') start = std::make_pair(i, j);
		}
	}
	printf("%d", calculate());
}