#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits.h>
#include <numeric>

// 1944 복제로봇 문제
// S, K간의 거리를 구한 뒤에 가장 가까운 걸로 모든 K와 S를 포함 한 것 중 최솟값을 찾으면 된다.
// 즉, MST문제이다.

int N, M;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
std::vector<int> parent;
std::vector < std::vector<char> > map;
std::vector< std::pair<int, int> > keys;


//distance , a번 노드, b번 노드
std::priority_queue< std::tuple<int, int, int>, std::vector< std::tuple<int, int, int> >, std::greater< std::tuple<int, int, int> > > pq;

int get_parent(int node) {
	if (parent[node] == node) return node;
	else return parent[node] = get_parent(parent[node]);
}

void union_n(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool find(int a, int b) {
	if (get_parent(a) == get_parent(b)) return true;
	else return false;
}

int bfs(int from, int to, std::pair<int, int> start, std::pair<int, int> end) {
	std::queue< std::tuple<int, int, int> > q;
	std::vector< std::vector<bool> > visited(N, std::vector<bool>(N, false));

	q.emplace(std::make_tuple(start.first, start.second, 0));
	visited[start.first][start.second] = true;

	while (!q.empty()) {
		int x, y, cost;
		std::tie(x, y, cost) = q.front();
		q.pop();


		if (x == end.first && y == end.second) {
			return cost;
		}

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (!visited[nx][ny] && map[nx][ny] != '1') {
					q.emplace(std::make_tuple(nx, ny, cost + 1));
					visited[nx][ny] = true;
				}
			}

		}
	}
	return -1;
}

int MST() {
	int ans = 0;
	int line_count = 0;
	while (!pq.empty()) {
		int cost, a, b;
		std::tie(cost, a, b) = pq.top();
		pq.pop();

		if (!find(a, b)) {
			union_n(a, b);
			ans += cost;
			line_count++;
			if (line_count == (keys.size() - 1)) return ans;
		}
	}
	return -1;
}

int main() {
	scanf("%d %d", &N, &M);
	map.assign(N, std::vector<char>(N, 0));
	parent.assign(M + 1, 0);
	std::iota(parent.begin(), parent.end(), 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'S' || map[i][j] == 'K') {
				keys.emplace_back(std::make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < keys.size(); i++) {
		for (int j = i + 1; j < keys.size(); j++) {
			int dis;
			if ((dis = bfs(i, j, keys[i], keys[j])) != -1) {
				pq.emplace(std::make_tuple(dis, i, j));
			}
		}
	}
	printf("%d", MST());
}