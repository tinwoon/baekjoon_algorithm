#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

//1012 유기농 배추 문제
//전형적인 BFS문제로 어려운 부분은 없었음.

int t;
int m, n, k;
int a, b;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

std::vector< std::vector<bool> > map;
std::vector< std::vector<bool> > visited;

void calculate(int i, int j) {
	visited[i][j] = true;
	std::queue< std::pair<int, int> > q;
	q.emplace(std::make_pair(i, j));

	while (!q.empty()) {
		auto front = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = front.first + dx[k];
			int ny = front.second + dy[k];

			if (nx >=0 && nx < m && ny >= 0 && ny < n) {
				if (!visited[nx][ny] && map[nx][ny]) {
					visited[nx][ny] = true;
					q.emplace(std::make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	scanf("%d", &t);
	
	
	while (t--) {
		int ans = 0;
		scanf("%d %d %d", &m, &n, &k);
		map.assign(m, std::vector<bool>(n, 0));
		visited.assign(m, std::vector<bool>(n, 0));
		for (int index = 0; index < k; index++) {
			scanf("%d %d", &a, &b);
			map[a][b] = true;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && map[i][j]) {
					calculate(i, j);
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}

}