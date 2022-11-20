#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <map>

int N, M;
//connected[a]에 연결된 노드들은 first이며, a와 b 사이의 거리는 second
std::vector< std::map<int, int> > connected;
std::vector<bool> visited;
std::vector<int> depth;
std::vector<int> parent;
//BFS 기준으로 indexing 하기 위함(BFS에서 첫번째로 방문한 노드는 1번, 두번째는 4번 등등)
std::vector<int> index;
//root 노드에서 특정 노드까지의 부분합을 넣기 위함.(6번노드와 5번노드 간의 거리는 1 -> 6 과 1 -> 5의 거리를 빼면 된다.
std::vector<int> dp;

void bfs() {
	int idx = 1;
	visited[1] = true;
	depth[1] = 0;
	parent[1] = 0;
	index[1] = idx;
	dp[idx] = 0;

	//node, depth
	std::queue<std::pair<int, int> > q;
	q.emplace(std::make_pair(1, 1));

	while (!q.empty()) {
		auto front = q.front();
		q.pop();

		int node = front.first;
		int level = front.second;

		for (auto itr = connected[node].begin(); itr != connected[node].end(); itr++) {
			int n_node = itr->first;
			int node_to_n_node = itr->second;

			if (!visited[n_node]) {
				index[n_node] = ++idx;
				dp[idx] = dp[idx - 1] + node_to_n_node;
				visited[n_node] = true;
				depth[n_node] = level + 1;
				parent[n_node] = node;
				q.emplace(std::make_pair(n_node, depth[n_node]));
			}
		}
	}
}

int LCA(int a, int b) {
	int first_a = a;
	int first_b = b;

	if (depth[a] > depth[b]) std::swap(a, b);

	while (depth[a] != depth[b]) {
		b = parent[b];
	}

	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

	return dp[first_a] + dp[first_b] - (2 * dp[a]);
}

int main() {
	int a, b, c;
	scanf("%d", &N);

	connected.assign(N + 1, std::map<int, int>());
	visited.assign(N + 1, false);
	depth.assign(N + 1, 0);
	parent.assign(N + 1, 0);
	index.assign(N + 1, 0);
	dp.assign(N + 1, 0);

	for (int k = 0; k < N - 1; k++) {
		scanf("%d %d %d", &a, &b, &c);
		connected[a].insert(std::make_pair(b, c));
		connected[b].insert(std::make_pair(a, c));
	}

	bfs();
	scanf("%d", &M);

	for (int k = 0; k < M; k++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", LCA(a, b));
	}
}