#pragma warning (disable : 4996)
#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#include <limits.h>
#include <algorithm>

//17141 연구소 2 문제
//전형적인 flood fill 문제와 조합문제이다.
//어려운 부분은 없었다.

int N, M;
std::vector <std::vector<int> > map;
std::vector< std::pair<int, int> > can_virus;
std::vector<int> chs;
//처음 바이러스를 놓을 수 있는 곳의 개수
int can_virus_size = 0;
//빈 칸의 개수
int empty_size = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int ans = INT_MAX;



int calculate() {
	std::queue< std::tuple<int, int, int> > q;
	std::vector< std::vector<bool> > visited(N, std::vector<bool>(N, 0));
	auto c_map = map;
	int ret = 0;
	int e_size = empty_size;

	for (int k = 0; k < chs.size(); k++) {
		q.emplace(std::make_tuple(can_virus[chs[k]].first, can_virus[chs[k]].second, 0));
		visited[can_virus[chs[k]].first][can_virus[chs[k]].second] = true;
		e_size--;
	}

	while (!q.empty()) {
		int x, y, count;

		std::tie(x, y, count) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			int ncount = count + 1;

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (!visited[nx][ny] && c_map[nx][ny] == 0) {
					visited[nx][ny] = true;
					q.emplace(std::make_tuple(nx, ny, count + 1));
					c_map[nx][ny] = ncount;
					ret = std::max(ret, ncount);
					e_size--;
				}
			}

		}

	}

	return (e_size == 0 ? ret : INT_MAX);
}

void choose(int level, int count) {
	if (level == M) {
		ans = std::min(ans, calculate());
		return;
	}

	for (int k = count; k < can_virus_size; k++) {
		chs[level] = k;
		choose(level + 1, k + 1);
	}

}


int main() {
	scanf("%d %d", &N, &M);
	map.assign(N, std::vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				can_virus.emplace_back(std::make_pair(i, j));
				map[i][j] = 0;
				empty_size++;
			}
			else if (map[i][j] == 0) empty_size++;
		}
	}
	can_virus_size = can_virus.size();
	chs.assign(M, 0);
	choose(0, 0);
	printf("%d\n", ans == INT_MAX ? -1 : ans);
}