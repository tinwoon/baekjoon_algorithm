#pragma warning (disable: 4996)
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <string.h>

//벌집 문제
//어려운 부분은 벌집의 구조를 배열로 정의하는 과정
//그 외에는 시뮬레이션에 가깝다 

int map[2000][2000];
int mx[6] = { -1, 0,1,1,0,-1 };
int my[6] = { 1,1,0,-1,-1,0 };
int dx[6] = { -1,-1,0,0,1,1 };
int dy[6] = { 0,1,-1,1,-1,0 };
int start, end;
std::pair<int,int> from[1000001];
std::pair<int, int> p_s, p_e;

void bfs() {

	for (int k = 0; k < 1000001; k++) from[k] = std::make_pair(-1, -1);

	for (int i = 0; i < 2000; i++) {
		for (int j = 0; j < 2000; j++) {
			if (map[i][j] == start) p_s = std::make_pair(i, j);
			if (map[i][j] == end) p_e = std::make_pair(i, j);
		}
	}

	std::queue< std::pair<int, int> > q;
	q.emplace(p_s);

	while (!q.empty()) {
		auto front = q.front();
		q.pop();

		if (map[front.first][front.second] == end) {
			return;
		}

		for (int k = 0; k < 6; k++) {
			int nx = front.first + dx[k];
			int ny = front.second + dy[k];
			if (nx >= 0 && nx < 2000 && ny >= 0 && ny < 2000) {
				if (from[map[nx][ny]] == std::make_pair(-1,-1)) {
					q.emplace(std::make_pair(nx, ny));
					from[map[nx][ny]] = std::make_pair(front.first, front.second);
				}
			}
		}
	}
	
}

int main() {
	map[1000][1000] = 1;
	int x = 1000, y = 999;
	int num = 2;
	int order = 1;
	while (num <= 1000000) {
		for (int i = 0; i <= 5; i++) {
			if (i == 0) {
				for (int k = 0; k < (order == 1 ? 1 : order - 1); k++) {
					x += mx[i];
					y += my[i];
					map[x][y] = num++;
				}
			}
			else {
				for (int k = 0; k < order; k++) {
					x += mx[i];
					y += my[i];
					map[x][y] = num++;
				}
			}
		}
		x += mx[5];
		y += my[5];
		map[x][y] = num++;
		order++;
	}
	scanf("%d %d", &start, &end);
	bfs();
	std::vector<int> ans;
	int rst = end;
	ans.emplace_back(rst);
	while (rst!= start) {
		rst = map[from[rst].first][from[rst].second];
		ans.emplace_back(rst);
	}
	for (auto ritr = ans.rbegin(); ritr != ans.rend(); ritr++) {
		printf("%d ", *ritr);
	}
}
