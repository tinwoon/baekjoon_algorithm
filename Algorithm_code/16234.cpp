#pragma warning (disable : 4996)
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

//그냥 bfs입니다

int N;
int L, R;
bool flag = false;
int ans = 0;
std::vector< std::vector<int> > map;
std::vector < std::vector<bool> > visited;

std::vector< std::pair<int, int> > c_node;
int c_node_sum = 0;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void calculate(int x, int y) {
	std::queue< std::pair<int, int> > q;
	q.emplace(std::make_pair(x, y));
	visited[x][y] = true;
	c_node.emplace_back(std::make_pair(x, y));
	c_node_sum = map[x][y];

	while (!q.empty()) {
		auto front = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = front.first + dx[k];
			int ny = front.second + dy[k];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				int diff = abs(map[nx][ny] - map[front.first][front.second]);
				if (diff >= L && diff <= R && !visited[nx][ny]) {
					flag = true;
					visited[nx][ny] = true;
					q.emplace(std::make_pair(nx, ny));
					c_node.emplace_back(std::make_pair(nx, ny));
					c_node_sum += map[nx][ny];
				}
			}
		}
	}

	for (int k = 0; k < c_node.size(); k++) {
		map[c_node[k].first][c_node[k].second] = c_node_sum / (int)c_node.size();
	}
	c_node_sum = 0;
	c_node.clear();

}

int main() {
	scanf("%d %d %d", &N, &L, &R);
	map.assign(N, std::vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	while (1) {
		flag = false;
		visited.assign(N, std::vector<bool>(N, false));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) calculate(i, j);
			}
		}
		if (flag) ans++;
		else break;
	}

	printf("%d", ans);
}